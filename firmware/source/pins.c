
#include "pins.h"

PinInfo_s Pin_RA0 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 0, .analog_chan = 0};
PinInfo_s Pin_RA1 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 1, .analog_chan = 1};
PinInfo_s Pin_RA2 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 2, .analog_chan = -1};
PinInfo_s Pin_RA3 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 3, .analog_chan = -1};
PinInfo_s Pin_RA4 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 4, .analog_chan = -1};
PinInfo_s Pin_RB0 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 0, .analog_chan = 2};
PinInfo_s Pin_RB1 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 1, .analog_chan = 3};
PinInfo_s Pin_RB2 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 2, .analog_chan = 4};
PinInfo_s Pin_RB3 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 3, .analog_chan = 5};
PinInfo_s Pin_RB4 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 4, .analog_chan = -1};
PinInfo_s Pin_RB5 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 5, .analog_chan = -1};
PinInfo_s Pin_RB6 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 6, .analog_chan = -1};
PinInfo_s Pin_RB7 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 7, .analog_chan = -1};
PinInfo_s Pin_RB8 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 8, .analog_chan = -1};
PinInfo_s Pin_RB9 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 9, .analog_chan = -1};
PinInfo_s Pin_RB10 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 10, .analog_chan = -1};
PinInfo_s Pin_RB11 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 11, .analog_chan = -1};
PinInfo_s Pin_RB12 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 12, .analog_chan = 12};
PinInfo_s Pin_RB13 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 13, .analog_chan = 11};
PinInfo_s Pin_RB14 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 14, .analog_chan = 10};
PinInfo_s Pin_RB15 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 15, .analog_chan = 9};

PinInfo_s Pin_SPI_D0 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 0};
PinInfo_s Pin_SPI_D1 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 1};
PinInfo_s Pin_SPI_D2 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 2};
PinInfo_s Pin_SPI_D3 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 3};
PinInfo_s Pin_SPI_D4 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 4};
PinInfo_s Pin_SPI_D5 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 5};
PinInfo_s Pin_SPI_D6 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 6};
PinInfo_s Pin_SPI_D7 = {.location = SPI_DIO, .tris = 0, .port = 0, .latch = 0, .bit_pos = 7};


PinConfig_s Pin_A0 = {.info = &Pin_RA0, .mode = Digital, .dir = Output};
PinConfig_s Pin_A1 = {.info = &Pin_RA1, .mode = Digital, .dir = Output};
PinConfig_s Pin_A2 = {.info = &Pin_RA2, .mode = Digital, .dir = Output};    // no AN
PinConfig_s Pin_A3 = {.info = &Pin_RA3, .mode = Digital, .dir = Output};    // no AN
PinConfig_s Pin_A4 = {.info = &Pin_RA4, .mode = Digital, .dir = Output};    // no AN
PinConfig_s Pin_A5 = {.info = &Pin_RB2, .mode = Digital, .dir = Output};
PinConfig_s Pin_A6 = {.info = &Pin_RB3, .mode = Digital, .dir = Output};
PinConfig_s Pin_A7 = {.info = &Pin_RB4, .mode = Digital, .dir = Output};    // no AN
PinConfig_s Pin_A8 = {.info = &Pin_RB0, .mode = Digital, .dir = Output};
PinConfig_s Pin_A9 = {.info = &Pin_RB1, .mode = Digital, .dir = Output};

PinConfig_s Pin_D0 = {.info = &Pin_SPI_D0, .mode = Digital, .dir = Input};
PinConfig_s Pin_D1 = {.info = &Pin_SPI_D1, .mode = Digital, .dir = Input};
PinConfig_s Pin_D2 = {.info = &Pin_SPI_D2, .mode = Digital, .dir = Input};
PinConfig_s Pin_D3 = {.info = &Pin_SPI_D3, .mode = Digital, .dir = Input};
PinConfig_s Pin_D4 = {.info = &Pin_SPI_D4, .mode = Digital, .dir = Input};
PinConfig_s Pin_D5 = {.info = &Pin_SPI_D5, .mode = Digital, .dir = Input};
PinConfig_s Pin_D6 = {.info = &Pin_SPI_D6, .mode = Digital, .dir = Input};
PinConfig_s Pin_D7 = {.info = &Pin_SPI_D7, .mode = Digital, .dir = Input};


PinConfig_s * pin_array[18] = {
    &Pin_A0,
    &Pin_A1,
    &Pin_A2,
    &Pin_A3,
    &Pin_A4,
    &Pin_A5,
    &Pin_A6,
    &Pin_A7,
    &Pin_A8,
    &Pin_A9,
    &Pin_D0,
    &Pin_D1,
    &Pin_D2,
    &Pin_D3,
    &Pin_D4,
    &Pin_D5,
    &Pin_D6,
    &Pin_D7,
};

PinConfig_s * get_pin_config(PinName_e pin)
{
    return pin_array[pin];
}

PinInfo_s * get_pin_info(PinName_e pin)
{
    return pin_array[pin]->info;
}

PinMode_e get_pin_mode(PinName_e pin)
{
    return get_pin_config(pin)->mode;
}

PinDir_e get_pin_dir(PinName_e pin)
{
    return get_pin_config(pin)->dir;
}

