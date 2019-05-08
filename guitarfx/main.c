#include "com_interface.h" // Used for communicating with Arduino
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

extern interrupt void isr_func();
extern void ring_buffer();

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void main( void )
{
    printf("Entering Main\n");
    /* Initialize BSL */
    USBSTK5505_init( );

    /* Initialise hardware interface and I2C for code */
    aic3204_hardware_init();

    /* Initialise the AIC3204 codec */
    aic3204_init();

    /* Setup sampling frequency and 30dB gain for microphone */
    set_sampling_frequency_and_gain(SAMPLES_PER_SECOND, GAIN_IN_dB);

    printf("AIC3204 is initialized and configured\n");

    // Communication setup
    CSL_Status status;
    //puts("Status declared\nEntering COMS_SetupI2C\n");
    status = COMS_SetupI2C();
    if(status != CSL_SOK){printf("I2C was not set up correctly!");}
    //puts("I2C was set up correctly!");
    status = COMS_SetupDMA();
    if(status != CSL_SOK){printf("DMA was not set up correctly!");}

    status = COMS_Enable();
    if(status != CSL_SOK){printf("DMA was not enabled!");}

    ring_buffer();

    Uint32 vec;

    IRQ_setVecs(((Uint32)&vec) << 1);
    IRQ_plug(15, &isr_func);
    IRQ_enable(15);
    IRQ_plug(8, &coms_isr);
    IRQ_enable(8);
    IRQ_globalEnable();

    while (1){}
}
