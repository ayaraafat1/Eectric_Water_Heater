/*
 * extrint_init.h
 *
 *  Created on: Sep 23, 2023
 *      Author: hp
 */

#ifndef HAL_EXTR_INT_EXTRINT_INIT_H_
#define HAL_EXTR_INT_EXTRINT_INIT_H_


#define INT0    (uint8)0
#define INT1    (uint8)1
#define INT2    (uint8)2


#define FALLING_ED   (uint8)0
#define RISSING_ED   (uint8)1
#define LOW_ED       (uint8)2
#define ANY_LOG_ED   (uint8)3


void EXTR_vidInit(uint8 u8INTCopy,uint8 u8StCopy);
void EXTR_vidISR0FUN(void (*FUN_ISR)(void));
void EXTR_vidISR1FUN(void (*FUN_ISR)(void));
void EXTR_vidISR2FUN(void (*FUN_ISR)(void));
#endif /* HAL_EXTR_INT_EXTRINT_INIT_H_ */
