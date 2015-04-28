
#include "digitalio.h"
#include "util.h"
#include "spi_util.h"


bool digitalio_read_internal(RegAddr_t reg_addr, const uint8_t bit_pos);
void digitalio_write_internal(RegAddr_t reg_addr, const uint8_t bit_pos, const bool val);


// SPI-DIO chip select pin
#define DIO_CS_TRIS _TRISB12
#define DIO_CS _RB12
// SPI-DIO interrupt pin
#define DIO_INT_TRIS _TRISB13
#define DIO_INT _RB13

// SPI-DIO control words: device header + addr + R/W flag
#define DIO_CTRL_READ 0b01000001
#define DIO_CTRL_WRITE 0b01000000

// SPI-DIO register addresses
#define DIO_ADDR_IODIR 0x00
#define DIO_ADDR_IPOL 0x01
#define DIO_ADDR_GPINTEN 0x02
#define DIO_ADDR_DEFVAL 0x03
#define DIO_ADDR_INTCON 0x04
#define DIO_ADDR_IOCON 0x05
#define DIO_ADDR_GPPU 0x06
#define DIO_ADDR_INTF 0x07
#define DIO_ADDR_INTCAP 0x08
#define DIO_ADDR_GPIO 0x09
#define DIO_ADDR_OLAT 0x0A

bool digitalio_read_external(const uint8_t reg_addr, const uint8_t bit_pos);
void digitalio_write_external(const uint8_t reg_addr, const uint8_t bit_pos, const bool val);

uint8_t digitalio_read_spi_register(const uint8_t reg_addr);
void digitalio_write_spi_register(const uint8_t reg_addr, const uint8_t value);

/* config sequence for DIO SPI device */
void digitalio_init()
{
    // set chip-select pin as output (and set it to idle)
    DIO_CS_TRIS = 0;
    DIO_CS = 1;

    // set interrupt pin as input
    DIO_INT_TRIS = 1;
}

void digitalio_pin_mode(PinInfo_s * pin, PinMode_e mode)
{
    if (pin->location == Internal)
    {
        uint16_t tris = *(pin->tris);
        if (mode == Digital_Out)
        {
            bit_clear(tris, pin->bit_pos);
        }
        else if (mode == Digital_In)
        {
            bit_set(tris, pin->bit_pos);

            // NOTE: must configure ADC pins to allow digital input
            uint16_t adc_tris = AD1PCFGL;
            //bit_set(adc_tris, pin->bit_pos);      // AD1PCFGL ANx does not map to port pins number
            AD1PCFGL = adc_tris;
        }
        *(pin->tris) = tris;
    }
    else if (pin->location == External)
    {
        uint8_t tris = digitalio_read_spi_register(DIO_ADDR_IODIR);
        if (mode == Digital_Out)
        {
            bit_clear(tris, pin->bit_pos);
        }
        else if (mode == Digital_In)
        {
            bit_set(tris, pin->bit_pos);
        }
        digitalio_write_spi_register(DIO_ADDR_IODIR, tris);
        delay_us(1);
    }

    pin->mode = mode;
}

bool digitalio_read(PinInfo_s * pin)
{
    if (pin->mode != Digital_In)
    {
        digitalio_pin_mode(pin, Digital_In);
    }

    bool value = 0;
    if (pin->location == Internal)
    {
        value = digitalio_read_internal(pin->port, pin->bit_pos);
    }
    else if (pin->location == External)
    {
        value = digitalio_read_external(0, pin->bit_pos);
    }

    return value;
}

void digitalio_write(PinInfo_s * pin, const bool value)
{
    if (pin->mode != Digital_Out)
    {
        digitalio_pin_mode(pin, Digital_Out);
    }

    if (pin->location == Internal)
    {
        digitalio_write_internal(pin->latch, pin->bit_pos, value);
    }
    else if (pin->location == External)
    {
        digitalio_write_external(0, pin->bit_pos, value);
    }
}

void digitalio_write_internal(RegAddr_t reg_addr, const uint8_t bit_pos, const bool val)
{
    uint16_t latch = *(reg_addr);
    if (val)
    {
        bit_set(latch, bit_pos);
    }
    else
    {
        bit_clear(latch, bit_pos);
    }
    *(reg_addr) = latch;
}

bool digitalio_read_internal(RegAddr_t reg_addr, const uint8_t bit_pos)
{
    uint16_t port = *(reg_addr);
    bool val = bit_read(port, bit_pos);
    return val;
}

