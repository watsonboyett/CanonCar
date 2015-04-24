
// system functions
#include <p24Hxxxx.h>
//#include <stdio.h>

// low level functions
#include "util.h"
#include "analogio.h"
#include "spi_util.h"
#include "digitalio.h"
#include "rfm12.h"
#include "motor.h"

// high level functions
#include "controller.h"
//#include "driver.h"
//#include "comm.h"


// Select Internal FRC at POR
_FOSCSEL(FNOSC_FRCPLL);
// Enable Clock Switching and Configure
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_OFF);
// Disable watchdog timer
_FWDT(FWDTEN_OFF);

int main(void)
{

    // initialize the brains
    clock_init();
    periph_killall();

    // initialize the peripherals
    aio_init();
    spi_init();
    dio_init();
    RFM12_init();
    motor_init();


    // show that we're alive
    blink_init();


    //stick_init();

    // the main loop
    while (1)
    {
        //drive();

        dio_test();
    }

    return 0;
}


uint8 dev_id = 0;

void trx()
{

    uint8 txbuf[] = {0, 0, 1, 0, 0, 0, 0, 1};
    uint8 rxbuf[8];
    uint8 i;
    bool rx_good = 1;

    // transmit message
    delay_ms(1000);
    if (dev_id == 0)
    {
        RFM12_TxData(txbuf, sizeof (txbuf));
        blink_flip();
    }
    else if (dev_id == 1)
    {
        RFM12_RxData(rxbuf, 8);

        for (i = 0; i < 8; i++)
        {
            if (txbuf[i] != rxbuf[i])
            {
                rx_good = 0;
                break;
            }
        }
        if (rx_good)
        {
            blink_flip();
        }
    }

}
