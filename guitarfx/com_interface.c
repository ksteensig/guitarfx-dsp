/*
 * com_interface.c
 *
 *  Created on: 24. apr. 2019
 *      Author: Krist
 */

#include "com_interface.h"

CSL_I2cConfig       COMS_I2C_config;
CSL_I2cSetup        COMS_I2C_setup;

void COMS_SetupI2C(Uint16 slaveAddress){
    CSL_Status status; // Used to escape if an error occurs
    Uint16             startStop; // What is this

    // Initialize the I2C for setup and eventually run
    status = I2C_init(CSL_I2C0);
    if(status != CSL_SOK){printf("I2C Init Failed\n"); return;} // System OK

    COMS_I2C_setup.addrMode    = CSL_I2C_ADDR_7BIT;
    COMS_I2C_setup.bitCount    = CSL_I2C_BC_8BITS;
    COMS_I2C_setup.loopBack    = CSL_I2C_LOOPBACK_DISABLE;
    COMS_I2C_setup.freeMode    = CSL_I2C_FREEMODE_DISABLE;
    COMS_I2C_setup.repeatMode  = CSL_I2C_REPEATMODE_DISABLE;
    COMS_I2C_setup.ownAddr     = COMS_I2C_OWN_ADDR;
    COMS_I2C_setup.sysInputClk = COMS_I2C_SYS_CLK;
    COMS_I2C_setup.i2cBusFreq  = COMS_I2C_BUS_FREQ;
    startStop            = ((CSL_I2C_START) | (CSL_I2C_STOP));

    status = I2C_setup(&COMS_I2C_setup);
    if(status != CSL_SOK){printf("I2C Setup Failed\n"); return;} // System OK


}
