/******************************************************************************* 
* File:  adc.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file initializes the A-to-D converter.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
*              2.0, Sets up ADC for Project 2b
* 
* Created on March 12, 2012
*******************************************************************************/

#include "QSKDefines.h"

/*******************************************************************************
* Purpose: Set up the A2D for Repeat Sweep Mode 0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void ADInit(void) {
    /* Configured using a Repeat Sweep Mode 0 setup*/
    adcon0 = REPEAT_SWEEP;
    
    adcon1 = CLEAR_REGISTER;
    adcon1 |= SWEEP_AN0_AN3;
    adcon1 |= CONNECT_VREF;
    adcon1 |= TEN_BIT_MODE;
    
    adcon2 = SAMPLE_AND_HOLD;

    adst = ADC_START;   // Start a conversion here
}   
