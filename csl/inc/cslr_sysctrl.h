/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/*********************************************************************
* file: cslr_sysctrl.h
*
* Brief: This file contains the Register Description for sys
*
*********************************************************************/
#ifndef _CSLR_SYSCTRL_H_
#define _CSLR_SYSCTRL_H_

#include <cslr.h>

#include <tistdtypes.h>
#include <csl_general.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/



typedef struct  {
	volatile Uint16 EBSR;
    volatile Uint16 RSVD0;
	volatile Uint16 PCGCR1;
    volatile Uint16 PCGCR2;
    volatile Uint16 PSRCR;
    volatile Uint16 PRCR;
    volatile Uint16 RSVD1[14];
    volatile Uint16 TIAFR;

#if (defined(CHIP_C5517))
	volatile Uint16 MSIAFR;
#else
    volatile Uint16 RSVD2;
#endif

    volatile Uint16 ODSCR;
    volatile Uint16 PDINHIBR1;
    volatile Uint16 PDINHIBR2;
    volatile Uint16 PDINHIBR3;
    volatile Uint16 DMA0CESR1;
    volatile Uint16 DMA0CESR2;
    volatile Uint16 DMA1CESR1;
    volatile Uint16 DMA1CESR2;

#if (defined(CHIP_C5517))
	volatile Uint16 CCR1;
    volatile Uint16 CCR2;
    volatile Uint16 PMR;
    volatile Uint16 PICR;
    volatile Uint16 PCR;
    volatile Uint16 PODCR;
#elif (defined(CHIP_C5505_C5515) || defined(CHIP_C5504_C5514) || defined(CHIP_C5535) || defined(CHIP_C5545))
    volatile Uint16 CCR1;
    volatile Uint16 CCR2;
    volatile Uint16 CGCR1;
    volatile Uint16 CGCR2;
    volatile Uint16 CGCR3;
    volatile Uint16 CGCR4;
#else
    volatile Uint16 CCR1;
    volatile Uint16 CCR2;
    volatile Uint16 CGCR1;
    volatile Uint16 CGICR;
    volatile Uint16 CGCR2;
    volatile Uint16 CGOCR;
#endif

#if (defined(CHIP_C5517))
    volatile Uint16 CLKOUTCR;
#else
    volatile Uint16 CCSSR;
#endif

    volatile Uint16 RSVD3;
    volatile Uint16 ECDR;

#if (defined(CHIP_C5517))
	volatile Uint16 RSCR;
#else
    volatile Uint16 RSVD4;
#endif

    volatile Uint16 RAMSLPMDCNTLR1;
    volatile Uint16 RSVD5;
    volatile Uint16 RAMSLPMDCNTLR2;

#if (defined(CHIP_C5505_C5515) || defined(CHIP_C5504_C5514) || defined(CHIP_C5517) || defined(CHIP_C5535) || defined(CHIP_C5545))
    volatile Uint16 RAMSLPMDCNTLR3;
    volatile Uint16 RAMSLPMDCNTLR4;
    volatile Uint16 RAMSLPMDCNTLR5;
    volatile Uint16 RSVD6[2];
#else
	volatile Uint16 RSVD6[5];
#endif

    volatile Uint16 DMAIFR;
    volatile Uint16 DMAIER;
    volatile Uint16 USBSCR;
    volatile Uint16 ESCR;

#if (defined(CHIP_C5517))
	volatile Uint16 BMR;
	volatile Uint16 RSVD7;
#else
	volatile Uint16 RSVD7[2];
#endif

    volatile Uint16 DMA2CESR1;
    volatile Uint16 DMA2CESR2;
    volatile Uint16 DMA3CESR1;
    volatile Uint16 DMA3CESR2;

#if (defined(CHIP_C5517))
	volatile Uint16 CLKSTOP1;
    volatile Uint16 CLKSTOP2;
    volatile Uint16 MSPIFCDR;
	volatile Uint16 MSIAER;
	volatile Uint16 TISR;
    volatile Uint16 RSVD8;
#else
    volatile Uint16 CLKSTOP;
    volatile Uint16 RSVD8[5];
#endif

    volatile Uint16 DIEIDR0;
    volatile Uint16 DIEIDR1;
    volatile Uint16 DIEIDR2;
    volatile Uint16 DIEIDR3;
    volatile Uint16 DIEIDR4;
    volatile Uint16 DIEIDR5;
    volatile Uint16 DIEIDR6;
    volatile Uint16 DIEIDR7;

#if (defined(CHIP_C5517))
    volatile Uint16 RSVD9[4];
    volatile Uint16 PUDINHIBR4;
    volatile Uint16 PUDINHIBR5;
    volatile Uint16 UHPICR;
    volatile Uint16 PUDINHIBR6;
    volatile Uint16 PUDINHIBR7;
    volatile Uint16 RSVD10[7];
    volatile Uint16 JTAGIDLSW;
    volatile Uint16 JTAGIDMSW;
#endif

} CSL_SysRegs;

/**************************************************************************\
* Field Definition Macros - C5504/05/14/15
\**************************************************************************/

#if (defined(CHIP_C5505_C5515) || defined(CHIP_C5504_C5514) || defined(CHIP_C5535) || defined(CHIP_C5545))


/* EBSR */


#define CSL_SYS_EBSR_PPMODE_MASK         (0x7000u)
#define CSL_SYS_EBSR_PPMODE_SHIFT        (0x000Cu)
#define CSL_SYS_EBSR_PPMODE_RESETVAL     (0x0000u)
/*----PPMODE Tokens----*/
#define CSL_SYS_EBSR_PPMODE_MODE0        (0x0000u)
#define CSL_SYS_EBSR_PPMODE_MODE1        (0x0001u)
#define CSL_SYS_EBSR_PPMODE_MODE2        (0x0002u)
#define CSL_SYS_EBSR_PPMODE_MODE3        (0x0003u)
#define CSL_SYS_EBSR_PPMODE_MODE4        (0x0004u)
#define CSL_SYS_EBSR_PPMODE_MODE5        (0x0005u)
#define CSL_SYS_EBSR_PPMODE_MODE6        (0x0006u)
#define CSL_SYS_EBSR_PPMODE_MODE7        (0x0007u)

#define CSL_SYS_EBSR_SP1MODE_MASK        (0x0C00u)
#define CSL_SYS_EBSR_SP1MODE_SHIFT       (0x000Au)
#define CSL_SYS_EBSR_SP1MODE_RESETVAL    (0x0000u)
/*----SP1MODE Tokens----*/
#define CSL_SYS_EBSR_SP1MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP1MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP1MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP1MODE_MODE3       (0x0003u)

#define CSL_SYS_EBSR_SP0MODE_MASK        (0x0300u)
#define CSL_SYS_EBSR_SP0MODE_SHIFT       (0x0008u)
#define CSL_SYS_EBSR_SP0MODE_RESETVAL    (0x0000u)
/*----SP0MODE Tokens----*/
#define CSL_SYS_EBSR_SP0MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP0MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP0MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP0MODE_MODE3       (0x0003u)


#define CSL_SYS_EBSR_A20_MODE_MASK       (0x0020u)
#define CSL_SYS_EBSR_A20_MODE_SHIFT      (0x0005u)
#define CSL_SYS_EBSR_A20_MODE_RESETVAL   (0x0000u)
/*----A20_MODE Tokens----*/
#define CSL_SYS_EBSR_A20_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A20_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A19_MODE_MASK       (0x0010u)
#define CSL_SYS_EBSR_A19_MODE_SHIFT      (0x0004u)
#define CSL_SYS_EBSR_A19_MODE_RESETVAL   (0x0000u)
/*----A19_MODE Tokens----*/
#define CSL_SYS_EBSR_A19_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A19_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A18_MODE_MASK       (0x0008u)
#define CSL_SYS_EBSR_A18_MODE_SHIFT      (0x0003u)
#define CSL_SYS_EBSR_A18_MODE_RESETVAL   (0x0000u)
/*----A18_MODE Tokens----*/
#define CSL_SYS_EBSR_A18_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A18_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A17_MODE_MASK       (0x0004u)
#define CSL_SYS_EBSR_A17_MODE_SHIFT      (0x0002u)
#define CSL_SYS_EBSR_A17_MODE_RESETVAL   (0x0000u)
/*----A17_MODE Tokens----*/
#define CSL_SYS_EBSR_A17_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A17_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A16_MODE_MASK       (0x0002u)
#define CSL_SYS_EBSR_A16_MODE_SHIFT      (0x0001u)
#define CSL_SYS_EBSR_A16_MODE_RESETVAL   (0x0000u)
/*----A16_MODE Tokens----*/
#define CSL_SYS_EBSR_A16_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A16_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A15_MODE_MASK       (0x0001u)
#define CSL_SYS_EBSR_A15_MODE_SHIFT      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_RESETVAL   (0x0000u)
/*----A15_MODE Tokens----*/
#define CSL_SYS_EBSR_A15_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_RESETVAL            (0x0000u)

/* PCGCR1 */

#define CSL_SYS_PCGCR1_SYSCLKDIS_MASK    (0x8000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_SHIFT   (0x000Fu)
#define CSL_SYS_PCGCR1_SYSCLKDIS_RESETVAL (0x0000u)
/*----SYSCLKDIS Tokens----*/
#define CSL_SYS_PCGCR1_SYSCLKDIS_ACTIVE  (0x0000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2S2CG_MASK       (0x4000u)
#define CSL_SYS_PCGCR1_I2S2CG_SHIFT      (0x000Eu)
#define CSL_SYS_PCGCR1_I2S2CG_RESETVAL   (0x0000u)
/*----I2S2CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR2CG_MASK       (0x2000u)
#define CSL_SYS_PCGCR1_TMR2CG_SHIFT      (0x000Du)
#define CSL_SYS_PCGCR1_TMR2CG_RESETVAL   (0x0000u)
/*----TMR2CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR1CG_MASK       (0x1000u)
#define CSL_SYS_PCGCR1_TMR1CG_SHIFT      (0x000Cu)
#define CSL_SYS_PCGCR1_TMR1CG_RESETVAL   (0x0000u)
/*----TMR1CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_EMIFCG_MASK       (0x0800u)
#define CSL_SYS_PCGCR1_EMIFCG_SHIFT      (0x000Bu)
#define CSL_SYS_PCGCR1_EMIFCG_RESETVAL   (0x0000u)
/*----EMIFCG Tokens----*/
#define CSL_SYS_PCGCR1_EMIFCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_EMIFCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR0CG_MASK       (0x0400u)
#define CSL_SYS_PCGCR1_TMR0CG_SHIFT      (0x000Au)
#define CSL_SYS_PCGCR1_TMR0CG_RESETVAL   (0x0000u)
/*----TMR0CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_I2S1CG_MASK       (0x0200u)
#define CSL_SYS_PCGCR1_I2S1CG_SHIFT      (0x0009u)
#define CSL_SYS_PCGCR1_I2S1CG_RESETVAL   (0x0000u)
/*----I2S1CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_I2S0CG_MASK       (0x0100u)
#define CSL_SYS_PCGCR1_I2S0CG_SHIFT      (0x0008u)
#define CSL_SYS_PCGCR1_I2S0CG_RESETVAL   (0x0000u)
/*----I2S0CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_MMCSD1CG_MASK     (0x0080u)
#define CSL_SYS_PCGCR1_MMCSD1CG_SHIFT    (0x0007u)
#define CSL_SYS_PCGCR1_MMCSD1CG_RESETVAL (0x0000u)
/*----MMCSD1CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD1CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD1CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2CCG_MASK        (0x0040u)
#define CSL_SYS_PCGCR1_I2CCG_SHIFT       (0x0006u)
#define CSL_SYS_PCGCR1_I2CCG_RESETVAL    (0x0000u)
/*----I2CCG Tokens----*/
#define CSL_SYS_PCGCR1_I2CCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_I2CCG_DISABLED    (0x0001u)


#define CSL_SYS_PCGCR1_MMCSD0CG_MASK     (0x0010u)
#define CSL_SYS_PCGCR1_MMCSD0CG_SHIFT    (0x0004u)
#define CSL_SYS_PCGCR1_MMCSD0CG_RESETVAL (0x0000u)
/*----MMCSD0CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD0CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD0CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_DMA0CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR1_DMA0CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR1_DMA0CG_RESETVAL   (0x0000u)
/*----DMA0CG Tokens----*/
#define CSL_SYS_PCGCR1_DMA0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_DMA0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_UARTCG_MASK       (0x0004u)
#define CSL_SYS_PCGCR1_UARTCG_SHIFT      (0x0002u)
#define CSL_SYS_PCGCR1_UARTCG_RESETVAL   (0x0000u)
/*----UARTCG Tokens----*/
#define CSL_SYS_PCGCR1_UARTCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_UARTCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_SPICG_MASK        (0x0002u)
#define CSL_SYS_PCGCR1_SPICG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR1_SPICG_RESETVAL    (0x0000u)
/*----SPICG Tokens----*/
#define CSL_SYS_PCGCR1_SPICG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_SPICG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR1_I2S3CG_MASK       (0x0001u)
#define CSL_SYS_PCGCR1_I2S3CG_SHIFT      (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_RESETVAL   (0x0000u)
/*----I2S3CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_RESETVAL          (0x0000u)

/* PCGCR2 */


#define CSL_SYS_PCGCR2_ANAREGCG_MASK     (0x0040u)
#define CSL_SYS_PCGCR2_ANAREGCG_SHIFT    (0x0006u)
#define CSL_SYS_PCGCR2_ANAREGCG_RESETVAL (0x0000u)
/*----ANAREGCG Tokens----*/
#define CSL_SYS_PCGCR2_ANAREGCG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR2_ANAREGCG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR2_DMA3CG_MASK       (0x0020u)
#define CSL_SYS_PCGCR2_DMA3CG_SHIFT      (0x0005u)
#define CSL_SYS_PCGCR2_DMA3CG_RESETVAL   (0x0000u)
/*----DMA3CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA2CG_MASK       (0x0010u)
#define CSL_SYS_PCGCR2_DMA2CG_SHIFT      (0x0004u)
#define CSL_SYS_PCGCR2_DMA2CG_RESETVAL   (0x0000u)
/*----DMA2CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA1CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR2_DMA1CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR2_DMA1CG_RESETVAL   (0x0000u)
/*----DMA1CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_USBCG_MASK        (0x0004u)
#define CSL_SYS_PCGCR2_USBCG_SHIFT       (0x0002u)
#define CSL_SYS_PCGCR2_USBCG_RESETVAL    (0x0000u)
/*----USBCG Tokens----*/
#define CSL_SYS_PCGCR2_USBCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_USBCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_SARCG_MASK        (0x0002u)
#define CSL_SYS_PCGCR2_SARCG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR2_SARCG_RESETVAL    (0x0000u)
/*----SARCG Tokens----*/
#define CSL_SYS_PCGCR2_SARCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_SARCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_LCDCG_MASK        (0x0001u)
#define CSL_SYS_PCGCR2_LCDCG_SHIFT       (0x0000u)
#define CSL_SYS_PCGCR2_LCDCG_RESETVAL    (0x0000u)
/*----LCDCG Tokens----*/
#define CSL_SYS_PCGCR2_LCDCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_LCDCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_RESETVAL          (0x0000u)

/* PSRCR */

#define CSL_SYS_PSRCR_COUNT_MASK         (0xFFFFu)
#define CSL_SYS_PSRCR_COUNT_SHIFT        (0x0000u)
#define CSL_SYS_PSRCR_COUNT_RESETVAL     (0x0000u)

#define CSL_SYS_PSRCR_RESETVAL           (0x0000u)

/* PRCR */


#define CSL_SYS_PRCR_PG4_RST_MASK        (0x0080u)
#define CSL_SYS_PRCR_PG4_RST_SHIFT       (0x0007u)
#define CSL_SYS_PRCR_PG4_RST_RESETVAL    (0x0000u)
/*----PG4_RST Tokens----*/
#define CSL_SYS_PRCR_PG4_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG4_RST_NRST        (0x0000u)


#define CSL_SYS_PRCR_PG3_RST_MASK        (0x0020u)
#define CSL_SYS_PRCR_PG3_RST_SHIFT       (0x0005u)
#define CSL_SYS_PRCR_PG3_RST_RESETVAL    (0x0000u)
/*----PG3_RST Tokens----*/
#define CSL_SYS_PRCR_PG3_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG3_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_DMA_RST_MASK        (0x0010u)
#define CSL_SYS_PRCR_DMA_RST_SHIFT       (0x0004u)
#define CSL_SYS_PRCR_DMA_RST_RESETVAL    (0x0000u)
/*----DMA_RST Tokens----*/
#define CSL_SYS_PRCR_DMA_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_DMA_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_USB_RST_MASK        (0x0008u)
#define CSL_SYS_PRCR_USB_RST_SHIFT       (0x0003u)
#define CSL_SYS_PRCR_USB_RST_RESETVAL    (0x0000u)
/*----USB_RST Tokens----*/
#define CSL_SYS_PRCR_USB_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_USB_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_SAR_RST_MASK        (0x0004u)
#define CSL_SYS_PRCR_SAR_RST_SHIFT       (0x0002u)
#define CSL_SYS_PRCR_SAR_RST_RESETVAL    (0x0000u)
/*----SAR_RST Tokens----*/
#define CSL_SYS_PRCR_SAR_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_SAR_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_PG1_RST_MASK        (0x0002u)
#define CSL_SYS_PRCR_PG1_RST_SHIFT       (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_RESETVAL    (0x0000u)
/*----PG1_RST Tokens----*/
#define CSL_SYS_PRCR_PG1_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_I2C_RST_MASK        (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_SHIFT       (0x0000u)
#define CSL_SYS_PRCR_I2C_RST_RESETVAL    (0x0000u)
/*----I2C_RST Tokens----*/
#define CSL_SYS_PRCR_I2C_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_RESETVAL            (0x0000u)

/* TIAFR */


#define CSL_SYS_TIAFR_TIM2FLAG_MASK      (0x0004u)
#define CSL_SYS_TIAFR_TIM2FLAG_SHIFT     (0x0002u)
#define CSL_SYS_TIAFR_TIM2FLAG_RESETVAL  (0x0000u)
/*----TIM2FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM2FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM2FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM1FLAG_MASK      (0x0002u)
#define CSL_SYS_TIAFR_TIM1FLAG_SHIFT     (0x0001u)
#define CSL_SYS_TIAFR_TIM1FLAG_RESETVAL  (0x0000u)
/*----TIM1FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM1FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM1FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM0FLAG_MASK      (0x0001u)
#define CSL_SYS_TIAFR_TIM0FLAG_SHIFT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_RESETVAL  (0x0000u)
/*----TIM0FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM0FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_RESETVAL           (0x0000u)

/* ODSCR */


#define CSL_SYS_ODSCR_CLKOUTDS_MASK      (0x0004u)
#define CSL_SYS_ODSCR_CLKOUTDS_SHIFT     (0x0002u)
#define CSL_SYS_ODSCR_CLKOUTDS_RESETVAL  (0x0001u)
/*----CLKOUTDS Tokens----*/
#define CSL_SYS_ODSCR_CLKOUTDS_MIN       (0x0000u)
#define CSL_SYS_ODSCR_CLKOUTDS_MAX       (0x0001u)


#define CSL_SYS_ODSCR_EMIFDS_MASK        (0x0001u)
#define CSL_SYS_ODSCR_EMIFDS_SHIFT       (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_RESETVAL    (0x0001u)
/*----EMIFDS Tokens----*/
#define CSL_SYS_ODSCR_EMIFDS_MIN         (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_MAX         (0x0001u)

#define CSL_SYS_ODSCR_RESETVAL           (0x0005u)

/* PDINHIBR1 */

#define CSL_SYS_PDINHIBR1_S15PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S15PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S15PD_RESETVAL (0x0001u)
/*----S15PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S14PD_MASK     (0x1000u)
#define CSL_SYS_PDINHIBR1_S14PD_SHIFT    (0x000Cu)
#define CSL_SYS_PDINHIBR1_S14PD_RESETVAL (0x0001u)
/*----S14PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S14PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S14PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S13PD_MASK     (0x0800u)
#define CSL_SYS_PDINHIBR1_S13PD_SHIFT    (0x000Bu)
#define CSL_SYS_PDINHIBR1_S13PD_RESETVAL (0x0001u)
/*----S13PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S13PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S13PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S12PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR1_S12PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR1_S12PD_RESETVAL (0x0001u)
/*----S12PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S12PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S12PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S11PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR1_S11PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR1_S11PD_RESETVAL (0x0001u)
/*----S11PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S11PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S11PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S10PD_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR1_S10PD_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR1_S10PD_RESETVAL (0x0001u)
/*----S10PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S10PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S10PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S5PD_MASK      (0x0020u)
#define CSL_SYS_PDINHIBR1_S5PD_SHIFT     (0x0005u)
#define CSL_SYS_PDINHIBR1_S5PD_RESETVAL  (0x0001u)
/*----S5PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S5PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S5PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S4PD_MASK      (0x0010u)
#define CSL_SYS_PDINHIBR1_S4PD_SHIFT     (0x0004u)
#define CSL_SYS_PDINHIBR1_S4PD_RESETVAL  (0x0001u)
/*----S4PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S4PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S4PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S3PD_MASK      (0x0008u)
#define CSL_SYS_PDINHIBR1_S3PD_SHIFT     (0x0003u)
#define CSL_SYS_PDINHIBR1_S3PD_RESETVAL  (0x0001u)
/*----S3PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S3PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S3PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S2PD_MASK      (0x0004u)
#define CSL_SYS_PDINHIBR1_S2PD_SHIFT     (0x0002u)
#define CSL_SYS_PDINHIBR1_S2PD_RESETVAL  (0x0001u)
/*----S2PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S2PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S2PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S1PD_MASK      (0x0002u)
#define CSL_SYS_PDINHIBR1_S1PD_SHIFT     (0x0001u)
#define CSL_SYS_PDINHIBR1_S1PD_RESETVAL  (0x0001u)
/*----S1PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S1PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S1PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S0PD_MASK      (0x0001u)
#define CSL_SYS_PDINHIBR1_S0PD_SHIFT     (0x0000u)
#define CSL_SYS_PDINHIBR1_S0PD_RESETVAL  (0x0001u)
/*----S0PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S0PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S0PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_RESETVAL       (0x3F3Fu)


/* PDINHIBR2 */


#define CSL_SYS_PDINHIBR2_INT1PU_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR2_INT1PU_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR2_INT1PU_RESETVAL (0x0001u)
/*----INT1PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT1PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT1PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_INT0PU_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR2_INT0PU_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR2_INT0PU_RESETVAL (0x0001u)
/*----INT0PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT0PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT0PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETPU_MASK   (0x1000u)
#define CSL_SYS_PDINHIBR2_RESETPU_SHIFT  (0x000Cu)
#define CSL_SYS_PDINHIBR2_RESETPU_RESETVAL (0x0000u)
/*----RESETPU Tokens----*/
#define CSL_SYS_PDINHIBR2_RESETPU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_RESETPU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_EMU01PU_MASK   (0x0800u)
#define CSL_SYS_PDINHIBR2_EMU01PU_SHIFT  (0x000Bu)
#define CSL_SYS_PDINHIBR2_EMU01PU_RESETVAL (0x0000u)
/*----EMU01PU Tokens----*/
#define CSL_SYS_PDINHIBR2_EMU01PU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_EMU01PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_TDIPU_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR2_TDIPU_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR2_TDIPU_RESETVAL (0x0000u)
/*----TDIPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TDIPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TDIPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TMSPU_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR2_TMSPU_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR2_TMSPU_RESETVAL (0x0000u)
/*----TMSPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TMSPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TMSPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TCKPU_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR2_TCKPU_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR2_TCKPU_RESETVAL (0x0000u)
/*----TCKPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TCKPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TCKPU_DISABLE  (0x0001u)


#define CSL_SYS_PDINHIBR2_A20PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR2_A20PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR2_A20PD_RESETVAL (0x0001u)
/*----A20PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A20PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A20PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A19PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR2_A19PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR2_A19PD_RESETVAL (0x0001u)
/*----A19PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A19PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A19PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A18PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR2_A18PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR2_A18PD_RESETVAL (0x0001u)
/*----A18PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A18PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A18PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A17PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR2_A17PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR2_A17PD_RESETVAL (0x0001u)
/*----A17PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A17PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A17PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A16PD_MASK     (0x0002u)
#define CSL_SYS_PDINHIBR2_A16PD_SHIFT    (0x0001u)
#define CSL_SYS_PDINHIBR2_A16PD_RESETVAL (0x0001u)
/*----A16PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A16PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A16PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A15PD_MASK     (0x0001u)
#define CSL_SYS_PDINHIBR2_A15PD_SHIFT    (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_RESETVAL (0x0001u)
/*----A15PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETVAL       (0x603Fu)

/* PDINHIBR3 */

