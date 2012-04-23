/******************************************************************************* 
* File:  menus.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the Menu functions.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*
* Created on April 12, 2012
*******************************************************************************/
#include "menus.h"
#include "proto.h"
#include "ports.h"
#include "QSKDefines.h"
#include "extern.h"

/*******************************************************************************
 * Purpose: This function allows the user to view resistor values by scrolling 
 *          through them.
 * Passed: No arguments passed.
 * Locals: int menuItem - the selected menu item from the thumbwheel.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void resistorMenu() {
    int menuItem = CLEAR_INDEX;
    LED0 = LED_ON; // Turn the Button's LED on 
    while(!buttonPressed){
        menuItem = menuItemVal(T_WHEEL);
        clearScreen();
        switch (menuItem) {
            case FIRST_MENU_ITEM:
                DisplayString(LCD_LINE1,"    0");
                DisplayString(LCD_LINE2,"  Black");
                //BNSPrintf(LCD, "\t  Black\n    0");
                break;
            case SECOND_MENU_ITEM:
                DisplayString(LCD_LINE1,"    1");
                DisplayString(LCD_LINE2,"  Brown");
                //BNSPrintf(LCD, "\t  Brown\n    1");
                break;
            case THIRD_MENU_ITEM:
                DisplayString(LCD_LINE1,"    2");
                DisplayString(LCD_LINE2,"   Red");
                //BNSPrintf(LCD, "\t   Red\n    2");
                break;
            case FOURTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    3");
                DisplayString(LCD_LINE2," Orange");
                //BNSPrintf(LCD, "\t Orange\n    3");
                break;
            case FIFTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    4");
                DisplayString(LCD_LINE2," Yellow");
                //BNSPrintf(LCD, "\t Yellow\n    4");
                break;
            case SIXTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    5");
                DisplayString(LCD_LINE2,"  Green");
                //BNSPrintf(LCD, "\t  Green\n    5");
                break;
            case SEVENTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    6");
                DisplayString(LCD_LINE2,"  Blue");
                //BNSPrintf(LCD, "\t  Blue\n    6");
                break;
            case EIGHTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    7");
                DisplayString(LCD_LINE2," Violet");
                //BNSPrintf(LCD, "\t  Violet\n    7");
                break;
            case NINTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    8");
                DisplayString(LCD_LINE2,"  Gray");
                //BNSPrintf(LCD, "\t  Gray\n    8");
                break;
            case TENTH_MENU_ITEM:
                DisplayString(LCD_LINE1,"    9");
                DisplayString(LCD_LINE2,"  White");
                //BNSPrintf(LCD, "\t  White\n    9");
                break;
            default:
                BNSPrintf(LCD, "\tBroken\n %d", T_WHEEL);
                break;
        }
        DisplayDelay(DISPLAY_DELAY);
    }
    LED0 = LED_OFF; // Clean up 
}

/*******************************************************************************
 * Purpose: This function allows the user to view shapes by scrolling through
 *          them.
 * Passed: No arguments passed.
 * Locals: int menuItem - the selected menu item from the thumbwheel.
 *          _far char * shapes[] - the shapes that we need to look through.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void shapeMenu() {
    int menuItem = CLEAR_INDEX;
	_far char * shapes[] = {
        "Circle",
        "Square",
        "Triangle",
        "Octagon",
        "Pentagon",
        "Hexagon",
        "Cube",
        "Oval",
        "Sphere",
        "Cylinder"
	};
    
    LED1 = LED_ON; // Turn the Button's LED on 
    while(!buttonPressed){
        menuItem = menuItemVal(T_WHEEL);
		if (menuItem == TENTH_MENU_ITEM) menuItem = NINTH_MENU_ITEM;
		clearScreen();
        DisplayString(LCD_LINE1, shapes[menuItem]);
		DisplayString(LCD_LINE2, shapes[menuItem + SECOND_MENU_ITEM]);
        DisplayDelay(DISPLAY_DELAY);
    }
    LED1 = LED_OFF;
}

/*******************************************************************************
 * Purpose: This function sets the fight song up so that the thumbwheel is in 
 *          the correct position for it to start.
 * Passed: No arguments passed.
 * Locals: int menuItem - the selected menu item from the thumbwheel.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void fightSongMenu() {
    int menuItem = CLEAR_INDEX;
    LED2 = LED_ON;
    while(!buttonPressed){
        menuItem = menuItemVal(T_WHEEL);
        clearScreen();
        if (menuItem != FIRST_MENU_ITEM) {
            DisplayString(LCD_LINE1, "Get to");
            DisplayString(LCD_LINE2, "1st item.");
        }
        else {
            cheerFightSong();
            break;
        }
        DisplayDelay(DISPLAY_DELAY);
    }
    LED2 = LED_OFF;
}

/*******************************************************************************
 * Purpose: This function allows the user to press a button which gives us menus.
 * Passed: No arguments passed.
 * Locals: int menuItem - the selected menu item from the thumbwheel.
 *         int dirChange - the direction that the scroll wheel is traveling.
 *         _far char * song[] - the song lyrics to the fight song.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
void cheerFightSong() {
    int menuItem = CLEAR_INDEX;
    int dirChange = DIR_INIT;
    _far char * song[] = { 
        "We're ","the ","Red ","and ","White ",
        "from ", "State ","And ", "we ", "know ",
        "we ", "are ","the ","best.","A ", "hand ",
        "behind ", "our ", "back, ","We ", "can ", "take ",
        "on ", "all ", "the ", "rest.", "Come ", "over ", 
        "the ", "hill,", "Carolina.","Devils ", "and ", "Deacs ", 
        "stand ", "in ", "line.", "The ", "Red ", "and ", "White ", 
        "from ", "N.C. ", "State. ", "Go ", "State!", NULL
    };
/* // Test Patterns for clarity
    _far char * song[] = {
        "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
        "16","17","18","19","20","21","22","23","24","25","26","27","28","29",
        "30","31","32","33","34","35","36","37","38","39","40", NULL
    };
    
*/
    while (!buttonPressed) {
        menuItem = menuItemVal(T_WHEEL);
        clearScreen();
        
        if (dirChange == DIR_FWD_1){
            if (menuItem == TENTH_MENU_ITEM) ++dirChange;
            DisplayString(LCD_LINE1, song[menuItem]);
            //DisplayString(LCD_LINE2, song[menuItem + SECOND_MENU_ITEM]);
        }
        else if (dirChange == DIR_REV_1) {
            if (menuItem == TENTH_MENU_ITEM) {
                DisplayString(LCD_LINE1, song[menuItem]);
                //DisplayString(LCD_LINE2, song[menuItem + SECOND_MENU_ITEM]);
            }
            else {
                DisplayString(LCD_LINE1, song[SONG_LVL_1 - menuItem]);
                //DisplayString(LCD_LINE2, song[SONG_LVL_1- menuItem + SECOND_MENU_ITEM]);
            }
            if (menuItem == FIRST_MENU_ITEM) ++dirChange;

        }
        else if (dirChange == DIR_FWD_2) {
            if (menuItem == TENTH_MENU_ITEM) ++dirChange;
            DisplayString(LCD_LINE1, song[SONG_LVL_2 + menuItem]);
            //DisplayString(LCD_LINE2, song[SONG_LVL_2 + menuItem + SECOND_MENU_ITEM]);
        }
        else if (dirChange == DIR_REV_2) {
            if (menuItem == TENTH_MENU_ITEM) {
                DisplayString(LCD_LINE1, song[SONG_LVL_2 + menuItem]);
                //DisplayString(LCD_LINE2, song[SONG_LVL_2 + menuItem + SECOND_MENU_ITEM]);
            }
            else {
                DisplayString(LCD_LINE1, song[SONG_LVL_3 - menuItem]);
                //DisplayString(LCD_LINE2, song[SONG_LVL_3- menuItem + SECOND_MENU_ITEM]);
            }
            if (menuItem == FIRST_MENU_ITEM) ++dirChange;
        }
        else if (dirChange == DIR_FWD_3) {
            /* Stay at the end of the fight song when we reach the end */
            if (menuItem >= EIGHTH_MENU_ITEM) menuItem = EIGHTH_MENU_ITEM;            
            DisplayString(LCD_LINE1, song[SONG_LVL_3 + menuItem]);
        }
        if (menuItem % BINARY == EVEN) DisplayString(LCD_LINE2, "     Red");
        else DisplayString(LCD_LINE2, "   White");
        DisplayDelay(DISPLAY_DELAY);
    }
}

