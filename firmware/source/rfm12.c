/*** FILEHEADER ****************************************************************
 *
 *    FILENAME:    rfm12.c
 *    DATE:        31.10.2010
 *    AUTHOR:      (c) Christian Stadler
 *
 *    DESCRIPTION: Driver for RFM12 wireless tranceiver module.
 *
 ******************************************************************************/

/*** HISTORY OF CHANGE *********************************************************
 *
 *    $Log: /pic/_drv/rfm12.c $
 * 
 * 2     1.11.10 11:50 Stadler
 * - adaptions for Microchip C18 compiler
 * 
 * 1     31.10.10 14:45 Stadler
 * - RFM12 tranceiver module driver
 * 
 ******************************************************************************/

#include "rfm12.h"
#include "util.h"



/*****************************************************************************/
/* RFM12_Write                                                               */
/*                                                                           */
/* Writes 16 bit data to RFM12 module via SPI interface and returns 16 bit   */
/* data which has been read during write.                                    */
/*                                                                           */
/* data:    16 bit data to be written to the RFM12 module                    */
/*                                                                           */
/* Return:  16 bit value read from RFM12 module                              */

/*****************************************************************************/
uint16_t RFM12_Write(uint16_t data)
{
    uint16_t data_in = 0;
    uint8_t bit_i;

    /* set select RFM12 module */
    RFM12_ClrNSEL();

    for (bit_i = 0; bit_i < 16; bit_i++)
    {
        /* transmit bit per bit, MSB first */
        if (data & 0x8000)
        {
            RFM12_SetSDI();
        }
        else
        {
            RFM12_ClrSDI();
        }
        data <<= 1;

        /* get bit from RFM12 module */
        data_in <<= 1;
        if (RFM12_GetSDO())
        {
            data_in |= 1;
        }

        /* toggle clock */
        RFM12_SetSCK();
        RFM12_ClrSCK();
    }

    /* deselect RFM12 module */
    RFM12_SetNSEL();
    return (data_in);
}

/* config sequence for DIO SPI device */
void RFM12_init()
{
    // set chip-select pin as output (and set it to idle)
    RFM12_CS_TRIS = 0;
    RFM12_CS = 1;

    // set interrupt pin as input
    RFM12_INT_TRIS = 1;
}


/*****************************************************************************/
/* RFM12_Init                                                                */
/*                                                                           */
/* Initialize RFM12 module.                                                  */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_setup(void)
{
    RFM12_GetIRQ();
    RFM12_GetSDO();

    RFM12_SetNSEL();
    RFM12_ClrSCK();

    /* wait until POR done */
    delay_ms(1000);

    RFM12_Write(0x0000);
    RFM12_Write(0xC0E0); /* clockout: 10MHz */
    RFM12_Write(0x80D7); /* enable FIFO */
    RFM12_Write(0xC2AB); /* data filter: internal */
    RFM12_Write(0xCA81); /* set FIFO mode */
    RFM12_Write(0xE000); /* disable wakeuptimer */
    RFM12_Write(0xC800); /* disable low duty cycle */
    RFM12_Write(0xC4F7); /* AFC settings: autotuning: -10kHz...+7,5kHz */

    // set radio parameters
    RFM12_SetFreq(RFM12FREQ(433.92)); // Rx/Tx frequency 433.92MHz
    RFM12_SetBandwidth(4, 1, 4); // 200kHz BW, -6dB LNA gain, DRSSI: -79dBm )
    RFM12_SetBaud(19200); // 19200 baud
    RFM12_SetPower(0, 6); // 1mW output power, 120kHz frequency shift
}



/*****************************************************************************/
/* RFM12_SetBandwidth                                                        */
/*                                                                           */
/* Set bandwidth.                                                            */
/*                                                                           */
/* bandwidth:  Baseband Bandwidth [kHz]                                      */
/*             0 .. reserved                                                 */
/*             1 .. 400 kHz                                                  */
/*             2 .. 340 kHz                                                  */
/*             3 .. 270 kHz                                                  */
/*             4 .. 200 kHz                                                  */
/*             5 .. 134 kHz                                                  */
/*             6 .. 67 kHz                                                   */
/*             7 .. reserved                                                 */
/* gain:       LNA gain (dBm)                                                */
/*             0 .. 0 dBm                                                    */
/*             1 .. -6 dBm                                                   */
/*             2 .. -14 dBm                                                  */
/*             3 .. -20 dBm                                                  */
/* drssi:      RSSIsetth [dBm]                                               */
/*             0 .. -103 dBm                                                 */
/*             1 .. -97 dBm                                                  */
/*             2 .. -91 dBm                                                  */
/*             3 .. -85 dBm                                                  */
/*             4 .. -79 dBm                                                  */
/*             5 .. -73 dBm                                                  */
/*             6 .. reserved                                                 */
/*             7 .. reserved                                                 */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_SetBandwidth(uint8_t bandwidth, uint8_t gain, uint8_t drssi)
{
    RFM12_Write(0x9400 | ((bandwidth & 7) << 5) | ((gain & 3) << 3) | (drssi & 7));
}



