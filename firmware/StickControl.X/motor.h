
#ifndef MOTOR_H
#define MOTOR_H

#define D1C1_VREF _RB5
#define D1C1_TRIS _TRISB5
#define D1C2_VREF _RB6
#define D1C2_TRIS _TRISB6

#define D1C1_PHASE 0
#define D1C2_PHASE 1
#define D1C1_I01 2
#define D1C1_I02 3

#define D2C1_VREF _RB7
#define D2C1_TRIS _TRISB7
#define D2C2_VREF _RB8
#define D2C2_TRIS _TRISB8

#define D2C1_PHASE 4
#define D2C2_PHASE 5
#define D2C1_I01 6
#define D2C1_I02 7


#define PWM_RES 4096
void motor_init( );

typedef enum {
    Motor1,
    Motor2
} MotorDriver_e;

typedef enum {
    Stepper,
    DC
} MotorMode_e;

void motor_set_mode(MotorDriver_e driver, MotorMode_e mode);
void motor_set_dir(MotorDriver_e driver, unsigned int chan, unsigned int dir);
void motor_set_speed(MotorDriver_e driver, unsigned int chan, float val);


#endif
