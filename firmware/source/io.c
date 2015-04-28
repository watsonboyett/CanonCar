
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
        digitalio_pin_mode(pin_config, dir);
    }
    else if (mode == Analog)
    {
        analogio_pin_mode(pin_config, dir);
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


int analog_read(const PinName_e pin)
{
    return 0;
}

void analog_write(const PinName_e pin, int value)
{

}

void analog_reference(uint8_t mode)
{

}

    /*
        uint8_t bit = digitalPinToBitMask(pin);
        uint8_t port = digitalPinToPort(pin);
        volatile uint8_t *reg, *out;

        if (port == NOT_A_PIN) return;

        // JWS: can I let the optimizer do this?
        reg = portModeRegister(port);
        out = portOutputRegister(port);

        if (mode == INPUT) {
                uint8_t oldSREG = SREG;
                cli();
     *reg &= ~bit;
     *out &= ~bit;
                SREG = oldSREG;
        } else if (mode == INPUT_PULLUP) {
                uint8_t oldSREG = SREG;
                cli();
     *reg &= ~bit;
     *out |= bit;
                SREG = oldSREG;
        } else {
                uint8_t oldSREG = SREG;
                cli();
     *reg |= bit;
                SREG = oldSREG;
        }
     */
