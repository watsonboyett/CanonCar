
#include "io.h"

void io_init()
{
    analogio_init();
    digitalio_init();
}

void pin_mode(PinConfig_s * pin, const PinMode_e mode, const PinDir_e dir)
{
    if (mode == Digital)
    {
        digitalio_set_dir(pin, dir);
    }
    else if (mode == Analog)
    {
        analogio_set_dir(pin, dir);
    }

    pin->mode = mode;
}

bool digital_read(PinConfig_s * pin)
{
    return digitalio_read(pin);
}

void digital_write(PinConfig_s * pin, const bool value)
{
    digitalio_write(pin, value);
}

uint16_t analog_read(PinConfig_s * pin)
{
    return analogio_read(pin);
}

float analog_read_frac(PinConfig_s * pin)
{
    return analogio_read_frac(pin);
}

void analog_write(PinConfig_s * pin, const uint16_t value)
{
    analogio_write(pin, value);
}

void analog_write_frac(PinConfig_s * pin, const float value)
{
    analogio_write_frac(pin, value);
}
