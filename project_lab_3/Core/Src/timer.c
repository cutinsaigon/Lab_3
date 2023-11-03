/*
 * timer.c
 *
 *  Created on: Oct 14, 2023
 *      Author: USER
 */

# include "main.h"
# include "input_reading.h"
# include "timer.h"

#define TIMER_CYCLE 10

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

void setTimer1(int duration)
{
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}
void timerRun1()
{
	if (timer1_counter > 0)
	{
		timer1_counter--;
		if (timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
}

void setTimer2(int duration)
{
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}
void timerRun2()
{
	if (timer2_counter > 0)
	{
		timer2_counter--;
		if (timer2_counter <= 0)
		{
			timer2_flag = 1;
		}
	}
}

void setTimer3(int duration)
{
	timer3_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}
void timerRun3()
{
	if (timer3_counter > 0)
	{
		timer3_counter--;
		if (timer3_counter <= 0)
		{
			timer3_flag = 1;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	 if(htim->Instance	==	TIM2)
	 {
		button_reading();
		timerRun1();
		timerRun2();
		timerRun3();
	 }
}


