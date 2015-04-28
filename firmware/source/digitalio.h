#ifndef DIGITALIO_H
#define	DIGITALIO_H

#include "pins.h"

void digitalio_init();
void digitalio_pin_mode(PinInfo_s * pin, const PinMode_e mode);
bool digitalio_read(PinInfo_s * pin);
void digitalio_write(PinInfo_s * pin, const bool value);

bool digitalio_test();

#endif
