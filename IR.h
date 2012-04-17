/******************************************************************************* 
* File:  IR.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the function prototypes for the car's
*              IR detectors.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              
* Created on March 22, 2012
*******************************************************************************/

#ifndef IR_H
#define IR_H

#define IR_EMIT_ON 1
#define IR_EMIT_OFF 0
#define ADC_BITMASK (0x03ff)
#define NUM_OF_SENSORS (2)

void IR_emitter_on(void);
void IR_emitter_off(void);
void calibrateIR(void);
void setIR_threshold(unsigned int reading);

#endif /* IR_H */