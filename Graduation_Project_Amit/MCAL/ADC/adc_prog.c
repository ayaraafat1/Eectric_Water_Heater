/*
 * adc_prog.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#include "../../SERV/std.h"
#include "../../SERV/bit_math.h"
#include "adc_privet.h"
#include "adc_conf.h"
#include "adc_init.h"

#define ISR(vector)  															\
void vector(void)	__attribute__((signal,used,externally_visible));		    \
void vector(void)

ISR(__vector_16)//the ADC  index in vector table
{
	ISR_ADC_INT();
}

void ADC_vid_int(){
	//determine the ADC VOLTAGE sources
	#if ADC_VOLT_source == ADC_AREF
	CLEAR(ADMUX,REFS0);
	CLEAR(ADMUX,REFS1);
	#elif ADC_VOLT_source == ADC_AVCC
	SET(ADMUX,REFS0);
	CLEAR(ADMUX,REFS1);
	#elif ADC_VOLT_source == ADC_INTERNAL
	SET(ADMUX,REFS0);
	SET(ADMUX,REFS1);
	#endif

	//determine the ADC ADJUSTMENT
	#if ADC_ADJUSTMENT == ADC_Right_ADJUSTMENT
		CLEAR(ADMUX,ADLAR);   // RIGHT the default
	#elif ADC_ADJUSTMENT == ADC_Left_ADJUSTMENT
		SET(ADMUX,ADLAR);   // left
	#endif

	SET(ADCSRA,ADEN);  // Enable Pin

	ADCSRA |= ADC_PRESCALER; //Pre_scaler
}

uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy)
{
		uint16 DigitalVal=0;
		ADMUX &= ADC_CLEAR_MASK;
		ADMUX |= ChannelCopy;
		SET(ADCSRA,ADSC);

		while((GET(ADCSRA,ADSC)));//to wait until the conversion end

		#if ADC_ADJUSTMENT == ADC_Right_ADJUSTMENT
				DigitalVal = ADCL;
				DigitalVal |= (ADCH << 8);
		#elif ADC_ADJUSTMENT == ADC_Left_ADJUSTMENT
				DigitalVal = 0x00;
				DigitalVal |= (ADCH << 2);
		#endif
		return DigitalVal;
}

void ADC_vid_Enable()
{
	SET(ADCSRA,ADEN);
}
void ADC_vid_Disable()
{
	CLEAR(ADCSRA,ADEN);
}

void ADC_vid_InterruptEnable()
{
	SET(SREG,GIE);
	SET(ADCSRA,ADIE);
}
void ADC_vid_InterruptDisable()
{
	CLEAR(ADCSRA,ADIE);
}
void ADC_vid_ClrFlag()
{
	SET(ADCSRA,ADIF);
}

float32 ADC_F32_STEP_mvolt()//digital value to volt
{float32 step;
		#if ADC_VOLT_source == ADC_AREF
			step=5000.0/1024.00;
		#elif ADC_VOLT_source == ADC_AVCC
			step=5000.0/1024.00;
		#elif ADC_VOLT_source == ADC_INTERNAL
			step=2560/1024.00;
		#endif

		return step;
}

