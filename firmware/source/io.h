#ifndef IO_H
#define	IO_H

#include "digitalio.h"
#include "analogio.h"


void io_init();

void pin_mode(const PinName_e pin, const PinMode_e mode, const PinDir_e dir);

bool digital_read(const PinName_e pin);
void digital_write(const PinName_e pin, const bool value);
//uint32_t pulse_in(const PinName_e pin);
//void pulse_out(const PinName_e, const uint32_t dur);


//void analog_reference(uint8_t mode);
uint16_t analog_read(const PinName_e pin);
float analog_read_frac(const PinName_e pin);
void analog_write(const PinName_e pin, const uint16_t value);
void analog_write_frac(const PinName_e pin, const float value);


#endif
