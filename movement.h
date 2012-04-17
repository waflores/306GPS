/******************************************************************************* 
* File:  movement.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the function prototypes for the car's
*              movement.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/

#ifndef MOVEMENT_H
#define	MOVEMENT_H

/* Pin definitions are from 'ports.h' */
#define LEFT_MOTOR_ON PIN_HIGH
#define LEFT_MOTOR_OFF PIN_LOW
#define RIGHT_MOTOR_ON PIN_HIGH
#define RIGHT_MOTOR_OFF PIN_LOW

void left_motor_forward(void);
void left_motor_reverse(void);
void left_motor_off(void);
int is_left_forward_on(void);
int is_left_reverse_on(void);
int is_left_motor_on(void);

void right_motor_forward(void);
void right_motor_reverse(void);
void right_motor_off(void);
int is_right_forward_on(void);
int is_right_reverse_on(void);
int is_right_motor_on(void);

void move_forward(void);
void move_reverse(void);
void motors_off(void);

#endif	/* MOVEMENT_H */
