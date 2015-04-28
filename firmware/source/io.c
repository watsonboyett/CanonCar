
#include "io.h"

void io_init()
{
    analogio_init();
    digitalio_init();
}

void pin_mode(const PinName_e pin, const PinMode_e mode)
{
    PinInfo_s * pin_info = get_pin_info(pin);

    if (mode == Digital_In || mode == Digital_Out)
    {
        digitalio_pin_mode(pin_info, mode);
    }
    else if (mode == Analog_In || mode == Analog_Out)
    {
        analogio_pin_mode(pin_info, mode);
    }
}


bool digital_read(const PinName_e pin)
{
    PinInfo_s * pin_info = get_pin_info(pin);
    return digitalio_read(pin_info);
}

void digital_write(const PinName_e pin, const bool value)
{
    PinInfo_s * pin_info = get_pin_info(pin);
    digitalio_write(pin_info, value);
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
