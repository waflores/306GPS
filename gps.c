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
#include "gps.h"

#define GPS_BOUND_CHECK (GPS_COORD_SIZE - 1)
// adhoc defines
#define HAVENOTHING 0x00
#define HAVEADOLLARSIGN 0x01
#define HAVEAG 0x02
#define HAVEAP 0x04
#define HAVEAR 0x08
#define HAVEAM 0x10
#define HAVEAC 0x20
#define HAVEGPSHEAD 0x3F
#define VALIDCOORD 0x40 // assuming we got a gps header
#define VALIDATEREADY 2 // numbers of commas in message
#define LAT_READY 3
#define LON_READY 5
#define COORD_OVER 7
// Display defines
#define ADC_MSbyte_SHIFT 0x08
#define GPS_DISPLAY_LIMIT 4 // Number of chars to display on LCD
#define LCD_DISPLAY_LIMIT 10 

/* Global Latitude and Longitude Buffers */
volatile unsigned char lonGet[GPS_COORD_SIZE];
volatile unsigned char latGet[GPS_COORD_SIZE];

/*******************************************************************************
* Purpose: Initializes the GPS Module.
* Passed: No arguments passed.
* Locals: int index - GPS Buffer Index
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void gps_init() {
    int index; // GPS Buffer Index
    
    /* 1. Turn GPS OFF before turning it on */
    GPS_PWR = OFF;
    clearScreen();
    BNSPrintf(LCD, "\tTurning\nGPS on...");
    DisplayDelay(DISPLAY_DELAY1);
    
    /* 2. Turn GPS ON */ 
    GPS_PWR = ON; // transistion from low to high
    timerDelay(2*ONE_SECOND);
    while(timerA1_started); // wait 2 seconds
    
    /* 3. Turn GPS_RESET ON for 250 ms */
    //clearScreen();
    //BNSPrintf(LCD, "\tGPS\nRESET");
    //DisplayDelay(DISPLAY_DELAY);
    GPS_RESET = ON; // transistion from low to high
    timerDelay(TWO_FIFTY_MS);
    while(timerA1_started); // wait 250 ms to transistion this signal
    
    /* 4. Pull GPS_PWRCTRL LOW for 2 seconds */
    //clearScreen();
    //BNSPrintf(LCD,"\tGPSPWRCTRL\nLOW");
    GPS_PWRCTRL = OFF; // GPS PWRCNTRL LOW
    timerDelay(2*ONE_SECOND);
    while(timerA1_started); // wait 2 seconds 
    //BNSPrintf(LCD, "\tGPSPWRCTRL\nHIGH");
    //DisplayDelay(DISPLAY_DELAY);
    
    /* 5. Transition GPS_PWRCTRL */
    GPS_PWRCTRL = ON;
    
    /* 6. Wait until GPS_PWRCHK turns ON */
    //clearScreen();
    //BNSPrintf(LCD, "\tChecking\nPWRCHK");
    //DisplayDelay(DISPLAY_DELAY);
    while(!GPS_PWRCHK); // GPS PWRCHK
    
    /* 7. Release GPS_PWRCTRL */
    //clearScreen();
    //BNSPrintf(LCD, "\tPWRCTRL\nLOW");
    //DisplayDelay(DISPLAY_DELAY);
    GPS_PWRCTRL = OFF; // Drive PWRCNTRL back to low
    
    /* 8. We're done! */
    clearScreen();
    BNSPrintf(LCD, "\tGPS on!");
    DisplayDelay(DISPLAY_DELAY);
    
    /* Clear the longitude and latitude buffers */
    for (index = 0; index < 13; ++index){
        lonGet[index] = latGet[index] = CLEAR_INDEX;
    }
}

