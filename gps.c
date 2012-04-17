/******************************************************************************* 
* File:  gps.c
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

#include "proto.h"
#include "QSKDefines.h"
#include "ports.h"
#include "extern.h"
#include "helperfuncs.h"

void gps_init() {
    GPS_PWR = OFF;
    clearScreen();
    BNSPrintf(LCD, "\tTurning\nGPS on...");
    DisplayDelay(DISPLAY_DELAY1);
    GPS_PWR = ON; // transistion from low to high
    timerDelay(2*ONE_SECOND);
    while(timerA1_started); // wait 3 seconds

    //clearScreen();
    //BNSPrintf(LCD, "\tGPS\nRESET");
    //DisplayDelay(DISPLAY_DELAY);
    p3_5 = ON; // transistion from low to high
    timerDelay(TWO_FIFTY_MS);
    while(timerA1_started); // wait 250 ms to transistion this signal
    
    //clearScreen();
    //BNSPrintf(LCD,"\tGPSPWRCTRL\nLOW");
    
    GPS_PWRCTRL = OFF; // GPS PWRCNTRL LOW
    timerDelay(2*ONE_SECOND);
    while(timerA1_started); // wait 2 seconds 
    //BNSPrintf(LCD, "\tGPSPWRCTRL\nHIGH");
    //DisplayDelay(DISPLAY_DELAY);
    GPS_PWRCTRL = ON;
    
    //clearScreen();
    //BNSPrintf(LCD, "\tChecking\nPWRCHK");
    //DisplayDelay(DISPLAY_DELAY);
    while(!GPS_PWRCHK); // GPS PWRCHK
    
    //clearScreen();
    //BNSPrintf(LCD, "\tPWRCTRL\nLOW");
    //DisplayDelay(DISPLAY_DELAY);
    GPS_PWRCTRL = OFF; // Drive PWRCNTRL back to low
    
    clearScreen();
    BNSPrintf(LCD, "\tGPS on!");
    DisplayDelay(DISPLAY_DELAY);
}

void displayScroller() {
    //char Str2[] ="0123456789_11" ;
    char Str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char LCDdisplayTop[10];
    char LCDdisplayBottom[10];
    int count; 
    int displayIndex = 0; 
    int displayLimit = 3; // num of chars to display
    int strSize;
    int thumbval = 0;
    //char mode = '\0';
    
    strSize = strlength(Str2);
    
    while (FOREVER) {
        displayIndex = 0;
        thumbval = (T_WHEEL & T_WHEELMASK) >> 0x08;
        displayIndex = thumbval*displayLimit;
        
        clearScreen();
        for(count = 0; count < 9; ++count) {
            LCDdisplayBottom[count] = 0;
            LCDdisplayTop[count] = 0;
        }
        LCDdisplayTop[0] ='L';
        LCDdisplayTop[1] ='A';
        LCDdisplayTop[2] ='T';
        LCDdisplayTop[3] = ' ';
        if (displayIndex <= strSize){
            for (count = 4; count < 9; ++count){
                LCDdisplayTop[count] = Str2[displayIndex++];
            }
			LCDdisplayTop[9] = 0;
            DisplayString(LCD_LINE1, LCDdisplayTop);
        }
        else DisplayString(LCD_LINE1, Str2);
        DisplayDelay(2*DISPLAY_DELAY);
    }
    
}