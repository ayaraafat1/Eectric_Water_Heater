/*
 * sw_pro.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Aya Raafat
 */
#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "../../MCAL/DIO/dio_int.h"
#include "sw_conf.h"
#include "sw_int.h"


void SW_vidInt(){
	DIO_vidSetPinDir(SW1_Pin,INPUT_PIN);
	DIO_vidSetPinVal(SW1_Pin,HIGH);
	DIO_vidSetPinDir(SW2_Pin,INPUT_PIN);
	DIO_vidSetPinVal(SW2_Pin,HIGH);
	DIO_vidSetPinDir(SW3_Pin,INPUT_PIN);
	DIO_vidSetPinVal(SW3_Pin,HIGH);
}
uint8 SW1_u8Read( ){
	return DIO_u8GetPinVal(SW1_Pin);
}
uint8 SW2_u8Read( ){
	return DIO_u8GetPinVal(SW2_Pin);
}

uint8 SW3_u8Read( ){
	return DIO_u8GetPinVal(SW3_Pin);
}

