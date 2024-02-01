/*
 * eeprom.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */


#include "../../Serv/std.h"
#include "../../MCAL/I2C/i2c.h"

#include "eeprom.h"


void EEPROM_voidInit (void)
{
	TWI_voidMasterInit();
}
//write data on EEPROM by TWI
void EEPROM_SendData(uint16 Copy_u16Adress,uint8 Copy_u8Data)
{
	EEPROM_SendDataByte(Copy_u16Adress,Copy_u8Data);
}

//Read data from EEPROM by TWI
void EEPROM_ReadData(uint16 Copy_u16Adress,uint8 *Copy_pu8Data)
{
	EEPROM_ReadDataByte(Copy_u16Adress,Copy_pu8Data);
}
