/*
 * bit_math.h
 *
 *  Created on: Sep 8, 2023
 *      Author: hp
 */

#ifndef SERV_BIT_MATH_H_
#define SERV_BIT_MATH_H_

#define CLEAR(reg,bit) (reg &= (~(1<<bit)))
#define SET(reg,bit) (reg |= (1<<bit))
#define TOGGLE(reg,bit) (reg ^=(1<<bit))
#define GET(reg,bit) ((reg >> bit) & 1)

#endif /* SERV_BIT_MATH_H_ */
