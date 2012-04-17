/******************************************************************************* 
* File:  movementRightCheck.c
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
* Purpose: Checks if Right Motor Forward Pin is active.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: RIGHT_MOTOR_OFF - equivalent to logical false
*           RIGHT_MOTOR_ON - equivalent to logical true
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_right_forward_on(void) {
    if (p3_0 == RIGHT_MOTOR_ON) {
        return RIGHT_MOTOR_ON;
    }
    else return RIGHT_MOTOR_OFF;
}

/*******************************************************************************
* Purpose: Checks if Left Motor Reverse Pin is active.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: RIGHT_MOTOR_OFF - equivalent to logical false
*           RIGHT_MOTOR_ON - equivalent to logical true
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_right_reverse_on(void) {
    if (p3_1 == RIGHT_MOTOR_ON) {
        return RIGHT_MOTOR_ON;
    }
    else return RIGHT_MOTOR_OFF;
}

/*******************************************************************************
* Purpose: Checks if Right Motor on.
* Passed: No arguments passed.
* Locals: retval - Boolean value as a result of checking the Right Motor Pins
* Returned: TRUE - The Right Motor is on
*           FALSE - The Right Motor is off
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
int is_right_motor_on(void) {
    int retval = (is_right_forward_on() || is_right_reverse_on());
    return retval;
}
