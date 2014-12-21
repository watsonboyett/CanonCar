

#include <p24Hxxxx.h>
//#include <Generic.h>
//#include <ports.h>
#include <pps.h>
#include <timer.h>

#include "motor.h"
#include "util.h"



/* initialize motor drivers */
void motor_init() {

    // setup motor direction pins
    m1p1_dir = 0;
    m1p2_dir = 0;
    m2p1_dir = 0;
    m2p2_dir = 0;

    // setup open drain outputs (for full motor voltage range)
    //ODCB = ODCB | 0b0000000111100000;

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
    OpenTimer2(T2_ON & T2_GATE_OFF & T2_IDLE_STOP &
            T2_PS_1_1 & T2_SOURCE_INT, PWM_RES);
}


unsigned int m1v1_dc = 0;
unsigned int m1v2_dc = 0;
unsigned int m2v1_dc = 0;
unsigned int m2v2_dc = 0;

/* update motor control voltages (PWM) */
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void) {
    /* Interrupt Service Routine code goes here */
    OC1RS = m1v1_dc; // Write Duty Cycle value for next PWM cycle
    OC2RS = m1v2_dc; // Write Duty Cycle value for next PWM cycle
    OC3RS = m2v1_dc; // Write Duty Cycle value for next PWM cycle
    OC4RS = m2v2_dc; // Write Duty Cycle value for next PWM cycle

    IFS0bits.T2IF = 0; // Clear Timer 2 interrupt flag
}

/* set motor direction */
void motor_set_dir(unsigned int motor, unsigned int chan, unsigned int dir) {
    if (motor == 1) {
        if (chan == 1) {
            m1p1_pin = dir;
        } else if (chan == 2) {
            m1p2_pin = dir;
        }
    } else if (motor == 2) {
        if (chan == 1) {
            m2p1_pin = dir;
        } else if (chan == 2) {
            m2p2_pin = dir;
        }
    }
}

/* stop motor voltage/speed */
void motor_set_speed(unsigned int motor, unsigned int chan, float val) {
    unsigned int buf = val * PWM_RES;
    // ensure output is clamped at max value
    if (buf > PWM_RES) {
        buf = PWM_RES;
    }

    // set output voltage
    if (motor == 1) {
        if (chan == 1) {
            m1v1_dc = buf;
        } else if (chan == 2) {
            m1v2_dc = buf;
        }
    } else if (motor == 2) {
        if (chan == 1) {
            m2v1_dc = buf;
        } else if (chan == 2) {
            m2v2_dc = buf;
        }
    }
}

