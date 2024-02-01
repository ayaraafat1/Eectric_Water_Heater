/*
 * adc_privet.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#ifndef MCAL_ADC_ADC_PRIVET_H_
#define MCAL_ADC_ADC_PRIVET_H_


#define ADMUX    *((volatile uint8 *)0x27)//multiplexer register
#define ADCSRA   *((volatile uint8 *)0x26)// control and status register
#define ADCH     *((volatile uint8 *)0x25)// the ADC data high register (high digital value)
#define ADCL     *((volatile uint8 *)0x24)// the ADC data low register (low digital value)
#define SFIOR    *((volatile uint8 *)0x50)// use to determine the voltage source
#define SREG     *((volatile uint8 *)0x5F)// use to global interrupt on


#endif /* MCAL_ADC_ADC_PRIVET_H_ */
