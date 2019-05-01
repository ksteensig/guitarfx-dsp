/*
 * com_interface.h
 *
 *  Created on: 24. apr. 2019
 *      Author: Kristoffer
 */
#ifndef _COM_INTERFACE_H
#define _COM_INTERFACE_H


#include <stdio.h>
#include <csl_i2c.h>
#include <csl_dma.h>
#include <csl_general.h>

#define COMS_I2C_OWN_ADDR         (0x43)
#define COMS_I2C_SYS_CLK          (100)
#define COMS_I2C_BUS_FREQ         (10)

extern pI2cHandle     i2cHandle;

// Note that the functions below (all) should be called in the order they are listed!

CSL_Status COMS_SetupI2C( void ); // Call only once!

CSL_Status COMS_SetupDMA( void ); // Call only once! require: I2C setup

CSL_Status COMS_Enable( void ); // Call once to start, then only use after a COMS_Disable call

CSL_Status COMS_Disable( void ); // Only call after COMS_Enable call

#endif // _COM_INTERFACE_H
