#include <stdio.h>
#include <usbstk5505.h>
#include <aic3204.h>
#include "PLL.h"
#include <csl_pll.h>
#include <stereo.h>
#include <csl_intc.h>
#include <csl_dma.h>

volatile Int16 dummy;
volatile Int16 left_input;
volatile Int16 right_input;
volatile Int16 left_output;
volatile Int16 right_output;
volatile Int16 mono_input;

#define SAMPLES_PER_SECOND 48000

/* New. Gain as a #define */
/* Use 30 for microphone. Use 0 for line */
#define GAIN_IN_dB 0

unsigned long int i = 0;

/* New. Variable for step */
unsigned int Step = 1;

extern void ringBuffer();
extern void echoUpdate();

interrupt void myIsr() {
    //dummy = I2S2_W0_LSW_R;              // Read Least Significant Word (ignore)
    //dummy = I2S2_W1_LSW_R;
    //I2S2_W0_MSW_W = I2S2_W0_MSW_R;         // Left output
    //I2S2_W1_MSW_W = I2S2_W1_MSW_R;        // Right output
    //I2S2_W0_LSW_W = 0;
    //I2S2_W1_LSW_W = 0;

    __asm(" MOV *(#002A2Dh), AR0 ");

    echoUpdate();

    __asm(" AMOV #002A0Dh, XAR1 ");
    __asm(" MOV AR0, *AR1 ");

    //__asm(" AMOV #, XAR1 ");
    //__asm(" AMOV XAR0, *XAR1 ");

    //__asm(" NOP ");
}


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void main( void )
{
    /* Initialize BSL */
    USBSTK5505_init( );

    /* Initialize PLL */
    //pll_frequency_setup(100);

    //PLL_Obj pllObj;

    /* Initialise hardware interface and I2C for code */
    aic3204_hardware_init();

    /* Initialise the AIC3204 codec */
    aic3204_init();

    printf("\n\nRunning Improved Audio Template Project\n");
    printf( "<-> Audio Loopback from Stereo IN --> to HP/Lineout\n\n" );

    /* Setup sampling frequency and 30dB gain for microphone */
    set_sampling_frequency_and_gain(SAMPLES_PER_SECOND, GAIN_IN_dB);

    /* New. Add descriptive text */
    puts("\nChanges configuration once every 20 seconds and flashes LED");
    puts(" 1 Flash   = Straight through, no signal processing");
    puts(" 2 Flashes = Convert stereo to mono");
    puts(" 3 Flashes = Left input -> right output. Right input -> left output");

    /* New. Default to XF LED off */

    //CSL_DMA_Config dmaConfig;
/*
    dmaConfig.pingPongMode  = CSL_DMA_PING_PONG_ENABLE;
    dmaConfig.autoMode      = CSL_DMA_AUTORELOAD_ENABLE;
    dmaConfig.burstLen      = CSL_DMA_TXBURST_4WORD;
    dmaConfig.trigger       = CSL_DMA_EVENT_TRIGGER;
    dmaConfig.dmaInt        = CSL_DMA_INTERRUPT_DISABLE;
    dmaConfig.dataLen       = 8;
    dmaConfig.trfType       = CSL_DMA_TRANSFER_IO_MEMORY;


    dmaConfig.chanDir       = CSL_DMA_READ;
    dmaConfig.dmaEvt        = CSL_DMA_EVT_I2S2_RX;              // Microphone on I2S1 (CSL_DMA_EVT_I2S0_RX)
    dmaConfig.srcAddr       = (Uint32)(I2S2_W0_LSW_R);// I2S0 Receive left Data 0 Register
    dmaConfig.destAddr      = (Uint32)(I2S2_W0_LSW_W);


    CSL_Status status;
    CSL_DMA_Handle = DMA_open(CSL_DMA_CHAN1, &dmaCodecUL_Obj, &status);
    DMA_config(hDMA_CodecUL, &dmaConfig);
  */

    ringBuffer();

    Uint32 vec;

    IRQ_setVecs(((Uint32)&vec) << 1);
    IRQ_plug(15, &myIsr);
    IRQ_enable(15);
    IRQ_globalEnable();

    while (1);
}
