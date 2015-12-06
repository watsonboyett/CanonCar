#ifndef IO_H
#define	IO_H

#include "../periph/periph.h"


void io_init();

void pin_mode(PinConfig_s * pin, const PinMode_e mode, const PinDir_e dir);

bool digital_read(PinConfig_s * pin);
void digital_write(PinConfig_s * pin, const bool value);
//uint32_t pulse_in(const PinName_e pin);
//void pulse_out(const PinName_e, const uint32_t dur);


//void analog_reference(uint8_t mode);
uint16_t analog_read(PinConfig_s * pin);
float analog_read_frac(PinConfig_s * pin);
void analog_write(PinConfig_s * pin, const uint16_t value);
void analog_write_frac(PinConfig_s * pin, const float value);


#endif
