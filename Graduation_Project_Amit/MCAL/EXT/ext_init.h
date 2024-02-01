/*
 * ext_init.h
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_EXT_INIT_H_
#define MCAL_EXT_EXT_INIT_H_


#define INT0_CONF    (uint8)0
#define INT1_CONF    (uint8)1
#define INT2_CONF    (uint8)2


#define FALLING   (uint8)0
#define RISSING   (uint8)1
#define LOW_       (uint8)2
#define ANY_LOG   (uint8)3



void (*ISR_FUN_INT0)(void);
void (*ISR_FUN_INT1)(void);
void (*ISR_FUN_INT2)(void);

void EXT_vidInit(uint8 u8ExtIntNum , uint8 u8ISRStCont);


#endif /* MCAL_EXT_EXT_INIT_H_ */
