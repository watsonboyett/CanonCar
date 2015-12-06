#ifndef DIGITALIO_H
#define	DIGITALIO_H

#include "../bsp/pins.h"

void digitalio_init();
void digitalio_set_dir(PinConfig_s * pin, const PinDir_e dir);
bool digitalio_read(PinConfig_s * pin);
void digitalio_write(PinConfig_s * pin, const bool value);

bool digitalio_test();

#endif
