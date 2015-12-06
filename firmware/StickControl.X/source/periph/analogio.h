#ifndef ANALOGIO_H
#define ANALOGIO_H

#include "../bsp/bsp.h"

#define ADC_NCHAN 8
#define ADC_RES 4096

void analogio_init();
void analogio_set_dir(PinConfig_s * pin, const PinDir_e dir);

uint16_t analogio_read(PinConfig_s * pin);
float analogio_read_frac(PinConfig_s * pin);
void analogio_write(PinConfig_s * pin, const uint16_t value);
void analogio_write_frac(PinConfig_s * pin, const float value);

#endif
