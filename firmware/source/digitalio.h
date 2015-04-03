/* 
 * File:   digitalio.h
 * Author: merlin
 *
 * Created on October 28, 2012, 9:20 PM
 */

#ifndef DIGITALIO_H
#define	DIGITALIO_H


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



void dio_init();
void dio_write(unsigned char, unsigned char);
unsigned char dio_read(unsigned char reg_addr);
unsigned char dio_test();

#endif	/* DIGITALIO_H */

