#ifndef MOTOR_H
#define MOTOR_H

#include "common.h"

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
    Full = 0b00,
    TwoThirds = 0b10,
    OneThird = 0b01,
    None = 0b11
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


#endif
