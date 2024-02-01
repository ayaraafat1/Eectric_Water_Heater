/*
 * adc_init.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_


typedef enum{
	//single ended channels
	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7
		}ADC_CHANNEL;




void ADC_vid_int();//interface and initialize ADC
uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy);


void (*ISR_ADC_INT)(void);//pointer to ISR function

void ADC_vid_Enable();
void ADC_vid_Disable();

void ADC_vid_InterruptEnable();
void ADC_vid_InterruptDisable();
void ADC_vid_ClrFlag();
float32 ADC_F32_STEP_mvolt();//digital value to volt

#endif /* MCAL_ADC_ADC_INIT_H_ */
