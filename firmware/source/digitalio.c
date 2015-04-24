
#include <p24Hxxxx.h>
//#include <Generic.h>
//#include <ports.h>
#include <spi.h>

#include "digitalio.h"
#include "util.h"
#include "spi_util.h"

/* config sequence for DIO SPI device */
void dio_init()
{
    // set chip-select pin as output (and set it to idle)
    DIO_CS_TRIS = 0;
    DIO_CS = 1;

    // set interrupt pin as input
    DIO_INT_TRIS = 1;
}

/* write sequence for DIO SPI device */
void dio_write(uint8 reg_addr, uint8 data)
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
uint8 dio_read(uint8 reg_addr)
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
    uint8 data = spi_read();
    return data;
}

uint8 dio_test()
{

    dio_write(DIO_ADDR_IODIR, 0x00);
    delay_ms(100);
    uint8 read1 = dio_read(DIO_ADDR_IODIR);

    dio_write(DIO_ADDR_GPIO, 0x69);
    delay_ms(100);
    uint8 read2 = dio_read(DIO_ADDR_GPIO);

    dio_write(DIO_ADDR_OLAT, 0xA5);
    delay_ms(100);
    uint8 read3 = dio_read(DIO_ADDR_OLAT);

    Nop();
    return 0;
}
