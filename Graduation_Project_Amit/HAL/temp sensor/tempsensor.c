/*
 * tempsensor.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */

#include "../../Serv/std.h"
#include "../../MCAL/ADC/adc_init.h"
#include "tempsensor.h"
void EXT_ADC_vid_int()
{	 ADC_vid_int();
	 ADC_vid_Enable();
}
uint16 EXT_ADC_u16ReadDigitalVal(CHANNEL ChannelCopy)
{
	return ADC_u16ReadDigitalVal(ChannelCopy);
}


