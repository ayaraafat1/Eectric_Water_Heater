/*
 * led_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Aya Raafat
 */

#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "../../MCAL/DIO/dio_int.h"
#include "led_conf.h"
#include "led_int.h"



void LEDS_vidInt(){
	DIO_vidSetPinDir(LED1_PIN,OUTPUT_PIN);
	DIO_vidSetPinVal(LED1_PIN,LOW);
	DIO_vidSetPinDir(LED2_PIN,OUTPUT_PIN);
	DIO_vidSetPinVal(LED2_PIN,LOW);
	DIO_vidSetPinDir(LED3_PIN,OUTPUT_PIN);
	DIO_vidSetPinVal(LED3_PIN,LOW);
	DIO_vidSetPinDir(LED4_PIN,OUTPUT_PIN);
	DIO_vidSetPinVal(LED4_PIN,LOW);
}

void LED1_vidSet(uint8 u8Stat){
	DIO_vidSetPinVal(LED1_PIN,u8Stat);
}

void LED2_vidSet(uint8 u8Stat){
	DIO_vidSetPinVal(LED2_PIN,u8Stat);
}

void LED3_vidSet(uint8 u8Stat){
	DIO_vidSetPinVal(LED3_PIN,u8Stat);
}

void LED4_vidSet(uint8 u8Stat){
	DIO_vidSetPinVal(LED4_PIN,u8Stat);
}
