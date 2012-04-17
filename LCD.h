/******************************************************************************* 
 * File:  LCD.h
 * Author: Will Flores waflores@ncsu.edu
 * Usage:
 * Description: This file contains the defines for using a standard LCD 
 *              character module including init, delay, printf, and putch.
 * Environment: Windows 7, x64 build
 *              Built in HEW with MC16 Series Compiler V.5.44 Release 00
 * Notes:       NONE
 * Revisions:   0.0, Initial Release
 *              1.0, Better documented file
 * Created on March 12, 2012
 *******************************************************************************/

// These are used with printf.  They are standard places for printf to print to.  
// They may or may not be used in this program.

// DirectedPrintf Stuff
#ifndef LCD_H
#define LCD_H

#define pputch(a)       BNSPutch(where, a);if(where > GREATEST_FILE_NUMBER) (char *)where++;
#define STDIN  0        // this isn't used with printf, but is defined here for completeness.
#define STDOUT 1
#define STDERR 2
#define LCD		(LCD_FILE_NUM)
#define SERIAL		(SERIAL_FILE_NUM)
#define LCD_FILE_NUM	(1)
#define SERIAL_FILE_NUM (2)
#define GREATEST_FILE_NUMBER	(SERIAL_FILE_NUM)

/* The special bitmap characters are mapped to display values 0 to 7 */
#define LOGO		"waflores"

#define DATA_PORT       p9      // Data bus port
#define RS_PIN          p2_0    // RS Register Select pin
#define RS_PIN_MASK     0x0     // bit mask from entire port
#define RS_PIN_DDR      pd2_0   // RS pin DDR
#define EN_PIN          p2_1    // Display Enable pin
#define EN_PIN_MASK     0x02    // bit mask from entire port
#define EN_PIN_DDR      pd2_1   // EN pin DDR

#define PORT_DDR        pd9     // Data bus direction register
#define PORT_DDR_VALUE	0x0f	// Can't read DDR reg, so have can't OR values

#define DATA_WR         1
#define CTRL_WR         0

#define MAXIMUM_LINES           2       // number of lines on the LCD display
#define NUMB_CHARS_PER_LINE	8	// Maximum charactors per line of LCD display.  

#define LCD_LINE1 0
#define LCD_LINE2 16

/**********************************************************************************/
// LCD commands - use LCD_write function to write these commands to the LCD. 
/**********************************************************************************/
#define LCD_CLEAR        0x01    // Clear LCD display and home cursor   
#define LCD_HOME_L1      0x80    // move cursor to line 1               
#define LCD_HOME_L2      0xC0    // move cursor to line 2               
#define CURSOR_MODE_DEC  0x04    // Cursor auto decrement after R/W     
#define CURSOR_MODE_INC  0x06    // Cursor auto increment after R/W     
#define FUNCTION_SET     0x28    // Setup, 4 bits,2 lines, 5X7          
#define LCD_CURSOR_ON    0x0E    // Display ON with Cursor              
#define LCD_CURSOR_OFF   0x0C    // Display ON with Cursor off
#define LCD_CURSOR_BLINK 0x0D    // Display on with blinking cursor     
#define LCD_CURSOR_LEFT  0x10    // Move Cursor Left One Position       
#define LCD_CURSOR_RIGHT 0x14    // Move Cursor Right One Position      

#endif /* LCD_H */
