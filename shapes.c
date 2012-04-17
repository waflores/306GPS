/******************************************************************************* 
* File:  shapes.c
* Author: Will Flores waflores@ncsu.edu
* Usage: Implementation of 'shapes.h'.
* Description: This file contains the functions for shapes for this vehicle.
* Environment: Windows 7, x64 build
*              Built in HEW with MC16 Series Compiler V.5.44 Release 00
* Notes:       NONE
* Revisions:   0.0, Initial Release
*              1.0, Better documented file header with function headers
* Created on March 12, 2012
*******************************************************************************/

#include "proto.h"
#include "shapes.h"
#include "movement.h"
#include "extern.h"
#include "ports.h"
#include "QSKDefines.h"

/* Right Circle Parameters */
#define RC_LEFTON (2) 
#define RC_RIGHTON (4) 
#define RC_SMALLDELAY (10)

/* Left Circle Parameters */
#define LC_LEFTON (5)
#define LC_RIGHTON (4)
#define LC_SMALLDELAY (10)

/*******************************************************************************
* Purpose: Moves the car in a right circle however many circle segments
*          designated by the 'numCircles' parameter.
* Passed: int numCircles - number of segments of a circle to move.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void rightCircle (int numCircles) {
    while (numCircles > NO_MORE_SHAPES){
        set_rWheelCount(RC_RIGHTON);
        set_lWheelCount(RC_LEFTON);
        start_wheelTimers();
        move_forward();

        while(timerB0_started || timerA0_started) {
            if (!timerA0_started) {
                set_lWheelCount(RC_LEFTON);
                timerDelay(RC_SMALLDELAY);
                while(timerA1_started); // pause for 25 ms
                start_leftWheel();
                left_motor_forward();
            }
        }// end inner while loop
        numCircles--;
    } // end outer while loop	
    return;
}

/*******************************************************************************
* Purpose: Moves the car in a left circle however many circle segments
*          designated by the 'numCircles' parameter.
* Passed: int numCircles - number of segments of a circle to move.
* Locals: No locals variables used.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void leftCircle (int numCircles) {
    while (numCircles > NO_MORE_SHAPES){
        set_lWheelCount(LC_LEFTON);
        set_rWheelCount(LC_RIGHTON);
        start_wheelTimers();
        move_forward();
        
        while(timerB0_started || timerA0_started) {
            if (!timerB0_started) {
                set_rWheelCount(LC_RIGHTON);
                timerDelay(LC_SMALLDELAY);
                start_rightWheel();
                right_motor_forward();
            }
        }// end inner while loop
        numCircles--;
    } // end outer while loop	
    return;
} 

/*******************************************************************************
* Purpose: Moves the car in a triangle for however many triangle segments
*           designated by the numTriangles parameter.
* Passed: int numTriangles - number of triangles to do.
* Locals: unsigned int turn - the amount of an arc to turn between segements.
*         unsigned int delay - the amount of delay between segments.
*         unsigned int tri_leg - the amount of time doing a segment.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void triangle (int numTriangles) {
    unsigned int turn = 150; // orig = 200 
    unsigned int delay = 100;
    unsigned int tri_leg = 300;

    for(; numTriangles > NO_MORE_SHAPES; --numTriangles) {
        // first leg
        set_lWheelCount(tri_leg);
        set_rWheelCount(tri_leg);
        start_wheelTimers();
        move_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(delay); // a second delay
        while (timerA1_started);

        // turn some
        set_rWheelCount(turn);
        start_rightWheel();
        right_motor_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(delay); // a second delay
        while (timerA1_started);


        // next leg
        set_lWheelCount(tri_leg);
        set_rWheelCount(tri_leg);
        start_wheelTimers();
        move_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(delay); // a second delay
        while (timerA1_started);

        // turn somemore
        set_rWheelCount(turn);
        start_rightWheel();
        right_motor_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(delay); // a second delay
        while (timerA1_started);

        // home stretch
        set_lWheelCount(tri_leg);
        set_rWheelCount(tri_leg);
        start_wheelTimers();
        move_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(delay); // a second delay
        while (timerA1_started);

        // turn a bit and done
        set_rWheelCount(turn);
        start_rightWheel();
        right_motor_forward();
        while(timerB0_started || timerA0_started);
        timerDelay(2*delay); // a 2 second delay
        while (timerA1_started);
    }
    return;	
}

/*******************************************************************************
* Purpose: Moves the car in a figure 8 motion once.
* Passed: No arguments passed.
* Locals: unsigned int left_circ - how many segments of a left circle to do.
*         unsigned int right_circ - how many segments of a right circle to do.
*         unsigned int fig_delay - a delay between circles.
* Returned: No values returned.
* Author: Will Flores waflores@ncsu.edu
*******************************************************************************/
void figure8 (void) {
    unsigned int left_circ = 27; // left circle circumference
    unsigned int right_circ = 3*27; // right circle circumference
    unsigned int fig_delay = 100; // a 1 second delay between circles

    /* figure 8 time! */
    leftCircle(left_circ);
    timerDelay(fig_delay);
    while(timerA1_started);
    rightCircle(right_circ);
    return;
}
