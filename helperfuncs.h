/******************************************************************************* 
 * File:  helperfuncs.h
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

#ifndef HELPERFUNCS_H
#define	HELPERFUNCS_H

/* Split: tokenizes input by using delim,
*   the function returns a NULL terminated array of NULL terminated strings
*   or a NULL pointer, if memory cannot be allocated for the array.
*/
char ** Split(const char * input, const char delim);

/*  emptyStr: returns the string "*" when the Split function encounters
*   an empty token, thus preventing Segmentation and/or Protection Faults.
*   Prints error message and returns NULL if string cannot be generated.
*/
char * emptyStr(void);

/*  fillStr: returns the string indicated by the start pointer, sPtr, and
*   end pointer, ePtr. The string is trimmed of leading whitespaces and trailing
*   whitespaces before returned to the caller. Prints error message and returns
*   NULL if string cannot be generated.
*/
char * fillStr(char * sPtr, char* ePtr, char delim);
int strlength(char str[]);

//void destroyArray(char ** array);
//void safefree(char ** pp);

#endif	/* HELPERFUNCS_H */
