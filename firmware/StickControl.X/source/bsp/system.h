#ifndef SYSTEM_H
#define	SYSTEM_H

#include "device.h"

/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        (79227500L)  //(80000000L)
#define FCY             (SYS_FREQ/2)

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration functions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void);

void clock_init();
void periph_disable_all();

#endif
