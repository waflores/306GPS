/******************************************************************************* 
* File:  movementLeftCheck.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the functions that check the states of the
*				car's motors.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release- from movement.c
*
* Created on March 22, 2012
*******************************************************************************/

#include "movement.h"
#include "ports.h"
#include "QSKDefines.h"

/*******************************************************************************
* Purpose: Checks if Left Motor Forward Pin is active.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: LEFT_MOTOR_OFF - equivalent to logical false
*           LEFT_MOTOR_ON - equivalent to logical true
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_left_forward_on(void) {
    if (p3_2 == LEFT_MOTOR_ON) {
        return LEFT_MOTOR_ON;
    }
    else return LEFT_MOTOR_OFF;
}

/*******************************************************************************
* Purpose: Checks if Left Motor Reverse Pin is active.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: LEFT_MOTOR_OFF - equivalent to logical false
*           LEFT_MOTOR_ON - equivalent to logical true
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_left_reverse_on(void) {
    if (p3_3 == LEFT_MOTOR_ON) {
        return LEFT_MOTOR_ON;
    }
    else return LEFT_MOTOR_OFF;
}

/*******************************************************************************
* Purpose: Checks if Left Motor on.
* Passed: No arguments passed.
* Locals: retval - Boolean value as a result of checking the Left Motor Pins
* Returned: TRUE - The Left Motor is on
*           FALSE - The Left Motor is off
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_left_motor_on(void) {
    int retval = (is_left_forward_on() || is_left_reverse_on());
    return retval;
}
