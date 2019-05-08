/*
 * com_interface.c
 *
 *  Created on: 24. apr. 2019
 *      Author: Krist
 */

#include "com_interface.h"

CSL_I2cConfig       COMS_I2C_config;
CSL_I2cSetup        COMS_I2C_setup;

CSL_DMA_Handle        dmaHandle;
CSL_DMA_Config        dmaConfig;
CSL_DMAChanNum        dmaChanNum;
CSL_DMA_ChannelObj    dmaChanObj;

unsigned long DMA_CONFIG_TEMP_ADDRESS = 0;
unsigned long CONFIG_ADDRESS = 0;

CSL_Status COMS_SetupI2C( void ){

    puts("COMS_SetupI2C\n");
    CSL_Status status; // Used to escape if an error occurs

    // Initialize the I2C for setup and eventually run
    status = I2C_init(CSL_I2C0);

    if(status != CSL_SOK){puts("I2C Init Failed\n"); return status;} // System OK

    // Configure I2C
    COMS_I2C_setup.addrMode    = CSL_I2C_ADDR_7BIT;         // Standard
    COMS_I2C_setup.bitCount    = CSL_I2C_BC_8BITS;          // Standard
    COMS_I2C_setup.loopBack    = CSL_I2C_LOOPBACK_DISABLE;  // Standard
    COMS_I2C_setup.freeMode    = CSL_I2C_FREEMODE_DISABLE;  // Standard
    COMS_I2C_setup.repeatMode  = CSL_I2C_REPEATMODE_DISABLE;// Standard
    COMS_I2C_setup.ownAddr     = COMS_I2C_OWN_ADDR;         // Set in header
    COMS_I2C_setup.sysInputClk = COMS_I2C_SYS_CLK;          // Set in header (from example)
    COMS_I2C_setup.i2cBusFreq  = COMS_I2C_BUS_FREQ;         // Set in header (from example)

    // Setup I2C with configured parameters
    status = I2C_setup(&COMS_I2C_setup);
    if(status != CSL_SOK){puts("I2C Setup Failed\n"); return status;} // System OK
    CSL_FINST(i2cHandle->i2cRegs->ICMDR, I2C_ICMDR_STT, SET);
    return CSL_SOK;

}

CSL_Status COMS_SetupDMA( void ){
    DMA_CONFIG_TEMP_ADDRESS = get_config_dma_address(); // Return BYTE address (no offset yet)
    //DMA_CONFIG_TEMP_ADDRESS = DMA_CONFIG_TEMP_ADDRESS + 0x10000; // Add DARAM offset to byte address.
    CONFIG_ADDRESS = DMA_CONFIG_TEMP_ADDRESS + (COMS_CONFIGSIZE * 2);

    dmaChanNum = CSL_DMA_CHAN8; //DMA2CH0 - not confirmed yet
    CSL_Status status;

    // Initialize DMA module (clock enable, etc.)
    status = DMA_init(); // ALWAYS returns CSL_SOK, no need to check it then.

    // OPEN DMA CHANNEL
    dmaHandle = DMA_open(dmaChanNum, &dmaChanObj, &status);
    if(status != CSL_SOK){puts("DMA open Failed\n"); return status;} // Sys Check


    // Configuration
    // Ping Pong Mode should always be disabled
    dmaConfig.pingPongMode = CSL_DMA_PING_PONG_DISABLE;
    // Autoreload should always be enabled.
    // This allows the DMA to rerun on every event trigger.
    dmaConfig.autoMode     = CSL_DMA_AUTORELOAD_ENABLE;
    // Burst Length = 1 DoubleWord every event
    dmaConfig.burstLen     = CSL_DMA_TXBURST_1WORD;
    // Trigger type is "event"
    dmaConfig.trigger      = CSL_DMA_EVENT_TRIGGER;
    // Event to trigger on is "I2C Receive Ready"
    dmaConfig.dmaEvt       = CSL_DMA_EVT_I2C_RX;
    // We should interrupt the CPU
    dmaConfig.dmaInt       = CSL_DMA_INTERRUPT_ENABLE;
    // We are reading from a device
    dmaConfig.chanDir      = CSL_DMA_READ;
    // We are transfering from IO to Memory
    dmaConfig.trfType      = CSL_DMA_TRANSFER_IO_MEMORY;
    // Number of doublewords to transfer for each run of the DMA (not per event) * 4 to get in bytes.
    dmaConfig.dataLen      = COMS_CONFIGSIZE*4;
    dmaConfig.srcAddr      = (Uint32)&(i2cHandle->i2cRegs->ICDRR);
    dmaConfig.destAddr     = (Uint32)DMA_CONFIG_TEMP_ADDRESS;

    // CONFIGURE DMA HANDLER
    status = DMA_config(dmaHandle, &dmaConfig);
    if(status != CSL_SOK){puts("DMA Config Failed\n"); return status;}

    // Enable DMA2CH0 in DMAInterruptEnableRegister
    asm(" OR #0000000100000000b, *(#1C31h) ");

    // Return status if we got this far, everything should be OK.
    return CSL_SOK;
}

CSL_Status COMS_Enable( void ){
    CSL_Status status;
    status = DMA_start(dmaHandle);
    if(status != CSL_SOK){puts("DMA Start/Enable Failed\n"); return status;}
    return CSL_SOK;
}

CSL_Status COMS_Disable( void ){
    CSL_Status status;
    status = DMA_stop(dmaHandle);
    if(status != CSL_SOK){puts("DMA Stop/Disable Failed\n"); return status;}
    return CSL_SOK;
}



// END OF FILE
