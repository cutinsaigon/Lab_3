/*
 * input_processing.c
 *
 *  Created on: Oct 14, 2023
 *      Author: USER
 */

# include "main.h"
# include "input_reading.h"
# include "input_processing.h"

int buffer_for_button1 = 0;

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState = BUTTON_RELEASED ;
void fsm_for_input_processing (void)
{
	switch (buttonState)
	{
		 case BUTTON_RELEASED:
		 //next, button is pressed
			if(is_button_pressed(0))
			{
				buttonState = BUTTON_PRESSED ;
			 // INCREASE VALUE OF PORT A BY ONE UNIT
			}
			break ;


		 case BUTTON_PRESSED:
		 // next, button is released
			if (!is_button_pressed(0))
			{
				buttonState = BUTTON_RELEASED ;
			}
			else
			{
				if(is_button_pressed_1s(0))
				{
					buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
				}
			}
			break ;
			//////////////////////////


		 case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		 // next, button is pressed
			if (!is_button_pressed(0))
			{
				 buttonState = BUTTON_RELEASED ;
			}
		 	// todo

			break;
	}
}


