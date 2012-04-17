/******************************************************************************* 
* File:  QSKDefines.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: All external declarations shall be made in this file.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/

// Project Specific
#ifndef EXTERN_H
#define EXTERN_H

extern int disp_count;                  // LED control variable
extern unsigned int A2DValue;
extern unsigned int A2DValuePot;
extern unsigned int A2DValueTherm;
extern unsigned char A2DProcessed;

/* Wheel Timer parameters */
extern volatile unsigned int l_count;   // left wheel counts
extern volatile unsigned int r_count;   // right wheel counts
extern volatile unsigned int A1_ticks;  // times timer_A1 has interrupted

/* Active Timer Flags */
extern volatile unsigned short timerA0_started;
extern volatile unsigned short timerA1_started;
extern volatile unsigned short timerB0_started;
extern volatile unsigned short timerA2_started;

/* Button Pressed Flag */
extern volatile unsigned short buttonPressed;

/* IR Emitter threshold */
extern volatile unsigned int IR_threshold;

/* Serial variables */
#define U0_BUF_SIZE 8
#define U2_BUF_SIZE 64

extern volatile unsigned int u0_rd; // buffer indices
extern volatile unsigned int u0_wr;
extern volatile unsigned int u2_rd;
extern volatile unsigned int u2_wr;
extern volatile unsigned char u2BuffFull;
extern volatile unsigned char u0BUFFER[U0_BUF_SIZE];
extern volatile unsigned char u2BUFFER[U2_BUF_SIZE];
#endif /* EXTERN_H */
