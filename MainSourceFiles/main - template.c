/******************************************************************************* 
 * File:  main.c
 * Author: Will Flores waflores@ncsu.edu
 *
 * Usage: Implemented using a host of API in the headers
 * Description: This file contains the main function template
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       Template
 * Revisions:   0.0, Initial Release
 *
 * Created on XXX, XX, XXXX
 *******************************************************************************/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "ports.h"
#include "shapes.h"
#include "movement.h"
#define DEBOUNCE_DELAY  200     // 1 second delay
#define MOVEMENT_TURNS	3     // Go back & forth 3 times

int TempStore0 = 0x0000;		// Location where ADC ch0 result is stored
int TempStore1 = 0x0000;		// Location where ADC ch1 result is stored
int TempStore2 = 0x0000;		// Location where ADC ch2 result is stored
int TempStore3 = 0x0000;		// Location where ADC ch3 result is stored

/*******************************************************************************
 * Purpose: This function allows the user... 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void main(void) {
    /* Watchdog timer would go here */
	char purposeStr[] = "";
    /* Initialize the ports */
    init_ports();
    
    /* Initialize the interrupts */
    init_interrupts();
    
    /* Initialize the System clock */
    system_clock_init();
	
    /* Initialize the display */
    InitDisplay(purposeStr);
	
    /* Initialize the System timers */
    TimerInit();
	
    /* Initialize Serial ports */
    InitUART();
	
    /* Initialize AD converter */
    ADInit();	
    
    // use timerA1_to debounce a button
    while(FOREVER) {
   		TempStore0= ad0 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore1= ad1 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore2= ad2 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore3= ad3 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		// print the results on the display
		// Since the display is only 8 characters we need to display in hex, 3 characters wide
		// with a space in between each.  Channel 0 is upper left, Channel 1 is upper right
		// Channel 2 is lower left and Channel 3 is lower right
		BNSPrintf(LCD,"\t%03x %03x \n%03x %03x ",TempStore0,TempStore1,TempStore2,TempStore3);
		
		// now put the results to the serial port.
		BNSPrintf(SERIAL,"\n\r%03x %03x %03x %03x",TempStore0,TempStore1,TempStore2,TempStore3);
        }
    } /* End while loop */
} /* End main function */

void A2DInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:  This will init the A2D and put it in Sweep mode.  It will then start a converstion.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{	
	adcon0 = 0x98;
		      /*
  		      10011000;  	** Repeat sweep mode 0, soft trigger, fAD/2
		   	  ||||||||______Analog input select bit 0
		   	  |||||||_______Analog input select bit 1
		   	  ||||||________Analog input select bit 2
		  	  |||||_________A/D operation mode select bit 0
		   	  ||||__________A/D operation mode select bit 1
		   	  |||___________Trigger select bit
		   	  ||____________A/D conversion start flag
		  	  |_____________Frequency select bit 0 */

	adcon1 = 0x39;
		      /*
		      00111001;		** Scan AN0-AN3, 10-bit mode, fAD/2, Vref connected
		   	  ||||||||______A/D sweep pin select bit 0
		   	  |||||||_______A/D sweep pin select bit 1
		  	  ||||||________A/D operation mode select bit 1
		   	  |||||_________8/10 bit mode select bit
		   	  ||||__________Frequency select bit 1
		   	  |||___________Vref connect bit
		   	  ||____________External op-amp connection mode bit 0
		  	  |_____________External op-amp connection mode bit 1 */   

	adcon2 = 0x01;
		      /*
		      00000001;		** Sample and hold enabled, fAD/2
		  	  ||||||||______AD conversion method select bit
 	          |||||||_______AD input group select bit 0
		      ||||||________AD input group select bit 1
		      |||||_________Reserved
		      ||||__________Frequency select bit 2
		      |||___________Reserved
		      ||____________Reserved
		      |_____________Reserved */

    adst = 1;				// Start a conversion here
}
