#ifndef COMMONIO_H
#define	COMMONIO_H

#include "common.h"

typedef volatile uint16_t * RegAddr_t;

typedef enum {
    Internal,
    External
} PortLocation_e;

typedef enum {
    Digital_In,
    Digital_Out,
    Analog_In,
    Analog_Out
} PinMode_e;

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

typedef struct {
    PortLocation_e location;
    RegAddr_t port;
    RegAddr_t tris;
    uint8_t bit_pos;
    PinMode_e mode;
} PinInfo_s;

PinInfo_s * get_pin_info(PinName_e pin);

#endif
