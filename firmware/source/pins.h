#ifndef COMMONIO_H
#define	COMMONIO_H

#include "common.h"

// convenienence definitions for analog IO pins
typedef enum {
    A0 = 0,
    A1 = 1,
    A2 = 2,
    A3 = 3,
    A4 = 4,
    A5 = 5,
    A6 = 6,
    A7 = 7,
    A8 = 8,
    A9 = 9,

    D0 = 10,
    D1 = 11,
    D2 = 12,
    D3 = 13,
    D4 = 14,
    D5 = 15,
    D6 = 16,
    D7 = 17
} PinName_e;


typedef volatile uint16_t * const RegAddr_t;

typedef enum {
    Internal,
    SPI_DIO
} PortLoc_e;

typedef enum {
    Digital,
    Analog
} PinMode_e;

typedef enum {
    Output = 0,
    Input = 1,
    Input_Pullup = 2
} PinDir_e;

typedef struct {
    const PortLoc_e location;   // pin's location (internal/spi)
    RegAddr_t tris;             // pin's port direction register address
    RegAddr_t port;             // pin's port read register address
    RegAddr_t latch;            // pin's port write register address
    const uint8_t bit_pos;      // pin's bit position within port
    const uint8_t analog_chan;  // pin's analog channel (if present)
} PinInfo_s;

typedef struct {
    PinInfo_s * info;
    PinMode_e mode;
    PinDir_e dir;
} PinConfig_s;


PinConfig_s * get_pin_config(PinName_e pin);
PinInfo_s * get_pin_info(PinName_e pin);
PinMode_e get_pin_mode(PinName_e pin);
PinDir_e get_pin_dir(PinName_e pin);


#endif
