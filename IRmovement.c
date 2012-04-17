/******************************************************************************* 
* File:  IRmovement.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the functions that control the movement of the
*				car with the IR emitters.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*
* Created on March 22, 2012
*******************************************************************************/

#include "movement.h"
#include "IR.h"
#include "IRmovement.h"
#include "extern.h"
#include "sfr62p.h"
#include "proto.h"
#include "ports.h"
#include "QSKDefines.h"

#define GOING_FORWARD (1)
#define GOING_BACKWARDS (1)

void moveBackandForth(void) {
    int left_sensor = ADC_BITMASK;
    int right_sensor = ADC_BITMASK;
    int avg_sensor_reading;
    int times_to_run = 2;

    IR_emitter_on(); // Turn the emitter on    
    while (times_to_run) {
        // however many times need to do this 
        move_forward(); // Go forward until we hit a black line
        timerDelay(HALF_SECOND); // pause for a .5 second
        while(timerA1_started);
        while (GOING_FORWARD) {
            left_sensor = ad3 & ADC_BITMASK;
            right_sensor = ad2 & ADC_BITMASK;
            avg_sensor_reading = (left_sensor + right_sensor) / NUM_OF_SENSORS;
            if (avg_sensor_reading > IR_threshold) {
                LED1 = LED_ON;
                break;
            }
        }
		motors_off();
		timerDelay(HALF_SECOND);
		while(timerA1_started); // pause for .5 seconds
        LED1 = LED_OFF;
        move_reverse();
        timerDelay(HALF_SECOND); // pause for a .5 second
        while(timerA1_started);
		while (GOING_BACKWARDS) {
            left_sensor = ad3 & ADC_BITMASK;
            right_sensor = ad2 & ADC_BITMASK;
            avg_sensor_reading = (left_sensor + right_sensor) / NUM_OF_SENSORS;
            if (avg_sensor_reading > IR_threshold) {
                LED1 = LED_ON;
                break;
            }
        }
  		motors_off();
		timerDelay(HALF_SECOND);
		while(timerA1_started); // pause for .5 seconds
        LED1 = LED_OFF;
		//--times_to_run; // The car will always run 3-26
    }
    motors_off();
    IR_emitter_off();
    return;
}
