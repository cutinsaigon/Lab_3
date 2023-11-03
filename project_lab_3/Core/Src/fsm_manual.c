/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2023
 *      Author: USER
 */
#include "main.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "global.h"
#include "timer.h"
#include "input_reading.h"
#include "led_display.h"


void fsm_manual()
{
	switch(status)
	{
		// Mode AUTO run as fsm_automatic
		case AUTO:
			status = INIT;
			setTimer1(timeGREEN*1000);
			setTimer2(1000);
			updateClockBuffer(timeRED--, timeGREEN--);
			if(is_button_pressed(0) == 1)
			{
				status = MAN_MODE1;
				setTimer1(500);
				setTimer2(1000);
			}
			break;

		case MAN_MODE1:
			// Display only RED LED
			ledSystem1(1);
			ledSystem2(1);
			if(timer1_flag == 1)
			{
				HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
				setTimer1(500);
			}
			if(is_button_pressed(0) == 1)
			{
				status = MAN_MODE2;
				setTimer1(500);
				setTimer2(1000);
			}
			if(is_button_pressed(1) == 1)
			{
				tempRED++;
				// Display current value of tempRED
				updateClockBuffer(1, tempRED);
				if(tempRED > 99)
				{
					tempRED = 0;
				}
			}
			if(is_button_pressed(2) == 1)
			{
				// Set timeRED = tempRED
				timeRED = tempRED;
			}
			if(timer2_flag == 1)
			{
				// Count down setting time value;
				updateClockBuffer(1, timeRED--);
				setTimer2(1000);
			}


		case MAN_MODE2:
			// Display only YELLOW LED
			ledSystem1(2);
			ledSystem2(2);
			if (timer1_flag == 1)
			{
				HAL_GPIO_TogglePin(YELLOW_GPIO_Port, YELLOW_Pin);
				HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			}
			if (is_button_pressed(0) == 1)
			{
				status = MAN_MODE3;
				setTimer1(500);
				setTimer2(1000);
			}
			if (is_button_pressed(1) == 1)
			{
				tempRED++;
				// Display current value of tempRED
				updateClockBuffer(2, tempYELLOW);
				if (tempYELLOW > 99)
				{
					tempYELLOW = 0;
				}
			}
			if (is_button_pressed(2) == 1)
			{
				// Set timeYELLOW = tempYELLOW
				timeYELLOW = tempYELLOW;
			}
			if (timer2_flag == 1)
			{
				// Count down setting time value;
				updateClockBuffer(2, timeYELLOW--);
				setTimer2(1000);
			}

		case MAN_MODE3:
			ledSystem1(2);
			ledSystem2(2);
			if (timer1_flag == 1)
			{
				HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
				HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			}
			if (is_button_pressed(0) == 1)
			{
				status = AUTO;
				setTimer1(500);
				setTimer2(1000);
			}
			if (is_button_pressed(1) == 1)
			{
				tempGREEN++;
				// Display current value of tempRED
				updateClockBuffer(2, tempGREEN);
				if (tempGREEN > 99)
				{
					tempGREEN = 0;
				}
			}
			if (is_button_pressed(2) == 1)
			{
				// Set timeGREEN = tempGREEN
				timeGREEN = tempGREEN;
			}
			if (timer2_flag == 1)
			{
				// Count down setting time value;
				updateClockBuffer(2, timeGREEN--);
				setTimer2(1000);
			}
	}
}
