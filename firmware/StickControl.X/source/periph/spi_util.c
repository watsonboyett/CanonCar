
#include <pps.h>
#include <spi.h>

#include "../hal/hal.h"

/* Configure SPI module (used by several slave devices) */
void spi_init()
{
    // configure Peripheral Pin Select for SPI module
    PPSUnLock;
    OUT_PIN_PPS_RP9 = OUT_FN_PPS_SCK1;
    OUT_PIN_PPS_RP10 = OUT_FN_PPS_SDO1;
    IN_FN_PPS_SDI1 = IN_PIN_PPS_RP11;
    PPSLock;

    // NOTE: PIC24 docs claim that peripheral module handles TRIS bits, but they
    // appear to be incorrect; must set TRIS manually
    pin_mode(MISO, Digital, Input);

    // setup SPI configuration bits
    uint16_t cfg_SPI1CON1 = 0xFFFF;
    cfg_SPI1CON1 &= ENABLE_SCK_PIN;
    cfg_SPI1CON1 &= ENABLE_SDO_PIN;
    cfg_SPI1CON1 &= SPI_MODE16_OFF;
    cfg_SPI1CON1 &= SPI_SMP_OFF;
    cfg_SPI1CON1 &= SPI_CKE_ON;
    cfg_SPI1CON1 &= SLAVE_ENABLE_OFF;
    cfg_SPI1CON1 &= CLK_POL_ACTIVE_HIGH;
    cfg_SPI1CON1 &= MASTER_ENABLE_ON;
    cfg_SPI1CON1 &= PRI_PRESCAL_4_1;
    cfg_SPI1CON1 &= SEC_PRESCAL_8_1;
    SPI1CON1 = cfg_SPI1CON1;

    uint16_t cfg_SPI1CON2 = 0xFFFF;
    cfg_SPI1CON2 &= FRAME_ENABLE_OFF;
    cfg_SPI1CON2 &= FRAME_SYNC_OUTPUT;
    cfg_SPI1CON2 &= FRAME_POL_ACTIVE_LOW;
    cfg_SPI1CON2 &= FRAME_SYNC_EDGE_PRECEDE;
    cfg_SPI1CON2 &= FIFO_BUFFER_DISABLE;
    SPI1CON2 = cfg_SPI1CON2;

    uint16_t cfg_SPI1STAT = 0xFFFF;
    cfg_SPI1STAT &= SPI_DISABLE;  // keep module disabled while configuring it
    cfg_SPI1STAT &= SPI_IDLE_CON;
    cfg_SPI1STAT &= SPI_RX_OVFLOW_CLR;
    SPI1STAT = cfg_SPI1STAT;

    spi_clear_rx();

    IEC0bits.SPI1EIE = 1;

    // enable the SPI peripheral
    SPI1STATbits.SPIEN = 1;


    // enable the SPI periph
    SPI1STATbits.SPIEN = 1;
}

const static int SCLK_PER_ns = 800;

/* send data to the SPI module */
int spi_write(uint8_t data)
{
    // wait until SPI transmit buffer is clear
    int wait_count = 20;
    while (SPI1STATbits.SPITBF)
    {
        if (wait_count <= 0)
        {
            return 1;
        }
        delay_ns(SCLK_PER_ns);
        wait_count--;
    }

    // load SPI transmit buffer
    SPI1BUF = data;

    // NOTE: must wait until buffer full flag is set
    // (as described in 24HJ128GP502 errata)
    wait_count = 20;
    while (!SPI1STATbits.SPITBF)
    {
        if (wait_count <= 0)
        {
            return 1;
        }
        delay_ns(SCLK_PER_ns);
        wait_count--;
    }

    // wait until SPI transmit buffer is clear
    wait_count = 20;
    while (SPI1STATbits.SPITBF)
    {
        if (wait_count <= 0)
        {
            return 1;
        }
        delay_ns(SCLK_PER_ns);
        wait_count--;
    }

    // NOTE: must wait at least 1 SPI clock cycle before writing to SPIBUF again
    // (as described in 24HJ128GP502 errata)
    delay_ns(8*SCLK_PER_ns);
    
    return 0;
}

/* send data to the SPI module (and block until success) */
int spi_query(uint8_t send, uint8_t * resp)
{
    // dummy read from SPIxBUF to ensure it's clear (so overflow doesn't happen)
    spi_clear_rx();
    //*resp = SPI1BUF;
    
    // write zeros out, so CLK will continue to shift data into SDI
    int error = spi_write(send);

    // read in query response data
    error += spi_read(resp);
    
    return error;
}

/* send data to the SPI module (and block until success) */
int spi_read(uint8_t * data)
{
    int error = 0;
    
    // wait until SPI receive buffer is full
    int wait_count = 200;
    while (!SPI1STATbits.SPIRBF)
    {
        if (wait_count <= 0)
        {
            error = 1;
            break;
        }
        delay_ns(SCLK_PER_ns);
        wait_count--;
    }

    // return SPI receive buffer data
    *data = SPI1BUF;
    return error;
}

uint8_t spi_clear_rx()
{
    uint8_t data = SPI1BUF;
    SPI1STATbits.SPIROV = 0;
    return data;
}

void __attribute__((interrupt, auto_psv)) _SPI1ErrInterrupt(void)
{
    spi_clear_rx();
    IFS0bits.SPI1EIF = 0;
}


