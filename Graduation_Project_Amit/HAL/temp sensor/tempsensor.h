/*
 * tempsensor.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */

#ifndef HAL_TEMP_SENSOR_TEMPSENSOR_H_
#define HAL_TEMP_SENSOR_TEMPSENSOR_H_

typedef enum{
	//single ended channels
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7
}CHANNEL;
void EXT_ADC_vid_int();
uint16 EXT_ADC_u16ReadDigitalVal(CHANNEL ChannelCopy);


#endif /* HAL_TEMP_SENSOR_TEMPSENSOR_H_ */
