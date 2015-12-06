#ifndef PINS_H
#define	PINS_H

#include <stdint.h>
#include <stdbool.h>


#define A0      (&Pin_RA0)
#define A1      (&Pin_RA1)
#define A2      (&Pin_RA2)
#define A3      (&Pin_RA3)
#define A4      (&Pin_RA4)
#define A5      (&Pin_RB2)
#define A6      (&Pin_RB3)
#define A7      (&Pin_RB4)


#define SCLK    (&Pin_RB9)
#define MOSI    (&Pin_RB10)
#define MISO    (&Pin_RB11)
#define DIO_CS  (&Pin_RB12)
#define DIO_IRQ (&Pin_RB13)
#define RFM_CS  (&Pin_RB14)
#define RFM_IRQ (&Pin_RB15)


#define D0      (&Pin_D0)
#define D1      (&Pin_D1)
#define D2      (&Pin_D2)
#define D3      (&Pin_D3)
#define D4      (&Pin_D4)
#define D5      (&Pin_D5)
#define D6      (&Pin_D6)
#define D7      (&Pin_D7)

#define M1_PHASE1   (&Pin_M0)
#define M1_PHASE2   (&Pin_M1)
#define M1_I0X      (&Pin_M2)
#define M1_I1X      (&Pin_M3)
#define M2_PHASE1   (&Pin_M4)
#define M2_PHASE2   (&Pin_M5)
#define M2_I0X      (&Pin_M6)
#define M2_I1X      (&Pin_M7)

#define M1_VREF1    (&Pin_RB5)
#define M1_VREF2    (&Pin_RB6)
#define M2_VREF1    (&Pin_RB7)
#define M2_VREF2    (&Pin_RB8)


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
    const PortLoc_e location; // pin's location (internal/spi)
    const uint8_t addr; // pin's base/device address
    RegAddr_t tris; // pin's port direction register address
    RegAddr_t port; // pin's port read register address
    RegAddr_t latch; // pin's port write register address
    const uint8_t bit_pos; // pin's bit position within port
    const uint8_t analog_chan; // pin's analog channel (if present)
} PinInfo_s;

typedef struct {
    PinInfo_s * const info;
    PinMode_e mode;
    PinDir_e dir;
} PinConfig_s;


PinInfo_s * get_pin_info(PinConfig_s * pin);
PinMode_e get_pin_mode(PinConfig_s * pin);
PinDir_e get_pin_dir(PinConfig_s * pin);



// NOTE: must define pins (declared in C source file)
// TODO: is there a better way of managing the pins than this?
extern PinConfig_s Pin_RA0;
extern PinConfig_s Pin_RA1;
extern PinConfig_s Pin_RA2;
extern PinConfig_s Pin_RA3;
extern PinConfig_s Pin_RA4;
extern PinConfig_s Pin_RB0;
extern PinConfig_s Pin_RB1;
extern PinConfig_s Pin_RB2;
extern PinConfig_s Pin_RB3;
extern PinConfig_s Pin_RB4;
extern PinConfig_s Pin_RB5;
extern PinConfig_s Pin_RB6;
extern PinConfig_s Pin_RB7;
extern PinConfig_s Pin_RB8;
extern PinConfig_s Pin_RB9;
extern PinConfig_s Pin_RB10;
extern PinConfig_s Pin_RB11;
extern PinConfig_s Pin_RB12;
extern PinConfig_s Pin_RB13;
extern PinConfig_s Pin_RB14;
extern PinConfig_s Pin_RB15;


extern PinConfig_s Pin_D0;
extern PinConfig_s Pin_D1;
extern PinConfig_s Pin_D2;
extern PinConfig_s Pin_D3;
extern PinConfig_s Pin_D4;
extern PinConfig_s Pin_D5;
extern PinConfig_s Pin_D6;
extern PinConfig_s Pin_D7;

extern PinConfig_s Pin_M0;
extern PinConfig_s Pin_M1;
extern PinConfig_s Pin_M2;
extern PinConfig_s Pin_M3;
extern PinConfig_s Pin_M4;
extern PinConfig_s Pin_M5;
extern PinConfig_s Pin_M6;
extern PinConfig_s Pin_M7;




#endif
