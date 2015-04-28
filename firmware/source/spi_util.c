
#include <pps.h>
#include <spi.h>

#include "util.h"

/* Configure SPI module (used by several slave devices) */
void spi_init()
{
    // configure Peripheral Pin Select for SPI module
    PPSUnLock;
    OUT_PIN_PPS_RP9 = OUT_FN_PPS_SCK1;
    OUT_PIN_PPS_RP10 = OUT_FN_PPS_SDO1;
    IN_FN_PPS_SDI1 = IN_PIN_PPS_RP11;
    PPSLock;

    // setup SPI configuration bits
    uint16_t cfg1 = MASTER_ENABLE_ON & SLAVE_ENABLE_OFF & ENABLE_SCK_PIN & ENABLE_SDO_PIN &
            SPI_MODE16_OFF & PRI_PRESCAL_4_1 & SEC_PRESCAL_8_1 &
            SPI_SMP_OFF & SPI_CKE_ON & CLK_POL_ACTIVE_HIGH;
    uint16_t cfg2 = FRAME_ENABLE_OFF & FRAME_SYNC_OUTPUT & FRAME_POL_ACTIVE_LOW &
            FRAME_SYNC_EDGE_PRECEDE;
    SPI1CON1 = cfg1;
    SPI1CON2 = cfg2;
    // enable the SPI periph
    SPI1STATbits.SPIEN = 1;
}

/* send data to the SPI module (and block until success) */
void spi_write(uint8_t data)
{
    // load SPI transmit buffer
    SPI1BUF = data;
    // block until buffer is filed (as per errata)
    while (!SPI1STATbits.SPITBF)
    {
        delay_ns(100);
    }
    // block until SPI transmit buffer is clear
    while (SPI1STATbits.SPITBF)
    {
        delay_ns(100);
    }
}

/* send data to the SPI module (and block until success) */
uint8_t spi_read()
{
    // block until SPI receive buffer is full
    while (!SPI1STATbits.SPIRBF)
    {
        delay_ns(100);
    }
    // return SPI receive buffer data
    uint8_t data = SPI1BUF;
    return data;
}

uint8_t spi_clear_rx()
{
    SPI1STATbits.SPIROV = 0;
    delay_ns(300);
    uint8_t data = SPI1BUF;
    delay_ns(300);
    SPI1STATbits.SPIROV = 0;
    delay_ns(300);
    return data;
}
