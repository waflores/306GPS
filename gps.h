/******************************************************************************* 
* File:  gps.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file initializes the GPS.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
* 
* Created on April 16, 2012
*******************************************************************************/
#ifndef GPS_H
#define GPS_H

void gps_init(void);
void gpsProcess (void);
void gpsCleanUp(int * numberToClear1, int * numberToClear2);
void displayScroller(char * TopStr, char * BottomStr); 
void initDisplayStrings(char * topStr, char * botStr);
#endif