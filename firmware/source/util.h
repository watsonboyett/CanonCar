

/*
p01 - /Mclr
p02 (AN0/RA0/CN2) - HeartBeat
p03 (AN1/RA1/CN3) - Ain 1?
p04 (AN2/RB0/CN4) - PGD
p05 (AN3/RB1/CN5) - PGC
p06 (AN4/RB2/CN6) - Ain 2 (js.x-axis)
p07 (AN5/RB3/CN7) - Ain 3 (js.y-axis)
p08 - Vss (ground)
p09 (xxx/RA2/CN30) - 	[motor1 phase1]
p10 (xxx/RA3/CN29) - 	[motor1 phase2]
p11 (xxx/RB4/CN1) - 	[motor2 phase1]
p12 (xxx/RA4/CN0) - 	[motor2 phase2]
p13 - Vdd (power)
p14 (RP5/RB5/CN27) - 	[motor1 vref1]
- - - - - 
p15 (RP6/RB6/CN24) - 	[motor1 vref2]
p16 (RP7/RB7/CN23) - 	[motor2 vref1]
p17 (RP8/RB8/CN22) - 	[motor2 vref2]  (see 24H family errata for TRISB error)
p18 (RP9/RB9/CN21) - 	Spi Clk
p19 - Vss (ground)
p20 - Vcap
p21 (RP10/RB10/CN16) - 	Spi DO (MOSI)
p22 (RP11/RB11/CN15) - 	Spi DI (MISO)
p23 (AN12/RB12/CN14) - 	Digital I/O /cs
p24 (AN11/RB13/CN13) - 	Digital I/O /int
p25 (AN10/RB14/CN12) - 	Comms /cs (Uart Tx)
p26 (AN9/RB15/CN11) - 	Comms /int (Uart Rx)
p27 - Vss (ground)
p28 - Vdd (power)


{b1 left} 	[lim up]
{b2 middle} 	[lim down]
{b3 right} 	[lim left]
{ } 		[lim right]
{bt fire} 	[aim fire]


*/


#ifndef INIT_H
#define INIT_H

#define Fcy (40e6)


#define HEART_TRIS _RA0
#define HEART_LAT _LATA0


void clock_init( );
void periph_killall( );
void blink_init( );
void blink_flip( );


void delay_ns(unsigned long count);
void delay_us(unsigned long count);
void delay_ms(unsigned long count);
void delay(unsigned long count);

#endif

