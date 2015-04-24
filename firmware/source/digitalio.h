#ifndef DIGITALIO_H
#define	DIGITALIO_H

#include "pins.h"

// DIO chip select pin
#define DIO_CS_TRIS _TRISB12
#define DIO_CS _RB12
// DIO interrupt pin
#define DIO_INT_TRIS _TRISB13
#define DIO_INT _RB13

// R/W ops: device header + addr + op flag
#define DIO_CTRL_READ 0b01000001
#define DIO_CTRL_WRITE 0b01000000

// device register addresses
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


void digitalio_init();
void digitalio_pin_mode(PinInfo_s * pin, PinMode_e mode);
void digitalio_write(uint8_t reg_addr, uint8_t data);
uint8_t digitalio_read(uint8_t reg_addr);

bool digitalio_test();

#endif
