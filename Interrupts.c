/******************************************************************************* 
* File:  Interrupts.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains all the interrupt routines for the peripherals.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
*              2.0, Interrupts for buttons added
* Created on March 12, 2012
*******************************************************************************/

#include "proto.h"
#include "QSKDefines.h"
#include "extern.h"
#include "ports.h"

#define FALLING_EDGE    (0x0)
#define RISING_EDGE     (0x1)

#pragma INTERRUPT UART0TransmitInterrupt
#pragma INTERRUPT KeyBoardInterrupt
#pragma INTERRUPT DMA0Interrupt
#pragma INTERRUPT RTCInterrupt
#pragma INTERRUPT WatchDogInterrupt

/*******************************************************************************
* Purpose: Initializes interrupts for this board.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void init_interrupts(void) {
    enable_LeftBtn_isr();
    enable_MiddleBtn_isr();
    enable_RightBtn_isr();
}

/*******************************************************************************
* Purpose: Initializes interrupt for the left button.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void enable_LeftBtn_isr(void) {
    /* Set interrupt priority level for int1
     * to 7 (binary 111)
     */
    DISABLE_IRQ
    int1ic = HIGHEST_PRIORITY_LEVEL;
    ENABLE_IRQ

    /* set int0 to trigger on negative edge */
    pol_int1ic = FALLING_EDGE;
}

/*******************************************************************************
* Purpose: Initializes interrupt for the middle button.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void enable_MiddleBtn_isr(void) {
    ta4mr = CLEAR_REGISTER;     // Clear Timer A4 Mode Register
    ta4mr |= EVENT_MODE;        // Event mode
    
    /* Trigger select register information */
    ta4tgh = TA4IN_AS_INPUT; // input on TA4in 
    ta4tgl = TA4IN_AS_INPUT;
    
    // just count whenever
    ta4 = COUNT_NOTHING;
	
    // disable irqs before setting irq registers - macro defined in skp_bsp.h
    DISABLE_IRQ		
    // Set the timer A4's IPL (interrupt priority level) to 7
    ta4ic = HIGHEST_PRIORITY_LEVEL;
    ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
    start_MiddleBtn_isr();
}

/*******************************************************************************
* Purpose: This function starts Middle Button Interrupt.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void start_MiddleBtn_isr(void) {
    ta4s = TIMER_START;
}

/*******************************************************************************
* Purpose: This function stops Middle Button Interrupt.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void stop_MiddleBtn_isr(void) {
    ta4s = TIMER_STOP;
}

/*******************************************************************************
* Purpose: Initializes interrupt for the right button.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void enable_RightBtn_isr(void) {
    /* Set interrupt priority level for int0
     * to 7 (binary 111)
     */
    DISABLE_IRQ
    int0ic = HIGHEST_PRIORITY_LEVEL;
    ENABLE_IRQ
    
    /* set int0 to trigger on negative edge */
    pol_int0ic = FALLING_EDGE;
}

/*******************************************************************************
* Purpose: Keeps Left Wheel on until l_count reaches zero.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT TimerA0Interrupt
void TimerA0Interrupt(void) {
    if (l_count > WHEELS_STOPPED) --l_count;
    else {
        // l_count is zero, turn left motor off
        left_motor_off();
        stop_timerA0();
    }
    return;
}

/*******************************************************************************
* Purpose: Counts down every 5 ms until A1_ticks is 0
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT TimerA1Interrupt
void TimerA1Interrupt(void) {
    if (A1_ticks > TIMER_STOP) --A1_ticks;
    else {
        ta1s = TIMER_STOP; // stop these interrupts
        timerA1_started = TIMER_STOP;
    }
    return;
}

/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT TimerA2Interrupt
void TimerA2Interrupt(void) {
    // Toggle an LED to test 5ms timer
    LED0 ^= LED_OFF;
}

/*******************************************************************************
* Purpose: Keeps Right Wheel on until r_count reaches zero.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT TimerB0Interrupt
void TimerB0Interrupt(void) {
    if (r_count > WHEELS_STOPPED) --r_count;
    else {
        // r_count is zero, turn right motor off
        right_motor_off();
        stop_timerB0();
    }
    return;
}

/*******************************************************************************
* Purpose: Sets flag for Switch 1 being pressed.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT LeftBtnInterrupt
void LeftBtnInterrupt(void) {
    buttonPressed |= SW1_PRESSED;
}

/*******************************************************************************
* Purpose: Sets flag for Switch 2 being pressed.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT MiddleBtnInterrupt
void MiddleBtnInterrupt(void) {
    buttonPressed |= SW2_PRESSED;
}

/*******************************************************************************
* Purpose: Sets flag for Switch 3 being pressed..
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT RightBtnInterrupt
void RightBtnInterrupt(void) {
    buttonPressed |= SW3_PRESSED;
}

/*******************************************************************************
* Purpose: Processes serial input on UART0.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT UART0ReceiveInterrupt
void UART0ReceiveInterrupt(void) {
    while (ri_u0c1 == RECEIVING); // make sure receive is complete
    u0BUFFER[u0_wr++] = u0rb;
    if (u0_wr == U0_BUF_SIZE) u0_wr = CLEAR_INDEX;
}

/*******************************************************************************
* Purpose: Processes serial input on UART2.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT UART2ReceiveInterrupt
void UART2ReceiveInterrupt(void) {
    while (ri_u2c1 == RECEIVING); // make sure receive is complete
    u2BUFFER[u2_wr++] = u2rb;
    if (u2_wr == U2_BUF_SIZE) {
        u2BuffFull = TRUE;
        u2_wr = CLEAR_INDEX;
    }
}

/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
#pragma INTERRUPT A2DInterrupt
void A2DInterrupt(void) {
}
/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void KeyBoardInterrupt(void) {}


/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void RTCInterrupt(void) {}

/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void WatchDogInterrupt(void) {}

/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void UART0TransmitInterrupt(void) {}

/*******************************************************************************
* Purpose: Not used in this project.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void DMA0Interrupt(void) {}