#define CSL_SYS_PDINHIBR3_PD15PD_MASK    (0x8000u)
#define CSL_SYS_PDINHIBR3_PD15PD_SHIFT   (0x000Fu)
#define CSL_SYS_PDINHIBR3_PD15PD_RESETVAL (0x0001u)
/*----PD15PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD15PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD15PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD14PD_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR3_PD14PD_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR3_PD14PD_RESETVAL (0x0001u)
/*----PD14PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD14PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD14PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD13PD_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR3_PD13PD_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR3_PD13PD_RESETVAL (0x0001u)
/*----PD13PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD13PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD13PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD12PD_MASK    (0x1000u)
#define CSL_SYS_PDINHIBR3_PD12PD_SHIFT   (0x000Cu)
#define CSL_SYS_PDINHIBR3_PD12PD_RESETVAL (0x0001u)
/*----PD12PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD12PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD12PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD11PD_MASK    (0x0800u)
#define CSL_SYS_PDINHIBR3_PD11PD_SHIFT   (0x000Bu)
#define CSL_SYS_PDINHIBR3_PD11PD_RESETVAL (0x0001u)
/*----PD11PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD11PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD11PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD10PD_MASK    (0x0400u)
#define CSL_SYS_PDINHIBR3_PD10PD_SHIFT   (0x000Au)
#define CSL_SYS_PDINHIBR3_PD10PD_RESETVAL (0x0001u)
/*----PD10PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD10PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD10PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD9PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR3_PD9PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR3_PD9PD_RESETVAL (0x0001u)
/*----PD9PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD9PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD9PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD8PD_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR3_PD8PD_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR3_PD8PD_RESETVAL (0x0001u)
/*----PD8PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD8PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD8PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD7PD_MASK     (0x0080u)
#define CSL_SYS_PDINHIBR3_PD7PD_SHIFT    (0x0007u)
#define CSL_SYS_PDINHIBR3_PD7PD_RESETVAL (0x0001u)
/*----PD7PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD7PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD7PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD6PD_MASK     (0x0040u)
#define CSL_SYS_PDINHIBR3_PD6PD_SHIFT    (0x0006u)
#define CSL_SYS_PDINHIBR3_PD6PD_RESETVAL (0x0001u)
/*----PD6PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD6PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD6PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD5PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR3_PD5PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR3_PD5PD_RESETVAL (0x0001u)
/*----PD5PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD5PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD5PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD4PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR3_PD4PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR3_PD4PD_RESETVAL (0x0001u)
/*----PD4PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD4PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD4PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD3PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR3_PD3PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR3_PD3PD_RESETVAL (0x0001u)
/*----PD3PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD3PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD3PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD2PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR3_PD2PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR3_PD2PD_RESETVAL (0x0001u)
/*----PD2PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD2PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD2PD_DISABLE  (0x0001u)


#define CSL_SYS_PDINHIBR3_RESETVAL       (0x603Du)

/* DMA0CESR1 */


#define CSL_SYS_DMA0CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA0CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA0CESR1_RESETVAL       (0x0000u)

/* DMA0CESR2 */


#define CSL_SYS_DMA0CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA0CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA0CESR2_RESETVAL       (0x0000u)

/* DMA1CESR1 */


#define CSL_SYS_DMA1CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA1CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA1CESR1_RESETVAL       (0x0000u)

/* DMA1CESR2 */


#define CSL_SYS_DMA1CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA1CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA1CESR2_RESETVAL       (0x0000u)

/* CCR1 */


#define CSL_SYS_CCR1_SDCLK_EN_MASK   (0x0001u)
#define CSL_SYS_CCR1_SDCLK_EN_SHIFT  (0x0000u)
#define CSL_SYS_CCR1_SDCLK_EN_RESETVAL (0x0001u)
/*----SDCLK_EN Tokens----*/
#define CSL_SYS_CCR1_SDCLK_EN_SDCLKON (0x0001u)
#define CSL_SYS_CCR1_SDCLK_EN_SDCLKOFF (0x0000u)

#define CSL_SYS_CCR1_RESETVAL        (0x0001u)

/* CCR2 */


#define CSL_SYS_CCR2_SYSCLKSRC_MASK      (0x0030u)
#define CSL_SYS_CCR2_SYSCLKSRC_SHIFT     (0x0004u)
#define CSL_SYS_CCR2_SYSCLKSRC_RESETVAL  (0x0000u)
/*----SYSCLKSRC Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSRC_BYPRTC    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKRTC   (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSRC_BYPCLKIN  (0x0002u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKCLKIN (0x0004u)

#define CSL_SYS_CCR2_CLKSELSTAT_MASK     (0x0004u)
#define CSL_SYS_CCR2_CLKSELSTAT_SHIFT    (0x0002u)
#define CSL_SYS_CCR2_CLKSELSTAT_RESETVAL (0x0000u)
/*----CLKSELSTAT Tokens----*/
#define CSL_SYS_CCR2_CLKSELSTAT_RTCIN    (0x0000u)
#define CSL_SYS_CCR2_CLKSELSTAT_CLKIN    (0x0001u)

#define CSL_SYS_CCR2_SYSCLKSEL_MASK      (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSEL_SHIFT     (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_RESETVAL  (0x0000u)
/*----SYSCLKSEL Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSEL_BYPASS    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_LOCK      (0x0001u)

#define CSL_SYS_CCR2_RESETVAL            (0x0000u)

/* CGCR1 */

#define CSL_SYS_CGCR1_RSVD_MASK      (0x8000u)
#define CSL_SYS_CGCR1_RSVD_SHIFT     (0x000Fu)
#define CSL_SYS_CGCR1_RSVD_RESETVAL  (0x0000u)
/*----CLR_CNTL Tokens----*/
#define CSL_SYS_CGCR1_RSVD_CLEAR     (0x0000u)
#define CSL_SYS_CGCR1_RSVD_SET       (0x0001u)

#define CSL_SYS_CGCR1_PLL_PWRDN_MASK     (0x1000u)
#define CSL_SYS_CGCR1_PLL_PWRDN_SHIFT    (0x000Cu)
#define CSL_SYS_CGCR1_PLL_PWRDN_RESETVAL (0x0001u)
/*----PLL_PWRDN Tokens----*/
#define CSL_SYS_CGCR1_PLL_PWRDN_POWERED  (0x0000u)
#define CSL_SYS_CGCR1_PLL_PWRDN_POWERDWN (0x0001u)

#define CSL_SYS_CGCR1_M_MASK            (0x0FFFu)
#define CSL_SYS_CGCR1_M_SHIFT           (0x0000u)
#define CSL_SYS_CGCR1_M_RESETVAL        (0x0000u)

#define CSL_SYS_CGCR1_RESETVAL           (0x1000u)


/* CGCR2 */

#define CSL_SYS_CGCR2_RDBYPASS_MASK      (0x8000u)
#define CSL_SYS_CGCR2_RDBYPASS_SHIFT     (0x000Fu)
#define CSL_SYS_CGCR2_RDBYPASS_RESETVAL  (0x0000u)
/*----RDBYPASS Tokens----*/
#define CSL_SYS_CGCR2_RDBYPASS_ENABLE    (0x0000u)
#define CSL_SYS_CGCR2_RDBYPASS_BYPASS    (0x0001u)

#define CSL_SYS_CGCR2_RDRATIO_MASK       (0x0FFFu)
#define CSL_SYS_CGCR2_RDRATIO_SHIFT      (0x0000u)
#define CSL_SYS_CGCR2_RDRATIO_RESETVAL   (0x0000u)

#define CSL_SYS_CGCR2_RESETVAL           (0x0000u)


/* CGCR3 */

#define CSL_SYS_CGCR3_INIT_MASK          (0xFFFFu)
#define CSL_SYS_CGCR3_INIT_SHIFT         (0x0000u)
#define CSL_SYS_CGCR3_INIT_RESETVAL      (0x0806u)

#define CSL_SYS_CGCR3_RESETVAL           (0x0806u)

/* CGCR4 */

#define CSL_SYS_CGCR4_OUTDIVEN_MASK      (0x0200u)
#define CSL_SYS_CGCR4_OUTDIVEN_SHIFT     (0x0009u)
#define CSL_SYS_CGCR4_OUTDIVEN_RESETVAL  (0x0000u)
/*----OUTDIVEN Tokens----*/
#define CSL_SYS_CGCR4_OUTDIVEN_BYPASS    (0x0000u)
#define CSL_SYS_CGCR4_OUTDIVEN_ENABLE    (0x0001u)


#define CSL_SYS_CGCR4_ODRATIO_MASK       (0x00FFu)
#define CSL_SYS_CGCR4_ODRATIO_SHIFT      (0x0000u)
#define CSL_SYS_CGCR4_ODRATIO_RESETVAL   (0x0000u)

#define CSL_SYS_CGCR4_RESETVAL           (0x0000u)

#if (defined(CHIP_C5517))
/* CLKOUTCR */

#define CSL_SYS_CLKOUTCR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CLKOUTCR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CLKOUTCR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CLKOUTCR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CLKOUTCR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CLKOUTCR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CLKOUTCR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CLKOUTCR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CLKOUTCR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CLKOUTCR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CLKOUTCR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CLKOUTCR_SRC_MODE10         (0x000au)
#define CSL_SYS_CLKOUTCR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CLKOUTCR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CLKOUTCR_SRC_MODE13         (0x000du)
#define CSL_SYS_CLKOUTCR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CLKOUTCR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CLKOUTCR_RESETVAL           (0x000Bu)

#else
/* CCSSR */


#define CSL_SYS_CCSSR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CCSSR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CCSSR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CCSSR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CCSSR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CCSSR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CCSSR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CCSSR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CCSSR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CCSSR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CCSSR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CCSSR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CCSSR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CCSSR_SRC_MODE10         (0x000au)
#define CSL_SYS_CCSSR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CCSSR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CCSSR_SRC_MODE13         (0x000du)
#define CSL_SYS_CCSSR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CCSSR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CCSSR_RESETVAL           (0x000Bu)
#endif

/* ECDR */


#define CSL_SYS_ECDR_EDIV_MASK           (0x0001u)
#define CSL_SYS_ECDR_EDIV_SHIFT          (0x0000u)
#define CSL_SYS_ECDR_EDIV_RESETVAL       (0x0001u)
/*----EDIV Tokens----*/
#define CSL_SYS_ECDR_EDIV_HALFRATE       (0x0000u)
#define CSL_SYS_ECDR_EDIV_FULLRATE       (0x0001u)

#define CSL_SYS_ECDR_RESETVAL            (0x0001u)


/* RAMSLPMDCNTLR1 */

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_RESETVAL (0x0001u)
/*----DARAM7SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_RESETVAL (0x0001u)
/*----DARAM7SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_RESETVAL (0x0001u)
/*----DARAM6SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_RESETVAL (0x0001u)
/*----DARAM6SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_RESETVAL (0x0001u)
/*----DARAM5SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_RESETVAL (0x0001u)
/*----DARAM5SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_RESETVAL (0x0001u)
/*----DARAM4SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_RESETVAL (0x0001u)
/*----DARAM4SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_RESETVAL (0x0001u)
/*----DARAM3SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_RESETVAL (0x0001u)
/*----DARAM3SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_RESETVAL (0x0001u)
/*----DARAM2SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_RESETVAL (0x0001u)
/*----DARAM2SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_RESETVAL (0x0001u)
/*----DARAM1SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_RESETVAL (0x0001u)
/*----DARAM1SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_RESETVAL (0x0001u)
/*----DARAM0SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_RESETVAL (0x0001u)
/*----DARAM0SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR2 */

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_RESETVAL (0x0001u)
/*----SARAM7SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_RESETVAL (0x0001u)
/*----SARAM7SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_RESETVAL (0x0001u)
/*----SARAM6SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_RESETVAL (0x0001u)
/*----SARAM6SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_RESETVAL (0x0001u)
/*----SARAM5SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_RESETVAL (0x0001u)
/*----SARAM5SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_RESETVAL (0x0001u)
/*----SARAM4SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_RESETVAL (0x0001u)
/*----SARAM4SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_RESETVAL (0x0001u)
/*----SARAM3SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_RESETVAL (0x0001u)
/*----SARAM3SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_RESETVAL (0x0001u)
/*----SARAM2SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_RESETVAL (0x0001u)
/*----SARAM2SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_RESETVAL (0x0001u)
/*----SARAM1SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_RESETVAL (0x0001u)
/*----SARAM1SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_RESETVAL (0x0001u)
/*----SARAM0SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_RESETVAL (0x0001u)
/*----SARAM0SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR3 */

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_RESETVAL (0x0001u)
/*----SARAM15SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_RESETVAL (0x0001u)
/*----SARAM15SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_RESETVAL (0x0001u)
/*----SARAM14SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_RESETVAL (0x0001u)
/*----SARAM14SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_RESETVAL (0x0001u)
/*----SARAM13SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_RESETVAL (0x0001u)
/*----SARAM13SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_RESETVAL (0x0001u)
/*----SARAM12SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_RESETVAL (0x0001u)
/*----SARAM12SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_RESETVAL (0x0001u)
/*----SARAM11SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_RESETVAL (0x0001u)
/*----SARAM11SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_RESETVAL (0x0001u)
/*----SARAM10SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_RESETVAL (0x0001u)
/*----SARAM10SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_RESETVAL (0x0001u)
/*----SARAM9SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_RESETVAL (0x0001u)
/*----SARAM9SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_RESETVAL (0x0001u)
/*----SARAM8SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_RESETVAL (0x0001u)
/*----SARAM8SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR4 */

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_RESETVAL (0x0001u)
/*----SARAM23SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_RESETVAL (0x0001u)
/*----SARAM23SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_RESETVAL (0x0001u)
/*----SARAM22SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_RESETVAL (0x0001u)
/*----SARAM22SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_RESETVAL (0x0001u)
/*----SARAM21SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_RESETVAL (0x0001u)
/*----SARAM21SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_RESETVAL (0x0001u)
/*----SARAM20SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_RESETVAL (0x0001u)
/*----SARAM20SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_RESETVAL (0x0001u)
/*----SARAM19SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_RESETVAL (0x0001u)
/*----SARAM19SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_RESETVAL (0x0001u)
/*----SARAM18SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_RESETVAL (0x0001u)
/*----SARAM18SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_RESETVAL (0x0001u)
/*----SARAM17SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_RESETVAL (0x0001u)
/*----SARAM17SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_RESETVAL (0x0001u)
/*----SARAM16SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_RESETVAL (0x0001u)
/*----SARAM16SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR5 */

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_RESETVAL (0x0001u)
/*----SARAM31SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_RESETVAL (0x0001u)
/*----SARAM31SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_RESETVAL (0x0001u)
/*----SARAM30SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_RESETVAL (0x0001u)
/*----SARAM30SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_RESETVAL (0x0001u)
/*----SARAM29SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_RESETVAL (0x0001u)
/*----SARAM29SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_RESETVAL (0x0001u)
/*----SARAM28SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_RESETVAL (0x0001u)
/*----SARAM28SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_RESETVAL (0x0001u)
/*----SARAM27SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_RESETVAL (0x0001u)
/*----SARAM27SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_RESETVAL (0x0001u)
/*----SARAM26SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_RESETVAL (0x0001u)
/*----SARAM26SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_RESETVAL (0x0001u)
/*----SARAM25SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_RESETVAL (0x0001u)
/*----SARAM25SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_RESETVAL (0x0001u)
/*----SARAM24SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_RESETVAL (0x0001u)
/*----SARAM24SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_RESETVAL  (0xFFFFu)

/* DMAIFR */

#define CSL_SYS_DMAIFR_DMA3CH3IF_MASK    (0x8000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIFR_DMA3CH3IF_RESETVAL (0x0000u)
/*----DMA3CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH2IF_MASK    (0x4000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIFR_DMA3CH2IF_RESETVAL (0x0000u)
/*----DMA3CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH1IF_MASK    (0x2000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SHIFT   (0x000Du)
#define CSL_SYS_DMAIFR_DMA3CH1IF_RESETVAL (0x0000u)
/*----DMA3CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH0IF_MASK    (0x1000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIFR_DMA3CH0IF_RESETVAL (0x0000u)
/*----DMA3CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH3IF_MASK    (0x0800u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIFR_DMA2CH3IF_RESETVAL (0x0000u)
/*----DMA2CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH2IF_MASK    (0x0400u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SHIFT   (0x000Au)
#define CSL_SYS_DMAIFR_DMA2CH2IF_RESETVAL (0x0000u)
/*----DMA2CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH1IF_MASK    (0x0200u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SHIFT   (0x0009u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_RESETVAL (0x0000u)
/*----DMA2CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH0IF_MASK    (0x0100u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SHIFT   (0x0008u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_RESETVAL (0x0000u)
/*----DMA2CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH3IF_MASK    (0x0080u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SHIFT   (0x0007u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_RESETVAL (0x0000u)
/*----DMA1CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH2IF_MASK    (0x0040u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SHIFT   (0x0006u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_RESETVAL (0x0000u)
/*----DMA1CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH1IF_MASK    (0x0020u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SHIFT   (0x0005u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_RESETVAL (0x0000u)
/*----DMA1CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH0IF_MASK    (0x0010u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SHIFT   (0x0004u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_RESETVAL (0x0000u)
/*----DMA1CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH3IF_MASK    (0x0008u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SHIFT   (0x0003u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_RESETVAL (0x0000u)
/*----DMA0CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH2IF_MASK    (0x0004u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SHIFT   (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_RESETVAL (0x0000u)
/*----DMA0CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH1IF_MASK    (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SHIFT   (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_RESETVAL (0x0000u)
/*----DMA0CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH0IF_MASK    (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SHIFT   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_RESETVAL (0x0000u)
/*----DMA0CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_RESETVAL          (0x0000u)

/* DMAIER */

#define CSL_SYS_DMAIER_DMA3CH3IE_MASK    (0x8000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIER_DMA3CH3IE_RESETVAL (0x0000u)
/*----DMA3CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH2IE_MASK    (0x4000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIER_DMA3CH2IE_RESETVAL (0x0000u)
/*----DMA3CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH1IE_MASK    (0x2000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_SHIFT   (0x000Du)
#define CSL_SYS_DMAIER_DMA3CH1IE_RESETVAL (0x0000u)
/*----DMA3CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH0IE_MASK    (0x1000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIER_DMA3CH0IE_RESETVAL (0x0000u)
/*----DMA3CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH3IE_MASK    (0x0800u)
#define CSL_SYS_DMAIER_DMA2CH3IE_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIER_DMA2CH3IE_RESETVAL (0x0000u)
/*----DMA2CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH2IE_MASK    (0x0400u)
#define CSL_SYS_DMAIER_DMA2CH2IE_SHIFT   (0x000Au)
#define CSL_SYS_DMAIER_DMA2CH2IE_RESETVAL (0x0000u)
/*----DMA2CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH1IE_MASK    (0x0200u)
#define CSL_SYS_DMAIER_DMA2CH1IE_SHIFT   (0x0009u)
#define CSL_SYS_DMAIER_DMA2CH1IE_RESETVAL (0x0000u)
/*----DMA2CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH0IE_MASK    (0x0100u)
#define CSL_SYS_DMAIER_DMA2CH0IE_SHIFT   (0x0008u)
#define CSL_SYS_DMAIER_DMA2CH0IE_RESETVAL (0x0000u)
/*----DMA2CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH3IE_MASK    (0x0080u)
#define CSL_SYS_DMAIER_DMA1CH3IE_SHIFT   (0x0007u)
#define CSL_SYS_DMAIER_DMA1CH3IE_RESETVAL (0x0000u)
/*----DMA1CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH2IE_MASK    (0x0040u)
#define CSL_SYS_DMAIER_DMA1CH2IE_SHIFT   (0x0006u)
#define CSL_SYS_DMAIER_DMA1CH2IE_RESETVAL (0x0000u)
/*----DMA1CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH1IE_MASK    (0x0020u)
#define CSL_SYS_DMAIER_DMA1CH1IE_SHIFT   (0x0005u)
#define CSL_SYS_DMAIER_DMA1CH1IE_RESETVAL (0x0000u)
/*----DMA1CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH0IE_MASK    (0x0010u)
#define CSL_SYS_DMAIER_DMA1CH0IE_SHIFT   (0x0004u)
#define CSL_SYS_DMAIER_DMA1CH0IE_RESETVAL (0x0000u)
/*----DMA1CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH3IE_MASK    (0x0008u)
#define CSL_SYS_DMAIER_DMA0CH3IE_SHIFT   (0x0003u)
#define CSL_SYS_DMAIER_DMA0CH3IE_RESETVAL (0x0000u)
/*----DMA0CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH2IE_MASK    (0x0004u)
#define CSL_SYS_DMAIER_DMA0CH2IE_SHIFT   (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH2IE_RESETVAL (0x0000u)
/*----DMA0CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH1IE_MASK    (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH1IE_SHIFT   (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH1IE_RESETVAL (0x0000u)
/*----DMA0CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH0IE_MASK    (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH0IE_SHIFT   (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_RESETVAL (0x0000u)
/*----DMA0CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_RESETVAL          (0x0000u)

/* USBSCR */

#define CSL_SYS_USBSCR_USBPWDN_MASK      (0x8000u)
#define CSL_SYS_USBSCR_USBPWDN_SHIFT     (0x000Fu)
#define CSL_SYS_USBSCR_USBPWDN_RESETVAL  (0x0001u)
/*----USBPWDN Tokens----*/
#define CSL_SYS_USBSCR_USBPWDN_POWERED   (0x0000u)
#define CSL_SYS_USBSCR_USBPWDN_PWRDN     (0x0001u)

#define CSL_SYS_USBSCR_USBSESSEND_MASK   (0x4000u)
#define CSL_SYS_USBSCR_USBSESSEND_SHIFT  (0x000Eu)
#define CSL_SYS_USBSCR_USBSESSEND_RESETVAL (0x0000u)
/*----USBSESSEND Tokens----*/
#define CSL_SYS_USBSCR_USBSESSEND_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBSESSEND_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBVBUSDET_MASK   (0x2000u)
#define CSL_SYS_USBSCR_USBVBUSDET_SHIFT  (0x000Du)
#define CSL_SYS_USBSCR_USBVBUSDET_RESETVAL (0x0001u)
/*----USBVBUSDET Tokens----*/
#define CSL_SYS_USBSCR_USBVBUSDET_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBVBUSDET_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBPLLEN_MASK     (0x1000u)
#define CSL_SYS_USBSCR_USBPLLEN_SHIFT    (0x000Cu)
#define CSL_SYS_USBSCR_USBPLLEN_RESETVAL (0x0000u)
/*----USBPLLEN Tokens----*/
#define CSL_SYS_USBSCR_USBPLLEN_NORMAL   (0x0000u)
#define CSL_SYS_USBSCR_USBPLLEN_FORCEON  (0x0001u)


#define CSL_SYS_USBSCR_USBDATPOL_MASK    (0x0040u)
#define CSL_SYS_USBSCR_USBDATPOL_SHIFT   (0x0006u)
#define CSL_SYS_USBSCR_USBDATPOL_RESETVAL (0x0001u)
/*----USBDATPOL Tokens----*/
#define CSL_SYS_USBSCR_USBDATPOL_REVERSE (0x0000u)
#define CSL_SYS_USBSCR_USBDATPOL_NORMAL  (0x0001u)


#define CSL_SYS_USBSCR_USBOSCBIASDIS_MASK (0x0008u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_SHIFT (0x0003u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_RESETVAL (0x0001u)
/*----USBOSCBIASDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCBIASDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_USBOSCDIS_MASK    (0x0004u)
#define CSL_SYS_USBSCR_USBOSCDIS_SHIFT   (0x0002u)
#define CSL_SYS_USBSCR_USBOSCDIS_RESETVAL (0x0001u)
/*----USBOSCDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_BYTEMODE_MASK     (0x0003u)
#define CSL_SYS_USBSCR_BYTEMODE_SHIFT    (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_RESETVAL (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_USBSCR_BYTEMODE_FULL     (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_UPPER    (0x0001u)
#define CSL_SYS_USBSCR_BYTEMODE_LOWER    (0x0002u)
#define CSL_SYS_USBSCR_BYTEMODE_RSV      (0x0003u)

#define CSL_SYS_USBSCR_RESETVAL          (0xA04Cu)

/* ESCR */


#define CSL_SYS_ESCR_BYTEMODE_MASK       (0x0003u)
#define CSL_SYS_ESCR_BYTEMODE_SHIFT      (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_RESETVAL   (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_ESCR_BYTEMODE_FULL       (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_UPPER      (0x0001u)
#define CSL_SYS_ESCR_BYTEMODE_LOWER      (0x0002u)
#define CSL_SYS_ESCR_BYTEMODE_RSV        (0x0003u)

#define CSL_SYS_ESCR_RESETVAL            (0x0000u)

/* DMA2CESR1 */


#define CSL_SYS_DMA2CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA2CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA2CESR1_RESETVAL       (0x0000u)

/* DMA2CESR2 */


#define CSL_SYS_DMA2CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA2CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA2CESR2_RESETVAL       (0x0000u)

/* DMA3CESR1 */


#define CSL_SYS_DMA3CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA3CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA3CESR1_RESETVAL       (0x0000u)

/* DMA3CESR2 */


#define CSL_SYS_DMA3CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA3CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA3CESR2_RESETVAL       (0x0000u)

/* CLKSTOP */


#define CSL_SYS_CLKSTOP_URTCLKSTPACK_MASK (0x0020u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_SHIFT (0x0005u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_RESETVAL (0x0001u)
/*----URTCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_MASK (0x0010u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_SHIFT (0x0004u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_RESETVAL (0x0001u)
/*----URTCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_USBCLKSTPACK_MASK (0x0008u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_SHIFT (0x0003u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_RESETVAL (0x0001u)
/*----USBCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_MASK (0x0004u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_SHIFT (0x0002u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_RESETVAL (0x0001u)
/*----USBCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_MASK (0x0002u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_SHIFT (0x0001u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_RESETVAL (0x0001u)
/*----EMFCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_MASK (0x0001u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_SHIFT (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_RESETVAL (0x0001u)
/*----EMFCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_RESETVAL         (0x003Fu)

/* DIEIDR0 */

#define CSL_SYS_DIEIDR0_DIEID0_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR0_DIEID0_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR0_DIEID0_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR0_RESETVAL         (0x0000u)

/* DIEIDR1 */


#define CSL_SYS_DIEIDR1_DIEID1_MASK      (0x3FFFu)
#define CSL_SYS_DIEIDR1_DIEID1_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR1_DIEID1_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR1_RESETVAL         (0x0000u)

/* DIEIDR2 */

#define CSL_SYS_DIEIDR2_DIEID2_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR2_DIEID2_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR2_DIEID2_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR2_RESETVAL         (0x0000u)

