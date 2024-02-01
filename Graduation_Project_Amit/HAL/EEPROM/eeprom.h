/*
 * eeprom.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

void EEPROM_voidInit (void);
//write data on EEPROM by TWI
void EEPROM_SendData(uint16 Copy_u16Adress,uint8 Copy_u8Data);

//Read data from EEPROM by TWI
void EEPROM_ReadData(uint16 Copy_u16Adress,uint8 *Copy_pu8Data);

#endif /* HAL_EEPROM_EEPROM_H_ */
