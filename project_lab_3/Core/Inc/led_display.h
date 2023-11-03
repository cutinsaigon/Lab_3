/*
 * led_display.h
 *
 *  Created on: Oct 14, 2023
 *      Author: USER
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void updateClockBuffer(int sys1, int sys2);
void display7SEG(int num);
void ledSystem1(int num);
void ledSystem2(int num);
void scanLed();

#endif /* INC_LED_DISPLAY_H_ */
