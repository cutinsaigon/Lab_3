/*
 * fsm_automatic.c
 *
 *  Created on: Oct 23, 2023
 *      Author: USER
 */

#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "global.h"
#include "timer.h"
#include "input_reading.h"
#include "main.h"
#include "led_display.h"

void fsm_automatic()
{
	switch (status)
    {
        case INIT: 
            status = RED_GREEN;          
            setTimer1(timeGREEN*1000);
            setTimer2(1000);
            is_button_pressed(0);
            break;  
        case RED_GREEN:
            ledSystem1(1);
            ledSystem2(3);
            if(timer1_flag == 1)
            {
                status = RED_AMBER;
                setTimer1(timeYELLOW*1000);
                setTimer2(1000);
            }
            if(timer2_flag == 1)
            {
            	updateClockBuffer(timeRED--, timeGREEN--);
            	if(timeGREEN == 0)
            	{
            		timeGREEN = 3;
            		timeRED = 2;
            	}
            	setTimer2(1000);
            }
            if(is_button_pressed(0) == 1)
            {
            	status = MAN_MODE1;
            }
            break;

        case RED_AMBER:
        	ledSystem1(1);
        	ledSystem2(2);
            if(timer1_flag == 1)
            {
                status = GREEN_RED;
                setTimer1(timeGREEN*1000);
                setTimer2(1000);
            }
            if(timer2_flag == 1)
            {
            	updateClockBuffer(timeRED--, timeYELLOW--);
            	if(timeYELLOW == 0)
            	{
            		timeYELLOW = 2;
            		timeRED = 5;
            	}
            	setTimer2(1000);
            }
            if(is_button_pressed(0) == 1)
            {
            	status = MAN_MODE1;
            }
            break;

        case GREEN_RED:
        	ledSystem1(3);
        	ledSystem2(1);
            if(timer1_flag == 1)
            {
                status = AMBER_RED;
                setTimer1(timeYELLOW*1000);
                setTimer2(1000);
            }
            if(timer2_flag == 1)
            {
            	updateClockBuffer(timeGREEN--, timeRED--);
            	if(timeGREEN == 0)
            	{
            		timeGREEN = 3;
            		timeRED = 2;
            	}
            	setTimer2(1000);
            }
            if(is_button_pressed(0) == 1)
            {
            	status = MAN_MODE1;
            }
            break;

        case AMBER_RED:
        	ledSystem1(2);
        	ledSystem2(1);
            if (timer1_flag == 1)
            {
                status = RED_GREEN;
                setTimer1(timeGREEN*1000);
                setTimer2(1000);
            }
            if (timer2_flag == 1)
            {
            	updateClockBuffer(timeYELLOW--, timeRED--);
            	if(timeYELLOW == 0)
            	{
            		timeYELLOW = 2;
            		timeRED = 5;
            	}
            	setTimer2(1000);
            }
            if(is_button_pressed(0) == 1)
            {
            	status = MAN_MODE1;
            }
            break;

        default:
            break;         
    }
	
}
