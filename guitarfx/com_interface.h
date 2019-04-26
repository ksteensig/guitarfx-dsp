/*
 * com_interface.h
 *
 *  Created on: 24. apr. 2019
 *      Author: Kristoffer
 */
#ifndef _COM_INTERFACE_H
#define _COM_INTERFACE_H

#include <csl_i2c.h>
#include <csl_general.h>
#include <stdio.h>

#define COMS_I2C_OWN_ADDR         (0x2F)
#define COMS_I2C_SYS_CLK          (100)
#define COMS_I2C_BUS_FREQ         (10)

CSL_I2cConfig       COMS_I2C_config;
CSL_I2cSetup        COMS_I2C_setup;


void COMS_SetupI2C(Uint16 slaveAddress);


#endif // _COM_INTERFACE_H
