/*
 * dio_int.h
 *
 *  Created on: Sep 8, 2023
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_


#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3



#define INPUT_PORT   0x00
#define OUTPUT_PORT  0xFF

#define INPUT_PIN   0
#define OUTPUT_PIN  1


#define HIGH_PORT 0xFF
#define LOW_PORT  0x00

#define LOW     0
#define HIGH    1
#define TOGGLE_ 2



void DIO_vidSetPortDir(uint8 u8PortVal,uint8 u8DirVal);
void DIO_vidSetPortVal(uint8 u8PortVal,uint8 u8Val);
uint8 DIO_u8GetPortVal(uint8 u8PortVal);

void DIO_vidSetPinDir(uint8 u8PinNum,uint8 u8DirVal);
void DIO_vidSetPinVal(uint8 u8PinNum,uint8 u8PinVal);
uint8 DIO_u8GetPinVal(uint8 u8PinNum);

#endif /* MCAL_DIO_DIO_INT_H_ */
