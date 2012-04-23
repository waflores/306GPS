/******************************************************************************* 
* File:  menus.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: All menu declarations shall be made in this file.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/
#ifndef MENUS_H
#define MENUS_H

//ADC resolutions (Items are defined as less than macro)
#define FIRST_MENU_VAL (102)
#define SECOND_MENU_VAL (204)
#define THIRD_MENU_VAL (306)
#define FOURTH_MENU_VAL (408)
#define FIFTH_MENU_VAL (510)
#define SIXTH_MENU_VAL (612)
#define SEVENTH_MENU_VAL (714)
#define EIGHT_MENU_VAL (816)
#define NINTH_MENU_VAL (918)
#define TENTH_MENU_VAL (1023)

#define INVALID_MENU_ITEM (-1)
#define FIRST_MENU_ITEM (0)
#define SECOND_MENU_ITEM (1)
#define THIRD_MENU_ITEM (2)
#define FOURTH_MENU_ITEM (3)
#define FIFTH_MENU_ITEM (4)
#define SIXTH_MENU_ITEM (5)
#define SEVENTH_MENU_ITEM (6)
#define EIGHTH_MENU_ITEM (7)
#define NINTH_MENU_ITEM (8)
#define TENTH_MENU_ITEM (9)

#define SONG_LVL_1 (18) // first time going backwards
#define SONG_LVL_2 (20) // going forward again
#define SONG_LVL_3 (38) // going backwards

#define DIR_INIT (1)
#define DIR_FWD_1 (1)
#define DIR_REV_1 (2)
#define DIR_FWD_2 (3)
#define DIR_REV_2 (4)
#define DIR_FWD_3 (5)
#define DIR_REV_3 (6)
#define DIR_FWD_4 (7)
#define DIR_REV_4 (8)
#define DIR_FWD_5 (9)
#define DIR_REV_5 (10)

void resistorMenu();
void shapeMenu();
void fightSongMenu();
int menuItemVal(int thumbVal);
void cheerFightSong();

#endif
