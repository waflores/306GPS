/******************************************************************************* 
 * File:  main.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: Implements Project 2b.
 * Description: This file contains the main function which allows the user
 *              to press buttons on the QSK board and have the LCD display
 *              words as per button presses.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       NONE
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented main function
 *              2.0, Project 2a + Homework 5 improvements
 *              2.5, Project 2b
 * 
 * Created on March 26, 2012
 *******************************************************************************/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "ports.h"
#include "shapes.h"
#include "movement.h"
#include "IR.h"

#define DISPLAY_DELAY (1000)

/*******************************************************************************
 * Purpose: This function allows the user to press a button which lets the car
 *          travel in the desired directions.
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void main(void) {
	/* counter var */
	int count = 0;
	
    /* Watchdog timer would go here */
	
    /* Initialize the ports */
    init_ports();
    
    /* Initialize the interrupts */
    init_interrupts();
    
    /* Initialize the System clock */
    system_clock_init();
	
    /* Initialize the display */
    InitDisplay("Project2");
	
    /* Initialize the System timers */
    TimerInit();
	
    /* Initialize Serial ports */
    InitUART();
	
    /* Initialize AD converter */
    ADInit();	
    
    while(FOREVER) {
        if (buttonPressed) {
            if((buttonPressed & SW1_PRESSED)) {
                /* Clear the bit */
                buttonPressed &= ~(SW1_PRESSED);
				/* Clear the screen */
				BNSPrintf(LCD, "\t                ");
                /* Move around */
                BNSPrintf(LCD, "\tMoving.\nAround..");
                moveBackandForth();
            }
            else if ((buttonPressed & SW2_PRESSED)) {
                /* Clear the bit */
                buttonPressed &= ~(SW2_PRESSED);
				BNSPrintf(LCD, "\tMotor toggle: %d", count);
				
                /* toggle motors */
                switch (count) {
					case 0:
						left_motor_forward();
						break;
					case 1:	
						left_motor_reverse();
						break;
					case 2:
						right_motor_forward();
						break;
					case 3:
						right_motor_reverse();
						break;
					default:
						count = 0;	
				}
				 ++count;
            }
            else if ((buttonPressed & SW3_PRESSED)){
                /* Clear the bit */
                buttonPressed &= ~(SW3_PRESSED);
                /* Calibrate the sensors */
                calibrateIR();
            }	
        }
        else {
            /* Display the calibrated value */
            BNSPrintf(LCD, "\tIR val: \n%03x     ", IR_threshold);
            DisplayDelay(DISPLAY_DELAY);
        }
    }
}
