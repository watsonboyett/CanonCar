#ifndef SPI_UTIL_H
#define	SPI_UTIL_H

void spi_init();
int spi_write(uint8_t data);
int spi_query(uint8_t send, uint8_t * resp);
int spi_read(uint8_t * data);
uint8_t spi_clear_rx();

#endif
