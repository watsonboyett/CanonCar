
#include "pins.h"

PinInfo_s Pin_RA0 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 0, .mode = Digital_Out};
PinInfo_s Pin_RA1 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 1, .mode = Digital_Out};
PinInfo_s Pin_RA2 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 2, .mode = Digital_Out};
PinInfo_s Pin_RA3 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 3, .mode = Digital_Out};
PinInfo_s Pin_RA4 = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 4, .mode = Digital_Out};
PinInfo_s Pin_RB0 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 0, .mode = Digital_Out};
PinInfo_s Pin_RB1 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 1, .mode = Digital_Out};
PinInfo_s Pin_RB2 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 2, .mode = Digital_Out};
PinInfo_s Pin_RB3 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 3, .mode = Digital_Out};
PinInfo_s Pin_RB4 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 4, .mode = Digital_Out};
PinInfo_s Pin_RB5 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 5, .mode = Digital_Out};
PinInfo_s Pin_RB6 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 6, .mode = Digital_Out};
PinInfo_s Pin_RB7 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 7, .mode = Digital_Out};
PinInfo_s Pin_RB8 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 8, .mode = Digital_Out};
PinInfo_s Pin_RB9 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 9, .mode = Digital_Out};
PinInfo_s Pin_RB10 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 10, .mode = Digital_Out};
PinInfo_s Pin_RB11 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 11, .mode = Digital_Out};
PinInfo_s Pin_RB12 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 12, .mode = Digital_Out};
PinInfo_s Pin_RB13 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 13, .mode = Digital_Out};
PinInfo_s Pin_RB14 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 14, .mode = Digital_Out};
PinInfo_s Pin_RB15 = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 15, .mode = Digital_Out};

PinInfo_s Pin_SPI_D0 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 0, .mode = Digital_In};
PinInfo_s Pin_SPI_D1 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 1, .mode = Digital_In};
PinInfo_s Pin_SPI_D2 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 2, .mode = Digital_In};
PinInfo_s Pin_SPI_D3 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 3, .mode = Digital_In};
PinInfo_s Pin_SPI_D4 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 4, .mode = Digital_In};
PinInfo_s Pin_SPI_D5 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 5, .mode = Digital_In};
PinInfo_s Pin_SPI_D6 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 6, .mode = Digital_In};
PinInfo_s Pin_SPI_D7 = {.location = External, .tris = 0, .port = 0, .latch = 0, .bit_pos = 7, .mode = Digital_In};

PinInfo_s * pin_array[18] = {
    &Pin_RA0,
    &Pin_RA1,
    &Pin_RA2,
    &Pin_RA3,
    &Pin_RA4,
    &Pin_RB2,
    &Pin_RB3,
    &Pin_RB4,
    &Pin_RB0,
    &Pin_RB1,
    &Pin_SPI_D0,
    &Pin_SPI_D1,
    &Pin_SPI_D2,
    &Pin_SPI_D3,
    &Pin_SPI_D4,
    &Pin_SPI_D5,
    &Pin_SPI_D6,
    &Pin_SPI_D7,
};

PinInfo_s * get_pin_info(PinName_e pin)
{
    return pin_array[pin];
}
