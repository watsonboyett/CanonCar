/* 
 * File:   spi_util.h
 * Author: merlin
 *
 * Created on October 30, 2012, 7:41 PM
 */

#ifndef SPI_UTIL_H
#define	SPI_UTIL_H

void spi_init( );
void spi_write(unsigned char);
unsigned char spi_read();
unsigned char spi_clear_rx();

#endif	/* SPI_UTIL_H */

