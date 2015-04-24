
#include "digitalio.h"
#include "util.h"
#include "spi_util.h"

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

}

/* write sequence for DIO SPI device */
void digitalio_write(uint8_t reg_addr, uint8_t data)
{
    DIO_CS = 0;

    // send header + device addres + write opcode
    spi_write(DIO_CTRL_WRITE);
    // send register address
    spi_write(reg_addr);
    // send data
    spi_write(data);

    DIO_CS = 1;
}

/* read sequence for DIO SPI device */
uint8_t digitalio_read(uint8_t reg_addr)
{
    DIO_CS = 0;

    // send header + device addres + write opcode
    spi_write(DIO_CTRL_READ);
    // send register address
    spi_write(reg_addr);
    // clear receive buffer (and overflow bit)
    spi_clear_rx();
    // send register address again (used to clock data into receive buffer)
    spi_write(reg_addr);

    DIO_CS = 1;

    // read from receive buffer
    uint8_t data = spi_read();
    return data;
}

bool digitalio_test()
{
    bool success = true;

    uint8_t write1 = 0x00;
    digitalio_write(DIO_ADDR_IODIR, write1);
    delay_ms(100);
    uint8_t read1 = digitalio_read(DIO_ADDR_IODIR);
    success &= (read1 == write1);

    uint8_t write2 = 0x69;
    digitalio_write(DIO_ADDR_GPIO, write2);
    delay_ms(100);
    uint8_t read2 = digitalio_read(DIO_ADDR_GPIO);
    success &= (read2 == write2);

    uint8_t write3 = 0xA5;
    digitalio_write(DIO_ADDR_OLAT, write3);
    delay_ms(100);
    uint8_t read3 = digitalio_read(DIO_ADDR_OLAT);
    success &= (read3 == write3);

    Nop();
    return success;
}
