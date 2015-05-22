
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

// SPI-DIO control words: device header (7-3) + addr (2-1) + R/W flag (0)
#define DIO_CTRL_READ 0b01000001
#define DIO_CTRL_WRITE 0b01000000

#define DIO_SPI_ADDR 0b00
#define MOTOR_SPI_ADDR 0b11

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

bool digitalio_read_external(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t bit_pos);
void digitalio_write_external(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t bit_pos, const bool val);

uint8_t digitalio_read_spi_register(const uint8_t device_addr, const uint8_t reg_addr);
void digitalio_write_spi_register(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t value);

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
        uint8_t tris = digitalio_read_spi_register(pin_info->addr, DIO_ADDR_IODIR);
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
        digitalio_write_spi_register(pin_info->addr, DIO_ADDR_IODIR, tris);
        delay_us(1);
    }

    pin->dir = dir;
}

bool digitalio_read(PinConfig_s * pin)
{
    PinInfo_s * pin_info = pin->info;
    if (pin->mode != Digital || !(pin->dir == Input || pin->dir == Input_Pullup))
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
        value = digitalio_read_external(pin_info->addr, DIO_ADDR_GPIO, pin_info->bit_pos);
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
        digitalio_write_external(pin_info->addr, DIO_ADDR_OLAT, pin_info->bit_pos, value);
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

void digitalio_write_external(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t bit_pos, const bool val)
{
    uint8_t latch = digitalio_read_spi_register(device_addr, reg_addr);
    //latch = digitalio_read_spi_register(device_addr, DIO_ADDR_OLAT);
    if (val)
    {
        bit_set(latch, bit_pos);
    }
    else
    {
        bit_clear(latch, bit_pos);
    }
    digitalio_write_spi_register(device_addr, DIO_ADDR_OLAT, latch);
    delay_us(1);
}

bool digitalio_read_external(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t bit_pos)
{
    // NOTE: first read gives incorrect values, second read gives correct values
    // (not sure why...)
    uint8_t port = digitalio_read_spi_register(device_addr, reg_addr);
    port = digitalio_read_spi_register(device_addr, reg_addr);
    bool val = bit_read(port, bit_pos);
    return val;
}

/* write sequence for DIO SPI device */
void digitalio_write_spi_register(const uint8_t device_addr, const uint8_t reg_addr, const uint8_t data)
{
    DIO_CS = 0;
    delay_ns(100);

    // send header + device addres + write opcode
    uint8_t header = DIO_CTRL_WRITE | (device_addr << 1);
    spi_write(header);

    // send register address
    spi_write(reg_addr);

    // send data
    spi_write(data);

    delay_ns(100);
    DIO_CS = 1;
}

/* read sequence for DIO SPI device */
uint8_t digitalio_read_spi_register(const uint8_t device_addr, const uint8_t reg_addr)
{
    DIO_CS = 0;
    delay_ns(100);
    
    // send header + device addres + write opcode
    uint8_t header = DIO_CTRL_READ | (device_addr << 1);
    spi_write(header);

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

