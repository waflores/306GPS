/******************************************************************************* 
* File:  movement.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the functions that move the car back and
*              forth.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
*              2.0, Implements full H-Bridge capabilities
* Created on March 12, 2012
*******************************************************************************/

#include "movement.h"
#include "shapes.h"
#include "ports.h"
#include "QSKDefines.h"

/*******************************************************************************
* Purpose: Turns the left motor pin forward on - along with the left LED,
*          indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void left_motor_forward(void) {
    /* Check to see if Left Reverse Pin is active */
    if (is_left_reverse_on()) {
        left_motor_off();
    }
    /* Turn the Left Forward Pin on */
    p3_2 = LEFT_MOTOR_ON;
    LED0 = LED_ON; /* Left LED ON */
    return;
}

/*******************************************************************************
* Purpose: Turns the left motor pin reverse on - along with the left LED,
*          indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void left_motor_reverse(void) {
    /* Check to see if Left Forward Pin is active */
    if(is_left_forward_on()) {
        left_motor_off();
    }
    /* Turn the Left Reverse Pin on */
    p3_3 = LEFT_MOTOR_ON;
    LED0 = LED_ON; /* Left LED ON */
}

/*******************************************************************************
* Purpose: Turns the right motor pin forward on - along with the right LED,
*          indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void right_motor_forward(void) {
    /* Check to see if the Right Reverse Pin is on */
    if(is_right_reverse_on()) {
        right_motor_off();
    }
    
    /* Turn the Right Forward Pin on */
    p3_0 = RIGHT_MOTOR_ON;
    LED2 = LED_ON; /* Right LED ON */
    return;
}

/*******************************************************************************
* Purpose: Turns the right motor pin reverse on - along with the right LED,
*          indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void right_motor_reverse(void) {
    /* Check to see if the Reverse Forward Pin is on*/
    if(is_right_forward_on()) {
        right_motor_off();
    }
    
    /* Turn the Right Reverse Pin on */
    p3_1 = RIGHT_MOTOR_ON;
    LED2 = LED_ON; /* Right LED ON */
    return;
}

/*******************************************************************************
* Purpose: Turns both motors off.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void motors_off(void) {
    /* This is to kill the motor IO */
    right_motor_off();
    left_motor_off();
    return;
}


/*******************************************************************************
* Purpose: Turns right motor and LED off.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void right_motor_off(void) {
    p3_0 = RIGHT_MOTOR_OFF; /* R_FORWARD Pin */
    p3_1 = RIGHT_MOTOR_OFF; /* R_REVERSE Pin */
    LED2 = LED_OFF;
    return;
}

/*******************************************************************************
* Purpose: Turns left motor and LED off.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void left_motor_off(void) {
    p3_2 = LEFT_MOTOR_OFF; /* L_FORWARD Pin */
    p3_3 = LEFT_MOTOR_OFF; /* L_REVERSE Pin */
    LED0 = LED_OFF;
    return;
}

/*******************************************************************************
* Purpose: Turns both motors forward and LEDs on, indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void move_forward(void) {
    /* set the wheel counts and start the timer before proceeding */
    left_motor_forward();
    right_motor_forward();
    return;
}

/*******************************************************************************
* Purpose: Turns both motors reverse and LEDs on, indefinitely.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void move_reverse(void) {
    /* set the wheel counts and start the timer before proceeding */
    left_motor_reverse();
    right_motor_reverse();
    return;
}