/* DIEIDR3 */

#define CSL_SYS_DIEIDR3_DIEID3_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR3_DIEID3_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR3_DIEID3_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR3_RESETVAL         (0x0000u)

/* DIEIDR4 */

#define CSL_SYS_DIEIDR4_DIEID4_MASK      (0x0030u)
#define CSL_SYS_DIEIDR4_DIEID4_SHIFT     (0x0004u)
#define CSL_SYS_DIEIDR4_DIEID4_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR4_DESIGNREV_MASK   (0x000Fu)
#define CSL_SYS_DIEIDR4_DESIGNREV_SHIFT  (0x0000u)
#define CSL_SYS_DIEIDR4_DESIGNREV_RESETVAL (0x0000u)

#define CSL_SYS_DIEIDR4_RESETVAL         (0x0000u)

/* DIEIDR5 */


#define CSL_SYS_DIEIDR5_RESETVAL         (0x0000u)

/* DIEIDR6 */


#define CSL_SYS_DIEIDR6_RESETVAL         (0x0000u)

/* DIEIDR7 */


#define CSL_SYS_DIEIDR7_CHECKSUM_MASK    (0x7FFEu)
#define CSL_SYS_DIEIDR7_CHECKSUM_SHIFT   (0x0001u)
#define CSL_SYS_DIEIDR7_CHECKSUM_RESETVAL (0x0000u)


#define CSL_SYS_DIEIDR7_RESETVAL         (0x0000u)

/**************************************************************************\
* Field Definition Macros - C5517
\**************************************************************************/

#elif (defined(CHIP_C5517))

/* EBSR */

#define CSL_SYS_EBSR_CLKS_MODE_MASK      (0x8000u)
#define CSL_SYS_EBSR_CLKS_MODE_SHIFT     (0x000Fu)
#define CSL_SYS_EBSR_CLKS_MODE_RESETVAL  (0x0000u)
/*----CLKS_MODE Tokens----*/
#define CSL_SYS_EBSR_CLKS_MODE_ZERO      (0x0000u)
#define CSL_SYS_EBSR_CLKS_MODE_ONE       (0x0001u)

#define CSL_SYS_EBSR_PPMODE_MASK         (0x7000u)
#define CSL_SYS_EBSR_PPMODE_SHIFT        (0x000Cu)
#define CSL_SYS_EBSR_PPMODE_RESETVAL     (0x0000u)
/*----PPMODE Tokens----*/
#define CSL_SYS_EBSR_PPMODE_MODE0        (0x0000u)
#define CSL_SYS_EBSR_PPMODE_MODE1        (0x0001u)
#define CSL_SYS_EBSR_PPMODE_MODE2        (0x0002u)
#define CSL_SYS_EBSR_PPMODE_MODE3        (0x0003u)
#define CSL_SYS_EBSR_PPMODE_MODE4        (0x0004u)
#define CSL_SYS_EBSR_PPMODE_MODE5        (0x0005u)
#define CSL_SYS_EBSR_PPMODE_MODE6        (0x0006u)
#define CSL_SYS_EBSR_PPMODE_MODE7        (0x0007u)

#define CSL_SYS_EBSR_SP1MODE_MASK        (0x0C00u)
#define CSL_SYS_EBSR_SP1MODE_SHIFT       (0x000Au)
#define CSL_SYS_EBSR_SP1MODE_RESETVAL    (0x0000u)
/*----SP1MODE Tokens----*/
#define CSL_SYS_EBSR_SP1MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP1MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP1MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP1MODE_MODE3       (0x0003u)

#define CSL_SYS_EBSR_SP0MODE_MASK        (0x0300u)
#define CSL_SYS_EBSR_SP0MODE_SHIFT       (0x0008u)
#define CSL_SYS_EBSR_SP0MODE_RESETVAL    (0x0000u)
/*----SP0MODE Tokens----*/
#define CSL_SYS_EBSR_SP0MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP0MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP0MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP0MODE_MODE3       (0x0003u)


#define CSL_SYS_EBSR_A20_MODE_MASK       (0x0020u)
#define CSL_SYS_EBSR_A20_MODE_SHIFT      (0x0005u)
#define CSL_SYS_EBSR_A20_MODE_RESETVAL   (0x0001u)
/*----A20_MODE Tokens----*/
#define CSL_SYS_EBSR_A20_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A20_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A19_MODE_MASK       (0x0010u)
#define CSL_SYS_EBSR_A19_MODE_SHIFT      (0x0004u)
#define CSL_SYS_EBSR_A19_MODE_RESETVAL   (0x0001u)
/*----A19_MODE Tokens----*/
#define CSL_SYS_EBSR_A19_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A19_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A18_MODE_MASK       (0x0008u)
#define CSL_SYS_EBSR_A18_MODE_SHIFT      (0x0003u)
#define CSL_SYS_EBSR_A18_MODE_RESETVAL   (0x0001u)
/*----A18_MODE Tokens----*/
#define CSL_SYS_EBSR_A18_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A18_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A17_MODE_MASK       (0x0004u)
#define CSL_SYS_EBSR_A17_MODE_SHIFT      (0x0002u)
#define CSL_SYS_EBSR_A17_MODE_RESETVAL   (0x0001u)
/*----A17_MODE Tokens----*/
#define CSL_SYS_EBSR_A17_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A17_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A16_MODE_MASK       (0x0002u)
#define CSL_SYS_EBSR_A16_MODE_SHIFT      (0x0001u)
#define CSL_SYS_EBSR_A16_MODE_RESETVAL   (0x0001u)
/*----A16_MODE Tokens----*/
#define CSL_SYS_EBSR_A16_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A16_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A15_MODE_MASK       (0x0001u)
#define CSL_SYS_EBSR_A15_MODE_SHIFT      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_RESETVAL   (0x0001u)
/*----A15_MODE Tokens----*/
#define CSL_SYS_EBSR_A15_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_RESETVAL            (0x003Fu)

/* PCGCR1 */

#define CSL_SYS_PCGCR1_SYSCLKDIS_MASK    (0x8000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_SHIFT   (0x000Fu)
#define CSL_SYS_PCGCR1_SYSCLKDIS_RESETVAL (0x0000u)
/*----SYSCLKDIS Tokens----*/
#define CSL_SYS_PCGCR1_SYSCLKDIS_ACTIVE  (0x0000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2S2CG_MASK       (0x4000u)
#define CSL_SYS_PCGCR1_I2S2CG_SHIFT      (0x000Eu)
#define CSL_SYS_PCGCR1_I2S2CG_RESETVAL   (0x0000u)
/*----I2S2CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR2CG_MASK       (0x2000u)
#define CSL_SYS_PCGCR1_TMR2CG_SHIFT      (0x000Du)
#define CSL_SYS_PCGCR1_TMR2CG_RESETVAL   (0x0000u)
/*----TMR2CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR1CG_MASK       (0x1000u)
#define CSL_SYS_PCGCR1_TMR1CG_SHIFT      (0x000Cu)
#define CSL_SYS_PCGCR1_TMR1CG_RESETVAL   (0x0000u)
/*----TMR1CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_EMIFCG_MASK       (0x0800u)
#define CSL_SYS_PCGCR1_EMIFCG_SHIFT      (0x000Bu)
#define CSL_SYS_PCGCR1_EMIFCG_RESETVAL   (0x0000u)
/*----EMIFCG Tokens----*/
#define CSL_SYS_PCGCR1_EMIFCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_EMIFCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR0CG_MASK       (0x0400u)
#define CSL_SYS_PCGCR1_TMR0CG_SHIFT      (0x000Au)
#define CSL_SYS_PCGCR1_TMR0CG_RESETVAL   (0x0000u)
/*----TMR0CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_MCSPICG_MASK      (0x0200u)
#define CSL_SYS_PCGCR1_MCSPICG_SHIFT     (0x0009u)
#define CSL_SYS_PCGCR1_MCSPICG_RESETVAL  (0x0000u)
/*----MCSPICG Tokens----*/
#define CSL_SYS_PCGCR1_MCSPICG_ACTIVE    (0x0000u)
#define CSL_SYS_PCGCR1_MCSPICG_DISABLED  (0x0001u)

#define CSL_SYS_PCGCR1_I2S0CG_MASK       (0x0100u)
#define CSL_SYS_PCGCR1_I2S0CG_SHIFT      (0x0008u)
#define CSL_SYS_PCGCR1_I2S0CG_RESETVAL   (0x0000u)
/*----I2S0CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_MMCSD1CG_MASK     (0x0080u)
#define CSL_SYS_PCGCR1_MMCSD1CG_SHIFT    (0x0007u)
#define CSL_SYS_PCGCR1_MMCSD1CG_RESETVAL (0x0000u)
/*----MMCSD1CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD1CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD1CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2CCG_MASK        (0x0040u)
#define CSL_SYS_PCGCR1_I2CCG_SHIFT       (0x0006u)
#define CSL_SYS_PCGCR1_I2CCG_RESETVAL    (0x0000u)
/*----I2CCG Tokens----*/
#define CSL_SYS_PCGCR1_I2CCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_I2CCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR1_MCBSPCG_MASK      (0x0020u)
#define CSL_SYS_PCGCR1_MCBSPCG_SHIFT     (0x0005u)
#define CSL_SYS_PCGCR1_MCBSPCG_RESETVAL  (0x0000u)
/*----MCBSPCG Tokens----*/
#define CSL_SYS_PCGCR1_MCBSPCG_ACTIVE    (0x0000u)
#define CSL_SYS_PCGCR1_MCBSPCG_DISABLED  (0x0001u)

#define CSL_SYS_PCGCR1_MMCSD0CG_MASK     (0x0010u)
#define CSL_SYS_PCGCR1_MMCSD0CG_SHIFT    (0x0004u)
#define CSL_SYS_PCGCR1_MMCSD0CG_RESETVAL (0x0000u)
/*----MMCSD0CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD0CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD0CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_DMA0CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR1_DMA0CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR1_DMA0CG_RESETVAL   (0x0000u)
/*----DMA0CG Tokens----*/
#define CSL_SYS_PCGCR1_DMA0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_DMA0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_UARTCG_MASK       (0x0004u)
#define CSL_SYS_PCGCR1_UARTCG_SHIFT      (0x0002u)
#define CSL_SYS_PCGCR1_UARTCG_RESETVAL   (0x0000u)
/*----UARTCG Tokens----*/
#define CSL_SYS_PCGCR1_UARTCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_UARTCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_SPICG_MASK        (0x0002u)
#define CSL_SYS_PCGCR1_SPICG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR1_SPICG_RESETVAL    (0x0000u)
/*----SPICG Tokens----*/
#define CSL_SYS_PCGCR1_SPICG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_SPICG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR1_I2S3CG_MASK       (0x0001u)
#define CSL_SYS_PCGCR1_I2S3CG_SHIFT      (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_RESETVAL   (0x0000u)
/*----I2S3CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_RESETVAL          (0x0000u)

/* PCGCR2 */


#define CSL_SYS_PCGCR2_MCSPISPIREFCG_MASK (0x0080u)
#define CSL_SYS_PCGCR2_MCSPISPIREFCG_SHIFT (0x0007u)
#define CSL_SYS_PCGCR2_MCSPISPIREFCG_RESETVAL (0x0000u)
/*----McSPISPIREFCG Tokens----*/
#define CSL_SYS_PCGCR2_MCSPISPIREFCG_ACTIVE (0x0000u)
#define CSL_SYS_PCGCR2_MCSPISPIREFCG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR2_ANAREGCG_MASK     (0x0040u)
#define CSL_SYS_PCGCR2_ANAREGCG_SHIFT    (0x0006u)
#define CSL_SYS_PCGCR2_ANAREGCG_RESETVAL (0x0000u)
/*----ANAREGCG Tokens----*/
#define CSL_SYS_PCGCR2_ANAREGCG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR2_ANAREGCG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR2_DMA3CG_MASK       (0x0020u)
#define CSL_SYS_PCGCR2_DMA3CG_SHIFT      (0x0005u)
#define CSL_SYS_PCGCR2_DMA3CG_RESETVAL   (0x0000u)
/*----DMA3CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA2CG_MASK       (0x0010u)
#define CSL_SYS_PCGCR2_DMA2CG_SHIFT      (0x0004u)
#define CSL_SYS_PCGCR2_DMA2CG_RESETVAL   (0x0000u)
/*----DMA2CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA1CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR2_DMA1CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR2_DMA1CG_RESETVAL   (0x0000u)
/*----DMA1CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_USBCG_MASK        (0x0004u)
#define CSL_SYS_PCGCR2_USBCG_SHIFT       (0x0002u)
#define CSL_SYS_PCGCR2_USBCG_RESETVAL    (0x0000u)
/*----USBCG Tokens----*/
#define CSL_SYS_PCGCR2_USBCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_USBCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_SARCG_MASK        (0x0002u)
#define CSL_SYS_PCGCR2_SARCG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR2_SARCG_RESETVAL    (0x0000u)
/*----SARCG Tokens----*/
#define CSL_SYS_PCGCR2_SARCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_SARCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_HPICG_MASK        (0x0001u)
#define CSL_SYS_PCGCR2_HPICG_SHIFT       (0x0000u)
#define CSL_SYS_PCGCR2_HPICG_RESETVAL    (0x0000u)
/*----HPICG Tokens----*/
#define CSL_SYS_PCGCR2_HPICG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_HPICG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_RESETVAL          (0x0000u)

/* PSRCR */

#define CSL_SYS_PSRCR_COUNT_MASK         (0xFFFFu)
#define CSL_SYS_PSRCR_COUNT_SHIFT        (0x0000u)
#define CSL_SYS_PSRCR_COUNT_RESETVAL     (0x0000u)

#define CSL_SYS_PSRCR_RESETVAL           (0x0000u)

/* PRCR */

#define CSL_SYS_PRCR_PG4_CLRDIS_MASK     (0x8000u)
#define CSL_SYS_PRCR_PG4_CLRDIS_SHIFT    (0x000Fu)
#define CSL_SYS_PRCR_PG4_CLRDIS_RESETVAL (0x0000u)
/*----PG4_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_PG4_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_PG4_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_MCBSP_CLRDIS_MASK   (0x4000u)
#define CSL_SYS_PRCR_MCBSP_CLRDIS_SHIFT  (0x000Eu)
#define CSL_SYS_PRCR_MCBSP_CLRDIS_RESETVAL (0x0000u)
/*----MCBSP_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_MCBSP_CLRDIS_ENABLE (0x0000u)
#define CSL_SYS_PRCR_MCBSP_CLRDIS_DISABLE (0x0001u)

#define CSL_SYS_PRCR_PG3_CLRDIS_MASK     (0x2000u)
#define CSL_SYS_PRCR_PG3_CLRDIS_SHIFT    (0x000Du)
#define CSL_SYS_PRCR_PG3_CLRDIS_RESETVAL (0x0000u)
/*----PG3_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_PG3_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_PG3_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_DMA_CLRDIS_MASK     (0x1000u)
#define CSL_SYS_PRCR_DMA_CLRDIS_SHIFT    (0x000Cu)
#define CSL_SYS_PRCR_DMA_CLRDIS_RESETVAL (0x0000u)
/*----DMA_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_DMA_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_DMA_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_USB_CLRDIS_MASK     (0x0800u)
#define CSL_SYS_PRCR_USB_CLRDIS_SHIFT    (0x000Bu)
#define CSL_SYS_PRCR_USB_CLRDIS_RESETVAL (0x0000u)
/*----USB_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_USB_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_USB_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_SAR_CLRDIS_MASK     (0x0400u)
#define CSL_SYS_PRCR_SAR_CLRDIS_SHIFT    (0x000Au)
#define CSL_SYS_PRCR_SAR_CLRDIS_RESETVAL (0x0000u)
/*----SAR_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_SAR_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_SAR_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_PG1_CLRDIS_MASK    (0x0200u)
#define CSL_SYS_PRCR_PG1_CLRDIS_SHIFT   (0x0009u)
#define CSL_SYS_PRCR_PG1_CLRDIS_RESETVAL (0x0000u)
/*----PG1_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_PG1_CLRDIS_ENABLE  (0x0000u)
#define CSL_SYS_PRCR_PG1_CLRDIS_DISABLE (0x0001u)

#define CSL_SYS_PRCR_I2C_CLRDIS_MASK     (0x0100u)
#define CSL_SYS_PRCR_I2C_CLRDIS_SHIFT    (0x0008u)
#define CSL_SYS_PRCR_I2C_CLRDIS_RESETVAL (0x0000u)
/*----I2C_CLRDIS Tokens----*/
#define CSL_SYS_PRCR_I2C_CLRDIS_ENABLE   (0x0000u)
#define CSL_SYS_PRCR_I2C_CLRDIS_DISABLE  (0x0001u)

#define CSL_SYS_PRCR_PG4_RST_MASK        (0x0080u)
#define CSL_SYS_PRCR_PG4_RST_SHIFT       (0x0007u)
#define CSL_SYS_PRCR_PG4_RST_RESETVAL    (0x0000u)
/*----PG4_RST Tokens----*/
#define CSL_SYS_PRCR_PG4_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG4_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_MCBSP_RST_MASK      (0x0040u)
#define CSL_SYS_PRCR_MCBSP_RST_SHIFT     (0x0006u)
#define CSL_SYS_PRCR_MCBSP_RST_RESETVAL  (0x0000u)
/*----MCBSP_RST Tokens----*/
#define CSL_SYS_PRCR_MCBSP_RST_RST       (0x0001u)
#define CSL_SYS_PRCR_MCBSP_RST_NRST      (0x0000u)

#define CSL_SYS_PRCR_PG3_RST_MASK        (0x0020u)
#define CSL_SYS_PRCR_PG3_RST_SHIFT       (0x0005u)
#define CSL_SYS_PRCR_PG3_RST_RESETVAL    (0x0000u)
/*----PG3_RST Tokens----*/
#define CSL_SYS_PRCR_PG3_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG3_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_DMA_RST_MASK        (0x0010u)
#define CSL_SYS_PRCR_DMA_RST_SHIFT       (0x0004u)
#define CSL_SYS_PRCR_DMA_RST_RESETVAL    (0x0000u)
/*----DMA_RST Tokens----*/
#define CSL_SYS_PRCR_DMA_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_DMA_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_USB_RST_MASK        (0x0008u)
#define CSL_SYS_PRCR_USB_RST_SHIFT       (0x0003u)
#define CSL_SYS_PRCR_USB_RST_RESETVAL    (0x0000u)
/*----USB_RST Tokens----*/
#define CSL_SYS_PRCR_USB_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_USB_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_SAR_RST_MASK        (0x0004u)
#define CSL_SYS_PRCR_SAR_RST_SHIFT       (0x0002u)
#define CSL_SYS_PRCR_SAR_RST_RESETVAL    (0x0000u)
/*----SAR_RST Tokens----*/
#define CSL_SYS_PRCR_SAR_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_SAR_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_PG1_RST_MASK       (0x0002u)
#define CSL_SYS_PRCR_PG1_RST_SHIFT      (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_RESETVAL   (0x0000u)
/*----PG1_RST Tokens----*/
#define CSL_SYS_PRCR_PG1_RST_RST        (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_NRST       (0x0000u)

#define CSL_SYS_PRCR_I2C_RST_MASK        (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_SHIFT       (0x0000u)
#define CSL_SYS_PRCR_I2C_RST_RESETVAL    (0x0000u)
/*----I2C_RST Tokens----*/
#define CSL_SYS_PRCR_I2C_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_RESETVAL            (0x0000u)

/* TIAFR */


#define CSL_SYS_TIAFR_TIM2FLAG_MASK      (0x0004u)
#define CSL_SYS_TIAFR_TIM2FLAG_SHIFT     (0x0002u)
#define CSL_SYS_TIAFR_TIM2FLAG_RESETVAL  (0x0000u)
/*----TIM2FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM2FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM2FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM1FLAG_MASK      (0x0002u)
#define CSL_SYS_TIAFR_TIM1FLAG_SHIFT     (0x0001u)
#define CSL_SYS_TIAFR_TIM1FLAG_RESETVAL  (0x0000u)
/*----TIM1FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM1FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM1FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM0FLAG_MASK      (0x0001u)
#define CSL_SYS_TIAFR_TIM0FLAG_SHIFT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_RESETVAL  (0x0000u)
/*----TIM0FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM0FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_RESETVAL           (0x0000u)

/* MSIAFR */


#define CSL_SYS_MSIAFR_MSWAKEUPFLAG_MASK (0x0002u)
#define CSL_SYS_MSIAFR_MSWAKEUPFLAG_SHIFT (0x0001u)
#define CSL_SYS_MSIAFR_MSWAKEUPFLAG_RESETVAL (0x0000u)
/*----MSWAKEUPFLAG Tokens----*/
#define CSL_SYS_MSIAFR_MSWAKEUPFLAG_NOINT (0x0000u)
#define CSL_SYS_MSIAFR_MSWAKEUPFLAG_INT  (0x0001u)

#define CSL_SYS_MSIAFR_MSINTFLAG_MASK    (0x0001u)
#define CSL_SYS_MSIAFR_MSINTFLAG_SHIFT   (0x0000u)
#define CSL_SYS_MSIAFR_MSINTFLAG_RESETVAL (0x0000u)
/*----MSINTFLAG Tokens----*/
#define CSL_SYS_MSIAFR_MSINTFLAG_NOINT   (0x0000u)
#define CSL_SYS_MSIAFR_MSINTFLAG_INT     (0x0001u)

#define CSL_SYS_MSIAFR_RESETVAL          (0x0000u)

/* ODSCR */


#define CSL_SYS_ODSCR_CLKOUTDS_MASK      (0x0004u)
#define CSL_SYS_ODSCR_CLKOUTDS_SHIFT     (0x0002u)
#define CSL_SYS_ODSCR_CLKOUTDS_RESETVAL  (0x0001u)
/*----CLKOUTDS Tokens----*/
#define CSL_SYS_ODSCR_CLKOUTDS_MIN       (0x0000u)
#define CSL_SYS_ODSCR_CLKOUTDS_MAX       (0x0001u)


#define CSL_SYS_ODSCR_EMIFDS_MASK        (0x0001u)
#define CSL_SYS_ODSCR_EMIFDS_SHIFT       (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_RESETVAL    (0x0001u)
/*----EMIFDS Tokens----*/
#define CSL_SYS_ODSCR_EMIFDS_MIN         (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_MAX         (0x0001u)

#define CSL_SYS_ODSCR_RESETVAL           (0x0005u)

/* PDINHIBR1 */


#define CSL_SYS_PDINHIBR1_S15PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S15PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S15PD_RESETVAL (0x0000u)
/*----S15PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S14PD_MASK     (0x1000u)
#define CSL_SYS_PDINHIBR1_S14PD_SHIFT    (0x000Cu)
#define CSL_SYS_PDINHIBR1_S14PD_RESETVAL (0x0000u)
/*----S14PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S14PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S14PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S13PD_MASK     (0x0800u)
#define CSL_SYS_PDINHIBR1_S13PD_SHIFT    (0x000Bu)
#define CSL_SYS_PDINHIBR1_S13PD_RESETVAL (0x0000u)
/*----S13PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S13PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S13PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S12PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR1_S12PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR1_S12PD_RESETVAL (0x0000u)
/*----S12PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S12PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S12PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S11PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR1_S11PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR1_S11PD_RESETVAL (0x0000u)
/*----S11PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S11PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S11PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S10PD_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR1_S10PD_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR1_S10PD_RESETVAL (0x0000u)
/*----S10PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S10PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S10PD_DISABLE  (0x0001u)


#define CSL_SYS_PDINHIBR1_S5PD_MASK      (0x0020u)
#define CSL_SYS_PDINHIBR1_S5PD_SHIFT     (0x0005u)
#define CSL_SYS_PDINHIBR1_S5PD_RESETVAL  (0x0000u)
/*----S5PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S5PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S5PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S4PD_MASK      (0x0010u)
#define CSL_SYS_PDINHIBR1_S4PD_SHIFT     (0x0004u)
#define CSL_SYS_PDINHIBR1_S4PD_RESETVAL  (0x0000u)
/*----S4PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S4PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S4PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S3PD_MASK      (0x0008u)
#define CSL_SYS_PDINHIBR1_S3PD_SHIFT     (0x0003u)
#define CSL_SYS_PDINHIBR1_S3PD_RESETVAL  (0x0000u)
/*----S3PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S3PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S3PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S2PD_MASK      (0x0004u)
#define CSL_SYS_PDINHIBR1_S2PD_SHIFT     (0x0002u)
#define CSL_SYS_PDINHIBR1_S2PD_RESETVAL  (0x0000u)
/*----S2PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S2PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S2PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S1PD_MASK      (0x0002u)
#define CSL_SYS_PDINHIBR1_S1PD_SHIFT     (0x0001u)
#define CSL_SYS_PDINHIBR1_S1PD_RESETVAL  (0x0000u)
/*----S1PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S1PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S1PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S0PD_MASK      (0x0001u)
#define CSL_SYS_PDINHIBR1_S0PD_SHIFT     (0x0000u)
#define CSL_SYS_PDINHIBR1_S0PD_RESETVAL  (0x0000u)
/*----S0PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S0PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S0PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_RESETVAL       (0x0000u)

/* PDINHIBR2 */

