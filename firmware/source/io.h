#ifndef IO_H
#define	IO_H

#include "digitalio.h"
#include "analogio.h"


void io_init();

void pin_mode(PinName_e pin, PinMode_e mode);
void digital_write(PinName_e pin, bool value);
int digital_read(PinName_e pin);
int analog_read(PinName_e pin);
void analog_reference(uint8_t mode);
void analog_write(PinName_e pin, int value);

#endif
