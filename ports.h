/******************************************************************************* 
* File:  ports.h
* Author: Will Flores waflores@ncsu.edu
* Usage:
* Description: This file contains the function prototypes for the port
*              Initializations for this board.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header
* Created on March 12, 2012
*******************************************************************************/

#ifndef PORTS_H
#define	PORTS_H

#define INPUT 0
#define OUTPUT 1
#define INPUT_PORT 0x00
#define OUTPUT_PORT 0xFF
#define PIN_HIGH 1      /* Pin is active/ on */
#define PIN_LOW 0       /* Pin is inactive/ off */

/* Switches */
#define	SW1      p8_3 
#define SW2 	p8_1 
#define SW3 	p8_2 

/* Switch port direction register */
#define SW1_DDR	pd8_3
#define SW2_DDR	pd8_1
#define SW3_DDR	pd8_2

/* Switch Properties */
#define BUTTON_PRESSED PIN_LOW
#define BUTTON_RESET PIN_HIGH // Button not Pressed

#define DEFAULTS 0x0000
#define MULTIPLE_BUTTONS 2
#define SINGLE_BUTTONS 1
#define TWO_BTN_COMBO_1 0x03
#define TWO_BTN_COMBO_2 0x05
#define SW1_PRESSED 0x01 // Bit2
#define SW2_PRESSED 0x02 // Bit3
#define SW3_PRESSED 0x04 // Bit4

/* LEDs */
#define	LED0	p8_0
#define	LED1	p7_4
#define	LED2	p7_2

/* LED port direction register */
#define	LED0_DDR        pd8_0		
#define	LED1_DDR 	pd7_4
#define	LED2_DDR        pd7_2

/* LED States */
#define LED_ON  PIN_LOW
#define LED_OFF PIN_HIGH

/* GPS Signal Names */
#define GPS_RESET p3_5
#define GPS_PWR p3_6
#define GPS_PWRCHK p9_7
#define GPS_PWRCTRL p3_4
/* ports 6 & 9 need to be configured bit by bit */
/* some ports need to be configured for power - read hardware manual */

/* Port Initialization functions */
void init_ports(void);
void init_port0(void);
void init_port1(void);
void init_port2(void);
void init_port3(void);
void init_port4(void);
void init_port5(void);
void init_port6(void);
void init_port7(void);
void init_port8(void);
void init_port9(void);
void init_port10(void);

#endif	/* PORTS_H */
