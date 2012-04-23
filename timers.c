/******************************************************************************* 
* File:  timers.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the function implentations for the timer
*              initializations for this board.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
* Created on March 12, 2012
*******************************************************************************/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#define NUM_OF_SECS 1e-3
/* Use these vars to designate how many times you want a certain wheel to be on */
volatile unsigned int r_count; 
volatile unsigned int l_count;

/* Use these vars as timer flags, to denote timers being turned off and on */
volatile unsigned short timerA0_started;
volatile unsigned short timerB0_started;
volatile unsigned short timerA2_started;
volatile unsigned short timerA1_started;

// Designates how long timer_A1 has to be on
unsigned int A1_ticks;

/*******************************************************************************
* Purpose: This function calls all the timers functions for this board as five
 *         ms timers.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void TimerInit(void) {
    TimerA0_Init(); // left wheel timer
    TimerA1_Init(); // 5 millisecond delay timer
    TimerA2_Init(); // an extra timer
    TimerB0_Init(); // right wheel timer
    return;
}

/*******************************************************************************
* Purpose: This function initializes TimerA0 as the left wheel timer. It also
*          also initializes the right and left wheel counts.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void TimerA0_Init(void) {
    ta0mr = CLEAR_REGISTER;            // Clear Timer A0 Mode Register
    ta0mr |= TIMER_MODE;	             // Timer mode
    ta0mr |= SRC_F32;	             // Clock Source f32
    // (12MHz / 32 * [time in millisecond] / 1000 ms per second )-1

    ta0 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS*NUM_OF_SECS) - 1);	
    // disable irqs before setting irq registers - macro defined in skp_bsp.h
    DISABLE_IRQ		
    // Set the timer B0's IPL (interrupt priority level) to 3
    ta0ic = NORMAL_PRIORITY_LEVEL;
    ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
    // to enable time set tb0s =1 
    // initialize the counting variables for the wheels	
    r_count = WHEELS_STOPPED;
    l_count = WHEELS_STOPPED;
}

/*******************************************************************************
* Purpose: This function starts TimerA0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void start_leftWheel(void) {
    /* Start timer A0 */
    ta0s = TIMER_START;
    timerA0_started = TIMER_START;
    return;
}

/*******************************************************************************
* Purpose: This function stops TimerA0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void stop_timerA0(void) {
    /* Stop timer A0 */
    ta0s = TIMER_STOP;
    timerA0_started = TIMER_STOP;
    return;
}

/*******************************************************************************
* Purpose: This function initializes TimerA0 as a 5 ms delay timer.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void TimerA1_Init(void) {
    ta1mr = CLEAR_REGISTER;            // Clear Timer A1 Mode Register
    ta1mr |= TIMER_MODE;	             // Timer mode
    ta1mr |= SRC_F32;	             // Count Source f32
    // (12MHz / 32 * [time in millisecond] / 1000 ms per second )-1
    ta1 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS*NUM_OF_SECS) - 1); // 5 ms timer

    // disable irqs before setting irq registers - macro defined in skp_bsp.h
    DISABLE_IRQ		
    ta1ic = NORMAL_PRIORITY_LEVEL;
    ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
}

/*******************************************************************************
* Purpose: This function starts TimerA1 for a specified amount of ticks.
*          In this configuration, the ticks occur in 5 ms intervals.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void timerDelay(unsigned int timeDelay) {
    /* current configuration tA1 == 5ms */
    A1_ticks = timeDelay;
    ta1s = TIMER_START; // start the timer
    timerA1_started = TIMER_START;
    return;
}

/*******************************************************************************
* Purpose: This function initializes TimerA2 as a 5 ms delay timer. In this 
*          configuation, it's not used.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void TimerA2_Init(void) {
    ta2mr = CLEAR_REGISTER;            // Clear Timer A2 Mode Register
    ta2mr |= TIMER_MODE;	             // Timer mode
    // changed the count source :(
    ta2mr |= SRC_F32;	             // Count Source f32
    // (12MHz / 32 * [time in millisecond] / 1000 ms per second )-1

    ta2 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS*NUM_OF_SECS) - 1); // 5 ms timer

    // disable irqs before setting irq registers - macro defined in skp_bsp.h
    DISABLE_IRQ		
    ta2ic = NORMAL_PRIORITY_LEVEL;
    ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
}

/*******************************************************************************
* Purpose: This function starts TimerA2.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void start_timerA2(void) {
    /* Start timer A2 */
    ta2s = TIMER_START;
    timerA2_started = TIMER_START;
    return;
}

/*******************************************************************************
* Purpose: This function stops TimerA2.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void stop_timerA2(void) {
    /* Stop timer A2 */
    ta2s = TIMER_STOP;
    timerA2_started = TIMER_STOP;
    return;
}

/*******************************************************************************
* Purpose: This function initializes TimerB0 as the right wheel timer. It also
*          also initializes the right and left wheel counts.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void TimerB0_Init(void) {
    tb0mr = CLEAR_REGISTER;            // Clear Timer B0 Mode Register
    tb0mr |= TIMER_MODE;	             // Timer mode
    tb0mr |= SRC_F32;	             // Clock Source f32
    // (12MHz / 32 * [time in millisecond] / 1000 ms per second )-1

    tb0 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS*NUM_OF_SECS) - 1);	
    // disable irqs before setting irq registers - macro defined in skp_bsp.h
    DISABLE_IRQ
    // Set the timer B0's IPL (interrupt priority level) to 3
    tb0ic = NORMAL_PRIORITY_LEVEL;
    ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
    // to enable time set tb0s =1 
    // initialize the counting variables for the wheels	
    r_count = WHEELS_STOPPED;
    l_count = WHEELS_STOPPED;
}

/*******************************************************************************
* Purpose: This function starts TimerB0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void start_rightWheel(void) {
    /* Start timer B0 */
    tb0s = TIMER_START;
    timerB0_started = TIMER_START;
    return;
}

/*******************************************************************************
* Purpose: This function stops TimerB0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void stop_timerB0(void) {
    /* Stop timer B0 */
    tb0s = TIMER_STOP;
    timerB0_started = TIMER_STOP;
    return;
}

/*******************************************************************************
* Purpose: This function starts both wheel timers.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void start_wheelTimers(void) {
    start_leftWheel();
    start_rightWheel();
return;
}

/*******************************************************************************
* Purpose: This function stops both wheel timers.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void stop_wheelTimers(void) {
    stop_timerA0();
    stop_timerB0();
return;
}		

/*******************************************************************************
* Purpose: This function sets the r_count variable.
* Passed: unsigned int delay - used to set the amount of 5ms intervals for the
*         right motor to be on.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void set_rWheelCount(unsigned int delay) {
    r_count = delay;
    return;
}

/*******************************************************************************
* Purpose: This function sets the l_count variable.
* Passed: unsigned int delay - used to set the amount of 5ms intervals for the
*         left motor to be on.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void set_lWheelCount (unsigned int delay) {
    l_count = delay;
    return;
}
