/*
 * dio_pro.c
 *
 *  Created on: Sep 8, 2023
 *      Author: hp
 */
#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "dio_priv.h"
#include "dio_int.h"

volatile uint8 *Arr_Dir[4]={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
volatile uint8 *Arr_PORT[4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};
volatile uint8 *Arr_PIN[4]={PINA_REG,PINB_REG,PINC_REG,PIND_REG};


void DIO_vidSetPortDir(uint8 u8PortVal,uint8 u8DirVal){
	if(u8PortVal <= PORTD){
		*Arr_Dir[u8PortVal]=u8DirVal;
	}
	else{
	}

}
void DIO_vidSetPortVal(uint8 u8PortVal,uint8 u8Val){
	if(u8PortVal <= PORTD){
		*Arr_PORT[u8PortVal]=u8Val;
	}
	else{
	}
}



uint8 DIO_u8GetPortVal(uint8 u8PortVal){
	uint8 Get_Port;
	if(u8PortVal <= PORTD){
		Get_Port=*Arr_PIN[u8PortVal];
	}
	else{
	}
	return Get_Port;
}

/*************PORTA[0~7]-PORTB[8~15]-PORTC[16~23]-PORTD[24~31]*************/

void DIO_vidSetPinDir(uint8 u8PinNum,uint8 u8DirVal){
	if(u8PinNum>=0 && u8PinNum<=31){
		if(u8DirVal == INPUT_PIN){
			CLEAR(*Arr_Dir[(u8PinNum/8)],(u8PinNum%8));
		}else if(u8DirVal == OUTPUT_PIN) {
			SET(*Arr_Dir[(u8PinNum/8)],(u8PinNum%8));
		}
	}
}
void DIO_vidSetPinVal(uint8 u8PinNum,uint8 u8PinVal){
	if(u8PinNum>=0 && u8PinNum<=31){
		if(u8PinVal == LOW){
			CLEAR(*Arr_PORT[(u8PinNum/8)],(u8PinNum%8));
		}else if(u8PinVal == HIGH) {
			SET(*Arr_PORT[(u8PinNum/8)],(u8PinNum%8));
		}else if(u8PinVal == TOGGLE_){
			TOGGLE(*Arr_PORT[(u8PinNum/8)],(u8PinNum%8));
		}
	}
}
uint8 DIO_u8GetPinVal(uint8 u8PinNum){
	uint8 Get_stat=0;
	if(u8PinNum>=0 && u8PinNum<=31){
		Get_stat=GET(*Arr_PIN[(u8PinNum/8)],(u8PinNum%8));
	}
	return Get_stat;
}


void DIO_vidSetPinSDir(uint8 *u8PinNum,uint8 u8DirVal,uint8 u8ArrNum){
	uint8 i=0;
	for(i=0;i<u8ArrNum;i++){
		if(u8PinNum[i]>=0 && u8PinNum[i]<=31){
			if(u8DirVal == INPUT_PIN){
				CLEAR(*Arr_Dir[(u8PinNum[i]/8)],(u8PinNum[i]%8));
			}else if(u8DirVal == OUTPUT_PIN) {
				SET(*Arr_Dir[(u8PinNum[i]/8)],(u8PinNum[i]%8));
			}
		}else{}
	}
}
void DIO_vidSetPinSVal(uint8 *u8PinNum,uint8 u8PVal,uint8 u8ArrNum){
	uint8 i=0;
	for(i=0;i<u8ArrNum;i++){
		if(u8PinNum[i]>=0 && u8PinNum[i]<=31){
			if(u8PVal == LOW){
				CLEAR(*Arr_PORT[(u8PinNum[i]/8)],(u8PinNum[i]%8));
			}else if(u8PVal == HIGH) {
				SET(*Arr_PORT[(u8PinNum[i]/8)],(u8PinNum[i]%8));
			}else if(u8PVal == TOGGLE_){
				TOGGLE(*Arr_PORT[(u8PinNum[i]/8)],(u8PinNum[i]%8));
			}
		}else{}
	}
}