/*****************************************************************************/
/* RFM12_SetFreq                                                             */
/*                                                                           */
/* Set frequency. Use RFM12FREQ macro to convert frequency to proper value.  */
/*                                                                           */
/* freq:  RFM12 frequency for wireless communication                         */
/*        Example usage: RFM12_SetFreq(RFM12FREQ(430.2400MHz));              */
/*        Possible frequency values: 430.2400MHz .. 439.7575MHz              */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_SetFreq(uint16_t freq)
{
    /* 430.2400MHz */
    if (freq < 96)
    {
        freq = 96;
    }
        /* 439.7575MHz */
    else if (freq > 3903)
    {
        freq = 3903;
    }
    RFM12_Write(0xA000 | freq);
}



/*****************************************************************************/
/* RFM12_SetBaud                                                             */
/*                                                                           */
/* Set baudrate.                                                             */
/*                                                                           */
/* baud:  desired baudrate                                                   */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_SetBaud(uint16_t baud)
{
    if (baud < 663)
    {
        return;
    }

    /* Baudrate= 344827,58621/(R+1)/(1+CS*7) */
    if (baud < 5400)
    {
        RFM12_Write(0xC680 | ((43104 / baud) - 1));
    }
    else
    {
        RFM12_Write(0xC600 | ((344828UL / baud) - 1));
    }
}



/*****************************************************************************/
/* RFM12_SetPower                                                            */
/*                                                                           */
/* Set output power.                                                         */
/*                                                                           */
/* power:  output power                                                      */
/*         0 .. 0 dBm (1mW)                                                  */
/*         1 .. -3 dBm (501 µW)                                              */
/*         2 .. -6 dBm (251 µW)                                              */
/*         3 .. -9 dBm (126 µW)                                              */
/*         4 .. -12 dBm (63 µW)                                              */
/*         5 .. -15 dBm (32 µW)                                              */
/*         6 .. -18 dBm (16 µW)                                              */
/*         7 .. -21 dBm (8 µW)                                               */
/* mod:    frequency deviation                                               */
/*         0 .. 15 kHz                                                       */
/*         1 .. 30 kHz                                                       */
/*         2 .. 45 kHz                                                       */
/*         3 .. 60 kHz                                                       */
/*         4 .. 75 kHz                                                       */
/*         5 .. 90 kHz                                                       */
/*         6 .. 105 kHz                                                      */
/*         7 .. 120 kHz                                                      */
/*         8 .. 135 kHz                                                      */
/*         9 .. 150 kHz                                                      */
/*         10 .. 165 kHz                                                     */
/*         11 .. 180 kHz                                                     */
/*         12 .. 195 kHz                                                     */
/*         13 .. 210 kHz                                                     */
/*         14 .. 225 kHz                                                     */
/*         15 .. 240 kHz                                                     */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_SetPower(uint8_t power, uint8_t mod)
{
    RFM12_Write(0x9800 | (power & 7) | ((mod & 15) << 4));
}


/*****************************************************************************/
/* RFM12_Ready                                                               */
/*                                                                           */
/* Waits until FIFO is ready.                                                */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_Ready(void)
{
    RFM12_ClrSDI();
    RFM12_ClrNSEL();

    /* wait until FIFO ready */
    while (!(RFM12_GetSDO()));
}



/*****************************************************************************/
/* RFM12_TxData                                                              */
/*                                                                           */
/* Transmit data via RFM12 wireless tranceiver module.                       */
/*                                                                           */
/* data:   pointer to data buffer to be transmitted                          */
/* length: data buffer length                                                */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_TxData(uint8_t *data, uint8_t length)
{
    uint8_t i;

    /* enable TX */
    RFM12_Write(0x8238);
    RFM12_Ready();

    /* send preamble (0xAA) */
    RFM12_Write(0xB8AA);
    RFM12_Ready();
    RFM12_Write(0xB8AA);
    RFM12_Ready();
    RFM12_Write(0xB8AA);
    RFM12_Ready();

    /* send sync word 0x2DD4 */
    RFM12_Write(0xB82D);
    RFM12_Ready();
    RFM12_Write(0xB8D4);

    /* send data buffer */
    for (i = 0; i < length; i++)
    {
        RFM12_Ready();
        RFM12_Write(0xB800 | (*data++));
    }
    RFM12_Ready();

    /* transmit 2 dummy bytes to avoid that last bytes of real payload don't */
    /* get transmitted properly (due to transmitter disabled to early) */
    RFM12_Write(0xB800);
    RFM12_Ready();
    RFM12_Write(0xB800);
    RFM12_Ready();

    /* disable TX */
    RFM12_Write(0x8208);
}



/*****************************************************************************/
/* RFM12_TxData                                                              */
/*                                                                           */
/* Receive data via RFM12 wireless tranceiver module.                        */
/*                                                                           */
/* data:   pointer to data buffer to be received                             */
/* length: number of bytes to be received                                    */
/*                                                                           */
/* Return:  none                                                             */

/*****************************************************************************/
void RFM12_RxData(uint8_t *data, uint8_t length)
{
    uint8_t i;

    /* enable RX */
    RFM12_Write(0x82C8);

    /* set FIFO mode */
    RFM12_Write(0xCA81);

    /* enable FIFO */
    RFM12_Write(0xCA83);

    RFM12_ClrSDI();
    //delay_us(3);
    for (i = 0; i < length; i++)
    {
        RFM12_Ready();
        *data++ = RFM12_Write(0xB000);
    }

    /* disable RX */
    RFM12_Write(0x8208);
}

