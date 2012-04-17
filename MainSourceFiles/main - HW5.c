/******************************************************************************* 
 * File:  main.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: Implements Homework 4.
 * Description: This file contains the main function which allows the user
 *              to press buttons on the QSK board and have the LCD display
 *              words as per button presses.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       NONE
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented main function
 *              2.0, Project 2a + Homework 5 improvments
 * Created on March 12, 2012
 *******************************************************************************/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "ports.h"
#include "shapes.h"
#include "movement.h"
#define DEBOUNCE_DELAY  200     // 1 second delay
#define MOVEMENT_TURNS	3     // Go back & forth 3 times

/*******************************************************************************
 * Purpose: This function allows the user to press a button which lets the car
 *          travel in the desired directions.
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void main(void) {
	int i; // However many times we need to move 
	
    /* Watchdog timer would go here */
    /* Initialize the ports */
    init_ports();
    
    /* Initialize the interrupts */
    init_interrupts();
    
    /* Initialize the System clock */
    system_clock_init();
	
    /* Initialize the display */
    InitDisplay("Project2a");
	
    /* Initialize the System timers */
    TimerInit();
	
    /* Initialize Serial ports */
    InitUART();
	
    /* Initialize AD converter */
    ADInit();	
    
    // use timerA1_to debounce a button
    while(FOREVER) {
        if (buttonPressed) {
            if((buttonPressed & SW1_PRESSED) && !timerA1_started) {
                /* Clear the bit */
                buttonPressed &= ~(SW1_PRESSED);
                
                /* Debounce the buttons */
                timerDelay(DEBOUNCE_DELAY);
                BNSPrintf(LCD,"\tForward    \n      ");
                LED0 ^= LED_OFF;
                /* Set the time for the motors to move */
                /*
                for (i = MOVEMENT_TURNS; i > 0; --i) {
                    // go forward
                    set_lWheelCount(2*ONE_SECOND);
                    set_rWheelCount(2*ONE_SECOND);
                    start_wheelTimers();
                    move_forward();
                    while(timerB0_started || timerA0_started);
                    timerDelay(ONE_SECOND); // a second delay
                    while (timerA1_started);
                    
                    // Go Back some
                    set_lWheelCount(2*ONE_SECOND);
                    set_rWheelCount(2*ONE_SECOND);
                    start_wheelTimers();
                    move_reverse();
                    while(timerB0_started || timerA0_started);
                    timerDelay(ONE_SECOND); // a second delay
                    while (timerA1_started);
                }
                */
            }
            else if ((buttonPressed & SW2_PRESSED) && !timerA1_started) {
                /* Clear the bit */
                buttonPressed &= ~(SW2_PRESSED);
                
                /* Debounce the buttons */
                timerDelay(DEBOUNCE_DELAY);
                BNSPrintf(LCD, "\tOff      \n      ");
                /* Cut the motors off */
                LED1 ^= LED_OFF;
                //motors_off();
            }
            else if ((buttonPressed & SW3_PRESSED) && !timerA1_started){
                /* Clear the bit */
                buttonPressed &= ~(SW3_PRESSED);
                
                /* Debounce the buttons */
                timerDelay(DEBOUNCE_DELAY);
                BNSPrintf(LCD, "\tRight      \n      ");
                
                LED2 ^= LED_OFF;
                /* Set the time for the motors to move */
                /*for (i = MOVEMENT_TURNS; i > 0; --i) {
                    // go forward
                    set_lWheelCount(2*ONE_SECOND);
                    set_rWheelCount(2*ONE_SECOND);
                    start_wheelTimers();
                    move_reverse();
                    while(timerB0_started || timerA0_started);
                    timerDelay(ONE_SECOND); // a second delay
                    while (timerA1_started);
                    
                    // Go Back some
                    set_lWheelCount(2*ONE_SECOND);
                    set_rWheelCount(2*ONE_SECOND);
                    start_wheelTimers();
                    move_forward();
                    while(timerB0_started || timerA0_started);
                    timerDelay(ONE_SECOND); // a second delay
                    while (timerA1_started);
                }
                 */
            }	
            else {
                /* Don't do anything if buttons were not pressed */
                BNSPrintf(LCD, "\tOff       \n         ");
            }
        }
    } /* End while loop */
} /* End main function */