/*******************************************************************************
 * Purpose: This function returns the menu item from an ADC source
 * Passed: No arguments passed.
 * Locals: No locals variables used.
 * Returned: No values returned.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
int menuItemVal(int thumbVal) {
    if (thumbVal < FIRST_MENU_VAL){
        return FIRST_MENU_ITEM;
    }
    else if ((thumbVal >= FIRST_MENU_VAL) && (thumbVal < SECOND_MENU_VAL)) {
        return SECOND_MENU_ITEM;
    }
    else if ((thumbVal >= SECOND_MENU_VAL) && (thumbVal < THIRD_MENU_VAL)) {
        return THIRD_MENU_ITEM;
    }
    else if ((thumbVal >= THIRD_MENU_VAL) && (thumbVal < FOURTH_MENU_VAL)) {
        return FOURTH_MENU_ITEM;
    }
    else if ((thumbVal >= FOURTH_MENU_VAL) && (thumbVal < FIFTH_MENU_VAL)) {
        return FIFTH_MENU_ITEM;
    }
    else if ((thumbVal >= FIFTH_MENU_VAL) && (thumbVal < SIXTH_MENU_VAL)) {
        return SIXTH_MENU_ITEM;
    }
    else if ((thumbVal >= SIXTH_MENU_VAL) && (thumbVal < SEVENTH_MENU_VAL)) {
        return SEVENTH_MENU_ITEM;
    }
    else if ((thumbVal >= SEVENTH_MENU_VAL) && (thumbVal < EIGHT_MENU_VAL)) {
        return EIGHTH_MENU_ITEM;
    }
    else if ((thumbVal >= EIGHT_MENU_VAL) && (thumbVal < NINTH_MENU_VAL)) {
        return NINTH_MENU_ITEM;
    }
    else if ((thumbVal >= NINTH_MENU_VAL) && (thumbVal <= TENTH_MENU_VAL)) {
        return TENTH_MENU_ITEM;
    }
    else {
        return INVALID_MENU_ITEM;
    }
}
