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

#define NEXT_ELEMENT 1
#define SPACER 2 /* Space between last char and NULL */
#define DELIMITER_LOCATION 1
#define MIN_SIZE_OF_TOKEN 1
#define SIZE_OF_NO_TOKEN 0

// adhoc defines
#define HAVENOTHING 0x00
#define HAVEADOLLARSIGN 0x01
#define HAVEAG 0x02
#define HAVEAP 0x04
#define HAVEAR 0x08
#define HAVEAM 0x10
#define HAVEAC 0x20
#define HAVEGPSHEAD 0x3F
#define VALIDATEREADY 2

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

void gpsProcess (void) {
    /* Process GPS info only if there is something to process */
    char gpsVal = 0;
    static char parseStatus = 0;
    static int commaCount = 0;
    char gpsStr[2];
    //static int lastIndex = 0;
    //static int currIndex = 0;
    gpsStr[1] = 0; // clear GPS string
    if (u2_rd != u2_wr) {
        while(u2_rd != u2_wr) {
            gpsVal = u2BUFFER[u2_rd++];
            /* $GPRMC - replace inBuff with u2BUFFER*/
            if (!(parseStatus & HAVEGPSHEAD)) {
                /* Look for a dollar sign, otherwise do nothing */
                if (gpsVal == '$') { 
                    parseStatus |= HAVEADOLLARSIGN;
                    //LED0 = LED_ON;
                }
            }
            /* We already have a dollar sign :) */
            else if (parseStatus & HAVEADOLLARSIGN) {
                if ((gpsVal == 'G')) {
                    parseStatus |= HAVEAG;
                    //LED1 = LED_ON;
                }
                else if((parseStatus & HAVEAG) && (gpsVal == 'P')) {
                    parseStatus |= HAVEAP;
                    //LED2 = LED_ON;
                }
                else if((parseStatus & HAVEAP) && (gpsVal == 'R')) {
                    parseStatus |= HAVEAR;
                    //LED0 = LED_ON;
                }
                else if((parseStatus & HAVEAR) && (gpsVal == 'M')) {
                    parseStatus |= HAVEAM;
                    //LED1 = LED_ON;
                }
                else if((parseStatus & HAVEAM) && (gpsVal == 'C')){
                    parseStatus |= HAVEAC;
                    LED2 = LED_ON;
                }
                else {
                    parseStatus = HAVENOTHING;
                    LED0 = LED1 = LED2 = LED_OFF;
                }
            }
            else if ((parseStatus & HAVEGPSHEAD)) {
                /* count commas and validate bits */
                if((commaCount != VALIDATEREADY) && gpsVal == ',') ++commaCount;
                else if (commaCount == VALIDATEREADY) {
                    if (gpsVal == 'A') {
                        /* Do stuff if valid */
                        LED0 = LED_ON;
                        clearScreen();
                        timerDelay(ONE_SECOND);
                        BNSPrintf(LCD, "\tValid\nGPS_MSG");
                        while(timerA1_started);
                        commaCount = CLEAR_INDEX;
                        parseStatus = HAVENOTHING;
                    }
                    else {
                        commaCount = CLEAR_INDEX;
                        parseStatus = HAVENOTHING; // reset parsing machine
                        LED0 = LED1 = LED2 = LED_OFF;
                    }
                }
            }
            gpsStr[0] = gpsVal;
            DisplayString(LCD_LINE1, gpsStr);
            if (u2_rd >= U2_BUF_SIZE) u2_rd = CLEAR_INDEX;
            //if (currIndex >= inBuffSize) currIndex = CLEAR_INDEX;
            
            
        }
    }
}

void displayScroller() {
    //char Str2[] ="0123456789_11" ;
    char Str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char LCDdisplayTop[10];
    char LCDdisplayBottom[10];
    int count; 
    int displayIndex = 0; 
    int displayLimit = 4; // num of chars to display
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

