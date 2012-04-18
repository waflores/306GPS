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

#define CLEAR_INDEX 0
#define NEXT_ELEMENT 1
#define SPACER 2 /* Space between last char and NULL */
#define DELIMITER_LOCATION 1
#define MIN_SIZE_OF_TOKEN 1
#define SIZE_OF_NO_TOKEN 0
#define ERR_CNOTFOUND -1
#define NUM_SENTENCES 4
#define SENTENCE_LEN 16
/*------------------------------------------------------------------------------
Gets the index of a character in a string of size n starting at index i
mgyenik
------------------------------------------------------------------------------*/
int get_index(char c, char* str, int n, int i){
    for(i; i<n; i++){
        if(str[i] == c)
            return i;
    }
    return ERR_CNOTFOUND;
}
    
/*------------------------------------------------------------------------------
Crappy function that copies a nmea sentences from an array into some other arrays.
CHECK YO BOUNDS NIGGA, ELSE YOU STACK BE HURTIN'
mgyenik
------------------------------------------------------------------------------*/
/*
void get_nmea_sentences(char* in, char** out){
    int out_index = CLEAR_INDEX;
    int index = CLEAR_INDEX;
    int next_index = CLEAR_INDEX;
    index = get_index('$', u2BUFFER, BUF_LEN, index);
    while((index < BUF_LEN) && (out_index < NUM_SENTENCES)){
        // globalbuf == u2Buffer
        // implement strncpy
        next_index = get_index('$', u2BUFFER, BUF_LEN, index);
        lol_strncpy(globalbuf, out[out_index], index, next_index);
        out_index++;
        index = next_index;
    }
}
*/

/*******************************************************************************
* Purpose: Tokenizes a string with a delimiter.
* Passed: Input string and character delimter.
* Locals: char * inStr - Input Stream Pointer
*         char * prevStr - Previous occurance pointer
*         char ** output - result array
*         unsigned int i - Elements in output array
* 
* Returned: A null terminated array of strings.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
char ** Split(const char * input, const char delim) {
/* what if the string doesn't have anything to tokenize ? */
    char * inStr = NULL;   /* Input stream pointer */
    char * prevStr = NULL; /* Previous occurance pointer */
    char ** output = NULL; /* Array of NULL terminated strings */
    unsigned int i = CLEAR_INDEX; /* Elements in the output array */
    
    /* Initialize the pointers so that the pointers point
    *   to the beginning of the string. */
    prevStr = (char *) input;
    inStr = prevStr;

    /* Initialize the output array */
    output = (char **) malloc(sizeof(char **));
    if (!output) {
        return NULL; /* malloc failed */
    }

    /* Line tokenizing loop: This loop will check for empty fields,
     * and correct that input, thus avoiding segmentation faults
     * when the buffer normalizing array is accessed.
     */
     while(*inStr){
     /* Check for delimeter */
         if(*inStr == delim){
             /* The input pointer matches the delimter */
             if(inStr - prevStr < MIN_SIZE_OF_TOKEN){ /* Check to see if the string is empty */
                 /* Empty string case */
                 output[i] = (char *) emptyStr();
             }
             else { /* Unempty string case */
                 output[i] = (char *) fillStr(prevStr, inStr-DELIMITER_LOCATION, delim);
             }
             /* Create another array element for strings to reside */
             ++i; /* add another element to output ** */
             output = (char **) realloc(output, (i+NEXT_ELEMENT) * sizeof(char **));
             if(!output) {
                 return NULL;
             }
             /* Set pointers for the next token */
             inStr++;
             prevStr = inStr;
         }
         /* check for the end of the buffer */
         else if((*inStr == '\r') || (*inStr == '\n') || (*inStr == '\0') ){
             /* We reached the end of the buffer, the field could be empty */
             if(inStr - prevStr < 1) output[i] = (char *) emptyStr(); /* Empty string case */
             else output[i] = (char *) fillStr(prevStr, inStr-DELIMITER_LOCATION, delim); /* Unempty string case */
             *inStr = CLEAR_INDEX; /* Break out of the tokenization loop */
         }
         /* for all other inputs */
         else inStr++; /* Keep moving along the input string */
     } /* End of tokenization loop */

    /* Terminate the output array with a NULL */
    ++i; /* add another element to output ** */
    output = (char **) realloc(output, (i+NEXT_ELEMENT) * sizeof(char **));
    if(!output) {
        return NULL;
    }
    output[i] = NULL;
    return output;
}

/*******************************************************************************
* Purpose: returns a trimmed string indicated by a start pointer and end pointer.
* Passed: Start pointer, End pointer, and Delimeter
* Locals: char * s - trimmed return string
* 
* Returned: A trimmed return string.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
char * fillStr(char * sPtr, char* ePtr, char delim) {
    char * s = NULL; /* string to be returned after trimming and trailing operations on string */
    
    /* Check if both pointers are not NULL and trim the respective whitespaces */
    if(sPtr && ePtr) {
        while(isspace(*sPtr)){
           if(sPtr < ePtr) ++sPtr;
           else break;
        }
	while((*ePtr == delim) || isspace(*ePtr)) {
            if (ePtr > sPtr) --ePtr;
            else break;
        }
    }
    else {
        return NULL; /* either pointer is NULL */
    }

    /* Check to see if we overran pointers in our token */
    /* Gracefully handles fields that are only spaces */
    if((ePtr-sPtr) < SIZE_OF_NO_TOKEN) return emptyStr(); 
    /* Single character token fix */
    else if (((ePtr-sPtr) == SIZE_OF_NO_TOKEN) && (*ePtr == delim))  return emptyStr();
    
    /* Allocate space for new string */
    s = (char *) malloc( (ePtr-sPtr+SPACER) * sizeof(char));
    if(!s) {
        return NULL;
    }

    /* Clear out garbage in new space */
    memset(s, CLEAR_INDEX, (ePtr-sPtr+SPACER) * sizeof(char));

    /* Copy string data to allocated space,
     * which is the difference of the end and start ptrs plus SPACER - 1 */
    return (char *) memmove(s, sPtr, (ePtr-sPtr+DELIMITER_LOCATION) * sizeof(char));
}

/*******************************************************************************
* Purpose: returns the string "*" when the Split functions encounters an empty 
*          token. Thus preventing Segfaults. 
* Passed: No values passed.
* Locals: char * s - "*" return string
*         int i - loop variable
* 
* Returned: A trimmed return string.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
char * emptyStr(void) {
    int i; /* counter vars */
    char * s = NULL; /* clear the string */
    s = (char *) malloc(SPACER * sizeof(char)); /* string to be returned */
    
    /* Check if malloc failed */
    if(!s) {
        return NULL; /* malloc failed */
    }
    /* Clear string out */
    for(i = CLEAR_INDEX; i < SPACER; ++i){
        s[i] = CLEAR_INDEX;
    }
    /* Fill the array with a non-NULL item */
    return strncpy(s, "*", strlen("*"));
}

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

/* destroyArray: frees the memory obtained by a null terminated array */
//void destroyArray(char** array) {
 //   int index; /* Index of char ** */
    
    /* free every index in the array, provided that there's something to free */
 //   if (array) {
 //       for (index = 0; array[index] != NULL; ++index) {
 //           safefree(&array[index]);
 //       }
 //       safefree(&array[index]);
 //       safefree(array);
//    }
    
//}

/*
void safefree(char **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}
&*/
