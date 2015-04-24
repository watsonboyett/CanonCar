#ifndef SPI_UTIL_H
#define	SPI_UTIL_H

#include "types.h"


void spi_init();
void spi_write(uint8 data);
uint8 spi_read();
uint8 spi_clear_rx();


#endif
