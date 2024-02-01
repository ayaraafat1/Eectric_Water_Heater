/*
 * ext_prog.c
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */
#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "ext_reg.h"
#include "ext_conf.h"
#include "ext_init.h"

ISR(INT0_VECTRO){
	ISR_FUN_INT0();
}
ISR(INT1_VECTRO){
	ISR_FUN_INT1();
}
ISR(INT2_VECTRO){
	ISR_FUN_INT2();
}


void EXT_vidControlInt0(uint8 u8StCopy);
void EXT_vidControlInt1(uint8 u8StCopy);
void EXT_vidControlInt2(uint8 u8StCopy);
void EXT_vidInit(uint8 u8ExtIntNum, uint8 u8ISRStCont){
	SET(SREG,GIE);
	switch(u8ExtIntNum){
	case INT0_CONF:
		EXT_vidControlInt0(u8ISRStCont);
		SET(GICR,INT0);
		break;
	case INT1_CONF:
		EXT_vidControlInt1(u8ISRStCont);
		SET(GICR,INT1);
		break;
	case INT2_CONF:
		EXT_vidControlInt2(u8ISRStCont);
		SET(GICR,INT2);
		break;
	}
}

void EXT_vidControlInt0(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		CLEAR(MCUCR,ISC00);
		SET(MCUCR,ISC01);
		break;
	case RISSING:
		SET(MCUCR,ISC00);
		SET(MCUCR,ISC01);
		break;
	case LOW_:
		CLEAR(MCUCR,ISC00);
		CLEAR(MCUCR,ISC01);
		break;
	case ANY_LOG:
		SET(MCUCR,ISC00);
		CLEAR(MCUCR,ISC01);
		break;
	}
}
void EXT_vidControlInt1(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		CLEAR(MCUCR,ISC10);
		SET(MCUCR,ISC11);
		break;
	case RISSING:
		SET(MCUCR,ISC10);
		SET(MCUCR,ISC11);
		break;
	case LOW_:
		CLEAR(MCUCR,ISC10);
		CLEAR(MCUCR,ISC11);
		break;
	case ANY_LOG:
		SET(MCUCR,ISC10);
		CLEAR(MCUCR,ISC11);
		break;
	}
}
void EXT_vidControlInt2(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		CLEAR(MCUCSR,ISC2);
		break;
	case RISSING:
		SET(MCUCSR,ISC2);
		break;
	}
}
