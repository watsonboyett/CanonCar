#ifndef SPI_UTIL_H
#define	SPI_UTIL_H

#include "common.h"

void spi_init();
void spi_write(uint8_t data);
uint8_t spi_read();
uint8_t spi_clear_rx();

#endif
