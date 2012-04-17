#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION : This file sets up the CPU including clock, PLL,      */
/* 	  				UART for debugging at 9600 N 8 1	               */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/


void MCUInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose: The starter kit startup file initializes the clock circuit
//           to the main crystal with a divide by 1.  This function also sets
//			 the main clock to divide by 1 in case the SKP startup file is not 
//			 used.  It then enables the PLL 
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	 unsigned int count = 40000;
  
	/* configure clock for divide by 1 mode */
	prc0 =1;					/* enable access to clock registers */
	cm1 = 0x20;					/* set CM16,CM17 divide ratio to 1, 
									main clock on in high drive no PLL*/
	cm06 = 0;					/* set divide ratio to 1 */		
	
    /* configure and switch main clock to PLL at 24MHz - uncomment this section
		out if PLL operation is desired								*/
   
	prc1 = 1;					/* allow writing to processor mode register */
	pm20 = 1;					/* set SFR access to 2 wait which is required for
   									operation greater than 16 MHz */
	prc1 = 0;					/* protect processor mode register */

	plc0= 0x92;					// enable PLL (2X) and turn on

	while(count > 0) count--;   /* wait for PLL to stabilize (20mS maximum, 240,000 cycles @12Mhz)
                                   this decrement with no optimization is 12 cycles each */
    cm11 = 1;                   /* switch to PLL */
    prc0 = 0;   				/* protect clock control register */
	
	prc1 = 1;
	pm10 = 1;		// enable data flash area
	prc1 = 0;
	
}




void InitUART(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:  Sets up UART1 for 9600 N 8 1 and is used for debug status messages.
//				It uses interrupts for receive.  Transmit is done through polling.
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------

{

	u0brg = (unsigned char)(((f1_CLK_SPEED/16)/BAUD_RATE)-1);	// set UART0 bit rate generator

		 /*
	  	  bit rate can be calculated by:
	  	  bit rate = ((BRG count source / 16)/baud rate) - 1

		  in this example: BRG count source = f1 (12MHz - Xin in SKP16C62P)
						   baud rate = 19200
						   bit rate = ((12MHz/16)/19200) - 1 = 38 

	  	  ** one has to remember that the value of BCLK does not affect BRG count source */

  	ucon = 0x00; 		// UART transmit/receive control register 2
		 /*
		  00000000; 	// transmit irq not used
		  ||||||||______UART0 transmit irq cause select bit, U0IRS
	   	  |||||||_______UART1 transmit irq cause select bit, U1IRS
	   	  ||||||________UART0 continuous receive mode enable bit, U0RRM - set to 0 in UART mode
	  	  |||||_________UART1 continuous receive mode enable bit, U1RRM	- set to 0 in UART mode
	   	  ||||__________CLK/CLKS select bit 0, CLKMD0 - set to 0 in UART mode
	   	  |||___________CLK/CLKS select bit 1, CLKMD1 - set to 0 in UART mode
	   	  ||____________Separate CTS/RTS bit, RCSP
	  	  |_____________Reserved, set to 0 */

  	u0c0 = 0x10; 		// UART0 transmit/receive control register 1
		 /*
		  00010000;		// f1 count source, CTS/RTS disabled, CMOS output  
		  ||||||||______BRG count source select bit, CLK0
	   	  |||||||_______BRG count source select bit, CLK1
	   	  ||||||________CTS/RTS function select bit, CRS
	  	  |||||_________Transmit register empty flag, TXEPT
	   	  ||||__________CTS/RTS disable bit, CRD
	   	  |||___________Data output select bit, NCH
	   	  ||____________CLK polarity select bit, CKPOL 		- set to 0 in UART mode
	  	  |_____________Transfer format select bit, UFORM 	- set to 0 in UART mode */

  	u0c1 = 0x00; 		// UART0 transmit/receive control register 1
		 /*
		  00000000;		// disable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */

  	u0mr = 0x05;		// UART0 transmit/receive mode register, not reversed
		 /*
		  00000101;		// 8-bit data, internal clock, 1 stop bit, no parity
		  ||||||||______Serial I/O Mode select bit, SMD0
	   	  |||||||_______Serial I/O Mode select bit, SMD1
	   	  ||||||________Serial I/O Mode select bit, SMD2
	  	  |||||_________Internal/External clock select bit, CKDIR
	   	  ||||__________Stop bit length select bit, STPS
	   	  |||___________Odd/even parity select bit, PRY
	   	  ||____________Parity enable bit, PRYE
	  	  |_____________TxD, RxD I/O polarity reverse bit */

  	u0tb = u0rb;		// clear UART0 receive buffer by reading
  	u0tb = 0;			// clear UART0 transmit buffer

    DISABLE_IRQ			// disable irqs before setting irq registers
	s0ric = 0x04;		// Enable UART0 receive interrupt, priority level 4	
	ENABLE_IRQ			// Enable all interrupts

  	u0c1 = 0x05; 		// UART0 transmit/receive control register 1
		 /*
		  00000101;		// enable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */
}
