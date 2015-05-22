#ifndef COMMONIO_H
#define	COMMONIO_H

#include "common.h"

// convenienence definitions for analog IO pins

typedef enum {
    A0 = 0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    A8,
    A9,

    RFM_CS,
    RFM_IRQ,
    DIO_CS,
    DIO_IRQ,

    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,

    M1_PHASE1,
    M1_PHASE2,
    M1_I0X,
    M1_I1X,
    M2_PHASE1,
    M2_PHASE2,
    M2_I0X,
    M2_I1X,

    M1_VREF1,
    M1_VREF2,
    M2_VREF1,
    M2_VREF2
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
    Input_Pullup = 2,
    Output_OpenCollector = 3
} PinDir_e;

typedef struct {
    const PortLoc_e location;   // pin's location (internal/spi)
    const uint8_t addr;         // pin's base/device address
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
