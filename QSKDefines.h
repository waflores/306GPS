/******************************************************************************* 
* File:  QSKDefines.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: All the defines for the projects are kept here.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/

// These two defines are used to help keep track of which version of code we are running.
//  Major is incremented when a new feature or function is added.
//  Minor is incremented when there is a bug fix or attempted fix.
#ifndef QSKDEFINES_H
#define QSKDEFINES_H

#include "sfr62p.h"
#include <ctype.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include "LCD.h"

#define MAJOR_REV		1
#define MINOR_REV		1

// Shorthand stuff... 
#define BIT0    0x01
#define BIT1    0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80

#define ulong   unsigned long
#define uint	unsigned int
#define uchar 	unsigned char

#define TRUE	1
#define FALSE	0

// debounced polled ctrl
#define FOREVER TRUE

#define PASSED  TRUE
#define FAILED  FALSE

#define YES     TRUE
#define NO	FALSE

#define ON	TRUE
#define OFF	FALSE

#define HIGH    1
#define LOW     0

#define ENABLE_IRQ      {_asm(" FSET I");}
#define DISABLE_IRQ     {_asm(" FCLR I");}

// Defines used to configure the Timer 
// This stuff sets up the timer to run a 5ms tick.
#define f1_CLK_SPEED    (24000000L) // Original CLK SPEED @ 4x pLL
//#define f1_CLK_SPEED    (12000000L)

#define MS_PER_TICK	5       // Determined for how long a timer fires
#define CLEAR_REGISTER  (0x00)  // Clear Register
#define DESIRED_TIME_MS (0x05)  //  5 ms timer
#define TIMER_MODE      (0x00)  //  Timer Mode
#define EVENT_MODE      (0x01)  //  Event Mode
#define PULSE_MODE      (0x02)  //  Pulse Period Mode
#define PULSE_OUTPUT_ON (0x08)  //  Pulse Output Function Selection
#define FREE_RUN_COUNT  (0x40)  //  Count Operation Type Select

#define SRC_F1_F2_PCLK0 (0x00)  //  selected in PCLKR Register bit 0
#define SRC_F8          (0x40)  //  count source f8
#define SRC_F32         (0x80)  //  count source f32
#define SRC_FC32        (0xC0)  //  count source fC32

/* Time increments */
#define ONE_HUNDRED_MS  (100/(MS_PER_TICK))	// ticks in one hundred MS
#define TWO_FIFTY_MS    (250/(MS_PER_TICK))   //  ticks in 250 MS
#define HALF_SECOND     (5*ONE_HUNDRED_MS) // ticks in 500 MS
#define ONE_SECOND      (1000/(MS_PER_TICK))	// ticks in a second
#define TIMER_START     (1)
#define TIMER_STOP      (0)


/* Wheel counting */
#define WHEELS_STOPPED (0)
#define COUNT_NOTHING  (0)

#define TA4IN_AS_INPUT (0)

#define NORMAL_PRIORITY_LEVEL (3)
#define HIGHEST_PRIORITY_LEVEL (7)

/* ADC related stuff */
#define ADC_START       (0x01)
#define ADC_STOP        (0x00)
// adcon0
#define CLEAR_REGISTER  (0x00)
#define CLEAR_INDEX (CLEAR_REGISTER)
#define REPEAT_SWEEP    (0x98)
// adcon1
#define SWEEP_AN0_AN3   (0x01)
#define TEN_BIT_MODE    (0x08)
#define CONNECT_VREF    (0x30)
// adcon2
#define SAMPLE_AND_HOLD (0x01)

// Serial Port Defines
#define INIT_UART0_UART1        (0x00)

// u0c0 defines
#define LSB_FIRST        (0x00)
#define F8SIO_SELECTED   (0x01)
#define CTS_RTS_DISABLED (0x10)

// u0C1 defines
#define TRANSMIT_RECEIVE_ENABLED (0x05)

// u0mr defines
#define DATA_EIGHT_BITS_LONG (0x05)

#define TX0_PRIORITY_LEVEL      3
#define RX0_PRIORITY_LEVEL      4
#define TX2_PRIORITY_LEVEL      3
#define RX2_PRIORITY_LEVEL      4

#define RECEIVING (0x00)
#define TRANSMITTING (0x00)
#define ENABLE_TX0_INTERRUPTS	s0tic = TX0_PRIORITY_LEVEL;
#define DISABLE_TX0_INTERRUPTS  s0tic = 0;
#define ENABLE_RX0_INTERRUPTS   s0ric = RX0_PRIORITY_LEVEL;
#define DISABLE_RX0_INTERRUPTS  s0ric = 0;

#define ENABLE_RX2_INTERRUPTS s2ric = RX2_PRIORITY_LEVEL;
#define ENABLE_TX2_INTERRUPTS s2tic = TX2_PRIORITY_LEVEL;

#define TX0_INTERRUPTS_ENABLED  (s0tic != 0)
#define RX0_INTERRUPTS_ENABLED  (s0ric != 0)

#define CLEAR_CHAR ' '
#define TRANSMIT_DELAY 500

// GPS Baud Rate
#define BAUD_RATE       4800

// Receive Buffer length
#define MSG_BUFFER 16
// Use these macros to control the LEDs.  
#define LED(led, state) ((led) = !state)

// LCD defines
#define DISPLAY_DELAY (1000)
#define DISPLAY_DELAY1 (500)

// ADC defines
#define T_WHEEL ad0 // alias for thumbwheel
#define T_WHEELMASK 0x300
#define START_MSG 0x300
#define NEXT_MSG1 0x200
#define NEXT_MSG2 0x100
#define END_MSG   0x000

#endif /* QSKDEFINES_H */
