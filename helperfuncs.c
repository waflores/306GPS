/******************************************************************************* 
 * File:  helperfuncs.c
 * Author: Will Flores waflores@ncsu.edu
 * Usage: Implements String functionality.
 * Description: This file contains some string handling functionality.
 *              
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       The Timers are cut in half as far as duration is concerned
 * Revisions:   0.0, Initial Release
 * 
 * Created on April 12, 2012
 *******************************************************************************/
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "helperfuncs.h"

/*******************************************************************************
 * Purpose: This function counts the letters in a string.
 * Passed: Array of chars (a string).
 * Locals: count - counts the chars in a string.
 * Returned: Number of chars in a string.
 * Author: Will Flores waflores@ncsu.edu
 *******************************************************************************/
int strlength(char str[]) {
    int count = 0;
    while(str[count]) {
        ++count;
    }
    return count;
}