#define CSL_SYS_PDINHIBR2_CLKINPD_MASK   (0x8000u)
#define CSL_SYS_PDINHIBR2_CLKINPD_SHIFT  (0x000Fu)
#define CSL_SYS_PDINHIBR2_CLKINPD_RESETVAL (0x0000u)
/*----CLKINPD Tokens----*/
#define CSL_SYS_PDINHIBR2_CLKINPD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_CLKINPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_INT1PU_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR2_INT1PU_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR2_INT1PU_RESETVAL (0x0000u)
/*----INT1PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT1PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT1PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_INT0PU_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR2_INT0PU_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR2_INT0PU_RESETVAL (0x0000u)
/*----INT0PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT0PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT0PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETPU_MASK   (0x1000u)
#define CSL_SYS_PDINHIBR2_RESETPU_SHIFT  (0x000Cu)
#define CSL_SYS_PDINHIBR2_RESETPU_RESETVAL (0x0000u)
/*----RESETPU Tokens----*/
#define CSL_SYS_PDINHIBR2_RESETPU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_RESETPU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_EMU01PU_MASK   (0x0800u)
#define CSL_SYS_PDINHIBR2_EMU01PU_SHIFT  (0x000Bu)
#define CSL_SYS_PDINHIBR2_EMU01PU_RESETVAL (0x0000u)
/*----EMU01PU Tokens----*/
#define CSL_SYS_PDINHIBR2_EMU01PU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_EMU01PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_TDIPU_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR2_TDIPU_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR2_TDIPU_RESETVAL (0x0000u)
/*----TDIPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TDIPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TDIPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TMSPU_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR2_TMSPU_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR2_TMSPU_RESETVAL (0x0000u)
/*----TMSPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TMSPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TMSPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TCKPU_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR2_TCKPU_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR2_TCKPU_RESETVAL (0x0000u)
/*----TCKPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TCKPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TCKPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TRSTPD_MASK    (0x0080u)
#define CSL_SYS_PDINHIBR2_TRSTPD_SHIFT   (0x0007u)
#define CSL_SYS_PDINHIBR2_TRSTPD_RESETVAL (0x0000u)
/*----TRSTPD Tokens----*/
#define CSL_SYS_PDINHIBR2_TRSTPD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_TRSTPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_TDOPU_MASK     (0x0040u)
#define CSL_SYS_PDINHIBR2_TDOPU_SHIFT    (0x0006u)
#define CSL_SYS_PDINHIBR2_TDOPU_RESETVAL (0x0000u)
/*----TDOPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TDOPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TDOPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A20PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR2_A20PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR2_A20PD_RESETVAL (0x0000u)
/*----A20PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A20PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A20PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A19PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR2_A19PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR2_A19PD_RESETVAL (0x0000u)
/*----A19PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A19PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A19PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A18PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR2_A18PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR2_A18PD_RESETVAL (0x0000u)
/*----A18PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A18PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A18PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A17PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR2_A17PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR2_A17PD_RESETVAL (0x0000u)
/*----A17PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A17PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A17PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A16PD_MASK     (0x0002u)
#define CSL_SYS_PDINHIBR2_A16PD_SHIFT    (0x0001u)
#define CSL_SYS_PDINHIBR2_A16PD_RESETVAL (0x0000u)
/*----A16PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A16PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A16PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A15PD_MASK     (0x0001u)
#define CSL_SYS_PDINHIBR2_A15PD_SHIFT    (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_RESETVAL (0x0000u)
/*----A15PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETVAL       (0x0000u)

/* PDINHIBR3 */

#define CSL_SYS_PDINHIBR3_PD15PD_MASK    (0x8000u)
#define CSL_SYS_PDINHIBR3_PD15PD_SHIFT   (0x000Fu)
#define CSL_SYS_PDINHIBR3_PD15PD_RESETVAL (0x0001u)
/*----PD15PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD15PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD15PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD14PD_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR3_PD14PD_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR3_PD14PD_RESETVAL (0x0000u)
/*----PD14PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD14PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD14PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD13PD_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR3_PD13PD_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR3_PD13PD_RESETVAL (0x0000u)
/*----PD13PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD13PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD13PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD12PD_MASK    (0x1000u)
#define CSL_SYS_PDINHIBR3_PD12PD_SHIFT   (0x000Cu)
#define CSL_SYS_PDINHIBR3_PD12PD_RESETVAL (0x0001u)
/*----PD12PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD12PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD12PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD11PD_MASK    (0x0800u)
#define CSL_SYS_PDINHIBR3_PD11PD_SHIFT   (0x000Bu)
#define CSL_SYS_PDINHIBR3_PD11PD_RESETVAL (0x0001u)
/*----PD11PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD11PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD11PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD10PD_MASK    (0x0400u)
#define CSL_SYS_PDINHIBR3_PD10PD_SHIFT   (0x000Au)
#define CSL_SYS_PDINHIBR3_PD10PD_RESETVAL (0x0000u)
/*----PD10PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD10PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD10PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD9PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR3_PD9PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR3_PD9PD_RESETVAL (0x0000u)
/*----PD9PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD9PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD9PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD8PD_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR3_PD8PD_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR3_PD8PD_RESETVAL (0x0000u)
/*----PD8PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD8PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD8PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD7PD_MASK     (0x0080u)
#define CSL_SYS_PDINHIBR3_PD7PD_SHIFT    (0x0007u)
#define CSL_SYS_PDINHIBR3_PD7PD_RESETVAL (0x0000u)
/*----PD7PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD7PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD7PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD6PD_MASK     (0x0040u)
#define CSL_SYS_PDINHIBR3_PD6PD_SHIFT    (0x0006u)
#define CSL_SYS_PDINHIBR3_PD6PD_RESETVAL (0x0000u)
/*----PD6PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD6PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD6PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD5PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR3_PD5PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR3_PD5PD_RESETVAL (0x0000u)
/*----PD5PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD5PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD5PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD4PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR3_PD4PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR3_PD4PD_RESETVAL (0x0000u)
/*----PD4PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD4PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD4PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD3PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR3_PD3PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR3_PD3PD_RESETVAL (0x0000u)
/*----PD3PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD3PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD3PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD2PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR3_PD2PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR3_PD2PD_RESETVAL (0x0000u)
/*----PD2PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD2PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD2PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD1PD_MASK     (0x0002u)
#define CSL_SYS_PDINHIBR3_PD1PD_SHIFT    (0x0001u)
#define CSL_SYS_PDINHIBR3_PD1PD_RESETVAL (0x0000u)
/*----PD1PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD1PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD1PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD0PD_MASK     (0x0001u)
#define CSL_SYS_PDINHIBR3_PD0PD_SHIFT    (0x0000u)
#define CSL_SYS_PDINHIBR3_PD0PD_RESETVAL (0x0000u)
/*----PD0PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD0PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD0PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_RESETVAL       (0x0000u)

/* DMA0CESR1 */


#define CSL_SYS_DMA0CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR1_CH1EVT_RESETVAL (0x0000u)
/*----CH1EVT Tokens----*/
#define CSL_SYS_DMA0CESR1_CH1EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA0CESR1_CH1EVT_I2S0TX  (0x0001u)
#define CSL_SYS_DMA0CESR1_CH1EVT_I2S0RX  (0x0002u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI0RD (0x0003u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI0WR (0x0004u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MMCSD0TX (0x0005u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MMCSD0RX (0x0006u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MMCSD1TX (0x0007u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MMCSD1RX (0x0008u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI1RD (0x0009u)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI1WR (0x000au)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI2RD (0x000bu)
#define CSL_SYS_DMA0CESR1_CH1EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA0CESR1_CH1EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA0CESR1_CH1EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA0CESR1_CH1EVT_MCSPI2WR (0x000fu)


#define CSL_SYS_DMA0CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR1_CH0EVT_RESETVAL (0x0000u)
/*----CH0EVT Tokens----*/
#define CSL_SYS_DMA0CESR1_CH0EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA0CESR1_CH0EVT_I2S0TX  (0x0001u)
#define CSL_SYS_DMA0CESR1_CH0EVT_I2S0RX  (0x0002u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI0RD (0x0003u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI0WR (0x0004u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MMCSD0TX (0x0005u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MMCSD0RX (0x0006u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MMCSD1TX (0x0007u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MMCSD1RX (0x0008u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI1RD (0x0009u)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI1WR (0x000au)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI2RD (0x000bu)
#define CSL_SYS_DMA0CESR1_CH0EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA0CESR1_CH0EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA0CESR1_CH0EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA0CESR1_CH0EVT_MCSPI2WR (0x000fu)

#define CSL_SYS_DMA0CESR1_RESETVAL       (0x0000u)

/* DMA0CESR2 */


#define CSL_SYS_DMA0CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR2_CH3EVT_RESETVAL (0x0000u)
/*----CH3EVT Tokens----*/
#define CSL_SYS_DMA0CESR2_CH3EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA0CESR2_CH3EVT_I2S0TX  (0x0001u)
#define CSL_SYS_DMA0CESR2_CH3EVT_I2S0RX  (0x0002u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI0RD (0x0003u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI0WR (0x0004u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MMCSD0TX (0x0005u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MMCSD0RX (0x0006u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MMCSD1TX (0x0007u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MMCSD1RX (0x0008u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI1RD (0x0009u)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI1WR (0x000au)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI2RD (0x000bu)
#define CSL_SYS_DMA0CESR2_CH3EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA0CESR2_CH3EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA0CESR2_CH3EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA0CESR2_CH3EVT_MCSPI2WR (0x000fu)


#define CSL_SYS_DMA0CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR2_CH2EVT_RESETVAL (0x0000u)
/*----CH2EVT Tokens----*/
#define CSL_SYS_DMA0CESR2_CH2EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA0CESR2_CH2EVT_I2S0TX  (0x0001u)
#define CSL_SYS_DMA0CESR2_CH2EVT_I2S0RX  (0x0002u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI0RD (0x0003u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI0WR (0x0004u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MMCSD0TX (0x0005u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MMCSD0RX (0x0006u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MMCSD1TX (0x0007u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MMCSD1RX (0x0008u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI1RD (0x0009u)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI1WR (0x000au)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI2RD (0x000bu)
#define CSL_SYS_DMA0CESR2_CH2EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA0CESR2_CH2EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA0CESR2_CH2EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA0CESR2_CH2EVT_MCSPI2WR (0x000fu)

#define CSL_SYS_DMA0CESR2_RESETVAL       (0x0000u)

/* DMA1CESR1 */


#define CSL_SYS_DMA1CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RESETVAL (0x0000u)
/*----CH1EVT Tokens----*/
#define CSL_SYS_DMA1CESR1_CH1EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA1CESR1_CH1EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA1CESR1_CH1EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES0    (0x0003u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES1    (0x0004u)
#define CSL_SYS_DMA1CESR1_CH1EVT_UARTTX  (0x0005u)
#define CSL_SYS_DMA1CESR1_CH1EVT_UARTRX  (0x0006u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES2    (0x0007u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES3    (0x0008u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES4    (0x0009u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES5    (0x000au)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES6    (0x000bu)
#define CSL_SYS_DMA1CESR1_CH1EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA1CESR1_CH1EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA1CESR1_CH1EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA1CESR1_CH1EVT_RES7    (0x000fu)


#define CSL_SYS_DMA1CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RESETVAL (0x0000u)
/*----CH0EVT Tokens----*/
#define CSL_SYS_DMA1CESR1_CH0EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA1CESR1_CH0EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA1CESR1_CH0EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES0    (0x0003u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES1    (0x0004u)
#define CSL_SYS_DMA1CESR1_CH0EVT_UARTTX  (0x0005u)
#define CSL_SYS_DMA1CESR1_CH0EVT_UARTRX  (0x0006u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES2    (0x0007u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES3    (0x0008u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES4    (0x0009u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES5    (0x000au)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES6    (0x000bu)
#define CSL_SYS_DMA1CESR1_CH0EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA1CESR1_CH0EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA1CESR1_CH0EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA1CESR1_CH0EVT_RES7    (0x000fu)

#define CSL_SYS_DMA1CESR1_RESETVAL       (0x0000u)

/* DMA1CESR2 */


#define CSL_SYS_DMA1CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RESETVAL (0x0000u)
/*----CH3EVT Tokens----*/
#define CSL_SYS_DMA1CESR2_CH3EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA1CESR2_CH3EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA1CESR2_CH3EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES0    (0x0003u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES1    (0x0004u)
#define CSL_SYS_DMA1CESR2_CH3EVT_UARTTX  (0x0005u)
#define CSL_SYS_DMA1CESR2_CH3EVT_UARTRX  (0x0006u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES2    (0x0007u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES3    (0x0008u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES4    (0x0009u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES5    (0x000au)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES6    (0x000bu)
#define CSL_SYS_DMA1CESR2_CH3EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA1CESR2_CH3EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA1CESR2_CH3EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA1CESR2_CH3EVT_RES7    (0x000fu)


#define CSL_SYS_DMA1CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RESETVAL (0x0000u)
/*----CH2EVT Tokens----*/
#define CSL_SYS_DMA1CESR2_CH2EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA1CESR2_CH2EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA1CESR2_CH2EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES0    (0x0003u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES1    (0x0004u)
#define CSL_SYS_DMA1CESR2_CH2EVT_UARTTX  (0x0005u)
#define CSL_SYS_DMA1CESR2_CH2EVT_UARTRX  (0x0006u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES2    (0x0007u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES3    (0x0008u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES4    (0x0009u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES5    (0x000au)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES6    (0x000bu)
#define CSL_SYS_DMA1CESR2_CH2EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA1CESR2_CH2EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA1CESR2_CH2EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA1CESR2_CH2EVT_RES7    (0x000fu)

#define CSL_SYS_DMA1CESR2_RESETVAL       (0x0000u)

/* CCR1 */

#define CSL_SYS_CCR1_SDCLK_EN_MASK   (0x0001u)
#define CSL_SYS_CCR1_SDCLK_EN_SHIFT  (0x0000u)
#define CSL_SYS_CCR1_SDCLK_EN_RESETVAL (0x0001u)
/*----SDCLK_EN Tokens----*/
#define CSL_SYS_CCR1_SDCLK_EN_SDCLKON (0x0001u)
#define CSL_SYS_CCR1_SDCLK_EN_SDCLKOFF (0x0000u)

#define CSL_SYS_CCR1_RESETVAL        (0x0001u)


/* CCR2 */


#define CSL_SYS_CCR2_SYSCLKSRC_MASK      (0x0030u)
#define CSL_SYS_CCR2_SYSCLKSRC_SHIFT     (0x0004u)
#define CSL_SYS_CCR2_SYSCLKSRC_RESETVAL  (0x0000u)
/*----SYSCLKSRC Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSRC_BYPRTC    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKRTC   (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSRC_BYPCLKIN  (0x0002u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKCLKIN (0x0003u)

#define CSL_SYS_CCR2_CLKSELSTAT_MASK     (0x0004u)
#define CSL_SYS_CCR2_CLKSELSTAT_SHIFT    (0x0002u)
#define CSL_SYS_CCR2_CLKSELSTAT_RESETVAL (0x0000u)
/*----CLKSELSTAT Tokens----*/
#define CSL_SYS_CCR2_CLKSELSTAT_RTCIN    (0x0000u)
#define CSL_SYS_CCR2_CLKSELSTAT_CLKIN    (0x0001u)


#define CSL_SYS_CCR2_SYSCLKSEL_MASK      (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSEL_SHIFT     (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_RESETVAL  (0x0000u)
/*----SYSCLKSEL Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSEL_BYPASS    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_LOCK      (0x0001u)

#define CSL_SYS_CCR2_RESETVAL            (0x0000u)

/* PMR */

#define CSL_SYS_PMR_PLLM15_0_MASK        (0xFFFFu)
#define CSL_SYS_PMR_PLLM15_0_SHIFT       (0x0000u)
#define CSL_SYS_PMR_PLLM15_0_RESETVAL    (0x0000u)

#define CSL_SYS_PMR_RESETVAL             (0x0000u)

/* PICR */

#define CSL_SYS_PICR_PLLM16_MASK         (0x8000u)
#define CSL_SYS_PICR_PLLM16_SHIFT        (0x000Fu)
#define CSL_SYS_PICR_PLLM16_RESETVAL     (0x0000u)


#define CSL_SYS_PICR_RD_MASK             (0x003Fu)
#define CSL_SYS_PICR_RD_SHIFT            (0x0000u)
#define CSL_SYS_PICR_RD_RESETVAL         (0x0000u)

#define CSL_SYS_PICR_RESETVAL            (0x0000u)

/* PCR */

#define CSL_SYS_PCR_PLLRST_MASK          (0x4000u)
#define CSL_SYS_PCR_PLLRST_SHIFT         (0x000Eu)
#define CSL_SYS_PCR_PLLRST_RESETVAL      (0x0001u)
/*----PLLRST Tokens----*/
#define CSL_SYS_PCR_PLLRST_NRST          (0x0000u)
#define CSL_SYS_PCR_PLLRST_RST           (0x0001u)

#define CSL_SYS_PCR_PLLPWRDN_MASK        (0x2000u)
#define CSL_SYS_PCR_PLLPWRDN_SHIFT       (0x000Du)
#define CSL_SYS_PCR_PLLPWRDN_RESETVAL    (0x0001u)
/*----PLLPWRDN Tokens----*/
#define CSL_SYS_PCR_PLLPWRDN_PWRD        (0x0000u)
#define CSL_SYS_PCR_PLLPWRDN_NPWRD       (0x0001u)

#define CSL_SYS_PCR_RESETVAL			 (0x0000u)
/* PODCR */

#define CSL_SYS_PODCR_OD2_MASK           (0xF800u)
#define CSL_SYS_PODCR_OD2_SHIFT          (0x000Bu)
#define CSL_SYS_PODCR_OD2_RESETVAL       (0x0000u)


#define CSL_SYS_PODCR_OUTDIV2BY_MASK     (0x0020u)
#define CSL_SYS_PODCR_OUTDIV2BY_SHIFT    (0x0005u)
#define CSL_SYS_PODCR_OUTDIV2BY_RESETVAL (0x0000u)
/*----OUTDIV2BY Tokens----*/
#define CSL_SYS_PODCR_OUTDIV2BY_OD2EN    (0x0000u)
#define CSL_SYS_PODCR_OUTDIV2BY_OD2BYP   (0x0001u)


#define CSL_SYS_PODCR_OD_MASK            (0x0007u)
#define CSL_SYS_PODCR_OD_SHIFT           (0x0000u)
#define CSL_SYS_PODCR_OD_RESETVAL        (0x0000u)

#define CSL_SYS_PODCR_RESETVAL           (0x0000u)

#if (defined(CHIP_C5517))
/* CLKOUTCR */

#define CSL_SYS_CLKOUTCR_CLKOUT_GZ_MASK     (0x8000u)
#define CSL_SYS_CLKOUTCR_CLKOUT_GZ_SHIFT    (0x000Fu)
#define CSL_SYS_CLKOUTCR_CLKOUT_GZ_RESETVAL (0x0000u)
/*----CLKOUT_GZ Tokens----*/
#define CSL_SYS_CLKOUTCR_CLKOUT_GZ_COEN     (0x0000u)
#define CSL_SYS_CLKOUTCR_CLKOUT_GZ_COTRI    (0x0001u)


#define CSL_SYS_CLKOUTCR_CLKOUT_DIV_MASK    (0x0700u)
#define CSL_SYS_CLKOUTCR_CLKOUT_DIV_SHIFT   (0x0008u)
#define CSL_SYS_CLKOUTCR_CLKOUT_DIV_RESETVAL (0x0000u)


#define CSL_SYS_CLKOUTCR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CLKOUTCR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CLKOUTCR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CLKOUTCR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CLKOUTCR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CLKOUTCR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CLKOUTCR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CLKOUTCR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CLKOUTCR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CLKOUTCR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CLKOUTCR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CLKOUTCR_SRC_MODE10         (0x000au)
#define CSL_SYS_CLKOUTCR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CLKOUTCR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CLKOUTCR_SRC_MODE13         (0x000du)
#define CSL_SYS_CLKOUTCR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CLKOUTCR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CLKOUTCR_RESETVAL           (0x000Bu)
#else
/* CCSSR */

#define CSL_SYS_CCSSR_CLKOUT_GZ_MASK     (0x8000u)
#define CSL_SYS_CCSSR_CLKOUT_GZ_SHIFT    (0x000Fu)
#define CSL_SYS_CCSSR_CLKOUT_GZ_RESETVAL (0x0000u)
/*----CLKOUT_GZ Tokens----*/
#define CSL_SYS_CCSSR_CLKOUT_GZ_COEN     (0x0000u)
#define CSL_SYS_CCSSR_CLKOUT_GZ_COTRI    (0x0001u)


#define CSL_SYS_CCSSR_CLKOUT_DIV_MASK    (0x0700u)
#define CSL_SYS_CCSSR_CLKOUT_DIV_SHIFT   (0x0008u)
#define CSL_SYS_CCSSR_CLKOUT_DIV_RESETVAL (0x0000u)


#define CSL_SYS_CCSSR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CCSSR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CCSSR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CCSSR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CCSSR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CCSSR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CCSSR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CCSSR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CCSSR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CCSSR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CCSSR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CCSSR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CCSSR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CCSSR_SRC_MODE10         (0x000au)
#define CSL_SYS_CCSSR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CCSSR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CCSSR_SRC_MODE13         (0x000du)
#define CSL_SYS_CCSSR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CCSSR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CCSSR_RESETVAL           (0x000Bu)
#endif

/* ECDR */


#define CSL_SYS_ECDR_EDIV_MASK           (0x0001u)
#define CSL_SYS_ECDR_EDIV_SHIFT          (0x0000u)
#define CSL_SYS_ECDR_EDIV_RESETVAL       (0x0001u)
/*----EDIV Tokens----*/
#define CSL_SYS_ECDR_EDIV_HALFRATE       (0x0000u)
#define CSL_SYS_ECDR_EDIV_FULLRATE       (0x0001u)

#define CSL_SYS_ECDR_RESETVAL            (0x0001u)

/* RSCR */


#define CSL_SYS_RSCR_RTC_ISO_MASK        (0x0001u)
#define CSL_SYS_RSCR_RTC_ISO_SHIFT       (0x0000u)
#define CSL_SYS_RSCR_RTC_ISO_RESETVAL    (0x0000u)
/*----RTC_ISO Tokens----*/
#define CSL_SYS_RSCR_RTC_ISO_ISO         (0x0000u)
#define CSL_SYS_RSCR_RTC_ISO_NISO        (0x0001u)

#define CSL_SYS_RSCR_RESETVAL            (0x0000u)

