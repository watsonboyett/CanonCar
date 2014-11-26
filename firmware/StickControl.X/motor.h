
#ifndef MOTOR_H
#define MOTOR_H

#define m1p1_pin _RA2
#define m1p1_dir _TRISA2
//#define m1p1 _LATA2
#define m1p2_pin _RA3
#define m1p2_dir _TRISA3
//#define m1p2 _LATA3
#define m2p1_pin _RB4
#define m2p1_dir _TRISB4
//#define m2p1 _LATB4
#define m2p2_pin _RA4
#define m2p2_dir _TRISA4
//#define m2p2 _LATA4

#define m1v1_pin _RB5
#define m1v1_dir _TRISB5
//#define m1v1 _LATB5
#define m1v2_pin _RB6
#define m1v2_dir _TRISB6
//#define m1v2 _LATB6
#define m2v1_pin _RB7
#define m2v1_dir _TRISB7
//#define m2v1 _LATB7
#define m2v2_pin _RB8
#define m2v2_dir _TRISB8
//#define m2v2 _LATB8

#define PWM_RES 4096
void motor_init( );

void motor_set_dir(unsigned int motor, unsigned int chan, unsigned int dir);
void motor_set_speed(unsigned int motor, unsigned int chan, float val);


#endif
