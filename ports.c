/******************************************************************************* 
 * File:  ports.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: Implementation of 'ports.h'.
 * Description: This file contains the function implentations for the port
 *              initializations for this board.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       NONE
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented file header with function headers
 *              2.0, Better documented Port 7 & 8 functions
 * Created on March 12, 2012
 *******************************************************************************/
 
//---------------------------------------------------
//  Purpose:	Initialize Port 8
//  System registers associated with Port 8 configured
//  * Pin 0 - I/O    General Purpose I/O
//    Pin 0 - TA4OUT Timer A4 Out
//    Pin 0 - U      Three-Phase Positive Waveform Output Pin
//  * Pin 1 - I/O    General Purpose I/O
//    Pin 1 - TA4IN  Timer A4 In
//    Pin 1 - U      Three-Phase Negative Waveform Output Pin
//  * Pin 2 - I/O    General Purpose I/O
//    Pin 2 - INT0   Interrupt 0 Input
//  * Pin 3 - I/O    General Purpose I/O
//    Pin 3 - INT1   Interrupt 1 Input
//  * Pin 4 - I/O    General Purpose I/O
//    Pin 4 - INT2   Interrupt 2 Input
//    Pin 5 - I/O    General Purpose I/O
//  * Pin 5 - NMI    Non-Maskable Interrupt Input
//    Pin 6 - I/O    General Purpose I/O
//  * Pin 6 � XCIN ==> Connected to X2 back side
//    Pin 7 - I/O    General Purpose I/O
//  * Pin 7 - XCOUT ==> Connected to X2 back side
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Jim Carlson   
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//

#include "sfr62p.h"
#include "ports.h"
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/* Button Pressing Flag */
volatile unsigned short buttonPressed;

