
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

void digitalio_set_dir(PinConfig_s * pin, const PinDir_e dir)
{
    PinInfo_s * pin_info = pin->info;
    if (pin_info->location == Internal)
    {
        uint16_t tris = *(pin_info->tris);
        if (dir == Output)
        {
            bit_clear(tris, pin_info->bit_pos);
        }
        else if (dir == Input || dir == Input_Pullup)
        {
            bit_set(tris, pin_info->bit_pos);

            if (dir == Input_Pullup)
            {
                // TODO: this
            }

            // NOTE: must set ADC pin config register to allow digital input
            if (pin_info->analog_chan != -1)
            {
                uint16_t cfg_AD1PCFGL = AD1PCFGL;
                bit_set(cfg_AD1PCFGL, pin_info->analog_chan);
                AD1PCFGL = cfg_AD1PCFGL;
            }
        }
        *(pin_info->tris) = tris;
    }
    else if (pin_info->location == SPI_DIO)
    {
        uint8_t tris = digitalio_read_spi_register(DIO_ADDR_IODIR);
        if (dir == Output)
        {
            bit_clear(tris, pin_info->bit_pos);
        }
        else if (dir == Input || dir == Input_Pullup)
        {
            bit_set(tris, pin_info->bit_pos);

            if (dir == Input_Pullup)
            {
                // TODO: this
            }
        }
        digitalio_write_spi_register(DIO_ADDR_IODIR, tris);
        delay_us(1);
    }

    pin->dir = dir;
}

bool digitalio_read(PinConfig_s * pin)
{
    PinInfo_s * pin_info = pin->info;
    if (pin->mode != Digital || pin->dir != Input || pin->dir != Input_Pullup)
    {
        digitalio_set_dir(pin, Input);
    }

    bool value = 0;
    if (pin_info->location == Internal)
    {
        value = digitalio_read_internal(pin_info->port, pin_info->bit_pos);
    }
    else if (pin_info->location == SPI_DIO)
    {
        value = digitalio_read_external(0, pin_info->bit_pos);
    }

    return value;
}

void digitalio_write(PinConfig_s * pin, const bool value)
{
    PinInfo_s * pin_info = pin->info;
    if (pin->mode != Digital || pin->dir != Output)
    {
        digitalio_set_dir(pin, Output);
    }

    if (pin_info->location == Internal)
    {
        digitalio_write_internal(pin_info->latch, pin_info->bit_pos, value);
    }
    else if (pin_info->location == SPI_DIO)
    {
        digitalio_write_external(0, pin_info->bit_pos, value);
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

