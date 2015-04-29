
#include "io.h"

void io_init()
{
    analogio_init();
    digitalio_init();
}

void pin_mode(const PinName_e pin, const PinMode_e mode, const PinDir_e dir)
{
    PinConfig_s * pin_config = get_pin_config(pin);

    if (mode == Digital)
    {
        digitalio_set_dir(pin_config, dir);
    }
    else if (mode == Analog)
    {
        analogio_set_dir(pin_config, dir);
    }

    pin_config->mode = mode;
}

bool digital_read(const PinName_e pin)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    return digitalio_read(pin_config);
}

void digital_write(const PinName_e pin, const bool value)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    digitalio_write(pin_config, value);
}

uint16_t analog_read(const PinName_e pin)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    return analogio_read(pin_config);
}

float analog_read_frac(const PinName_e pin)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    return analogio_read_frac(pin_config);
}

void analog_write(const PinName_e pin, const uint16_t value)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    analogio_write(pin_config, value);
}

void analog_write_frac(const PinName_e pin, const float value)
{
    PinConfig_s * pin_config = get_pin_config(pin);
    analogio_write_frac(pin_config, value);
}