/*******************************************************************************
 * Purpose: This function calls all the port initialization functions for this
 *          board.
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void init_ports(void) {
    init_port0();
    init_port1();
    init_port2();
    init_port3();
    init_port4();
    init_port5();
    //init_port6();
    init_port7();
    init_port8();
    //init_port9();
    //init_port10();
    
    return;    
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void init_port0(void){
    pd0 = OUTPUT_PORT;
    p0_0 = PIN_LOW;
    p0_1 = PIN_LOW;
    p0_2 = PIN_LOW;
    p0_3 = PIN_LOW;
    p0_4 = PIN_LOW;
    p0_5 = PIN_LOW;
    p0_6 = PIN_LOW;
    p0_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port1: initializes port 1 to be an output port with all pins low
void init_port1(void){
    pd1 = OUTPUT_PORT;
    p1_0 = PIN_LOW;
    p1_1 = PIN_LOW;
    p1_2 = PIN_LOW;
    p1_3 = PIN_LOW;
    p1_4 = PIN_LOW;
    p1_5 = PIN_LOW;
    p1_6 = PIN_LOW;
    p1_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port2: initializes port 2 to be an output port with all pins low
void init_port2(void){
    pd2 = OUTPUT_PORT;
    p2_0 = PIN_LOW;
    p2_1 = PIN_LOW;
    p2_2 = PIN_LOW;
    p2_3 = PIN_LOW;
    p2_4 = PIN_LOW;
    p2_5 = PIN_LOW;
    p2_6 = PIN_LOW;
    p2_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port3: initializes port 3 to be an output port with all pins low
// This port is where our motors reside
void init_port3(void)  {
    /* Set up the direction of port 3, pins 0 and 2 */
    pd3 = OUTPUT_PORT;
    p3_0 = PIN_LOW; // left motor
    p3_1 = PIN_LOW;
    p3_2 = PIN_LOW;	// right motor
    p3_3 = PIN_LOW;
    p3_4 = PIN_LOW; // GPS_PWRCNTRL
    p3_5 = PIN_HIGH; // GPS_Reset
    p3_6 = PIN_HIGH; // GPS_PWR
    p3_7 = PIN_LOW; // IR emitter
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port4: initializes port 4 to be an output port with all pins low
void init_port4(void){
    pd4 = OUTPUT_PORT;
    p4_0 = PIN_LOW;
    p4_1 = PIN_LOW;
    p4_2 = PIN_LOW;
    p4_3 = PIN_LOW;
    p4_4 = PIN_LOW;
    p4_5 = PIN_LOW;
    p4_6 = PIN_LOW;
    p4_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port5: initializes port 5 to be an output port with all pins low
void init_port5(void){
    pd5 = OUTPUT_PORT;
    p5_0 = PIN_LOW;
    p5_1 = PIN_LOW;
    p5_2 = PIN_LOW;
    p5_3 = PIN_LOW;
    p5_4 = PIN_LOW;
    p5_5 = PIN_LOW;
    p5_6 = PIN_LOW;
    p5_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port6: initializes port 6 (serial port) with all pins low
void init_port6(void){
    pd6_0 = OUTPUT; // send - receive ctrl bits
    pd6_1 = OUTPUT; // transfer clock I/O
    pd6_2 = INPUT; // serial data input
    pd6_3 = OUTPUT; // serial output
    pd6_4 = OUTPUT;
    pd6_5 = OUTPUT;
    pd6_6 = INPUT;
    pd6_7 = OUTPUT;
    p6_0 = PIN_LOW;
    p6_1 = PIN_LOW;
    p6_2 = PIN_LOW;
    p6_3 = PIN_LOW;
    p6_4 = PIN_LOW;
    p6_5 = PIN_LOW;
    p6_6 = PIN_LOW;
    p6_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port 7
 * System registers associated with Port 7 configured
 *      Pin 0
 *      Pin 1
 *      Pin 2 - I/O     General Purpose I/O
 *      Pin 2 - CLK_VP
 *      Pin 2 - LED2    The Right Most LED
 *      Pin 3
 *      Pin 4 - I/O     General Purpose I/O
 *      Pin 4 - TA2OUT Timer A2 Out
 *      Pin 4 - LED1    The Middle LED
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void init_port7(void){
    //pd7 = OUTPUT_PORT;
    pd7_0 = OUTPUT; // UART2 TX
    pd7_1 = INPUT;  // UART2 RX
    LED2_DDR = OUTPUT; // LED2 - right LED
    pd7_3 = OUTPUT; 
    LED1_DDR = OUTPUT; // LED1 - middle LED
    pd7_5 = OUTPUT;
    pd7_6 = OUTPUT;
    pd7_7 = OUTPUT;

    p7_0 = PIN_LOW;
    p7_1 = PIN_LOW;
    LED2 = LED_OFF; // LED2 Off
    p7_3 = PIN_LOW;
    LED1 = LED_OFF; // LED1 Off 
    p7_5 = PIN_LOW;
    p7_6 = PIN_LOW;
    p7_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port 8
 * System registers associated with Port 8 configured
 *     *Pin 0 - I/O     General Purpose I/O
 *      Pin 0 - TA4OUT_UP
 *      Pin 0 - LED0    The Left Most LED
 *     *Pin 1 - I/O     General Purpose I/O
 *      Pin 1 - TA4IN_UN
 *      Pin 1 - S2      Middle Switch
 *     *Pin 2 - I/O     General Purpose I/O
 *      Pin 2 - INT0    Interrupt 0 Switch
 *      Pin 2 - S3      Right-most Switch
 *     *Pin 3 - I/O     General Purpose I/O
 *      Pin 3 - INT1    Interrupt 1 Input
 *      Pin 3 - S1      Left-most Switch
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void init_port8(void){
    //pd8 = OUTPUT_PORT;
    LED0_DDR = OUTPUT;  // LED0 - left LED
    SW2_DDR = INPUT;     // switch 2
    SW3_DDR = INPUT;     // switch 3
    SW1_DDR = INPUT;     // switch 1
    pd8_4 = OUTPUT;
    pd8_6 = OUTPUT;
    pd8_7 = OUTPUT;

    LED0 = LED_OFF;     // LED0 Off
    SW2 = BUTTON_RESET;  // Switch 2 unpressed
    SW3 = BUTTON_RESET;  // Switch 3 unpressed
    SW1 = BUTTON_RESET;  // Switch 1 unpressed
    p8_4 = PIN_LOW;
    p8_5 = PIN_LOW;
    p8_6 = PIN_LOW;
    p8_7 = PIN_LOW;
    
    /* Initialize Button Pressed Flag */
    buttonPressed = DEFAULTS;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port _
 * System registers associated with Port _ configured
 *      Pin 0
 *      Pin 1
 *      Pin 2
 *      Pin 3
 *      Pin 4
 *      Pin 5
 *      Pin 6
 *      Pin 7
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port9: initializes port 9 to an output port and sets all pins LOW
void init_port9(void){
    //pd9 = OUTPUT_PORT;
    pd9_0 = OUTPUT;
    pd9_1 = OUTPUT;
    pd9_2 = OUTPUT;
    pd9_3 = OUTPUT;
    pd9_4 = OUTPUT;
    pd9_5 = OUTPUT; // ADC
    pd9_6 = OUTPUT; // ADC
    pd9_7 = OUTPUT; // GPS PWRCHK

    p9_0 = PIN_LOW;
    p9_1 = PIN_LOW;
    p9_2 = PIN_LOW;
    p9_3 = PIN_LOW;
    p9_4 = PIN_LOW;
    p9_5 = PIN_LOW;
    p9_6 = PIN_LOW;
    p9_7 = PIN_LOW;
    return;
}

/*******************************************************************************
 * Purpose: Initialize Port 10
 * System registers associated with Port _ configured
 *      Pin 0 - Potentiometer
 *      Pin 1 - Thermistor
 *      Pin 2 - Unused
 *      Pin 3 - Unused
 *      Pin 4 - Unused
 *      Pin 5 - Unused
 *      Pin 6 - Unused
 *      Pin 7 - Unused
 * 
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
// init_port10: initializes port 10 to an output port and sets all pins LOW
void init_port10(void){
	pd10 = INPUT; // Shorthand for only enabling the thumbwheel to work
	
    //pd10_0 = OUTPUT_PORT;
    /*pd9_1 = OUTPUT;
    pd9_2 = OUTPUT;
    pd9_3 = OUTPUT;
    pd9_4 = OUTPUT;
    pd9_5 = OUTPUT; // ADC
    pd9_6 = OUTPUT; // ADC
    pd9_7 = OUTPUT;
    */
    p10_0 = PIN_LOW;
    p10_1 = PIN_LOW;
    p10_2 = PIN_LOW;
    p10_3 = PIN_LOW;
    p10_4 = PIN_LOW;
    p10_5 = PIN_LOW;
    p10_6 = PIN_LOW;
    p10_7 = PIN_LOW;
    return;
}
