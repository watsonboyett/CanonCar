
#include "device.h"
#include "pins.h"

PinInfo_s RA0_info = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 0, .analog_chan = 0};
PinInfo_s RA1_info = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 1, .analog_chan = 1};
PinInfo_s RA2_info = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 2, .analog_chan = -1};
PinInfo_s RA3_info = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 3, .analog_chan = -1};
PinInfo_s RA4_info = {.location = Internal, .tris = &TRISA, .port = &PORTA, .latch = &LATA, .bit_pos = 4, .analog_chan = -1};
PinInfo_s RB0_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 0, .analog_chan = 2};
PinInfo_s RB1_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 1, .analog_chan = 3};
PinInfo_s RB2_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 2, .analog_chan = 4};
PinInfo_s RB3_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 3, .analog_chan = 5};
PinInfo_s RB4_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 4, .analog_chan = -1};
PinInfo_s RB5_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 5, .analog_chan = -1};
PinInfo_s RB6_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 6, .analog_chan = -1};
PinInfo_s RB7_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 7, .analog_chan = -1};
PinInfo_s RB8_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 8, .analog_chan = -1};
PinInfo_s RB9_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 9, .analog_chan = -1};
PinInfo_s RB10_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 10, .analog_chan = -1};
PinInfo_s RB11_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 11, .analog_chan = -1};
PinInfo_s RB12_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 12, .analog_chan = 12};
PinInfo_s RB13_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 13, .analog_chan = 11};
PinInfo_s RB14_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 14, .analog_chan = 10};
PinInfo_s RB15_info = {.location = Internal, .tris = &TRISB, .port = &PORTB, .latch = &LATB, .bit_pos = 15, .analog_chan = 9};

PinInfo_s SD0_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 0};
PinInfo_s SD1_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 1};
PinInfo_s SD2_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 2};
PinInfo_s SD3_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 3};
PinInfo_s SD4_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 4};
PinInfo_s SD5_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 5};
PinInfo_s SD6_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 6};
PinInfo_s SD7_info = {.location = SPI_DIO, .addr = 0b00, .tris = 0, .port = 0, .latch = 0, .bit_pos = 7};

PinInfo_s SM0_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 0};
PinInfo_s SM1_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 1};
PinInfo_s SM2_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 2};
PinInfo_s SM3_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 3};
PinInfo_s SM4_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 4};
PinInfo_s SM5_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 5};
PinInfo_s SM6_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 6};
PinInfo_s SM7_info = {.location = SPI_DIO, .addr = 0b11, .tris = 0, .port = 0, .latch = 0, .bit_pos = 7};


PinConfig_s Pin_RA0 = {.info = &RA0_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RA1 = {.info = &RA1_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RA2 = {.info = &RA2_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RA3 = {.info = &RA3_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RA4 = {.info = &RA4_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB0 = {.info = &RB0_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB1 = {.info = &RB1_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB2 = {.info = &RB2_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB3 = {.info = &RB3_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB4 = {.info = &RB4_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB5 = {.info = &RB5_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB6 = {.info = &RB6_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB7 = {.info = &RB7_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB8 = {.info = &RB8_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB9 = {.info = &RB9_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB10 = {.info = &RB10_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB11 = {.info = &RB11_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB12 = {.info = &RB12_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB13 = {.info = &RB13_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB14 = {.info = &RB14_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_RB15 = {.info = &RB15_info, .mode = Digital, .dir = Input};

PinConfig_s Pin_D0 = {.info = &SD0_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D1 = {.info = &SD1_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D2 = {.info = &SD2_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D3 = {.info = &SD3_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D4 = {.info = &SD4_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D5 = {.info = &SD5_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D6 = {.info = &SD6_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_D7 = {.info = &SD7_info, .mode = Digital, .dir = Input};

PinConfig_s Pin_M0 = {.info = &SM0_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M1 = {.info = &SM1_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M2 = {.info = &SM2_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M3 = {.info = &SM3_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M4 = {.info = &SM4_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M5 = {.info = &SM5_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M6 = {.info = &SM6_info, .mode = Digital, .dir = Input};
PinConfig_s Pin_M7 = {.info = &SM7_info, .mode = Digital, .dir = Input};


PinInfo_s * get_pin_info(PinConfig_s * pin)
{
    return pin->info;
}

PinMode_e get_pin_mode(PinConfig_s * pin)
{
    return pin->mode;
}

PinDir_e get_pin_dir(PinConfig_s * pin)
{
    return pin->dir;
}

