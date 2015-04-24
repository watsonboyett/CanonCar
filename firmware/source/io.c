
#include "io.h"

void io_init()
{
    analogio_init();
    digitalio_init();
}

void pin_mode(PinName_e pin, PinMode_e mode)
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
}


int digital_read(PinName_e pin)
{
    return 0;
}

void digital_write(PinName_e pin, bool value)
{

}


int analog_read(PinName_e pin)
{
    return 0;
}

void analog_reference(uint8_t mode)
{

}

void analog_write(PinName_e pin, int value)
{

}
