/******************************************************************************* 
* File:  serial.c
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file initializes the UART capabilities for the QSK.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
* Created on March 12, 2012
*******************************************************************************/

#include "QSKDefines.h"
#include "helperfuncs.h"
#include "proto.h"
#include "serial.h"
#include "ports.h"
#include "extern.h"

volatile unsigned int u0_rd; // buffer indices
volatile unsigned int u0_wr;
volatile unsigned int u2_rd;
volatile unsigned int u2_wr;
volatile unsigned char u0BUFFER[U0_BUF_SIZE];
volatile unsigned char u2BUFFER[U2_BUF_SIZE];
volatile unsigned char u2BuffFull;

/*******************************************************************************
* Purpose: Sets up UART1 for 4800 N 8 1 and is used for debug status messages.
*          It uses interrupts for receive.  Transmit is done through polling.
* Passed: No arguments passed.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void InitUART(void) {
    // page 199 - hardware manual
    int i; // variable to clear the u0Buffer
    
    /* Set the UART0 bit rate generator to generate 4800 BAUD */
    //u0brg = (unsigned char) (((f1_CLK_SPEED/16)/BAUD_RATE)-1);
    
    u0brg = (unsigned char) (((f1_CLK_SPEED/16)/BAUD_RATE)-1); // 4800 BAUD
    /* UART transmit/receive control register 2 */
    ucon = INIT_UART0_UART1;

    /* UART0 transmit/receive control register 0 */
    u0c0 = CLEAR_REGISTER;
    u0c0 |= LSB_FIRST;
    u0c0 |= F8SIO_SELECTED;
    u0c0 |= CTS_RTS_DISABLED;

    /* UART0 transmit/receive control register 1 */ 
    u0c1 = CLEAR_REGISTER;

    // UART0 transmit/receive mode register, not reversed
    /* Data = 8 bits longs
     * 1 stop bit
     * No parity
     * No Polarity reverse  
     */
    u0mr = DATA_EIGHT_BITS_LONG;
    
    u0tb = u0rb;	// clear UART0 receive buffer by reading
    u0tb = CLEAR_REGISTER; // clear UART0 transmit buffer

    u0_wr = u0_rd = CLEAR_INDEX; // clear these indices
    // Clear the u0 buffer
    for (i = CLEAR_INDEX; i< U0_BUF_SIZE; ++i) u0BUFFER[i] = CLEAR_INDEX;
    
    DISABLE_IRQ		 // disable irqs before setting irq registers
    ENABLE_RX0_INTERRUPTS // Enable UART0 receive interrupt, priority level 4	
    ENABLE_IRQ		 // Enable all interrupts

    // UART0 transmit/receive control register 1
    u0c1 = TRANSMIT_RECEIVE_ENABLED;
    
    // UART2 setup 
    u2brg = (unsigned char) (((f1_CLK_SPEED/16/8)/BAUD_RATE)-1); // 4800 BAUD
    
    /* UART2 transmit/receive control register 0 */
    u2c0 = CLEAR_REGISTER;
	//u2c0 = 0x01;
    //u2c0 |= LSB_FIRST;
    u2c0 |= F8SIO_SELECTED;
    u2c0 |= CTS_RTS_DISABLED;
    
    /* UART2 transmit/receive control register 1 */ 
    u2c1 = CLEAR_REGISTER;
    
    // UART2 transmit/receive mode register, not reversed
    /* Data = 8 bits longs
     * 1 stop bit
     * No parity
     * No Polarity reverse  
     */
    u2mr = DATA_EIGHT_BITS_LONG;
    
    u2tb = u2rb;	// clear UART0 receive buffer by reading
    u2tb = CLEAR_REGISTER; // clear UART0 transmit buffer

    u2_wr = u2_rd = CLEAR_INDEX; // clear these indices
    // Clear the u2 buffer
    for (i = CLEAR_INDEX; i< U2_BUF_SIZE; ++i) u2BUFFER[i] = CLEAR_INDEX;
    u2BuffFull = FALSE;
    
    DISABLE_IRQ		 // disable irqs before setting irq registers
    ENABLE_RX2_INTERRUPTS // Enable UART2 receive interrupt, priority level 4	
    ENABLE_IRQ		 // Enable all interrupts
    
    // UART2 transmit/receive control register 1
    u2c1 = TRANSMIT_RECEIVE_ENABLED;
}

/*******************************************************************************
* Purpose: Transmit a string through UART2 at 4800 baud. Transmit is done thru
*          polling.
* Passed: char * transmitStr - the message needed to be transmitted.
* Locals: int transmitLength - length of string to be transmitted
*         int count - loop control variable
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void transmitUART2(char * transmitStr) {
    int transmitLength;
    int count;
    /* Transmit loop */
    LED0 = LED_ON;
    transmitLength = CLEAR_INDEX;
    count = CLEAR_INDEX;
    transmitLength = strlength(transmitStr);
    clearScreen();
    BNSPrintf(LCD, "\tTransmit ");
    DisplayDelay(TRANSMIT_DELAY);
    
    for (count = CLEAR_INDEX; count < transmitLength; ++count) {
        while(ti_u2c1 == TRANSMITTING); // wait until the transmit is complete
        u2tb = transmitStr[count];
    }
    BNSPrintf(LCD, "\t\n Done...");
    DisplayDelay(DISPLAY_DELAY);
    LED0 = LED_OFF;
}

/*******************************************************************************
* Purpose: Displays the UART2 stream.
* Passed: No values passed.
* Locals: char * receiveMsg - the receive buffer to be displayed.
*         int count - loop control variable.
*         int msgIndex - index in message received.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void displayUART2Stream(void) {
    int count; // Loop variable
    int msgIndex; // msg index
    char receiveMsg[MSG_BUFFER];
    
    /*Display the Feedbacked transmission */
    if (u2_wr != u2_rd) {
        for (count = CLEAR_INDEX; count < U2_BUF_SIZE; ++count) {
                receiveMsg[count] = CLEAR_CHAR;
            }
            msgIndex = CLEAR_INDEX;
        while (u2_wr != u2_rd) {
            receiveMsg[msgIndex++] = u2BUFFER[u2_rd++];
            if (msgIndex >= MSG_BUFFER) break;
            else if (u2_rd >= U2_BUF_SIZE) {
                u2_rd = CLEAR_INDEX;
            }
        }
    }
    clearScreen();
    DisplayString(LCD_LINE1, receiveMsg);
    DisplayDelay(DISPLAY_DELAY);
}
