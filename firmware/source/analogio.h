#ifndef ANALOGIO_H
#define ANALOGIO_H

#include "pins.h"

#define ADC_NCHAN 8
#define ADC_RES 4096

void analogio_init();
void analogio_pin_mode(PinConfig_s * pin, const PinDir_e dir);

float analogio_read(uint8_t chan);
void analogio_write(uint8_t chan, float val);

#endif
