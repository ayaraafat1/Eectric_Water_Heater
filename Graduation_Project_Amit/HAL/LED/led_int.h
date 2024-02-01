/*
 * led_int.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Aya Raafat
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#define LED_LOW      0
#define LED_HIGH     1
#define LED_TOGGLE   2


void LEDS_vidInt();
void LED1_vidSet(uint8 u8Stat);
void LED2_vidSet(uint8 u8Stat);
void LED3_vidSet(uint8 u8Stat);
void LED4_vidSet(uint8 u8Stat);
#endif /* HAL_LED_LED_INT_H_ */
