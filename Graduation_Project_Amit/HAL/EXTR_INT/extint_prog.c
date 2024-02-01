/*
 * extint_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: hp
 */
#include "../../Serv/std.h"
#include "../../MCAL/DIO/dio_int.h"
#include "../../MCAL/EXT/ext_init.h"
#include "extrint_conf.h"
#include "extrint_init.h"

void EXTR_vidInit(uint8 u8INTCopy,uint8 u8StCopy){
	DIO_vidSetPinDir(INT_PIN,INPUT_PIN);
	DIO_vidSetPinVal(INT_PIN,HIGH);
	EXT_vidInit(u8INTCopy,u8StCopy);
}

void EXTR_vidISR0FUN(void (*FUN_ISR)(void)){
	ISR_FUN_INT0=FUN_ISR;
}
void EXTR_vidISR1FUN(void (*FUN_ISR)(void)){
	ISR_FUN_INT1=FUN_ISR;
}
void EXTR_vidISR2FUN(void (*FUN_ISR)(void)){
	ISR_FUN_INT2=FUN_ISR;
}

