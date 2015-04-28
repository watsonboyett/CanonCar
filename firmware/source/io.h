#ifndef IO_H
#define	IO_H

#include "digitalio.h"
#include "analogio.h"


void io_init();

void pin_mode(const PinName_e pin, const PinMode_e mode, const PinDir_e dir);

bool digital_read(const PinName_e pin);
void digital_write(const PinName_e pin, const bool value);

int analog_read(const PinName_e pin);
void analog_write(const PinName_e pin, const int value);
void analog_reference(uint8_t mode);

#endif