/* RAMSLPMDCNTLR1 */

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_RESETVAL (0x0001u)
/*----DARAM7SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_RESETVAL (0x0001u)
/*----DARAM7SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM7SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_RESETVAL (0x0001u)
/*----DARAM6SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_RESETVAL (0x0001u)
/*----DARAM6SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM6SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_RESETVAL (0x0001u)
/*----DARAM5SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_RESETVAL (0x0001u)
/*----DARAM5SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM5SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_RESETVAL (0x0001u)
/*----DARAM4SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_RESETVAL (0x0001u)
/*----DARAM4SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM4SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_RESETVAL (0x0001u)
/*----DARAM3SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_RESETVAL (0x0001u)
/*----DARAM3SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM3SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_RESETVAL (0x0001u)
/*----DARAM2SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_RESETVAL (0x0001u)
/*----DARAM2SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM2SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_RESETVAL (0x0001u)
/*----DARAM1SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_RESETVAL (0x0001u)
/*----DARAM1SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM1SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_RESETVAL (0x0001u)
/*----DARAM0SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_RESETVAL (0x0001u)
/*----DARAM0SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAM0SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR2 */

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_RESETVAL (0x0001u)
/*----SARAM7SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_RESETVAL (0x0001u)
/*----SARAM7SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM7SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_RESETVAL (0x0001u)
/*----SARAM6SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_RESETVAL (0x0001u)
/*----SARAM6SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM6SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_RESETVAL (0x0001u)
/*----SARAM5SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_RESETVAL (0x0001u)
/*----SARAM5SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM5SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_RESETVAL (0x0001u)
/*----SARAM4SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_RESETVAL (0x0001u)
/*----SARAM4SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM4SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_RESETVAL (0x0001u)
/*----SARAM3SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_RESETVAL (0x0001u)
/*----SARAM3SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM3SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_RESETVAL (0x0001u)
/*----SARAM2SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_RESETVAL (0x0001u)
/*----SARAM2SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM2SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_RESETVAL (0x0001u)
/*----SARAM1SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_RESETVAL (0x0001u)
/*----SARAM1SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM1SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_RESETVAL (0x0001u)
/*----SARAM0SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_RESETVAL (0x0001u)
/*----SARAM0SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_SARAM0SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR3 */

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_RESETVAL (0x0001u)
/*----SARAM15SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_RESETVAL (0x0001u)
/*----SARAM15SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM15SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_RESETVAL (0x0001u)
/*----SARAM14SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_RESETVAL (0x0001u)
/*----SARAM14SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM14SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_RESETVAL (0x0001u)
/*----SARAM13SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_RESETVAL (0x0001u)
/*----SARAM13SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM13SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_RESETVAL (0x0001u)
/*----SARAM12SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_RESETVAL (0x0001u)
/*----SARAM12SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM12SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_RESETVAL (0x0001u)
/*----SARAM11SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_RESETVAL (0x0001u)
/*----SARAM11SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM11SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_RESETVAL (0x0001u)
/*----SARAM10SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_RESETVAL (0x0001u)
/*----SARAM10SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM10SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_RESETVAL (0x0001u)
/*----SARAM9SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_RESETVAL (0x0001u)
/*----SARAM9SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM9SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_RESETVAL (0x0001u)
/*----SARAM8SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_RESETVAL (0x0001u)
/*----SARAM8SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR3_SARAM8SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR3_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR4 */

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_RESETVAL (0x0001u)
/*----SARAM23SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_RESETVAL (0x0001u)
/*----SARAM23SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM23SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_RESETVAL (0x0001u)
/*----SARAM22SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_RESETVAL (0x0001u)
/*----SARAM22SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM22SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_RESETVAL (0x0001u)
/*----SARAM21SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_RESETVAL (0x0001u)
/*----SARAM21SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM21SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_RESETVAL (0x0001u)
/*----SARAM20SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_RESETVAL (0x0001u)
/*----SARAM20SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM20SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_RESETVAL (0x0001u)
/*----SARAM19SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_RESETVAL (0x0001u)
/*----SARAM19SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM19SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_RESETVAL (0x0001u)
/*----SARAM18SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_RESETVAL (0x0001u)
/*----SARAM18SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM18SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_RESETVAL (0x0001u)
/*----SARAM17SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_RESETVAL (0x0001u)
/*----SARAM17SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM17SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_RESETVAL (0x0001u)
/*----SARAM16SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_RESETVAL (0x0001u)
/*----SARAM16SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR4_SARAM16SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR4_RESETVAL  (0xFFFFu)

/* RAMSLPMDCNTLR5 */

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_RESETVAL (0x0001u)
/*----SARAM31SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_RESETVAL (0x0001u)
/*----SARAM31SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM31SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_RESETVAL (0x0001u)
/*----SARAM30SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_RESETVAL (0x0001u)
/*----SARAM30SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM30SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_RESETVAL (0x0001u)
/*----SARAM29SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_RESETVAL (0x0001u)
/*----SARAM29SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM29SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_RESETVAL (0x0001u)
/*----SARAM28SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_RESETVAL (0x0001u)
/*----SARAM28SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM28SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_RESETVAL (0x0001u)
/*----SARAM27SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_RESETVAL (0x0001u)
/*----SARAM27SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM27SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_RESETVAL (0x0001u)
/*----SARAM26SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_RESETVAL (0x0001u)
/*----SARAM26SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM26SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_RESETVAL (0x0001u)
/*----SARAM25SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_RESETVAL (0x0001u)
/*----SARAM25SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM25SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_RESETVAL (0x0001u)
/*----SARAM24SLPZVDD Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVDD_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_RESETVAL (0x0001u)
/*----SARAM24SLPZVSS Tokens----*/
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_ENABLED (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR5_SARAM24SLPZVSS_DISABLED (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR5_RESETVAL  (0xFFFFu)

/* PSSCR1 */

#define CSL_SYS_PSSCR1_DIVRNGADJ_MASK    (0xFE00u)
#define CSL_SYS_PSSCR1_DIVRNGADJ_SHIFT   (0x0009u)
#define CSL_SYS_PSSCR1_DIVRNGADJ_RESETVAL (0x0000u)

#define CSL_SYS_PSSCR1_LOOPBWADJ_MASK    (0x01FFu)
#define CSL_SYS_PSSCR1_LOOPBWADJ_SHIFT   (0x0000u)
#define CSL_SYS_PSSCR1_LOOPBWADJ_RESETVAL (0x0007u)

#define CSL_SYS_PSSCR1_RESETVAL          (0x0007u)

/* PSSCR2 */

#define CSL_SYS_PSSCR2_SPRDFRQ_MASK      (0xFE00u)
#define CSL_SYS_PSSCR2_SPRDFRQ_SHIFT     (0x0009u)
#define CSL_SYS_PSSCR2_SPRDFRQ_RESETVAL  (0x0000u)

#define CSL_SYS_PSSCR2_SPRDSLP_MASK      (0x01FFu)
#define CSL_SYS_PSSCR2_SPRDSLP_SHIFT     (0x0000u)
#define CSL_SYS_PSSCR2_SPRDSLP_RESETVAL  (0x0000u)

#define CSL_SYS_PSSCR2_RESETVAL          (0x0000u)

/* DMAIFR */

#define CSL_SYS_DMAIFR_DMA3CH3IF_MASK    (0x8000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIFR_DMA3CH3IF_RESETVAL (0x0000u)
/*----DMA3CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH2IF_MASK    (0x4000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIFR_DMA3CH2IF_RESETVAL (0x0000u)
/*----DMA3CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH1IF_MASK    (0x2000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SHIFT   (0x000Du)
#define CSL_SYS_DMAIFR_DMA3CH1IF_RESETVAL (0x0000u)
/*----DMA3CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH0IF_MASK    (0x1000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIFR_DMA3CH0IF_RESETVAL (0x0000u)
/*----DMA3CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH3IF_MASK    (0x0800u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIFR_DMA2CH3IF_RESETVAL (0x0000u)
/*----DMA2CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH2IF_MASK    (0x0400u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SHIFT   (0x000Au)
#define CSL_SYS_DMAIFR_DMA2CH2IF_RESETVAL (0x0000u)
/*----DMA2CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH1IF_MASK    (0x0200u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SHIFT   (0x0009u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_RESETVAL (0x0000u)
/*----DMA2CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH0IF_MASK    (0x0100u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SHIFT   (0x0008u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_RESETVAL (0x0000u)
/*----DMA2CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH3IF_MASK    (0x0080u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SHIFT   (0x0007u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_RESETVAL (0x0000u)
/*----DMA1CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH2IF_MASK    (0x0040u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SHIFT   (0x0006u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_RESETVAL (0x0000u)
/*----DMA1CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH1IF_MASK    (0x0020u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SHIFT   (0x0005u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_RESETVAL (0x0000u)
/*----DMA1CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH0IF_MASK    (0x0010u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SHIFT   (0x0004u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_RESETVAL (0x0000u)
/*----DMA1CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH3IF_MASK    (0x0008u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SHIFT   (0x0003u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_RESETVAL (0x0000u)
/*----DMA0CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH2IF_MASK    (0x0004u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SHIFT   (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_RESETVAL (0x0000u)
/*----DMA0CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH1IF_MASK    (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SHIFT   (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_RESETVAL (0x0000u)
/*----DMA0CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH0IF_MASK    (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SHIFT   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_RESETVAL (0x0000u)
/*----DMA0CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_RESETVAL          (0x0000u)

/* DMAIER */

#define CSL_SYS_DMAIER_DMA3CH3IE_MASK    (0x8000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIER_DMA3CH3IE_RESETVAL (0x0000u)
/*----DMA3CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH2IE_MASK    (0x4000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIER_DMA3CH2IE_RESETVAL (0x0000u)
/*----DMA3CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH1IE_MASK    (0x2000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_SHIFT   (0x000Du)
#define CSL_SYS_DMAIER_DMA3CH1IE_RESETVAL (0x0000u)
/*----DMA3CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH0IE_MASK    (0x1000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIER_DMA3CH0IE_RESETVAL (0x0000u)
/*----DMA3CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH3IE_MASK    (0x0800u)
#define CSL_SYS_DMAIER_DMA2CH3IE_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIER_DMA2CH3IE_RESETVAL (0x0000u)
/*----DMA2CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH2IE_MASK    (0x0400u)
#define CSL_SYS_DMAIER_DMA2CH2IE_SHIFT   (0x000Au)
#define CSL_SYS_DMAIER_DMA2CH2IE_RESETVAL (0x0000u)
/*----DMA2CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH1IE_MASK    (0x0200u)
#define CSL_SYS_DMAIER_DMA2CH1IE_SHIFT   (0x0009u)
#define CSL_SYS_DMAIER_DMA2CH1IE_RESETVAL (0x0000u)
/*----DMA2CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH0IE_MASK    (0x0100u)
#define CSL_SYS_DMAIER_DMA2CH0IE_SHIFT   (0x0008u)
#define CSL_SYS_DMAIER_DMA2CH0IE_RESETVAL (0x0000u)
/*----DMA2CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH3IE_MASK    (0x0080u)
#define CSL_SYS_DMAIER_DMA1CH3IE_SHIFT   (0x0007u)
#define CSL_SYS_DMAIER_DMA1CH3IE_RESETVAL (0x0000u)
/*----DMA1CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH2IE_MASK    (0x0040u)
#define CSL_SYS_DMAIER_DMA1CH2IE_SHIFT   (0x0006u)
#define CSL_SYS_DMAIER_DMA1CH2IE_RESETVAL (0x0000u)
/*----DMA1CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH1IE_MASK    (0x0020u)
#define CSL_SYS_DMAIER_DMA1CH1IE_SHIFT   (0x0005u)
#define CSL_SYS_DMAIER_DMA1CH1IE_RESETVAL (0x0000u)
/*----DMA1CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH0IE_MASK    (0x0010u)
#define CSL_SYS_DMAIER_DMA1CH0IE_SHIFT   (0x0004u)
#define CSL_SYS_DMAIER_DMA1CH0IE_RESETVAL (0x0000u)
/*----DMA1CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH3IE_MASK    (0x0008u)
#define CSL_SYS_DMAIER_DMA0CH3IE_SHIFT   (0x0003u)
#define CSL_SYS_DMAIER_DMA0CH3IE_RESETVAL (0x0000u)
/*----DMA0CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH2IE_MASK    (0x0004u)
#define CSL_SYS_DMAIER_DMA0CH2IE_SHIFT   (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH2IE_RESETVAL (0x0000u)
/*----DMA0CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH1IE_MASK    (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH1IE_SHIFT   (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH1IE_RESETVAL (0x0000u)
/*----DMA0CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH0IE_MASK    (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH0IE_SHIFT   (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_RESETVAL (0x0000u)
/*----DMA0CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_RESETVAL          (0x0000u)

/* USBSCR */

#define CSL_SYS_USBSCR_USBPWDN_MASK      (0x8000u)
#define CSL_SYS_USBSCR_USBPWDN_SHIFT     (0x000Fu)
#define CSL_SYS_USBSCR_USBPWDN_RESETVAL  (0x0001u)
/*----USBPWDN Tokens----*/
#define CSL_SYS_USBSCR_USBPWDN_POWERED   (0x0000u)
#define CSL_SYS_USBSCR_USBPWDN_PWRDN     (0x0001u)

#define CSL_SYS_USBSCR_USBSESSEND_MASK   (0x4000u)
#define CSL_SYS_USBSCR_USBSESSEND_SHIFT  (0x000Eu)
#define CSL_SYS_USBSCR_USBSESSEND_RESETVAL (0x0000u)
/*----USBSESSEND Tokens----*/
#define CSL_SYS_USBSCR_USBSESSEND_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBSESSEND_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBVBUSDET_MASK   (0x2000u)
#define CSL_SYS_USBSCR_USBVBUSDET_SHIFT  (0x000Du)
#define CSL_SYS_USBSCR_USBVBUSDET_RESETVAL (0x0001u)
/*----USBVBUSDET Tokens----*/
#define CSL_SYS_USBSCR_USBVBUSDET_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBVBUSDET_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBPLLEN_MASK     (0x1000u)
#define CSL_SYS_USBSCR_USBPLLEN_SHIFT    (0x000Cu)
#define CSL_SYS_USBSCR_USBPLLEN_RESETVAL (0x0000u)
/*----USBPLLEN Tokens----*/
#define CSL_SYS_USBSCR_USBPLLEN_NORMAL   (0x0000u)
#define CSL_SYS_USBSCR_USBPLLEN_FORCEON  (0x0001u)


#define CSL_SYS_USBSCR_USBDATPOL_MASK    (0x0040u)
#define CSL_SYS_USBSCR_USBDATPOL_SHIFT   (0x0006u)
#define CSL_SYS_USBSCR_USBDATPOL_RESETVAL (0x0001u)
/*----USBDATPOL Tokens----*/
#define CSL_SYS_USBSCR_USBDATPOL_REVERSE (0x0000u)
#define CSL_SYS_USBSCR_USBDATPOL_NORMAL  (0x0001u)


#define CSL_SYS_USBSCR_USBOSCBIASDIS_MASK (0x0008u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_SHIFT (0x0003u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_RESETVAL (0x0001u)
/*----USBOSCBIASDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCBIASDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_USBOSCDIS_MASK    (0x0004u)
#define CSL_SYS_USBSCR_USBOSCDIS_SHIFT   (0x0002u)
#define CSL_SYS_USBSCR_USBOSCDIS_RESETVAL (0x0001u)
/*----USBOSCDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_BYTEMODE_MASK     (0x0003u)
#define CSL_SYS_USBSCR_BYTEMODE_SHIFT    (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_RESETVAL (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_USBSCR_BYTEMODE_FULL     (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_UPPER    (0x0001u)
#define CSL_SYS_USBSCR_BYTEMODE_LOWER    (0x0002u)
#define CSL_SYS_USBSCR_BYTEMODE_RSV      (0x0003u)

#define CSL_SYS_USBSCR_RESETVAL          (0xA04Cu)

/* ESCR */


#define CSL_SYS_ESCR_BYTEMODE_MASK       (0x0003u)
#define CSL_SYS_ESCR_BYTEMODE_SHIFT      (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_RESETVAL   (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_ESCR_BYTEMODE_FULL       (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_UPPER      (0x0001u)
#define CSL_SYS_ESCR_BYTEMODE_LOWER      (0x0002u)
#define CSL_SYS_ESCR_BYTEMODE_RSV        (0x0003u)

#define CSL_SYS_ESCR_RESETVAL            (0x0000u)

/* BMR */


#define CSL_SYS_BMR_BMA_MASK             (0x07E0u)
#define CSL_SYS_BMR_BMA_SHIFT            (0x0005u)
#define CSL_SYS_BMR_BMA_RESETVAL         (0x0000u)


#define CSL_SYS_BMR_RESETVAL             (0x0000u)

/* DMA2CESR1 */


#define CSL_SYS_DMA2CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RESETVAL (0x0000u)
/*----CH1EVT Tokens----*/
#define CSL_SYS_DMA2CESR1_CH1EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA2CESR1_CH1EVT_I2CTX   (0x0001u)
#define CSL_SYS_DMA2CESR1_CH1EVT_I2CRX   (0x0002u)
#define CSL_SYS_DMA2CESR1_CH1EVT_SARAD   (0x0003u)
#define CSL_SYS_DMA2CESR1_CH1EVT_I2S3TX  (0x0004u)
#define CSL_SYS_DMA2CESR1_CH1EVT_I2S3RX  (0x0005u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES0    (0x0006u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES1    (0x0007u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES2    (0x0008u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES3    (0x0009u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES4    (0x000au)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES5    (0x000bu)
#define CSL_SYS_DMA2CESR1_CH1EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA2CESR1_CH1EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA2CESR1_CH1EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA2CESR1_CH1EVT_RES6    (0x000fu)


#define CSL_SYS_DMA2CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RESETVAL (0x0000u)
/*----CH0EVT Tokens----*/
#define CSL_SYS_DMA2CESR1_CH0EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA2CESR1_CH0EVT_I2CTX   (0x0001u)
#define CSL_SYS_DMA2CESR1_CH0EVT_I2CRX   (0x0002u)
#define CSL_SYS_DMA2CESR1_CH0EVT_SARAD   (0x0003u)
#define CSL_SYS_DMA2CESR1_CH0EVT_I2S3TX  (0x0004u)
#define CSL_SYS_DMA2CESR1_CH0EVT_I2S3RX  (0x0005u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES0    (0x0006u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES1    (0x0007u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES2    (0x0008u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES3    (0x0009u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES4    (0x000au)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES5    (0x000bu)
#define CSL_SYS_DMA2CESR1_CH0EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA2CESR1_CH0EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA2CESR1_CH0EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA2CESR1_CH0EVT_RES6    (0x000fu)

#define CSL_SYS_DMA2CESR1_RESETVAL       (0x0000u)

/* DMA2CESR2 */


#define CSL_SYS_DMA2CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RESETVAL (0x0000u)
/*----CH3EVT Tokens----*/
#define CSL_SYS_DMA2CESR2_CH3EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA2CESR2_CH3EVT_I2CTX   (0x0001u)
#define CSL_SYS_DMA2CESR2_CH3EVT_I2CRX   (0x0002u)
#define CSL_SYS_DMA2CESR2_CH3EVT_SARAD   (0x0003u)
#define CSL_SYS_DMA2CESR2_CH3EVT_I2S3TX  (0x0004u)
#define CSL_SYS_DMA2CESR2_CH3EVT_I2S3RX  (0x0005u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES0    (0x0006u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES1    (0x0007u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES2    (0x0008u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES3    (0x0009u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES4    (0x000au)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES5    (0x000bu)
#define CSL_SYS_DMA2CESR2_CH3EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA2CESR2_CH3EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA2CESR2_CH3EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA2CESR2_CH3EVT_RES6    (0x000fu)


#define CSL_SYS_DMA2CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RESETVAL (0x0000u)
/*----CH2EVT Tokens----*/
#define CSL_SYS_DMA2CESR2_CH2EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA2CESR2_CH2EVT_I2CTX   (0x0001u)
#define CSL_SYS_DMA2CESR2_CH2EVT_I2CRX   (0x0002u)
#define CSL_SYS_DMA2CESR2_CH2EVT_SARAD   (0x0003u)
#define CSL_SYS_DMA2CESR2_CH2EVT_I2S3TX  (0x0004u)
#define CSL_SYS_DMA2CESR2_CH2EVT_I2S3RX  (0x0005u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES0    (0x0006u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES1    (0x0007u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES2    (0x0008u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES3    (0x0009u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES4    (0x000au)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES5    (0x000bu)
#define CSL_SYS_DMA2CESR2_CH2EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA2CESR2_CH2EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA2CESR2_CH2EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA2CESR2_CH2EVT_RES6    (0x000fu)

#define CSL_SYS_DMA2CESR2_RESETVAL       (0x0000u)

/* DMA3CESR1 */


#define CSL_SYS_DMA3CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RESETVAL (0x0000u)
/*----CH1EVT Tokens----*/
#define CSL_SYS_DMA3CESR1_CH1EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA3CESR1_CH1EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA3CESR1_CH1EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA3CESR1_CH1EVT_MCBSPTXA (0x0003u)
#define CSL_SYS_DMA3CESR1_CH1EVT_MCBSPRXA (0x0004u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES0    (0x0005u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES1    (0x0006u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES2    (0x0007u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES3    (0x0008u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES4    (0x0009u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES5    (0x000au)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES6    (0x000bu)
#define CSL_SYS_DMA3CESR1_CH1EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA3CESR1_CH1EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA3CESR1_CH1EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA3CESR1_CH1EVT_RES7    (0x000fu)


#define CSL_SYS_DMA3CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RESETVAL (0x0000u)
/*----CH0EVT Tokens----*/
#define CSL_SYS_DMA3CESR1_CH0EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA3CESR1_CH0EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA3CESR1_CH0EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA3CESR1_CH0EVT_MCBSPTXA (0x0003u)
#define CSL_SYS_DMA3CESR1_CH0EVT_MCBSPRXA (0x0004u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES0    (0x0005u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES1    (0x0006u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES2    (0x0007u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES3    (0x0008u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES4    (0x0009u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES5    (0x000au)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES6    (0x000bu)
#define CSL_SYS_DMA3CESR1_CH0EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA3CESR1_CH0EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA3CESR1_CH0EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA3CESR1_CH0EVT_RES7    (0x000fu)

#define CSL_SYS_DMA3CESR1_RESETVAL       (0x0000u)

/* DMA3CESR2 */


#define CSL_SYS_DMA3CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RESETVAL (0x0000u)
/*----CH3EVT Tokens----*/
#define CSL_SYS_DMA3CESR2_CH3EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA3CESR2_CH3EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA3CESR2_CH3EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA3CESR2_CH3EVT_MCBSPTXA (0x0003u)
#define CSL_SYS_DMA3CESR2_CH3EVT_MCBSPRXA (0x0004u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES0    (0x0005u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES1    (0x0006u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES2    (0x0007u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES3    (0x0008u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES4    (0x0009u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES5    (0x000au)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES6    (0x000bu)
#define CSL_SYS_DMA3CESR2_CH3EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA3CESR2_CH3EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA3CESR2_CH3EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA3CESR2_CH3EVT_RES7    (0x000fu)


#define CSL_SYS_DMA3CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RESETVAL (0x0000u)
/*----CH2EVT Tokens----*/
#define CSL_SYS_DMA3CESR2_CH2EVT_NEVT    (0x0000u)
#define CSL_SYS_DMA3CESR2_CH2EVT_MCBSPTX (0x0001u)
#define CSL_SYS_DMA3CESR2_CH2EVT_MCBSPRX (0x0002u)
#define CSL_SYS_DMA3CESR2_CH2EVT_MCBSPTXA (0x0003u)
#define CSL_SYS_DMA3CESR2_CH2EVT_MCBSPRXA (0x0004u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES0    (0x0005u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES1    (0x0006u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES2    (0x0007u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES3    (0x0008u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES4    (0x0009u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES5    (0x000au)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES6    (0x000bu)
#define CSL_SYS_DMA3CESR2_CH2EVT_TIM0EVT (0x000cu)
#define CSL_SYS_DMA3CESR2_CH2EVT_TIM1EVT (0x000du)
#define CSL_SYS_DMA3CESR2_CH2EVT_TIM2EVT (0x000eu)
#define CSL_SYS_DMA3CESR2_CH2EVT_RES7    (0x000fu)

#define CSL_SYS_DMA3CESR2_RESETVAL       (0x0000u)

/* CLKSTOP1 */


#define CSL_SYS_CLKSTOP1_UHPICLKSTPACK_MASK (0x0800u)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPACK_SHIFT (0x000Bu)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPACK_RESETVAL (0x0000u)
/*----UHPICLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP1_UHPICLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP1_UHPICLKSTPREQ_MASK (0x0400u)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPREQ_SHIFT (0x000Au)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPREQ_RESETVAL (0x0000u)
/*----UHPICLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP1_UHPICLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP1_UHPICLKSTPREQ_REQ (0x0001u)


#define CSL_SYS_CLKSTOP1_MBPCLKSTPACK_MASK (0x0080u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPACK_SHIFT (0x0007u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPACK_RESETVAL (0x0000u)
/*----MBPCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP1_MBPCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP1_MBPCLKSTPREQ_MASK (0x0040u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPREQ_SHIFT (0x0006u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPREQ_RESETVAL (0x0000u)
/*----MBPCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP1_MBPCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP1_MBPCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP1_URTCLKSTPACK_MASK (0x0020u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPACK_SHIFT (0x0005u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPACK_RESETVAL (0x0000u)
/*----URTCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP1_URTCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP1_URTCLKSTPREQ_MASK (0x0010u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPREQ_SHIFT (0x0004u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPREQ_RESETVAL (0x0000u)
/*----URTCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP1_URTCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP1_URTCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP1_USBCLKSTPACK_MASK (0x0008u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPACK_SHIFT (0x0003u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPACK_RESETVAL (0x0000u)
/*----USBCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP1_USBCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP1_USBCLKSTPREQ_MASK (0x0004u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPREQ_SHIFT (0x0002u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPREQ_RESETVAL (0x0000u)
/*----USBCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP1_USBCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP1_USBCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP1_EMIFCLKSTPACK_MASK (0x0002u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPACK_SHIFT (0x0001u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPACK_RESETVAL (0x0000u)
/*----EMIFCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP1_EMIFCLKSTPREQ_MASK (0x0001u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPREQ_SHIFT (0x0000u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPREQ_RESETVAL (0x0000u)
/*----EMIFCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP1_EMIFCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP1_RESETVAL        (0x0000u)

/* CLKSTOP2 */


#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPACK_MASK (0x0010u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPACK_SHIFT (0x0004u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPACK_RESETVAL (0x0000u)
/*----MSPBRIDGECLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPREQ_MASK (0x0008u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPREQ_SHIFT (0x0003u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPREQ_RESETVAL (0x0000u)
/*----MSPBRIDGECLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP2_MSPBRIDGECLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP2_MSPCLKSTPACK_MASK (0x0006u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPACK_SHIFT (0x0001u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPACK_RESETVAL (0x0000u)
/*----MSPCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP2_MSPCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP2_MSPCLKSTPREQ_MASK (0x0001u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPREQ_SHIFT (0x0000u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPREQ_RESETVAL (0x0000u)
/*----MSPCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP2_MSPCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP2_MSPCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP2_RESETVAL        (0x0000u)

/* MSPIFCDR */

#define CSL_SYS_MSPIFCDR_OCDIV_MASK      (0xC000u)
#define CSL_SYS_MSPIFCDR_OCDIV_SHIFT     (0x000Eu)
#define CSL_SYS_MSPIFCDR_OCDIV_RESETVAL  (0x0001u)

#define CSL_SYS_MSPIFCDR_RSV_MASK        (0x3FF0u)
#define CSL_SYS_MSPIFCDR_RSV_SHIFT       (0x0004u)
#define CSL_SYS_MSPIFCDR_RSV_RESETVAL    (0x0000u)

#define CSL_SYS_MSPIFCDR_FCDIV_MASK      (0x000Fu)
#define CSL_SYS_MSPIFCDR_FCDIV_SHIFT     (0x0000u)
#define CSL_SYS_MSPIFCDR_FCDIV_RESETVAL  (0x0000u)

#define CSL_SYS_MSPIFCDR_RESETVAL        (0x4000u)

/* MSIAER */


#define CSL_SYS_MSIAER_MSWAKEUPEN_MASK   (0x0002u)
#define CSL_SYS_MSIAER_MSWAKEUPEN_SHIFT  (0x0001u)
#define CSL_SYS_MSIAER_MSWAKEUPEN_RESETVAL (0x0000u)
/*----MSWAKEUPEN Tokens----*/
#define CSL_SYS_MSIAER_MSWAKEUPEN_DISABLE (0x0000u)
#define CSL_SYS_MSIAER_MSWAKEUPEN_ENABLE (0x0001u)

#define CSL_SYS_MSIAER_MSINTEN_MASK      (0x0001u)
#define CSL_SYS_MSIAER_MSINTEN_SHIFT     (0x0000u)
#define CSL_SYS_MSIAER_MSINTEN_RESETVAL  (0x0000u)
/*----MSINTEN Tokens----*/
#define CSL_SYS_MSIAER_MSINTEN_DISABLE   (0x0000u)
#define CSL_SYS_MSIAER_MSINTEN_ENABLE    (0x0001u)

#define CSL_SYS_MSIAER_RESETVAL          (0x0000u)

/* TISR */

#define CSL_SYS_TISR_RSV_MASK            (0xFFF8u)
#define CSL_SYS_TISR_RSV_SHIFT           (0x0003u)
#define CSL_SYS_TISR_RSV_RESETVAL        (0x0000u)

#define CSL_SYS_TISR_TINT2SEL_MASK       (0x0004u)
#define CSL_SYS_TISR_TINT2SEL_SHIFT      (0x0002u)
#define CSL_SYS_TISR_TINT2SEL_RESETVAL   (0x0000u)
/*----TINT2SEL Tokens----*/
#define CSL_SYS_TISR_TINT2SEL_TINT       (0x0000u)
#define CSL_SYS_TISR_TINT2SEL_NMI        (0x0001u)

#define CSL_SYS_TISR_TINT1SEL_MASK       (0x0002u)
#define CSL_SYS_TISR_TINT1SEL_SHIFT      (0x0001u)
#define CSL_SYS_TISR_TINT1SEL_RESETVAL   (0x0000u)
/*----TINT1SEL Tokens----*/
#define CSL_SYS_TISR_TINT1SEL_TINT       (0x0000u)
#define CSL_SYS_TISR_TINT1SEL_NMI        (0x0001u)

#define CSL_SYS_TISR_TINT0SEL_MASK       (0x0001u)
#define CSL_SYS_TISR_TINT0SEL_SHIFT      (0x0000u)
#define CSL_SYS_TISR_TINT0SEL_RESETVAL   (0x0000u)
/*----TINT0SEL Tokens----*/
#define CSL_SYS_TISR_TINT0SEL_TINT       (0x0000u)
#define CSL_SYS_TISR_TINT0SEL_NMI        (0x0001u)

#define CSL_SYS_TISR_RESETVAL            (0x0000u)

/* DIEIDR0 */

#define CSL_SYS_DIEIDR0_DIEID0_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR0_DIEID0_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR0_DIEID0_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR0_RESETVAL         (0x0000u)

/* DIEIDR1 */


#define CSL_SYS_DIEIDR1_DIEID1_MASK      (0x3FFFu)
#define CSL_SYS_DIEIDR1_DIEID1_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR1_DIEID1_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR1_RESETVAL         (0x0000u)

/* DIEIDR2 */

#define CSL_SYS_DIEIDR2_DIEID2_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR2_DIEID2_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR2_DIEID2_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR2_RESETVAL         (0x0000u)

/* DIEIDR3 */

#define CSL_SYS_DIEIDR3_DESIGNREV_MASK   (0xF000u)
#define CSL_SYS_DIEIDR3_DESIGNREV_SHIFT  (0x000Cu)
#define CSL_SYS_DIEIDR3_DESIGNREV_RESETVAL (0x0005u)

#define CSL_SYS_DIEIDR3_DIEID3_MASK      (0x0FFFu)
#define CSL_SYS_DIEIDR3_DIEID3_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR3_DIEID3_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR3_RESETVAL         (0x5000u)

/* DIEIDR4 */


#define CSL_SYS_DIEIDR4_DIEID4_MASK      (0x003Fu)
#define CSL_SYS_DIEIDR4_DIEID4_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR4_DIEID4_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR4_RESETVAL         (0x0000u)

/* DIEIDR5 */


#define CSL_SYS_DIEIDR5_RESETVAL         (0x0000u)

/* DIEIDR6 */


#define CSL_SYS_DIEIDR6_RESETVAL         (0x0000u)

/* DIEIDR7 */


#define CSL_SYS_DIEIDR7_CHECKSUM_MASK    (0x7FFEu)
#define CSL_SYS_DIEIDR7_CHECKSUM_SHIFT   (0x0001u)
#define CSL_SYS_DIEIDR7_CHECKSUM_RESETVAL (0x0000u)


#define CSL_SYS_DIEIDR7_RESETVAL         (0x0000u)

/* PDINHIBR4 */

#define CSL_SYS_PDINHIBR4_D15PD_MASK     (0x8000u)
#define CSL_SYS_PDINHIBR4_D15PD_SHIFT    (0x000Fu)
#define CSL_SYS_PDINHIBR4_D15PD_RESETVAL (0x0000u)
/*----D15PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D14PD_MASK     (0x4000u)
#define CSL_SYS_PDINHIBR4_D14PD_SHIFT    (0x000Eu)
#define CSL_SYS_PDINHIBR4_D14PD_RESETVAL (0x0000u)
/*----D14PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D14PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D14PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D13PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR4_D13PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR4_D13PD_RESETVAL (0x0000u)
/*----D13PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D13PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D13PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D12PD_MASK     (0x1000u)
#define CSL_SYS_PDINHIBR4_D12PD_SHIFT    (0x000Cu)
#define CSL_SYS_PDINHIBR4_D12PD_RESETVAL (0x0000u)
/*----D12PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D12PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D12PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D11PD_MASK     (0x0800u)
#define CSL_SYS_PDINHIBR4_D11PD_SHIFT    (0x000Bu)
#define CSL_SYS_PDINHIBR4_D11PD_RESETVAL (0x0000u)
/*----D11PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D11PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D11PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D10PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR4_D10PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR4_D10PD_RESETVAL (0x0000u)
/*----D10PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D10PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR4_D10PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR4_D9PD_MASK      (0x0200u)
#define CSL_SYS_PDINHIBR4_D9PD_SHIFT     (0x0009u)
#define CSL_SYS_PDINHIBR4_D9PD_RESETVAL  (0x0000u)
/*----D9PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D9PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D9PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D8PD_MASK      (0x0100u)
#define CSL_SYS_PDINHIBR4_D8PD_SHIFT     (0x0008u)
#define CSL_SYS_PDINHIBR4_D8PD_RESETVAL  (0x0000u)
/*----D8PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D8PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D8PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D7PD_MASK      (0x0080u)
#define CSL_SYS_PDINHIBR4_D7PD_SHIFT     (0x0007u)
#define CSL_SYS_PDINHIBR4_D7PD_RESETVAL  (0x0000u)
/*----D7PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D7PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D7PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D6PD_MASK      (0x0040u)
#define CSL_SYS_PDINHIBR4_D6PD_SHIFT     (0x0006u)
#define CSL_SYS_PDINHIBR4_D6PD_RESETVAL  (0x0000u)
/*----D6PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D6PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D6PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D5PD_MASK      (0x0020u)
#define CSL_SYS_PDINHIBR4_D5PD_SHIFT     (0x0005u)
#define CSL_SYS_PDINHIBR4_D5PD_RESETVAL  (0x0000u)
/*----D5PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D5PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D5PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D4PD_MASK      (0x0010u)
#define CSL_SYS_PDINHIBR4_D4PD_SHIFT     (0x0004u)
#define CSL_SYS_PDINHIBR4_D4PD_RESETVAL  (0x0000u)
/*----D4PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D4PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D4PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D3PD_MASK      (0x0008u)
#define CSL_SYS_PDINHIBR4_D3PD_SHIFT     (0x0003u)
#define CSL_SYS_PDINHIBR4_D3PD_RESETVAL  (0x0000u)
/*----D3PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D3PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D3PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D2PD_MASK      (0x0004u)
#define CSL_SYS_PDINHIBR4_D2PD_SHIFT     (0x0002u)
#define CSL_SYS_PDINHIBR4_D2PD_RESETVAL  (0x0000u)
/*----D2PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D2PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D2PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D1PD_MASK      (0x0002u)
#define CSL_SYS_PDINHIBR4_D1PD_SHIFT     (0x0001u)
#define CSL_SYS_PDINHIBR4_D1PD_RESETVAL  (0x0000u)
/*----D1PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D1PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D1PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_D0PD_MASK      (0x0001u)
#define CSL_SYS_PDINHIBR4_D0PD_SHIFT     (0x0000u)
#define CSL_SYS_PDINHIBR4_D0PD_RESETVAL  (0x0000u)
/*----D0PD Tokens----*/
#define CSL_SYS_PDINHIBR4_D0PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR4_D0PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR4_RESETVAL       (0x0000u)

/* PDINHIBR5 */


#define CSL_SYS_PDINHIBR5_A14PD_MASK     (0x4000u)
#define CSL_SYS_PDINHIBR5_A14PD_SHIFT    (0x000Eu)
#define CSL_SYS_PDINHIBR5_A14PD_RESETVAL (0x0000u)
/*----A14PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A14PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR5_A14PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR5_A13PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR5_A13PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR5_A13PD_RESETVAL (0x0000u)
/*----A13PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A13PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR5_A13PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR5_A12PD_MASK     (0x1000u)
#define CSL_SYS_PDINHIBR5_A12PD_SHIFT    (0x000Cu)
#define CSL_SYS_PDINHIBR5_A12PD_RESETVAL (0x0000u)
/*----A12PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A12PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR5_A12PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR5_A11PD_MASK     (0x0800u)
#define CSL_SYS_PDINHIBR5_A11PD_SHIFT    (0x000Bu)
#define CSL_SYS_PDINHIBR5_A11PD_RESETVAL (0x0000u)
/*----A11PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A11PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR5_A11PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR5_A10PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR5_A10PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR5_A10PD_RESETVAL (0x0000u)
/*----A10PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A10PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR5_A10PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR5_A9PD_MASK      (0x0200u)
#define CSL_SYS_PDINHIBR5_A9PD_SHIFT     (0x0009u)
#define CSL_SYS_PDINHIBR5_A9PD_RESETVAL  (0x0000u)
/*----A9PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A9PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A9PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A8PD_MASK      (0x0100u)
#define CSL_SYS_PDINHIBR5_A8PD_SHIFT     (0x0008u)
#define CSL_SYS_PDINHIBR5_A8PD_RESETVAL  (0x0000u)
/*----A8PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A8PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A8PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A7PD_MASK      (0x0080u)
#define CSL_SYS_PDINHIBR5_A7PD_SHIFT     (0x0007u)
#define CSL_SYS_PDINHIBR5_A7PD_RESETVAL  (0x0000u)
/*----A7PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A7PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A7PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A6PD_MASK      (0x0040u)
#define CSL_SYS_PDINHIBR5_A6PD_SHIFT     (0x0006u)
#define CSL_SYS_PDINHIBR5_A6PD_RESETVAL  (0x0000u)
/*----A6PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A6PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A6PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A5PD_MASK      (0x0020u)
#define CSL_SYS_PDINHIBR5_A5PD_SHIFT     (0x0005u)
#define CSL_SYS_PDINHIBR5_A5PD_RESETVAL  (0x0000u)
/*----A5PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A5PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A5PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A4PD_MASK      (0x0010u)
#define CSL_SYS_PDINHIBR5_A4PD_SHIFT     (0x0004u)
#define CSL_SYS_PDINHIBR5_A4PD_RESETVAL  (0x0000u)
/*----A4PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A4PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A4PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A3PD_MASK      (0x0008u)
#define CSL_SYS_PDINHIBR5_A3PD_SHIFT     (0x0003u)
#define CSL_SYS_PDINHIBR5_A3PD_RESETVAL  (0x0000u)
/*----A3PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A3PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A3PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A2PD_MASK      (0x0004u)
#define CSL_SYS_PDINHIBR5_A2PD_SHIFT     (0x0002u)
#define CSL_SYS_PDINHIBR5_A2PD_RESETVAL  (0x0000u)
/*----A2PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A2PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A2PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A1PD_MASK      (0x0002u)
#define CSL_SYS_PDINHIBR5_A1PD_SHIFT     (0x0001u)
#define CSL_SYS_PDINHIBR5_A1PD_RESETVAL  (0x0000u)
/*----A1PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A1PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A1PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_A0PD_MASK      (0x0001u)
#define CSL_SYS_PDINHIBR5_A0PD_SHIFT     (0x0000u)
#define CSL_SYS_PDINHIBR5_A0PD_RESETVAL  (0x0000u)
/*----A0PD Tokens----*/
#define CSL_SYS_PDINHIBR5_A0PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR5_A0PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR5_RESETVAL       (0x0000u)

/* HPICR */


#define CSL_SYS_HPICR_BYTEADDR_MASK      (0x0004u)
#define CSL_SYS_HPICR_BYTEADDR_SHIFT     (0x0002u)
#define CSL_SYS_HPICR_BYTEADDR_RESETVAL  (0x0000u)
/*----BYTEADDR Tokens----*/
#define CSL_SYS_HPICR_BYTEADDR_WORD      (0x0000u)
#define CSL_SYS_HPICR_BYTEADDR_BYTE      (0x0001u)

#define CSL_SYS_HPICR_FULLWORD_MASK      (0x0002u)
#define CSL_SYS_HPICR_FULLWORD_SHIFT     (0x0001u)
#define CSL_SYS_HPICR_FULLWORD_RESETVAL  (0x0000u)
/*----FULLWORD Tokens----*/
#define CSL_SYS_HPICR_FULLWORD_16BIT     (0x0000u)
#define CSL_SYS_HPICR_FULLWORD_32BIT     (0x0001u)

#define CSL_SYS_HPICR_NMUX_MASK          (0x0001u)
#define CSL_SYS_HPICR_NMUX_SHIFT         (0x0000u)
#define CSL_SYS_HPICR_NMUX_RESETVAL      (0x0000u)
/*----NMUX Tokens----*/
#define CSL_SYS_HPICR_NMUX_MUX           (0x0000u)
#define CSL_SYS_HPICR_NMUX_NONMUX        (0x0001u)

#define CSL_SYS_HPICR_RESETVAL           (0x0000u)

/* PDINHIBR6 */


#define CSL_SYS_PDINHIBR6_NANDRDY1PD_MASK (0x4000u)
#define CSL_SYS_PDINHIBR6_NANDRDY1PD_SHIFT (0x000Eu)
#define CSL_SYS_PDINHIBR6_NANDRDY1PD_RESETVAL (0x0000u)
/*----NANDRDY1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_NANDRDY1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_NANDRDY1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_NANDRDY0PD_MASK (0x2000u)
#define CSL_SYS_PDINHIBR6_NANDRDY0PD_SHIFT (0x000Du)
#define CSL_SYS_PDINHIBR6_NANDRDY0PD_RESETVAL (0x0000u)
/*----NANDRDY0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_NANDRDY0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_NANDRDY0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_ASYNCRDY1PD_MASK (0x1000u)
#define CSL_SYS_PDINHIBR6_ASYNCRDY1PD_SHIFT (0x000Cu)
#define CSL_SYS_PDINHIBR6_ASYNCRDY1PD_RESETVAL (0x0000u)
/*----ASYNCRDY1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_ASYNCRDY1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_ASYNCRDY1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_ASYNCRDY0PD_MASK (0x0800u)
#define CSL_SYS_PDINHIBR6_ASYNCRDY0PD_SHIFT (0x000Bu)
#define CSL_SYS_PDINHIBR6_ASYNCRDY0PD_RESETVAL (0x0000u)
/*----ASYNCRDY0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_ASYNCRDY0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_ASYNCRDY0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_BA1PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR6_BA1PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR6_BA1PD_RESETVAL (0x0000u)
/*----BA1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_BA1PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR6_BA1PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR6_BA0PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR6_BA0PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR6_BA0PD_RESETVAL (0x0000u)
/*----BA0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_BA0PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR6_BA0PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR6_DQM1PD_MASK    (0x0100u)
#define CSL_SYS_PDINHIBR6_DQM1PD_SHIFT   (0x0008u)
#define CSL_SYS_PDINHIBR6_DQM1PD_RESETVAL (0x0000u)
/*----DQM1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_DQM1PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR6_DQM1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_DQM0PD_MASK    (0x0080u)
#define CSL_SYS_PDINHIBR6_DQM0PD_SHIFT   (0x0007u)
#define CSL_SYS_PDINHIBR6_DQM0PD_RESETVAL (0x0000u)
/*----DQM0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_DQM0PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR6_DQM0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_RNWPD_MASK     (0x0040u)
#define CSL_SYS_PDINHIBR6_RNWPD_SHIFT    (0x0006u)
#define CSL_SYS_PDINHIBR6_RNWPD_RESETVAL (0x0000u)
/*----RNWPD Tokens----*/
#define CSL_SYS_PDINHIBR6_RNWPD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR6_RNWPD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR6_OEPD_MASK      (0x0020u)
#define CSL_SYS_PDINHIBR6_OEPD_SHIFT     (0x0005u)
#define CSL_SYS_PDINHIBR6_OEPD_RESETVAL  (0x0000u)
/*----OEPD Tokens----*/
#define CSL_SYS_PDINHIBR6_OEPD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR6_OEPD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR6_WEPD_MASK      (0x0010u)
#define CSL_SYS_PDINHIBR6_WEPD_SHIFT     (0x0004u)
#define CSL_SYS_PDINHIBR6_WEPD_RESETVAL  (0x0000u)
/*----WEPD Tokens----*/
#define CSL_SYS_PDINHIBR6_WEPD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR6_WEPD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR6_NANDCE1PD_MASK (0x0008u)
#define CSL_SYS_PDINHIBR6_NANDCE1PD_SHIFT (0x0003u)
#define CSL_SYS_PDINHIBR6_NANDCE1PD_RESETVAL (0x0000u)
/*----NANDCE1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_NANDCE1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_NANDCE1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_NANDCE0PD_MASK (0x0004u)
#define CSL_SYS_PDINHIBR6_NANDCE0PD_SHIFT (0x0002u)
#define CSL_SYS_PDINHIBR6_NANDCE0PD_RESETVAL (0x0000u)
/*----NANDCE0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_NANDCE0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_NANDCE0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_ASYNCCE1PD_MASK (0x0002u)
#define CSL_SYS_PDINHIBR6_ASYNCCE1PD_SHIFT (0x0001u)
#define CSL_SYS_PDINHIBR6_ASYNCCE1PD_RESETVAL (0x0000u)
/*----ASYNCCE1PD Tokens----*/
#define CSL_SYS_PDINHIBR6_ASYNCCE1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_ASYNCCE1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_ASYNCCE0PD_MASK (0x0001u)
#define CSL_SYS_PDINHIBR6_ASYNCCE0PD_SHIFT (0x0000u)
#define CSL_SYS_PDINHIBR6_ASYNCCE0PD_RESETVAL (0x0000u)
/*----ASYNCCE0PD Tokens----*/
#define CSL_SYS_PDINHIBR6_ASYNCCE0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR6_ASYNCCE0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR6_RESETVAL       (0x0000u)

/* PDINHIBR7 */


#define CSL_SYS_PDINHIBR7_PCLKPD_MASK    (0x1000u)
#define CSL_SYS_PDINHIBR7_PCLKPD_SHIFT   (0x000Cu)
#define CSL_SYS_PDINHIBR7_PCLKPD_RESETVAL (0x0000u)
/*----PCLKPD Tokens----*/
#define CSL_SYS_PDINHIBR7_PCLKPD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR7_PCLKPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_PCNTL3PD_MASK  (0x0800u)
#define CSL_SYS_PDINHIBR7_PCNTL3PD_SHIFT (0x000Bu)
#define CSL_SYS_PDINHIBR7_PCNTL3PD_RESETVAL (0x0000u)
/*----PCNTL3PD Tokens----*/
#define CSL_SYS_PDINHIBR7_PCNTL3PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_PCNTL3PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_PCNTL2PD_MASK  (0x0400u)
#define CSL_SYS_PDINHIBR7_PCNTL2PD_SHIFT (0x000Au)
#define CSL_SYS_PDINHIBR7_PCNTL2PD_RESETVAL (0x0000u)
/*----PCNTL2PD Tokens----*/
#define CSL_SYS_PDINHIBR7_PCNTL2PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_PCNTL2PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_PCNTL1PD_MASK  (0x0200u)
#define CSL_SYS_PDINHIBR7_PCNTL1PD_SHIFT (0x0009u)
#define CSL_SYS_PDINHIBR7_PCNTL1PD_RESETVAL (0x0000u)
/*----PCNTL1PD Tokens----*/
#define CSL_SYS_PDINHIBR7_PCNTL1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_PCNTL1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_PCNTL0PD_MASK  (0x0100u)
#define CSL_SYS_PDINHIBR7_PCNTL0PD_SHIFT (0x0008u)
#define CSL_SYS_PDINHIBR7_PCNTL0PD_RESETVAL (0x0000u)
/*----PCNTL0PD Tokens----*/
#define CSL_SYS_PDINHIBR7_PCNTL0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_PCNTL0PD_DISABLE (0x0001u)


#define CSL_SYS_PDINHIBR7_SDCE1PD_MASK   (0x0020u)
#define CSL_SYS_PDINHIBR7_SDCE1PD_SHIFT  (0x0005u)
#define CSL_SYS_PDINHIBR7_SDCE1PD_RESETVAL (0x0000u)
/*----SDCE1PD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDCE1PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCE1PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_SDCE0PD_MASK   (0x0010u)
#define CSL_SYS_PDINHIBR7_SDCE0PD_SHIFT  (0x0004u)
#define CSL_SYS_PDINHIBR7_SDCE0PD_RESETVAL (0x0000u)
/*----SDCE0PD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDCE0PD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCE0PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_SDRASPD_MASK   (0x0008u)
#define CSL_SYS_PDINHIBR7_SDRASPD_SHIFT  (0x0003u)
#define CSL_SYS_PDINHIBR7_SDRASPD_RESETVAL (0x0000u)
/*----SDRASPD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDRASPD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDRASPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_SDCASPD_MASK   (0x0004u)
#define CSL_SYS_PDINHIBR7_SDCASPD_SHIFT  (0x0002u)
#define CSL_SYS_PDINHIBR7_SDCASPD_RESETVAL (0x0000u)
/*----SDCASPD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDCASPD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCASPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_SDCKEPD_MASK   (0x0002u)
#define CSL_SYS_PDINHIBR7_SDCKEPD_SHIFT  (0x0001u)
#define CSL_SYS_PDINHIBR7_SDCKEPD_RESETVAL (0x0000u)
/*----SDCKEPD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDCKEPD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCKEPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_SDCLKPD_MASK   (0x0001u)
#define CSL_SYS_PDINHIBR7_SDCLKPD_SHIFT  (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCLKPD_RESETVAL (0x0000u)
/*----SDCLKPD Tokens----*/
#define CSL_SYS_PDINHIBR7_SDCLKPD_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR7_SDCLKPD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR7_RESETVAL       (0x0000u)

/* JTAGIDLSW */

#define CSL_SYS_JTAGIDLSW_PARTCODE3DOWN0_MASK (0xF000u)
#define CSL_SYS_JTAGIDLSW_PARTCODE3DOWN0_SHIFT (0x000Cu)
#define CSL_SYS_JTAGIDLSW_PARTCODE3DOWN0_RESETVAL (0x0006u)

#define CSL_SYS_JTAGIDLSW_MFRID_MASK     (0x0FFEu)
#define CSL_SYS_JTAGIDLSW_MFRID_SHIFT    (0x0001u)
#define CSL_SYS_JTAGIDLSW_MFRID_RESETVAL (0x0017u)

#define CSL_SYS_JTAGIDLSW_AONE_MASK      (0x0001u)
#define CSL_SYS_JTAGIDLSW_AONE_SHIFT     (0x0000u)
#define CSL_SYS_JTAGIDLSW_AONE_RESETVAL  (0x0001u)

#define CSL_SYS_JTAGIDLSW_RESETVAL       (0x602Fu)

/* JTAGIDMSW */

#define CSL_SYS_JTAGIDMSW_VERSION_MASK   (0xF000u)
#define CSL_SYS_JTAGIDMSW_VERSION_SHIFT  (0x000Cu)
#define CSL_SYS_JTAGIDMSW_VERSION_RESETVAL (0x0000u)

#define CSL_SYS_JTAGIDMSW_PARTCODE15DOWN4_MASK (0x0FFFu)
#define CSL_SYS_JTAGIDMSW_PARTCODE15DOWN4_SHIFT (0x0000u)
#define CSL_SYS_JTAGIDMSW_PARTCODE15DOWN4_RESETVAL (0x0B95u)

#define CSL_SYS_JTAGIDMSW_RESETVAL       (0x0B95u)


/**************************************************************************\
* Field Definition Macros - VC5504/05
\**************************************************************************/
#else
/* EBSR */


#define CSL_SYS_EBSR_PPMODE_MASK         (0x7000u)
#define CSL_SYS_EBSR_PPMODE_SHIFT        (0x000Cu)
#define CSL_SYS_EBSR_PPMODE_RESETVAL     (0x0000u)
/*----PPMODE Tokens----*/
#define CSL_SYS_EBSR_PPMODE_MODE0        (0x0000u)
#define CSL_SYS_EBSR_PPMODE_MODE1        (0x0001u)
#define CSL_SYS_EBSR_PPMODE_MODE2        (0x0002u)
#define CSL_SYS_EBSR_PPMODE_MODE3        (0x0003u)
#define CSL_SYS_EBSR_PPMODE_MODE4        (0x0004u)
#define CSL_SYS_EBSR_PPMODE_MODE5        (0x0005u)
#define CSL_SYS_EBSR_PPMODE_MODE6        (0x0006u)
#define CSL_SYS_EBSR_PPMODE_MODE7        (0x0007u)

#define CSL_SYS_EBSR_SP1MODE_MASK        (0x0C00u)
#define CSL_SYS_EBSR_SP1MODE_SHIFT       (0x000Au)
#define CSL_SYS_EBSR_SP1MODE_RESETVAL    (0x0000u)
/*----SP1MODE Tokens----*/
#define CSL_SYS_EBSR_SP1MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP1MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP1MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP1MODE_MODE3       (0x0003u)

#define CSL_SYS_EBSR_SP0MODE_MASK        (0x0300u)
#define CSL_SYS_EBSR_SP0MODE_SHIFT       (0x0008u)
#define CSL_SYS_EBSR_SP0MODE_RESETVAL    (0x0000u)
/*----SP0MODE Tokens----*/
#define CSL_SYS_EBSR_SP0MODE_MODE0       (0x0000u)
#define CSL_SYS_EBSR_SP0MODE_MODE1       (0x0001u)
#define CSL_SYS_EBSR_SP0MODE_MODE2       (0x0002u)
#define CSL_SYS_EBSR_SP0MODE_MODE3       (0x0003u)


#define CSL_SYS_EBSR_A20_MODE_MASK       (0x0020u)
#define CSL_SYS_EBSR_A20_MODE_SHIFT      (0x0005u)
#define CSL_SYS_EBSR_A20_MODE_RESETVAL   (0x0000u)
/*----A20_MODE Tokens----*/
#define CSL_SYS_EBSR_A20_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A20_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A19_MODE_MASK       (0x0010u)
#define CSL_SYS_EBSR_A19_MODE_SHIFT      (0x0004u)
#define CSL_SYS_EBSR_A19_MODE_RESETVAL   (0x0000u)
/*----A19_MODE Tokens----*/
#define CSL_SYS_EBSR_A19_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A19_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A18_MODE_MASK       (0x0008u)
#define CSL_SYS_EBSR_A18_MODE_SHIFT      (0x0003u)
#define CSL_SYS_EBSR_A18_MODE_RESETVAL   (0x0000u)
/*----A18_MODE Tokens----*/
#define CSL_SYS_EBSR_A18_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A18_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A17_MODE_MASK       (0x0004u)
#define CSL_SYS_EBSR_A17_MODE_SHIFT      (0x0002u)
#define CSL_SYS_EBSR_A17_MODE_RESETVAL   (0x0000u)
/*----A17_MODE Tokens----*/
#define CSL_SYS_EBSR_A17_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A17_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A16_MODE_MASK       (0x0002u)
#define CSL_SYS_EBSR_A16_MODE_SHIFT      (0x0001u)
#define CSL_SYS_EBSR_A16_MODE_RESETVAL   (0x0000u)
/*----A16_MODE Tokens----*/
#define CSL_SYS_EBSR_A16_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A16_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_A15_MODE_MASK       (0x0001u)
#define CSL_SYS_EBSR_A15_MODE_SHIFT      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_RESETVAL   (0x0000u)
/*----A15_MODE Tokens----*/
#define CSL_SYS_EBSR_A15_MODE_MODE0      (0x0000u)
#define CSL_SYS_EBSR_A15_MODE_MODE1      (0x0001u)

#define CSL_SYS_EBSR_RESETVAL            (0x0000u)

/* PCGCR1 */

#define CSL_SYS_PCGCR1_SYSCLKDIS_MASK    (0x8000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_SHIFT   (0x000Fu)
#define CSL_SYS_PCGCR1_SYSCLKDIS_RESETVAL (0x0000u)
/*----SYSCLKDIS Tokens----*/
#define CSL_SYS_PCGCR1_SYSCLKDIS_ACTIVE  (0x0000u)
#define CSL_SYS_PCGCR1_SYSCLKDIS_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2S2CG_MASK       (0x4000u)
#define CSL_SYS_PCGCR1_I2S2CG_SHIFT      (0x000Eu)
#define CSL_SYS_PCGCR1_I2S2CG_RESETVAL   (0x0000u)
/*----I2S2CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR2CG_MASK       (0x2000u)
#define CSL_SYS_PCGCR1_TMR2CG_SHIFT      (0x000Du)
#define CSL_SYS_PCGCR1_TMR2CG_RESETVAL   (0x0000u)
/*----TMR2CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR1CG_MASK       (0x1000u)
#define CSL_SYS_PCGCR1_TMR1CG_SHIFT      (0x000Cu)
#define CSL_SYS_PCGCR1_TMR1CG_RESETVAL   (0x0000u)
/*----TMR1CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_EMIFCG_MASK       (0x0800u)
#define CSL_SYS_PCGCR1_EMIFCG_SHIFT      (0x000Bu)
#define CSL_SYS_PCGCR1_EMIFCG_RESETVAL   (0x0000u)
/*----EMIFCG Tokens----*/
#define CSL_SYS_PCGCR1_EMIFCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_EMIFCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_TMR0CG_MASK       (0x0400u)
#define CSL_SYS_PCGCR1_TMR0CG_SHIFT      (0x000Au)
#define CSL_SYS_PCGCR1_TMR0CG_RESETVAL   (0x0000u)
/*----TMR0CG Tokens----*/
#define CSL_SYS_PCGCR1_TMR0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_TMR0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_I2S1CG_MASK       (0x0200u)
#define CSL_SYS_PCGCR1_I2S1CG_SHIFT      (0x0009u)
#define CSL_SYS_PCGCR1_I2S1CG_RESETVAL   (0x0000u)
/*----I2S1CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_I2S0CG_MASK       (0x0100u)
#define CSL_SYS_PCGCR1_I2S0CG_SHIFT      (0x0008u)
#define CSL_SYS_PCGCR1_I2S0CG_RESETVAL   (0x0000u)
/*----I2S0CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_MMCSD1CG_MASK     (0x0080u)
#define CSL_SYS_PCGCR1_MMCSD1CG_SHIFT    (0x0007u)
#define CSL_SYS_PCGCR1_MMCSD1CG_RESETVAL (0x0000u)
/*----MMCSD1CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD1CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD1CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_I2CCG_MASK        (0x0040u)
#define CSL_SYS_PCGCR1_I2CCG_SHIFT       (0x0006u)
#define CSL_SYS_PCGCR1_I2CCG_RESETVAL    (0x0000u)
/*----I2CCG Tokens----*/
#define CSL_SYS_PCGCR1_I2CCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_I2CCG_DISABLED    (0x0001u)


#define CSL_SYS_PCGCR1_MMCSD0CG_MASK     (0x0010u)
#define CSL_SYS_PCGCR1_MMCSD0CG_SHIFT    (0x0004u)
#define CSL_SYS_PCGCR1_MMCSD0CG_RESETVAL (0x0000u)
/*----MMCSD0CG Tokens----*/
#define CSL_SYS_PCGCR1_MMCSD0CG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR1_MMCSD0CG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR1_DMA0CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR1_DMA0CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR1_DMA0CG_RESETVAL   (0x0000u)
/*----DMA0CG Tokens----*/
#define CSL_SYS_PCGCR1_DMA0CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_DMA0CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_UARTCG_MASK       (0x0004u)
#define CSL_SYS_PCGCR1_UARTCG_SHIFT      (0x0002u)
#define CSL_SYS_PCGCR1_UARTCG_RESETVAL   (0x0000u)
/*----UARTCG Tokens----*/
#define CSL_SYS_PCGCR1_UARTCG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_UARTCG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_SPICG_MASK        (0x0002u)
#define CSL_SYS_PCGCR1_SPICG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR1_SPICG_RESETVAL    (0x0000u)
/*----SPICG Tokens----*/
#define CSL_SYS_PCGCR1_SPICG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR1_SPICG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR1_I2S3CG_MASK       (0x0001u)
#define CSL_SYS_PCGCR1_I2S3CG_SHIFT      (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_RESETVAL   (0x0000u)
/*----I2S3CG Tokens----*/
#define CSL_SYS_PCGCR1_I2S3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR1_I2S3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR1_RESETVAL          (0x0000u)

/* PCGCR2 */


#define CSL_SYS_PCGCR2_ANAREGCG_MASK     (0x0040u)
#define CSL_SYS_PCGCR2_ANAREGCG_SHIFT    (0x0006u)
#define CSL_SYS_PCGCR2_ANAREGCG_RESETVAL (0x0000u)
/*----ANAREGCG Tokens----*/
#define CSL_SYS_PCGCR2_ANAREGCG_ACTIVE   (0x0000u)
#define CSL_SYS_PCGCR2_ANAREGCG_DISABLED (0x0001u)

#define CSL_SYS_PCGCR2_DMA3CG_MASK       (0x0020u)
#define CSL_SYS_PCGCR2_DMA3CG_SHIFT      (0x0005u)
#define CSL_SYS_PCGCR2_DMA3CG_RESETVAL   (0x0000u)
/*----DMA3CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA3CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA3CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA2CG_MASK       (0x0010u)
#define CSL_SYS_PCGCR2_DMA2CG_SHIFT      (0x0004u)
#define CSL_SYS_PCGCR2_DMA2CG_RESETVAL   (0x0000u)
/*----DMA2CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA2CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA2CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_DMA1CG_MASK       (0x0008u)
#define CSL_SYS_PCGCR2_DMA1CG_SHIFT      (0x0003u)
#define CSL_SYS_PCGCR2_DMA1CG_RESETVAL   (0x0000u)
/*----DMA1CG Tokens----*/
#define CSL_SYS_PCGCR2_DMA1CG_ACTIVE     (0x0000u)
#define CSL_SYS_PCGCR2_DMA1CG_DISABLED   (0x0001u)

#define CSL_SYS_PCGCR2_USBCG_MASK        (0x0004u)
#define CSL_SYS_PCGCR2_USBCG_SHIFT       (0x0002u)
#define CSL_SYS_PCGCR2_USBCG_RESETVAL    (0x0000u)
/*----USBCG Tokens----*/
#define CSL_SYS_PCGCR2_USBCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_USBCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_SARCG_MASK        (0x0002u)
#define CSL_SYS_PCGCR2_SARCG_SHIFT       (0x0001u)
#define CSL_SYS_PCGCR2_SARCG_RESETVAL    (0x0000u)
/*----SARCG Tokens----*/
#define CSL_SYS_PCGCR2_SARCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_SARCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_LCDCG_MASK        (0x0001u)
#define CSL_SYS_PCGCR2_LCDCG_SHIFT       (0x0000u)
#define CSL_SYS_PCGCR2_LCDCG_RESETVAL    (0x0000u)
/*----LCDCG Tokens----*/
#define CSL_SYS_PCGCR2_LCDCG_ACTIVE      (0x0000u)
#define CSL_SYS_PCGCR2_LCDCG_DISABLED    (0x0001u)

#define CSL_SYS_PCGCR2_RESETVAL          (0x0000u)

/* PSRCR */

#define CSL_SYS_PSRCR_COUNT_MASK         (0xFFFFu)
#define CSL_SYS_PSRCR_COUNT_SHIFT        (0x0000u)
#define CSL_SYS_PSRCR_COUNT_RESETVAL     (0x0000u)

#define CSL_SYS_PSRCR_RESETVAL           (0x0000u)

/* PRCR */


#define CSL_SYS_PRCR_PG4_RST_MASK        (0x0080u)
#define CSL_SYS_PRCR_PG4_RST_SHIFT       (0x0007u)
#define CSL_SYS_PRCR_PG4_RST_RESETVAL    (0x0000u)
/*----PG4_RST Tokens----*/
#define CSL_SYS_PRCR_PG4_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG4_RST_NRST        (0x0000u)


#define CSL_SYS_PRCR_PG3_RST_MASK        (0x0020u)
#define CSL_SYS_PRCR_PG3_RST_SHIFT       (0x0005u)
#define CSL_SYS_PRCR_PG3_RST_RESETVAL    (0x0000u)
/*----PG3_RST Tokens----*/
#define CSL_SYS_PRCR_PG3_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG3_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_DMA_RST_MASK        (0x0010u)
#define CSL_SYS_PRCR_DMA_RST_SHIFT       (0x0004u)
#define CSL_SYS_PRCR_DMA_RST_RESETVAL    (0x0000u)
/*----DMA_RST Tokens----*/
#define CSL_SYS_PRCR_DMA_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_DMA_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_USB_RST_MASK        (0x0008u)
#define CSL_SYS_PRCR_USB_RST_SHIFT       (0x0003u)
#define CSL_SYS_PRCR_USB_RST_RESETVAL    (0x0000u)
/*----USB_RST Tokens----*/
#define CSL_SYS_PRCR_USB_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_USB_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_PG1_RST_MASK        (0x0002u)
#define CSL_SYS_PRCR_PG1_RST_SHIFT       (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_RESETVAL    (0x0000u)
/*----PG1_RST Tokens----*/
#define CSL_SYS_PRCR_PG1_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_PG1_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_I2C_RST_MASK        (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_SHIFT       (0x0000u)
#define CSL_SYS_PRCR_I2C_RST_RESETVAL    (0x0000u)
/*----I2C_RST Tokens----*/
#define CSL_SYS_PRCR_I2C_RST_RST         (0x0001u)
#define CSL_SYS_PRCR_I2C_RST_NRST        (0x0000u)

#define CSL_SYS_PRCR_RESETVAL            (0x0000u)

/* TIAFR */


#define CSL_SYS_TIAFR_TIM2FLAG_MASK      (0x0004u)
#define CSL_SYS_TIAFR_TIM2FLAG_SHIFT     (0x0002u)
#define CSL_SYS_TIAFR_TIM2FLAG_RESETVAL  (0x0000u)
/*----TIM2FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM2FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM2FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM1FLAG_MASK      (0x0002u)
#define CSL_SYS_TIAFR_TIM1FLAG_SHIFT     (0x0001u)
#define CSL_SYS_TIAFR_TIM1FLAG_RESETVAL  (0x0000u)
/*----TIM1FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM1FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM1FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_TIM0FLAG_MASK      (0x0001u)
#define CSL_SYS_TIAFR_TIM0FLAG_SHIFT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_RESETVAL  (0x0000u)
/*----TIM0FLAG Tokens----*/
#define CSL_SYS_TIAFR_TIM0FLAG_NOINT     (0x0000u)
#define CSL_SYS_TIAFR_TIM0FLAG_INT       (0x0001u)

#define CSL_SYS_TIAFR_RESETVAL           (0x0000u)

/* ODSCR */


#define CSL_SYS_ODSCR_CLKOUTDS_MASK      (0x0004u)
#define CSL_SYS_ODSCR_CLKOUTDS_SHIFT     (0x0002u)
#define CSL_SYS_ODSCR_CLKOUTDS_RESETVAL  (0x0001u)
/*----CLKOUTDS Tokens----*/
#define CSL_SYS_ODSCR_CLKOUTDS_MIN       (0x0000u)
#define CSL_SYS_ODSCR_CLKOUTDS_MAX       (0x0001u)


#define CSL_SYS_ODSCR_EMIFDS_MASK        (0x0001u)
#define CSL_SYS_ODSCR_EMIFDS_SHIFT       (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_RESETVAL    (0x0001u)
/*----EMIFDS Tokens----*/
#define CSL_SYS_ODSCR_EMIFDS_MIN         (0x0000u)
#define CSL_SYS_ODSCR_EMIFDS_MAX         (0x0001u)

#define CSL_SYS_ODSCR_RESETVAL           (0x0005u)

/* PDINHIBR1 */

#define CSL_SYS_PDINHIBR1_S15PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S15PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S15PD_RESETVAL (0x0001u)
/*----S15PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S14PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S14PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S14PD_RESETVAL (0x0001u)
/*----S14PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S14PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S14PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S13PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S13PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S13PD_RESETVAL (0x0001u)
/*----S13PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S13PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S13PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S11PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S11PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S11PD_RESETVAL (0x0001u)
/*----S11PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S11PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S11PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S10PD_MASK     (0x2000u)
#define CSL_SYS_PDINHIBR1_S10PD_SHIFT    (0x000Du)
#define CSL_SYS_PDINHIBR1_S10PD_RESETVAL (0x0001u)
/*----S10PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S10PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S10PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_S5PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S5PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S5PD_RESETVAL  (0x0001u)
/*----S5PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S5PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S5PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S4PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S4PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S4PD_RESETVAL  (0x0001u)
/*----S4PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S4PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S4PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S3PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S3PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S3PD_RESETVAL  (0x0001u)
/*----S3PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S3PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S3PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S2PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S2PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S2PD_RESETVAL  (0x0001u)
/*----S2PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S2PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S2PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S1PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S1PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S1PD_RESETVAL  (0x0001u)
/*----S1PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S1PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S1PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S0PD_MASK      (0x2000u)
#define CSL_SYS_PDINHIBR1_S0PD_SHIFT     (0x000Du)
#define CSL_SYS_PDINHIBR1_S0PD_RESETVAL  (0x0001u)
/*----S0PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S0PD_ENABLE    (0x0000u)
#define CSL_SYS_PDINHIBR1_S0PD_DISABLE   (0x0001u)

#define CSL_SYS_PDINHIBR1_S12PD_MASK     (0x1000u)
#define CSL_SYS_PDINHIBR1_S12PD_SHIFT    (0x000Cu)
#define CSL_SYS_PDINHIBR1_S12PD_RESETVAL (0x0001u)
/*----S12PD Tokens----*/
#define CSL_SYS_PDINHIBR1_S12PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR1_S12PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR1_RESETVAL       (0x3000u)


/* PDINHIBR2 */


#define CSL_SYS_PDINHIBR2_INT1PU_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR2_INT1PU_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR2_INT1PU_RESETVAL (0x0001u)
/*----INT1PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT1PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT1PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_INT0PU_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR2_INT0PU_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR2_INT0PU_RESETVAL (0x0001u)
/*----INT0PU Tokens----*/
#define CSL_SYS_PDINHIBR2_INT0PU_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR2_INT0PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETPU_MASK   (0x1000u)
#define CSL_SYS_PDINHIBR2_RESETPU_SHIFT  (0x000Cu)
#define CSL_SYS_PDINHIBR2_RESETPU_RESETVAL (0x0000u)
/*----RESETPU Tokens----*/
#define CSL_SYS_PDINHIBR2_RESETPU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_RESETPU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_EMU01PU_MASK   (0x0800u)
#define CSL_SYS_PDINHIBR2_EMU01PU_SHIFT  (0x000Bu)
#define CSL_SYS_PDINHIBR2_EMU01PU_RESETVAL (0x0000u)
/*----EMU01PU Tokens----*/
#define CSL_SYS_PDINHIBR2_EMU01PU_ENABLE (0x0000u)
#define CSL_SYS_PDINHIBR2_EMU01PU_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR2_TDIPU_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR2_TDIPU_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR2_TDIPU_RESETVAL (0x0000u)
/*----TDIPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TDIPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TDIPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TMSPU_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR2_TMSPU_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR2_TMSPU_RESETVAL (0x0000u)
/*----TMSPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TMSPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TMSPU_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_TCKPU_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR2_TCKPU_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR2_TCKPU_RESETVAL (0x0000u)
/*----TCKPU Tokens----*/
#define CSL_SYS_PDINHIBR2_TCKPU_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_TCKPU_DISABLE  (0x0001u)


#define CSL_SYS_PDINHIBR2_A20PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR2_A20PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR2_A20PD_RESETVAL (0x0001u)
/*----A20PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A20PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A20PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A19PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR2_A19PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR2_A19PD_RESETVAL (0x0001u)
/*----A19PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A19PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A19PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A18PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR2_A18PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR2_A18PD_RESETVAL (0x0001u)
/*----A18PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A18PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A18PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A17PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR2_A17PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR2_A17PD_RESETVAL (0x0001u)
/*----A17PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A17PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A17PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A16PD_MASK     (0x0002u)
#define CSL_SYS_PDINHIBR2_A16PD_SHIFT    (0x0001u)
#define CSL_SYS_PDINHIBR2_A16PD_RESETVAL (0x0001u)
/*----A16PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A16PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A16PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_A15PD_MASK     (0x0001u)
#define CSL_SYS_PDINHIBR2_A15PD_SHIFT    (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_RESETVAL (0x0001u)
/*----A15PD Tokens----*/
#define CSL_SYS_PDINHIBR2_A15PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR2_A15PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR2_RESETVAL       (0x603Fu)

/* PDINHIBR3 */

#define CSL_SYS_PDINHIBR3_PD15PD_MASK    (0x8000u)
#define CSL_SYS_PDINHIBR3_PD15PD_SHIFT   (0x000Fu)
#define CSL_SYS_PDINHIBR3_PD15PD_RESETVAL (0x0000u)
/*----PD15PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD15PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD15PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD14PD_MASK    (0x4000u)
#define CSL_SYS_PDINHIBR3_PD14PD_SHIFT   (0x000Eu)
#define CSL_SYS_PDINHIBR3_PD14PD_RESETVAL (0x0001u)
/*----PD14PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD14PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD14PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD13PD_MASK    (0x2000u)
#define CSL_SYS_PDINHIBR3_PD13PD_SHIFT   (0x000Du)
#define CSL_SYS_PDINHIBR3_PD13PD_RESETVAL (0x0001u)
/*----PD13PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD13PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD13PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD11PD_MASK    (0x1000u)
#define CSL_SYS_PDINHIBR3_PD11PD_SHIFT   (0x000Cu)
#define CSL_SYS_PDINHIBR3_PD11PD_RESETVAL (0x0000u)
/*----PD11PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD11PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD11PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD10PD_MASK    (0x0800u)
#define CSL_SYS_PDINHIBR3_PD10PD_SHIFT   (0x000Bu)
#define CSL_SYS_PDINHIBR3_PD10PD_RESETVAL (0x0000u)
/*----PD10PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD10PD_ENABLE  (0x0000u)
#define CSL_SYS_PDINHIBR3_PD10PD_DISABLE (0x0001u)

#define CSL_SYS_PDINHIBR3_PD9PD_MASK     (0x0400u)
#define CSL_SYS_PDINHIBR3_PD9PD_SHIFT    (0x000Au)
#define CSL_SYS_PDINHIBR3_PD9PD_RESETVAL (0x0000u)
/*----PD9PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD9PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD9PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD8PD_MASK     (0x0200u)
#define CSL_SYS_PDINHIBR3_PD8PD_SHIFT    (0x0009u)
#define CSL_SYS_PDINHIBR3_PD8PD_RESETVAL (0x0000u)
/*----PD8PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD8PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD8PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD7PD_MASK     (0x0100u)
#define CSL_SYS_PDINHIBR3_PD7PD_SHIFT    (0x0008u)
#define CSL_SYS_PDINHIBR3_PD7PD_RESETVAL (0x0000u)
/*----PD7PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD7PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD7PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD6PD_MASK     (0x00C0u)
#define CSL_SYS_PDINHIBR3_PD6PD_SHIFT    (0x0006u)
#define CSL_SYS_PDINHIBR3_PD6PD_RESETVAL (0x0000u)
/*----PD6PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD6PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD6PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD5PD_MASK     (0x0020u)
#define CSL_SYS_PDINHIBR3_PD5PD_SHIFT    (0x0005u)
#define CSL_SYS_PDINHIBR3_PD5PD_RESETVAL (0x0001u)
/*----PD5PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD5PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD5PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD4PD_MASK     (0x0010u)
#define CSL_SYS_PDINHIBR3_PD4PD_SHIFT    (0x0004u)
#define CSL_SYS_PDINHIBR3_PD4PD_RESETVAL (0x0001u)
/*----PD4PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD4PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD4PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD3PD_MASK     (0x0008u)
#define CSL_SYS_PDINHIBR3_PD3PD_SHIFT    (0x0003u)
#define CSL_SYS_PDINHIBR3_PD3PD_RESETVAL (0x0001u)
/*----PD3PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD3PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD3PD_DISABLE  (0x0001u)

#define CSL_SYS_PDINHIBR3_PD2PD_MASK     (0x0004u)
#define CSL_SYS_PDINHIBR3_PD2PD_SHIFT    (0x0002u)
#define CSL_SYS_PDINHIBR3_PD2PD_RESETVAL (0x0001u)
/*----PD2PD Tokens----*/
#define CSL_SYS_PDINHIBR3_PD2PD_ENABLE   (0x0000u)
#define CSL_SYS_PDINHIBR3_PD2PD_DISABLE  (0x0001u)


#define CSL_SYS_PDINHIBR3_RESETVAL       (0x603Du)

/* DMA0CESR1 */


#define CSL_SYS_DMA0CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA0CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA0CESR1_RESETVAL       (0x0000u)

/* DMA0CESR2 */


#define CSL_SYS_DMA0CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA0CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA0CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA0CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA0CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA0CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA0CESR2_RESETVAL       (0x0000u)

/* DMA1CESR1 */


#define CSL_SYS_DMA1CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA1CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA1CESR1_RESETVAL       (0x0000u)

/* DMA1CESR2 */


#define CSL_SYS_DMA1CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA1CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA1CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA1CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA1CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA1CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA1CESR2_RESETVAL       (0x0000u)

/* CCR1 */

#define CSL_SYS_CCR1_RESETVAL            (0x0000u)

/* CCR2 */


#define CSL_SYS_CCR2_SYSCLKSRC_MASK      (0x0030u)
#define CSL_SYS_CCR2_SYSCLKSRC_SHIFT     (0x0004u)
#define CSL_SYS_CCR2_SYSCLKSRC_RESETVAL  (0x0000u)
/*----SYSCLKSRC Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSRC_BYPRTC    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKRTC   (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSRC_BYPCLKIN  (0x0002u)
#define CSL_SYS_CCR2_SYSCLKSRC_LOCKCLKIN (0x0004u)

#define CSL_SYS_CCR2_TIMER0CLKSEL_MASK   (0x0008u)
#define CSL_SYS_CCR2_TIMER0CLKSEL_SHIFT  (0x0003u)
#define CSL_SYS_CCR2_TIMER0CLKSEL_RESETVAL (0x0000u)
/*----TIMER0CLKSEL Tokens----*/
#define CSL_SYS_CCR2_TIMER0CLKSEL_SYSCLK (0x0000u)
#define CSL_SYS_CCR2_TIMER0CLKSEL_PLLOUT (0x0001u)

#define CSL_SYS_CCR2_CLKSELSTAT_MASK     (0x0004u)
#define CSL_SYS_CCR2_CLKSELSTAT_SHIFT    (0x0002u)
#define CSL_SYS_CCR2_CLKSELSTAT_RESETVAL (0x0000u)
/*----CLKSELSTAT Tokens----*/
#define CSL_SYS_CCR2_CLKSELSTAT_RTCIN    (0x0000u)
#define CSL_SYS_CCR2_CLKSELSTAT_CLKIN    (0x0001u)


#define CSL_SYS_CCR2_SYSCLKSEL_MASK      (0x0001u)
#define CSL_SYS_CCR2_SYSCLKSEL_SHIFT     (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_RESETVAL  (0x0000u)
/*----SYSCLKSEL Tokens----*/
#define CSL_SYS_CCR2_SYSCLKSEL_BYPASS    (0x0000u)
#define CSL_SYS_CCR2_SYSCLKSEL_LOCK      (0x0001u)

#define CSL_SYS_CCR2_RESETVAL            (0x0000u)

/* CGCR1 */

#define CSL_SYS_CGCR1_CLR_CNTL_MASK      (0x8000u)
#define CSL_SYS_CGCR1_CLR_CNTL_SHIFT     (0x000Fu)
#define CSL_SYS_CGCR1_CLR_CNTL_RESETVAL  (0x0000u)
/*----CLR_CNTL Tokens----*/
#define CSL_SYS_CGCR1_CLR_CNTL_CLEAR     (0x0000u)
#define CSL_SYS_CGCR1_CLR_CNTL_SET       (0x0001u)


#define CSL_SYS_CGCR1_PLL_STANDBY_MASK   (0x2000u)
#define CSL_SYS_CGCR1_PLL_STANDBY_SHIFT  (0x000Du)
#define CSL_SYS_CGCR1_PLL_STANDBY_RESETVAL (0x0000u)
/*----PLL_STANDBY Tokens----*/
#define CSL_SYS_CGCR1_PLL_STANDBY_ACTIVE (0x0000u)
#define CSL_SYS_CGCR1_PLL_STANDBY_STANDBY (0x0001u)

#define CSL_SYS_CGCR1_PLL_PWRDN_MASK     (0x1000u)
#define CSL_SYS_CGCR1_PLL_PWRDN_SHIFT    (0x000Cu)
#define CSL_SYS_CGCR1_PLL_PWRDN_RESETVAL (0x0001u)
/*----PLL_PWRDN Tokens----*/
#define CSL_SYS_CGCR1_PLL_PWRDN_POWERED  (0x0000u)
#define CSL_SYS_CGCR1_PLL_PWRDN_POWERDWN (0x0001u)

#define CSL_SYS_CGCR1_MH_MASK            (0x03FFu)
#define CSL_SYS_CGCR1_MH_SHIFT           (0x0000u)
#define CSL_SYS_CGCR1_MH_RESETVAL        (0x0000u)

#define CSL_SYS_CGCR1_RESETVAL           (0x1000u)


/* CGICR */

#define CSL_SYS_CGICR_RDBYPASS_MASK      (0x8000u)
#define CSL_SYS_CGICR_RDBYPASS_SHIFT     (0x000Fu)
#define CSL_SYS_CGICR_RDBYPASS_RESETVAL  (0x0000u)
/*----RDBYPASS Tokens----*/
#define CSL_SYS_CGICR_RDBYPASS_ENABLE    (0x0000u)
#define CSL_SYS_CGICR_RDBYPASS_BYPASS    (0x0001u)


#define CSL_SYS_CGICR_ML_MASK            (0x3000u)
#define CSL_SYS_CGICR_ML_SHIFT           (0x000Cu)
#define CSL_SYS_CGICR_ML_RESETVAL        (0x0000u)

#define CSL_SYS_CGICR_RDRATIO_MASK       (0x0FFFu)
#define CSL_SYS_CGICR_RDRATIO_SHIFT      (0x0000u)
#define CSL_SYS_CGICR_RDRATIO_RESETVAL   (0x0000u)

#define CSL_SYS_CGICR_RESETVAL           (0x0000u)

/* CGCR2 */

#define CSL_SYS_CGCR2_INIT_MASK          (0xFFFFu)
#define CSL_SYS_CGCR2_INIT_SHIFT         (0x0000u)
#define CSL_SYS_CGCR2_INIT_RESETVAL      (0x0832u)

#define CSL_SYS_CGCR2_RESETVAL           (0x0832u)

/* CGCR4 */

#define CSL_SYS_CGCR4_OUTDIVEN_MASK      (0x0200u)
#define CSL_SYS_CGCR4_OUTDIVEN_SHIFT     (0x0009u)
#define CSL_SYS_CGCR4_OUTDIVEN_RESETVAL  (0x0000u)
/*----OUTDIVEN Tokens----*/
#define CSL_SYS_CGCR4_OUTDIVEN_BYPASS    (0x0000u)
#define CSL_SYS_CGCR4_OUTDIVEN_ENABLE    (0x0001u)

#define CSL_SYS_CGCR4_OUTDIV2BYPASS_MASK (0x0100u)
#define CSL_SYS_CGCR4_OUTDIV2BYPASS_SHIFT (0x0008u)
#define CSL_SYS_CGCR4_OUTDIV2BYPASS_RESETVAL (0x0000u)
/*----OUTDIV2BYPASS Tokens----*/
#define CSL_SYS_CGCR4_OUTDIV2BYPASS_ENABLE (0x0000u)
#define CSL_SYS_CGCR4_OUTDIV2BYPASS_BYPASS (0x0001u)


#define CSL_SYS_CGCR4_ODRATIO_MASK       (0x003Fu)
#define CSL_SYS_CGCR4_ODRATIO_SHIFT      (0x0000u)
#define CSL_SYS_CGCR4_ODRATIO_RESETVAL   (0x0000u)

#define CSL_SYS_CGCR4_RESETVAL           (0x0000u)


#if (defined(CHIP_C5517))
/* CLKOUTCR */

#define CSL_SYS_CLKOUTCR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CLKOUTCR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CLKOUTCR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CLKOUTCR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CLKOUTCR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CLKOUTCR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CLKOUTCR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CLKOUTCR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CLKOUTCR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CLKOUTCR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CLKOUTCR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CLKOUTCR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CLKOUTCR_SRC_MODE10         (0x000au)
#define CSL_SYS_CLKOUTCR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CLKOUTCR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CLKOUTCR_SRC_MODE13         (0x000du)
#define CSL_SYS_CLKOUTCR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CLKOUTCR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CLKOUTCR_RESETVAL           (0x000Bu)

#else
/* CCSSR */


#define CSL_SYS_CCSSR_SRC_MASK           (0x000Fu)
#define CSL_SYS_CCSSR_SRC_SHIFT          (0x0000u)
#define CSL_SYS_CCSSR_SRC_RESETVAL       (0x000Bu)
/*----SRC Tokens----*/
#define CSL_SYS_CCSSR_SRC_MODE0          (0x0000u)
#define CSL_SYS_CCSSR_SRC_MODE1          (0x0001u)
#define CSL_SYS_CCSSR_SRC_MODE2          (0x0002u)
#define CSL_SYS_CCSSR_SRC_MODE3          (0x0003u)
#define CSL_SYS_CCSSR_SRC_MODE4          (0x0004u)
#define CSL_SYS_CCSSR_SRC_MODE5          (0x0005u)
#define CSL_SYS_CCSSR_SRC_MODE6          (0x0006u)
#define CSL_SYS_CCSSR_SRC_MODE7          (0x0007u)
#define CSL_SYS_CCSSR_SRC_MODE8          (0x0008u)
#define CSL_SYS_CCSSR_SRC_MODE9          (0x0009u)
#define CSL_SYS_CCSSR_SRC_MODE10         (0x000au)
#define CSL_SYS_CCSSR_SRC_MODE11         (0x000bu)
#define CSL_SYS_CCSSR_SRC_MODE12         (0x000cu)
#define CSL_SYS_CCSSR_SRC_MODE13         (0x000du)
#define CSL_SYS_CCSSR_SRC_MODE14         (0x000eu)
#define CSL_SYS_CCSSR_SRC_MODE15         (0x000fu)

#define CSL_SYS_CCSSR_RESETVAL           (0x000Bu)
#endif

/* ECDR */


#define CSL_SYS_ECDR_EDIV_MASK           (0x0001u)
#define CSL_SYS_ECDR_EDIV_SHIFT          (0x0000u)
#define CSL_SYS_ECDR_EDIV_RESETVAL       (0x0001u)
/*----EDIV Tokens----*/
#define CSL_SYS_ECDR_EDIV_HALFRATE       (0x0000u)
#define CSL_SYS_ECDR_EDIV_FULLRATE       (0x0001u)

#define CSL_SYS_ECDR_RESETVAL            (0x0001u)

/* RAMSLPMDCNTLR1 */

#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_SARAMSLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR1_DARAMSLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR1_RESETVAL  (0x000Fu)

/* RAMSLPMDCNTLR2 */

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVDD_MASK (0x8000u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVDD_SHIFT (0x000Fu)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVSS_MASK (0x4000u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVSS_SHIFT (0x000Eu)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG7SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVDD_MASK (0x2000u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVDD_SHIFT (0x000Du)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVSS_MASK (0x1000u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVSS_SHIFT (0x000Cu)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG6SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVDD_MASK (0x0800u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVDD_SHIFT (0x000Bu)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVSS_MASK (0x0400u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVSS_SHIFT (0x000Au)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG5SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVDD_MASK (0x0200u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVDD_SHIFT (0x0009u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVSS_MASK (0x0100u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVSS_SHIFT (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG4SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVDD_MASK (0x0080u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVDD_SHIFT (0x0007u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVSS_MASK (0x0040u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVSS_SHIFT (0x0006u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG3SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVDD_MASK (0x0020u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVDD_SHIFT (0x0005u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVSS_MASK (0x0010u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVSS_SHIFT (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG2SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVDD_MASK (0x0008u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVDD_SHIFT (0x0003u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVSS_MASK (0x0004u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVSS_SHIFT (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG1SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVDD_MASK (0x0002u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVDD_SHIFT (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVDD_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVSS_MASK (0x0001u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVSS_SHIFT (0x0000u)
#define CSL_SYS_RAMSLPMDCNTLR2_TSTPG0SLPZVSS_RESETVAL (0x0001u)

#define CSL_SYS_RAMSLPMDCNTLR2_RESETVAL  (0xFFFFu)

/* DMAIFR */

#define CSL_SYS_DMAIFR_DMA3CH3IF_MASK    (0x8000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIFR_DMA3CH3IF_RESETVAL (0x0000u)
/*----DMA3CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH2IF_MASK    (0x4000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIFR_DMA3CH2IF_RESETVAL (0x0000u)
/*----DMA3CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH1IF_MASK    (0x2000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SHIFT   (0x000Du)
#define CSL_SYS_DMAIFR_DMA3CH1IF_RESETVAL (0x0000u)
/*----DMA3CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA3CH0IF_MASK    (0x1000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIFR_DMA3CH0IF_RESETVAL (0x0000u)
/*----DMA3CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA3CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA3CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH3IF_MASK    (0x0800u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIFR_DMA2CH3IF_RESETVAL (0x0000u)
/*----DMA2CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH2IF_MASK    (0x0400u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SHIFT   (0x000Au)
#define CSL_SYS_DMAIFR_DMA2CH2IF_RESETVAL (0x0000u)
/*----DMA2CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH1IF_MASK    (0x0200u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SHIFT   (0x0009u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_RESETVAL (0x0000u)
/*----DMA2CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA2CH0IF_MASK    (0x0100u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SHIFT   (0x0008u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_RESETVAL (0x0000u)
/*----DMA2CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA2CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA2CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH3IF_MASK    (0x0080u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SHIFT   (0x0007u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_RESETVAL (0x0000u)
/*----DMA1CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH2IF_MASK    (0x0040u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SHIFT   (0x0006u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_RESETVAL (0x0000u)
/*----DMA1CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH1IF_MASK    (0x0020u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SHIFT   (0x0005u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_RESETVAL (0x0000u)
/*----DMA1CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA1CH0IF_MASK    (0x0010u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SHIFT   (0x0004u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_RESETVAL (0x0000u)
/*----DMA1CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA1CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA1CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH3IF_MASK    (0x0008u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SHIFT   (0x0003u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_RESETVAL (0x0000u)
/*----DMA0CH3IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH3IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH3IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH2IF_MASK    (0x0004u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SHIFT   (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_RESETVAL (0x0000u)
/*----DMA0CH2IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH2IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH2IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH1IF_MASK    (0x0002u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SHIFT   (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_RESETVAL (0x0000u)
/*----DMA0CH1IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH1IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH1IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_DMA0CH0IF_MASK    (0x0001u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SHIFT   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_RESETVAL (0x0000u)
/*----DMA0CH0IF Tokens----*/
#define CSL_SYS_DMAIFR_DMA0CH0IF_CLEAR   (0x0000u)
#define CSL_SYS_DMAIFR_DMA0CH0IF_SET     (0x0001u)

#define CSL_SYS_DMAIFR_RESETVAL          (0x0000u)

/* DMAIER */

#define CSL_SYS_DMAIER_DMA3CH3IE_MASK    (0x8000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_SHIFT   (0x000Fu)
#define CSL_SYS_DMAIER_DMA3CH3IE_RESETVAL (0x0000u)
/*----DMA3CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH2IE_MASK    (0x4000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_SHIFT   (0x000Eu)
#define CSL_SYS_DMAIER_DMA3CH2IE_RESETVAL (0x0000u)
/*----DMA3CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH1IE_MASK    (0x2000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_SHIFT   (0x000Du)
#define CSL_SYS_DMAIER_DMA3CH1IE_RESETVAL (0x0000u)
/*----DMA3CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA3CH0IE_MASK    (0x1000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_SHIFT   (0x000Cu)
#define CSL_SYS_DMAIER_DMA3CH0IE_RESETVAL (0x0000u)
/*----DMA3CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA3CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA3CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH3IE_MASK    (0x0800u)
#define CSL_SYS_DMAIER_DMA2CH3IE_SHIFT   (0x000Bu)
#define CSL_SYS_DMAIER_DMA2CH3IE_RESETVAL (0x0000u)
/*----DMA2CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH2IE_MASK    (0x0400u)
#define CSL_SYS_DMAIER_DMA2CH2IE_SHIFT   (0x000Au)
#define CSL_SYS_DMAIER_DMA2CH2IE_RESETVAL (0x0000u)
/*----DMA2CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH1IE_MASK    (0x0200u)
#define CSL_SYS_DMAIER_DMA2CH1IE_SHIFT   (0x0009u)
#define CSL_SYS_DMAIER_DMA2CH1IE_RESETVAL (0x0000u)
/*----DMA2CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA2CH0IE_MASK    (0x0100u)
#define CSL_SYS_DMAIER_DMA2CH0IE_SHIFT   (0x0008u)
#define CSL_SYS_DMAIER_DMA2CH0IE_RESETVAL (0x0000u)
/*----DMA2CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA2CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA2CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH3IE_MASK    (0x0080u)
#define CSL_SYS_DMAIER_DMA1CH3IE_SHIFT   (0x0007u)
#define CSL_SYS_DMAIER_DMA1CH3IE_RESETVAL (0x0000u)
/*----DMA1CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH2IE_MASK    (0x0040u)
#define CSL_SYS_DMAIER_DMA1CH2IE_SHIFT   (0x0006u)
#define CSL_SYS_DMAIER_DMA1CH2IE_RESETVAL (0x0000u)
/*----DMA1CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH1IE_MASK    (0x0020u)
#define CSL_SYS_DMAIER_DMA1CH1IE_SHIFT   (0x0005u)
#define CSL_SYS_DMAIER_DMA1CH1IE_RESETVAL (0x0000u)
/*----DMA1CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA1CH0IE_MASK    (0x0010u)
#define CSL_SYS_DMAIER_DMA1CH0IE_SHIFT   (0x0004u)
#define CSL_SYS_DMAIER_DMA1CH0IE_RESETVAL (0x0000u)
/*----DMA1CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA1CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA1CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH3IE_MASK    (0x0008u)
#define CSL_SYS_DMAIER_DMA0CH3IE_SHIFT   (0x0003u)
#define CSL_SYS_DMAIER_DMA0CH3IE_RESETVAL (0x0000u)
/*----DMA0CH3IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH3IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH3IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH2IE_MASK    (0x0004u)
#define CSL_SYS_DMAIER_DMA0CH2IE_SHIFT   (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH2IE_RESETVAL (0x0000u)
/*----DMA0CH2IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH2IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH2IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH1IE_MASK    (0x0002u)
#define CSL_SYS_DMAIER_DMA0CH1IE_SHIFT   (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH1IE_RESETVAL (0x0000u)
/*----DMA0CH1IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH1IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH1IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_DMA0CH0IE_MASK    (0x0001u)
#define CSL_SYS_DMAIER_DMA0CH0IE_SHIFT   (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_RESETVAL (0x0000u)
/*----DMA0CH0IE Tokens----*/
#define CSL_SYS_DMAIER_DMA0CH0IE_DISABLE (0x0000u)
#define CSL_SYS_DMAIER_DMA0CH0IE_ENABLE  (0x0001u)

#define CSL_SYS_DMAIER_RESETVAL          (0x0000u)

/* USBSCR */

#define CSL_SYS_USBSCR_USBPWDN_MASK      (0x8000u)
#define CSL_SYS_USBSCR_USBPWDN_SHIFT     (0x000Fu)
#define CSL_SYS_USBSCR_USBPWDN_RESETVAL  (0x0001u)
/*----USBPWDN Tokens----*/
#define CSL_SYS_USBSCR_USBPWDN_POWERED   (0x0000u)
#define CSL_SYS_USBSCR_USBPWDN_PWRDN     (0x0001u)

#define CSL_SYS_USBSCR_USBSESSEND_MASK   (0x4000u)
#define CSL_SYS_USBSCR_USBSESSEND_SHIFT  (0x000Eu)
#define CSL_SYS_USBSCR_USBSESSEND_RESETVAL (0x0000u)
/*----USBSESSEND Tokens----*/
#define CSL_SYS_USBSCR_USBSESSEND_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBSESSEND_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBVBUSDET_MASK   (0x2000u)
#define CSL_SYS_USBSCR_USBVBUSDET_SHIFT  (0x000Du)
#define CSL_SYS_USBSCR_USBVBUSDET_RESETVAL (0x0001u)
/*----USBVBUSDET Tokens----*/
#define CSL_SYS_USBSCR_USBVBUSDET_DISABLED (0x0000u)
#define CSL_SYS_USBSCR_USBVBUSDET_ENABLED (0x0001u)

#define CSL_SYS_USBSCR_USBPLLEN_MASK     (0x1000u)
#define CSL_SYS_USBSCR_USBPLLEN_SHIFT    (0x000Cu)
#define CSL_SYS_USBSCR_USBPLLEN_RESETVAL (0x0000u)
/*----USBPLLEN Tokens----*/
#define CSL_SYS_USBSCR_USBPLLEN_NORMAL   (0x0000u)
#define CSL_SYS_USBSCR_USBPLLEN_FORCEON  (0x0001u)


#define CSL_SYS_USBSCR_USBDATPOL_MASK    (0x0040u)
#define CSL_SYS_USBSCR_USBDATPOL_SHIFT   (0x0006u)
#define CSL_SYS_USBSCR_USBDATPOL_RESETVAL (0x0001u)
/*----USBDATPOL Tokens----*/
#define CSL_SYS_USBSCR_USBDATPOL_REVERSE (0x0000u)
#define CSL_SYS_USBSCR_USBDATPOL_NORMAL  (0x0001u)


#define CSL_SYS_USBSCR_USBOSCBIASDIS_MASK (0x0008u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_SHIFT (0x0003u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_RESETVAL (0x0001u)
/*----USBOSCBIASDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCBIASDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCBIASDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_USBOSCDIS_MASK    (0x0004u)
#define CSL_SYS_USBSCR_USBOSCDIS_SHIFT   (0x0002u)
#define CSL_SYS_USBSCR_USBOSCDIS_RESETVAL (0x0001u)
/*----USBOSCDIS Tokens----*/
#define CSL_SYS_USBSCR_USBOSCDIS_ENABLED (0x0000u)
#define CSL_SYS_USBSCR_USBOSCDIS_DISABLED (0x0001u)

#define CSL_SYS_USBSCR_BYTEMODE_MASK     (0x0003u)
#define CSL_SYS_USBSCR_BYTEMODE_SHIFT    (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_RESETVAL (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_USBSCR_BYTEMODE_FULL     (0x0000u)
#define CSL_SYS_USBSCR_BYTEMODE_UPPER    (0x0001u)
#define CSL_SYS_USBSCR_BYTEMODE_LOWER    (0x0002u)
#define CSL_SYS_USBSCR_BYTEMODE_RSV      (0x0003u)

#define CSL_SYS_USBSCR_RESETVAL          (0xA04Cu)

/* ESCR */


#define CSL_SYS_ESCR_BYTEMODE_MASK       (0x0003u)
#define CSL_SYS_ESCR_BYTEMODE_SHIFT      (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_RESETVAL   (0x0000u)
/*----BYTEMODE Tokens----*/
#define CSL_SYS_ESCR_BYTEMODE_FULL       (0x0000u)
#define CSL_SYS_ESCR_BYTEMODE_UPPER      (0x0001u)
#define CSL_SYS_ESCR_BYTEMODE_LOWER      (0x0002u)
#define CSL_SYS_ESCR_BYTEMODE_RSV        (0x0003u)

#define CSL_SYS_ESCR_RESETVAL            (0x0000u)

/* DMA2CESR1 */


#define CSL_SYS_DMA2CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA2CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA2CESR1_RESETVAL       (0x0000u)

/* DMA2CESR2 */


#define CSL_SYS_DMA2CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA2CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA2CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA2CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA2CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA2CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA2CESR2_RESETVAL       (0x0000u)

/* DMA3CESR1 */


#define CSL_SYS_DMA3CESR1_CH1EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR1_CH1EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR1_CH1EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA3CESR1_CH0EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR1_CH0EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR1_CH0EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA3CESR1_RESETVAL       (0x0000u)

/* DMA3CESR2 */


#define CSL_SYS_DMA3CESR2_CH3EVT_MASK    (0x0F00u)
#define CSL_SYS_DMA3CESR2_CH3EVT_SHIFT   (0x0008u)
#define CSL_SYS_DMA3CESR2_CH3EVT_RESETVAL (0x0000u)


#define CSL_SYS_DMA3CESR2_CH2EVT_MASK    (0x000Fu)
#define CSL_SYS_DMA3CESR2_CH2EVT_SHIFT   (0x0000u)
#define CSL_SYS_DMA3CESR2_CH2EVT_RESETVAL (0x0000u)

#define CSL_SYS_DMA3CESR2_RESETVAL       (0x0000u)

/* CLKSTOP */


#define CSL_SYS_CLKSTOP_URTCLKSTPACK_MASK (0x0020u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_SHIFT (0x0005u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_RESETVAL (0x0001u)
/*----URTCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_URTCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_MASK (0x0010u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_SHIFT (0x0004u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_RESETVAL (0x0001u)
/*----URTCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_URTCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_USBCLKSTPACK_MASK (0x0008u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_SHIFT (0x0003u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_RESETVAL (0x0001u)
/*----USBCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_USBCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_MASK (0x0004u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_SHIFT (0x0002u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_RESETVAL (0x0001u)
/*----USBCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_USBCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_MASK (0x0002u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_SHIFT (0x0001u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_RESETVAL (0x0001u)
/*----EMFCLKSTPACK Tokens----*/
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_NACK (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPACK_ACK (0x0001u)

#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_MASK (0x0001u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_SHIFT (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_RESETVAL (0x0001u)
/*----EMFCLKSTPREQ Tokens----*/
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_NREQ (0x0000u)
#define CSL_SYS_CLKSTOP_EMFCLKSTPREQ_REQ (0x0001u)

#define CSL_SYS_CLKSTOP_RESETVAL         (0x003Fu)

/* DIEIDR0 */

#define CSL_SYS_DIEIDR0_DIEID0_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR0_DIEID0_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR0_DIEID0_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR0_RESETVAL         (0x0000u)

/* DIEIDR1 */


#define CSL_SYS_DIEIDR1_DIEID1_MASK      (0x3FFFu)
#define CSL_SYS_DIEIDR1_DIEID1_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR1_DIEID1_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR1_RESETVAL         (0x0000u)

/* DIEIDR2 */

#define CSL_SYS_DIEIDR2_DIEID2_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR2_DIEID2_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR2_DIEID2_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR2_RESETVAL         (0x0000u)

/* DIEIDR3 */

#define CSL_SYS_DIEIDR3_DIEID3_MASK      (0xFFFFu)
#define CSL_SYS_DIEIDR3_DIEID3_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR3_DIEID3_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR3_RESETVAL         (0x0000u)

/* DIEIDR4 */

#define CSL_SYS_DIEIDR4_DIEID4_MASK      (0x003Fu)
#define CSL_SYS_DIEIDR4_DIEID4_SHIFT     (0x0000u)
#define CSL_SYS_DIEIDR4_DIEID4_RESETVAL  (0x0000u)

#define CSL_SYS_DIEIDR4_RESETVAL         (0x0000u)

#define CSL_SYS_DIEIDR4_RESETVAL         (0x0000u)

/* DIEIDR5 */


#define CSL_SYS_DIEIDR5_RESETVAL         (0x0000u)

/* DIEIDR6 */


#define CSL_SYS_DIEIDR6_RESETVAL         (0x0000u)

/* DIEIDR7 */


#define CSL_SYS_DIEIDR7_CHECKSUM_MASK    (0x7FFEu)
#define CSL_SYS_DIEIDR7_CHECKSUM_SHIFT   (0x0001u)
#define CSL_SYS_DIEIDR7_CHECKSUM_RESETVAL (0x0000u)


#define CSL_SYS_DIEIDR7_RESETVAL         (0x0000u)

#endif

#endif //_CSLR_SYSCTRL_H_
