/******************************************************************************* 
 * File:  led.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: This file makes the LEDS flash on the QSK Board.
 * Description: This is the main file for the project and contains most of the 
 *              project specific code.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       NONE
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented file and function headers
 * Created on March 12, 2012
 *******************************************************************************/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

int disp_count;         // LED control variable
uint A2DValue;
uint A2DValuePot;
uint A2DValueTherm;
uchar A2DProcessed;


/*******************************************************************************
* Purpose: Makes the LEDs scan back and forth.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void LEDDisplay(void) {
	/*
    switch (disp_count){
        case 1:                 
            LED0 = LED_OFF;			
            LED1 = LED_OFF;
            LED2 = LED_ON;
            break;
        case 2:                 
        case 4:
            LED0 = LED_OFF;			
            LED1 = LED_ON;
            LED2 = LED_OFF;
            break;
        case 3:                 
            LED0 = LED_ON;			
            LED1 = LED_OFF;
            LED2 = LED_OFF;
            break;
        default:                
            LED0 = LED_OFF;			
            LED1 = LED_OFF;
            LED2 = LED_OFF;
    }
	*/
}
