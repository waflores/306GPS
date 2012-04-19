/******************************************************************************* 
 * File:  main.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: Implements Project 2b.
 * Description: This file contains the main function which allows the user
 *              to press buttons on the QSK board and have the LCD display
 *              words as per button presses.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       The Timers are cut in half as far as duration is concerned
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented main function
 *              2.0, Project 2a + Homework 5 improvements
 *              2.5, Project 2b
 *              2.9, Homework 8 Functionality
 * 
 * Created on March 26, 2012
 *******************************************************************************/

//#include <stdio.h>
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "serial.h"
#include "ports.h"
#include "helperfuncs.h"
#include "shapes.h"
#include "movement.h"
#include "IR.h"
#include "gps.h"

/*******************************************************************************
 * Purpose: This function allows the user to press a button which sends a string
 *          Via serial.
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void main(void) {
    /* Transmit String */
    char transmitStr[] = "NCSU #1";
    
    /* Watchdog timer would go here */
	
    /* Initialize the ports */
    init_ports();
	
    /* Initialize the System clock */
    system_clock_init();
    
    /* Initialize the display */
    InitDisplay("Project3");
	clearScreen();
    
    /* Initialize the interrupts */
    BNSPrintf(LCD, "\tStart\nInterrupts");
	DisplayDelay(DISPLAY_DELAY1);
	init_interrupts();
    clearScreen();
	
    /* Initialize the System timers */
    BNSPrintf(LCD, "\tStart\nTimers");
	DisplayDelay(DISPLAY_DELAY1);
    TimerInit();
	clearScreen();
    
    /* Initialize Serial ports */
    BNSPrintf(LCD, "\tStart\nSerial");
	DisplayDelay(DISPLAY_DELAY1);
    InitUART();
	clearScreen();
    
    /* Initialize AD converter */
    BNSPrintf(LCD, "\tStart\nADCs");
	DisplayDelay(DISPLAY_DELAY1);
    ADInit();
    clearScreen();
    
    /* Initialize the GPS */
    gps_init();
    
    while(FOREVER) {
        if (buttonPressed) {
            if((buttonPressed & SW1_PRESSED)) {
                /* Clear the bit */
                buttonPressed &= ~(SW1_PRESSED);
                /* Clear the screen */
                clearScreen();
                /* Send HW 8 string */
                transmitUART2(transmitStr);
            }
            else if ((buttonPressed & SW2_PRESSED)) {
                /* Clear the bit */
                buttonPressed &= ~(SW2_PRESSED);
                clearScreen();
            }
            else if ((buttonPressed & SW3_PRESSED)){
                /* Clear the bit */
                buttonPressed &= ~(SW3_PRESSED);
            }	
        }
        else {
            /* Process in the input and display the coordinates */
            gpsProcess();
            displayScroller(latGet, lonGet);
        }
    }
}
