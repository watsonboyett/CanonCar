
#include <pps.h>
#include <timer.h>
#include "motor.h"
#include "io.h"
#include "util.h"

#define D1C1_VREF _RB5
#define D1C1_TRIS _TRISB5
#define D1C2_VREF _RB6
#define D1C2_TRIS _TRISB6

#define D2C1_VREF _RB7
#define D2C1_TRIS _TRISB7
#define D2C2_VREF _RB8
#define D2C2_TRIS _TRISB8

#define PWM_RES 4096
//#define PWM_RES 32000


void motor_pwm_init();
void motor_io_init();

/* initialize motor pins and modules */
void motor_init()
{
    motor_pwm_init();
    motor_io_init();


}

void motor_pwm_init()
{
    // connect PWM pins to Output Compare module (for motor control voltage)
    PPSUnLock;
    OUT_PIN_PPS_RP5 = OUT_FN_PPS_OC1;
    OUT_PIN_PPS_RP6 = OUT_FN_PPS_OC2;
    OUT_PIN_PPS_RP7 = OUT_FN_PPS_OC3;
    OUT_PIN_PPS_RP8 = OUT_FN_PPS_OC4;
    PPSLock;

    // Initialize Output Compare Modules
    OC1CONbits.OCM = 0b000; // Disable Output Compare Module
    OC1R = 0; // Write the duty cycle for the first PWM pulse
    OC1RS = 0; // Write the duty cycle for the second PWM pulse
    OC1CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC1R = 0; // Load the Compare Register Value
    OC1CONbits.OCM = 0b110; // Select the Output Compare mode

    OC2CONbits.OCM = 0b000; // Disable Output Compare Module
    OC2R = 0; // Write the duty cycle for the first PWM pulse
    OC2RS = 0; // Write the duty cycle for the second PWM pulse
    OC2CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC2R = 0; // Load the Compare Register Value
    OC2CONbits.OCM = 0b110; // Select the Output Compare mode

    OC3CONbits.OCM = 0b000; // Disable Output Compare Module
    OC3R = 0; // Write the duty cycle for the first PWM pulse
    OC3RS = 0; // Write the duty cycle for the second PWM pulse
    OC3CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC3R = 0; // Load the Compare Register Value
    OC3CONbits.OCM = 0b110; // Select the Output Compare mode

    OC4CONbits.OCM = 0b000; // Disable Output Compare Module
    OC4R = 0; // Write the duty cycle for the first PWM pulse
    OC4RS = 0; // Write the duty cycle for the second PWM pulse
    OC4CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC4R = 0; // Load the Compare Register Value
    OC4CONbits.OCM = 0b110; // Select the Output Compare mode

    // Initialize and enable Timer2
    ConfigIntTimer2(T2_INT_PRIOR_2 & T2_INT_ON);
    WriteTimer2(0);
    OpenTimer2(T2_ON & T2_GATE_OFF & T2_IDLE_STOP
               & T2_PS_1_1 & T2_SOURCE_INT, PWM_RES);
}

void motor_io_init()
{
    pin_mode(M1_PHASE1, Digital, Output);
    pin_mode(M1_PHASE2, Digital, Output);
    pin_mode(M1_I0X, Digital, Output);
    pin_mode(M1_I1X, Digital, Output);

    pin_mode(M2_PHASE1, Digital, Output);
    pin_mode(M2_PHASE2, Digital, Output);
    pin_mode(M2_I0X, Digital, Output);
    pin_mode(M2_I1X, Digital, Output);

    // setup open drain outputs (for full motor voltage range)
    ODCB = ODCB | 0b0000000111100000;
}

MotorMode_e Driver1_Mode = DC;
MotorMode_e Driver2_Mode = DC;

void motor_set_mode(MotorDriver_e driver, MotorMode_e mode)
{
    if (driver == Driver1)
    {
        Driver1_Mode = mode;
    }
    else if (driver == Driver2)
    {
        Driver2_Mode = mode;
    }
}


uint16_t Driver1_Channel1_DC = 0;
uint16_t Driver1_Channel2_DC = 0;
uint16_t Driver2_Channel1_DC = 0;
uint16_t Driver2_Channel2_DC = 0;

/* update motor control voltages (PWM) */
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    OC1RS = Driver1_Channel1_DC; // Write Duty Cycle value for next PWM cycle
    OC2RS = Driver1_Channel2_DC; // Write Duty Cycle value for next PWM cycle
    OC3RS = Driver2_Channel1_DC; // Write Duty Cycle value for next PWM cycle
    OC4RS = Driver2_Channel2_DC; // Write Duty Cycle value for next PWM cycle

    IFS0bits.T2IF = 0; // Clear Timer 2 interrupt flag
}

/* set motor direction */
void motor_set_dir(MotorDriver_e driver, DriverChannel_e channel, MotorDirection_e dir)
{
    switch (driver)
    {
    case Driver1:
        if (channel == Channel1 || Driver1_Mode == Stepper)
        {
            digital_write(M1_PHASE1, dir);
        }
        if (channel == Channel2 || Driver1_Mode == Stepper)
        {
            digital_write(M1_PHASE2, dir);
        }
        break;

    case Driver2:
        if (channel == Channel1 || Driver2_Mode == Stepper)
        {
            digital_write(M2_PHASE1, dir);
        }
        if (channel == Channel2 || Driver2_Mode == Stepper)
        {
            digital_write(M2_PHASE2, dir);
        }
        break;
    }
}


// NOTE: current control for each channel is tied together (not enough pins...)
void motor_set_current_level(MotorDriver_e driver, DriverChannel_e channel, MotorCurrentOutput_e current)
{
    switch (driver)
    {
    case Driver1:
        if (channel == Channel1 || Driver1_Mode == Stepper)
        {
            digital_write(M1_I0X, bit_read(current, 0));
            digital_write(M1_I1X, bit_read(current, 1));
        }
        if (channel == Channel2 || Driver1_Mode == Stepper)
        {
            digital_write(M1_I0X, bit_read(current, 0));
            digital_write(M1_I1X, bit_read(current, 1));
        }
        break;

    case Driver2:
        if (channel == Channel1 || Driver2_Mode == Stepper)
        {
            digital_write(M2_I0X, bit_read(current, 0));
            digital_write(M2_I1X, bit_read(current, 1));
        }
        if (channel == Channel2 || Driver2_Mode == Stepper)
        {
            digital_write(M2_I0X, bit_read(current, 0));
            digital_write(M2_I1X, bit_read(current, 1));
        }
        break;
    }

    Nop();
}

/* stop motor voltage/speed */
void motor_set_speed(MotorDriver_e driver, DriverChannel_e channel, float val)
{
    uint16_t buf = val * PWM_RES;
    // ensure output is clamped at max value
    if (buf > PWM_RES)
    {
        buf = PWM_RES;
    }

    // set output voltage
    switch (driver)
    {
    case Driver1:
        if (channel == Channel1 || Driver1_Mode == Stepper)
        {
            Driver1_Channel1_DC = buf;
        }
        if (channel == Channel2 || Driver1_Mode == Stepper)
        {
            Driver1_Channel2_DC = buf;
        }
        break;

    case Driver2:
        if (channel == Channel1 || Driver2_Mode == Stepper)
        {
            Driver2_Channel1_DC = buf;
        }
        if (channel == Channel2 || Driver2_Mode == Stepper)
        {
            Driver2_Channel2_DC = buf;
        }
        break;

    }
}
