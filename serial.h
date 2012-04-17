/******************************************************************************* 
* File:  serial.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file initializes the UART capabilities for the QSK.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
* Created on March 12, 2012
*******************************************************************************/
#ifndef SERIAL_H
#define SERIAL_H

void InitUART(void);
void transmitUART2(char *);
void displayUART2Stream(void);
    
#endif // SERIAL_H