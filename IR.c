/******************************************************************************* 
* File:  IR.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the functions that control the IR emitter and
* 				detector.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*
* Created on March 22, 2012
*******************************************************************************/

#include "IR.h"
#include "ports.h"
#include "proto.h"
#include "sfr62p.h"
#include "extern.h"
#include "QSKDefines.h"

volatile unsigned int IR_threshold;
/*******************************************************************************
* Purpose: Turns the IR emitter on.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void IR_emitter_on(void) {
	p3_7 = IR_EMIT_ON;
}

/*******************************************************************************
* Purpose: Turns the IR emitter off.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void IR_emitter_off(void) {
	p3_7 = IR_EMIT_OFF;
}

/*******************************************************************************
* Purpose: Calibrates the threshold for IR.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void calibrateIR(void) {
    int active_threshold = ADC_BITMASK;
    int left_sensor;
    int right_sensor;
    int min_l_sensor = ADC_BITMASK;
    int min_r_sensor = ADC_BITMASK;
    /* Calibration mode*/
    BNSPrintf(LCD, "\tCalibrat\ning... ");
    IR_emitter_on();
    timerDelay(5*ONE_SECOND); // Delay for 5 seconds
    while (timerA1_started) {
        /* read values in the sensors */
        left_sensor = ad3 & ADC_BITMASK;
        right_sensor = ad2 & ADC_BITMASK;

        if (left_sensor < min_l_sensor) min_l_sensor = left_sensor;
        if (right_sensor < min_r_sensor) min_r_sensor = right_sensor;
    }
    IR_emitter_off();
    /* compute the average threshold */
    active_threshold = (min_l_sensor + min_r_sensor) / NUM_OF_SENSORS;
    setIR_threshold((ADC_BITMASK + active_threshold) / NUM_OF_SENSORS);
    
    timerDelay(2*ONE_SECOND);
    while (timerA1_started) BNSPrintf(LCD, "\tLowest: \n%03x     ", active_threshold);
    timerDelay(2*ONE_SECOND);
    while (timerA1_started) BNSPrintf(LCD, "\tThresh: \n%03x     ", IR_threshold);
    return;
}

/*******************************************************************************
* Purpose: Sets the threshold for IR.
* Passed: unsigned int reading - from the calibrate function.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void setIR_threshold(unsigned int reading) {
    IR_threshold = reading;
    return;
}