void digitalio_write_external(const uint8_t reg_addr, const uint8_t bit_pos, const bool val)
{
    uint8_t latch = digitalio_read_spi_register(DIO_ADDR_OLAT);
    if (val)
    {
        bit_set(latch, bit_pos);
    }
    else
    {
        bit_clear(latch, bit_pos);
    }
    digitalio_write_spi_register(DIO_ADDR_OLAT, latch);
    delay_us(1);
}

bool digitalio_read_external(const uint8_t reg_addr, const uint8_t bit_pos)
{
    // NOTE: first read gives incorrect values, second read gives correct values
    // (not sure why...)
    uint8_t port = digitalio_read_spi_register(DIO_ADDR_GPIO);
    port = digitalio_read_spi_register(DIO_ADDR_GPIO);
    bool val = bit_read(port, bit_pos);
    return val;
}

/* write sequence for DIO SPI device */
void digitalio_write_spi_register(const uint8_t reg_addr, const uint8_t data)
{
    DIO_CS = 0;
    delay_ns(100);

    // send header + device addres + write opcode
    spi_write(DIO_CTRL_WRITE);
    // send register address
    spi_write(reg_addr);
    // send data
    spi_write(data);

    delay_ns(100);
    DIO_CS = 1;
}

/* read sequence for DIO SPI device */
uint8_t digitalio_read_spi_register(const uint8_t reg_addr)
{
    DIO_CS = 0;
    delay_ns(100);

    // send header + device addres + write opcode
    spi_write(DIO_CTRL_READ);

    // send register address
    spi_write(reg_addr);

    // clear receive buffer (and overflow bit)
    spi_clear_rx();

    // send register address again (used to clock data into receive buffer)
    spi_write(reg_addr);

    // read from receive buffer
    uint8_t data = spi_read();

    delay_ns(100);
    DIO_CS = 1;

    return data;
}

bool digitalio_test()
{
    bool success = true;

    uint8_t reg1 = digitalio_read_spi_register(DIO_ADDR_IODIR);
    success &= (reg1 == 0xff);
    uint8_t dir = 0b11001010;
    digitalio_write_spi_register(DIO_ADDR_IODIR, dir);
    uint8_t reg1a = digitalio_read_spi_register(DIO_ADDR_IODIR);
    success &= (reg1a == dir);

    uint8_t reg2 = digitalio_read_spi_register(DIO_ADDR_IPOL);
    success &= (reg2 == 0x00);

    uint8_t reg3 = digitalio_read_spi_register(DIO_ADDR_GPINTEN);
    success &= (reg3 == 0x00);

    uint8_t reg4 = digitalio_read_spi_register(DIO_ADDR_DEFVAL);
    success &= (reg4 == 0x00);

    uint8_t reg5 = digitalio_read_spi_register(DIO_ADDR_INTCON);
    success &= (reg5 == 0x00);

    uint8_t reg6 = digitalio_read_spi_register(DIO_ADDR_IOCON);
    success &= (reg6 == 0x00);

    uint8_t reg7 = digitalio_read_spi_register(DIO_ADDR_GPPU);
    success &= (reg7 == 0x00);
    uint8_t pu = 0xff;
    digitalio_write_spi_register(DIO_ADDR_GPPU, 0xff);
    uint8_t reg7a = digitalio_read_spi_register(DIO_ADDR_GPPU);
    success &= (reg7a == pu);

    uint8_t reg8 = digitalio_read_spi_register(DIO_ADDR_INTF);
    success &= (reg8 == 0x00);

    uint8_t reg9 = digitalio_read_spi_register(DIO_ADDR_INTCAP);
    success &= (reg9 == 0x00);

    uint8_t reg11 = digitalio_read_spi_register(DIO_ADDR_OLAT);
    success &= (reg11 == 0x00);
    uint8_t latch = 0b10101100;
    digitalio_write_spi_register(DIO_ADDR_GPPU, latch);
    uint8_t reg11a = digitalio_read_spi_register(DIO_ADDR_OLAT);
    success &= (reg11a == latch);

    uint8_t port = 0b10101110;
    uint8_t reg10 = digitalio_read_spi_register(DIO_ADDR_GPIO);
    uint8_t reg10a = digitalio_read_spi_register(DIO_ADDR_GPIO);
    success &= (reg10 == port) && (reg10 == reg10a);

    Nop();
    return success;
}

