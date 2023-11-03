/*
 * led_display.c
 *
 *  Created on: Oct 14, 2023
 *      Author: USER
 */

#include "main.h"
#include "led_display.h"
#include "timer.h"
#include "fsm_automatic.h"

int led_buffer[4] = {0, 0, 0, 0};

void updateClockBuffer(int sys1, int sys2)
{

    if (sys2 <= 9)
    {
        led_buffer[3] = sys2;
        led_buffer[2] = 0;
    }
    else
    {
        led_buffer[3] = sys2 % 10;
        led_buffer[2] = sys2 / 10;
    }
    if (sys1 <= 9)
    {
        led_buffer[1] = sys1;
        led_buffer[0] = 0;
    }
    else
    {
        led_buffer[1] = sys1 % 10;
        led_buffer[0] = sys1 / 10;
    }
}
void update7SEG(int index)
{
    switch (index)
    {
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			// Display the second 7 SEG with led_buffer [1]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			// Display the third 7 SEG with led_buffer [2]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			// Display the forth 7 SEG with led_buffer [3]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
    }
}

void display7SEG(int num)
{

    if (num == 1)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    }

    else if (num == 2)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 3)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 4)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 5)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 6)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 7)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    }

    else if (num == 8)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }

    else if (num == 9)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    }
    else if (num == 0)
    {
        HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    }
}
// RED ON = 1 ; YELLOW ON = 2 ; GREEN ON = 3
void ledSystem1(int num)
{
	if(num == 1)
    {
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
		
    }
    else if(num == 2)
    {
        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
 
    }
    else if(num == 3)
    {
        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);
 
    }
}

void ledSystem2(int num)
{
    if(num == 1)
    {
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
    }

    else if(num == 2)
    {
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
    }

    else if(num == 3)
    {
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
    }
    
}
int index_led = 0;

void scanLed()
{
    // display time in LED 7 SEGMENT
    if (timer3_flag == 1)
    {
        update7SEG(index_led++);
        if (index_led > 3)
            index_led = 0;
        setTimer3(250);
    }
}