/*******************************************************************************
* Purpose: Processes the GPS information 
* Passed: No arguments passed.
* Locals: char gpsVal - the value retrieved from UART2
*         char parseStatus - State of Parsing algorithm
*         char commaCount - Counts delimeters of GPS message
*         int latIndex - Index of latitude array
*         int lonIndex - Index of longitude array
* 
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void gpsProcess (void) {
    char gpsVal = CLEAR_CHAR;
    static char parseStatus = CLEAR_CHAR;
    static int commaCount = CLEAR_INDEX;
    static int latIndex = CLEAR_INDEX;
    static int lonIndex = CLEAR_INDEX;
    
    /* Process GPS info only if there is something to process */
    if (u2_rd != u2_wr) {
        /* GPS Message Tokenization Loop */
        while(u2_rd != u2_wr) {
            gpsVal = u2BUFFER[u2_rd++]; /* Read the next char in UART2 */
            /* Start Looking for Symbols */
            if (!(parseStatus & HAVEGPSHEAD) && !(parseStatus & HAVEADOLLARSIGN)) {
                if (gpsVal == '$') { 
                    parseStatus |= HAVEADOLLARSIGN;
                    //LED0 = LED_ON;
                }
            }
            /* We have the proper GPS Header, Validate the message */
            else if ((parseStatus & HAVEGPSHEAD) == HAVEGPSHEAD) {
                /* count commas */
                if(gpsVal == ',') ++commaCount;
                /* Determine if Stream is Valid */
                else if (commaCount == VALIDATEREADY) {
                    /* Validate the Stream */
                    if (gpsVal != 'A') {
                        /* Reset parsing machine, since stream is invalid */
                        gpsCleanUp(&commaCount, (int *)&parseStatus);
                        //return;
                        //LED0 = LED1 = LED2 = LED_OFF;
                    }
                    else {
                        /* Clear the longitude and latitude buffers */
                        for (latIndex = CLEAR_INDEX; latIndex < GPS_COORD_SIZE; ++latIndex){
                            lonGet[latIndex] = latGet[latIndex] = CLEAR_INDEX;
                        }
                        latIndex = CLEAR_INDEX; // Clear the used Index
                    }
                }
                /* Determine what's in the Latitude Token */
                else if ((commaCount >= LAT_READY) && (commaCount < LON_READY)) {
                    /* Bound Checking for lulz */
                    if (latIndex < GPS_BOUND_CHECK) latGet[latIndex++] = gpsVal;
                    else latGet[latIndex] = CLEAR_CHAR; 
                }
                /* Determine what's in the Longitude Token */
                else if ((commaCount >= LON_READY) && (commaCount < COORD_OVER)) {
                    /* Bound Checking for lulz */
                    if (lonIndex < GPS_BOUND_CHECK) lonGet[lonIndex++] = gpsVal;
                    else lonGet[lonIndex] = CLEAR_CHAR;
                }
                /* Clean up, we're done parsing the stream */
                else if (commaCount == COORD_OVER) {
                    gpsCleanUp(&lonIndex, &latIndex); // clear the indices
                    /* Reset the parsing machine */
                    gpsCleanUp(&commaCount, (int *)&parseStatus);
                    LED1 ^= LED_OFF; // Toggle the Middle LED to signal this
                    displayScroller(latGet, lonGet);
                    return; // return to display these buffers 
                }
            }
            /* If we don't have a GPS header, look for the requisite Symbols */
            else if (!((parseStatus & HAVEGPSHEAD) == HAVEGPSHEAD)) {
                if ((parseStatus & HAVEADOLLARSIGN) && (gpsVal == 'G')) {
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
                    //LED2 = LED_ON;
                }
                else {
                    /* Invalid GPS Header */
                    parseStatus = HAVENOTHING;
                    //LED0 = LED1 = LED2 = LED_OFF;
                }
            }
            else parseStatus = HAVENOTHING; // Nothing to see here, move along
            /* Hardcore, ring-buffer reset action :) */
            if (u2_rd >= U2_BUF_SIZE) u2_rd = CLEAR_INDEX;
        }
    }
}

void displayScroller(char * TopStr, char * BottomStr) {
    int count = CLEAR_INDEX; 
    int displayIndex = CLEAR_INDEX; 
    int topStrSize = CLEAR_INDEX;
    int bottomStrSize = CLEAR_INDEX;
    int thumbval = CLEAR_INDEX;
    char LCDdisplayTop[LCD_DISPLAY_LIMIT];
    char LCDdisplayBottom[LCD_DISPLAY_LIMIT];
    
    topStrSize = strlength(TopStr);
    bottomStrSize = strlength(BottomStr);
    
    thumbval = (T_WHEEL & T_WHEELMASK) >> ADC_MSbyte_SHIFT;
    displayIndex = thumbval*GPS_DISPLAY_LIMIT;
    
    /* Clear the Display Buffers */
    for(count = CLEAR_INDEX; count < LCD_DISPLAY_LIMIT; ++count) {
       LCDdisplayBottom[count] = LCDdisplayTop[count] = CLEAR_INDEX;
     }
    /* Initialize the Strings */
    initDisplayStrings(LCDdisplayTop, LCDdisplayBottom);
    
    /* Determine what you want to display */
    if (displayIndex <= topStrSize){ /* Check to see if index is displayable */
        for (count = strlength(LCDdisplayTop); count < LCD_DISPLAY_LIMIT; ++count){
            LCDdisplayTop[count] = TopStr[displayIndex++];
            if (displayIndex > topStrSize) break;
        }
    }
    if (displayIndex <= bottomStrSize){ /* Check to see if index is displayable */
        for (count = strlength(LCDdisplayBottom); count < LCD_DISPLAY_LIMIT; ++count){
            LCDdisplayBottom[count] = BottomStr[displayIndex++];
            if (displayIndex > bottomStrSize) break;
        }
    }
    /* Display your creations */
    clearScreen();
    DisplayString(LCD_LINE1, LCDdisplayTop);
    DisplayString(LCD_LINE2, LCDdisplayBottom);
    DisplayDelay(2*DISPLAY_DELAY);
}
    
/*******************************************************************************
* Purpose: Clears numbers pointed, in a concise manner.
* Passed: Pointers to integers to be cleared.
* Locals: No local variables used.
* 
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void gpsCleanUp(int * numberToClear1, int * numberToClear2) {
    *numberToClear1 = CLEAR_INDEX;
    *numberToClear2 = CLEAR_INDEX;
}

void initDisplayStrings(char * topStr, char * botStr) {
    int index = CLEAR_INDEX; // index for loop
    char topInitStr[] = "LAT ";
    char bottomInitStr[] = "LON ";
    
    // Initialize the strings to the predefined string
    while (topInitStr[index]) {
        topStr[index] = topInitStr[index];
        ++index;
    }
    index = CLEAR_INDEX; // reset the index 
    while (bottomInitStr[index]) {
        botStr[index] = bottomInitStr[index];
        ++index;
    }
}