/******************************************************************************* 
* File:  ports.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the function prototypes for the timers,
*              display, and A-to-D converter for this board.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/

#ifndef PROTO_H
#define PROTO_H

void init_interrupts(void);
void A2DInit(void);
void system_clock_init(void);
void InitDisplay(char far StartupString1[] );
void DisplayString(unsigned char position, _far const char * string);
void LCD_write(unsigned char data_or_ctrl, unsigned char value);
void DisplayDelay(unsigned long int units);
void BNSPutch(unsigned int where, char c);
unsigned char BNSPrintf(unsigned int where, char far * f, ...);
void clearScreen(void);

// Project Specific

void timerDelay(unsigned int); // an interrupt based delay interface
void TimerInit(void); // Initializes timers
void ADInit(void); // Initializes ADC
void LEDDisplay(void); 

void TimerA0_Init(void); // left wheel timer
void start_leftWheel(void);
void stop_timerA0(void);

void TimerA1_Init(void); // the delay timer

/* Extra intialized timer */
void TimerA2_Init(void); 
void start_timerA2(void);
void stop_timerA2(void);

void TimerB0_Init(void); // right wheel timer
void start_rightWheel(void);
void stop_timerB0(void);

void start_wheelTimers(void); // Both Wheels on
void stop_wheelTimers(void); // Both Wheels off

/* Wheel count accessor functions */
void set_rWheelCount(unsigned int delay);
void set_lWheelCount(unsigned int delay);

/* Switch Interrupts */

void enable_LeftBtn_isr(void);
void enable_MiddleBtn_isr(void);
void start_MiddleBtn_isr(void);
void stop_MiddleBtn_isr(void);
void enable_RightBtn_isr(void);

    
#endif // PROTO_H
