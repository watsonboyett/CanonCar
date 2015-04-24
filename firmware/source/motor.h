#ifndef MOTOR_H
#define MOTOR_H

#include "types.h"

#define D1C1_VREF _RB5
#define D1C1_TRIS _TRISB5
#define D1C2_VREF _RB6
#define D1C2_TRIS _TRISB6

#define D1C1_PHASE 0
#define D1C2_PHASE 1
#define D1Cx_Ix1 2
#define D1Cx_Ix2 3

#define D2C1_VREF _RB7
#define D2C1_TRIS _TRISB7
#define D2C2_VREF _RB8
#define D2C2_TRIS _TRISB8

#define D2C1_PHASE 4
#define D2C2_PHASE 5
#define D2Cx_Ix1 6
#define D2Cx_Ix2 7

#define PWM_RES 4096

typedef enum {
    Stepper,
    DC
} MotorMode_e;

typedef enum {
    Driver1,
    Driver2
} MotorDriver_e;

typedef enum {
    Channel1,
    Channel2
} DriverChannel_e;

typedef enum {
    Full = 0x00,
    TwoThirds = 0x10,
    OneThird = 0x01,
    None = 0x11
} MotorCurrentOutput_e;

typedef enum {
    Reverse = 0,
    Forward = 1
} MotorDirection_e;

void motor_init();
void motor_set_mode(MotorDriver_e driver, MotorMode_e mode);
void motor_set_dir(MotorDriver_e driver, DriverChannel_e channel, MotorDirection_e dir);
void motor_set_current_level(MotorDriver_e driver, DriverChannel_e chan, MotorCurrentOutput_e current);
void motor_set_speed(MotorDriver_e driver, DriverChannel_e chan, float val);


void spi_write_bit(uint8 bit_index, bool bit_value);
void spi_write_bits(uint8 bit_mask, uint8 bit_values);
bool spi_read_bit(uint8 bit_index);
uint8 spi_read_bits(uint8 bit_mask);

#endif
