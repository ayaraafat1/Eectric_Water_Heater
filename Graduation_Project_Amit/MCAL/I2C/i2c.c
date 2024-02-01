/*
 * i2c.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */

#include"../../Serv/std.h"
#include"../../Serv/bit_math.h"


#include"i2c_reg.h"
#include"i2c_priv.h"
#include"i2c_config.h"
#include"i2c.h"
#include <util/delay.h>
#include <stdlib.h>

void TWI_voidMasterInit (void)
{
	//Set frequency to 400kbps
		CLEAR(TWSR,TWSR_TWPS0);
		CLEAR(TWSR,TWSR_TWPS1);
		TWBR=12;

	//Enable TWI
		SET(TWCR,TWCR_TWEN);

}
/*
TWI_ErrorStatus TWI_voidMasterInit(u8 Copy_u8Address)
{
	TWI_ErrorStatus Local_Error= NoError;
	if (Copy_u8Address == NULL)
	{

	}
	else
	{
		if (( Copy_u8Address < SLAVE_MIN_RESERVED_ADD ) && (Copy_u8Address != SLAVE_GEN_CALL_ADD))
		{
			//Set the master address to the 7MSB of address register
			TWAR = ((Copy_u8Address<<1) | General_Call_MASTER_recognition) ;
		}else
		{
			TWI_ErrorStatus Local_Error= ReservedAddressErr;
		}
	}
	//PRESCALER is the Parameter_Of_4_Power_TWPS
#if		TWI_BIT_RATE_PRESCALER == TWI_BIT_RATE_PRESCALER_1
			//Set frequency to 400kbps
			CLR_BIT(TWSR,TWSR_TWPS0);
			CLR_BIT(TWSR,TWSR_TWPS1);

#elif	TWI_BIT_RATE_PRESCALER == TWI_BIT_RATE_PRESCALER_4
			//Set frequency to 400kbps
			SET_BIT(TWSR,TWSR_TWPS0);
			CLR_BIT(TWSR,TWSR_TWPS1);
#elif	TWI_BIT_RATE_PRESCALER == TWI_BIT_RATE_PRESCALER_16
			//Set frequency to 400kbps
			CLR_BIT(TWSR,TWSR_TWPS0);
			SET_BIT(TWSR,TWSR_TWPS1);
#elif	TWI_BIT_RATE_PRESCALER == TWI_BIT_RATE_PRESCALER_64
			//Set frequency to 400kbps
			SET_BIT(TWSR,TWSR_TWPS0);
			SET_BIT(TWSR,TWSR_TWPS1);
#endif
				TWBR=(((F_CPU/SCL)-16)/(2*TWI_BIT_RATE_PRESCALER));

	//Enable TWI
	SET_BIT(TWCR,TWCR_TWEN);
	return Local_Error;
}
*/
TWI_ErrorStatus TWI_voidSlaveInit(uint8 Copy_u8Address)
{   TWI_ErrorStatus Local_Error= NoError;
	/* ask if the slave address is one of the reserved addresses */
	if (( Copy_u8Address < SLAVE_MIN_RESERVED_ADD ) && (Copy_u8Address != SLAVE_GEN_CALL_ADD))
	{
				/*Set the slave address to the 7MSB of address register*/
		TWAR = ((Copy_u8Address<<1) | General_Call_SLAVE_recognition) ;
				/*Enable TWI */
		SET(TWCR,TWCR_TWEN);
	}
	else
	{
		Local_Error= ReservedAddressErr;
	}
	return Local_Error;
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_Error= NoError;

	/*Set the start condition*/
	SET(TWCR,TWCR_TWSTA);

	/*Clear interrupt flag to start the previous operation*/
	SET(TWCR,TWCR_TWINT);


	/*Polling on the interrupt flag*/
	while((GET(TWCR,TWCR_TWINT))==0);

	/*check on the operation status ID*/
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_Error= StartConditionErr;
	}
	else
	{

	}


	return Local_Error;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{

	TWI_ErrorStatus Local_Error= NoError;

	/*Set the start condition*/
	SET(TWCR,TWCR_TWSTA);

	/*Clear interrupt flag to start the previous operation*/
	SET(TWCR,TWCR_TWINT);

	/*Polling on the interrupt flag*/
	while((GET(TWCR,TWCR_TWINT))==0);

	/*check on the operation status ID*/
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_Error= RepeatedStartError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_Error;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAdress)
{
	TWI_ErrorStatus Local_Error= NoError;

	/*set the 7 bit slave address on the bus with write request*/
	TWDR= (Copy_u8SlaveAdress<<1);

	/*Clear Start condition & Clear interrupt flag to start the previous operation*/
TWCR =0x84;
	/*Polling on the interrupt flag*/
	while((GET(TWCR,TWCR_TWINT))==0);

	/*check on the operation status ID*/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_Error= SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_Error;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAdress)
{
	TWI_ErrorStatus Local_Error= NoError;


	/*set the 7 bit slave address on the bus with Read request*/
	TWDR= Copy_u8SlaveAdress<<1;
	SET(TWDR,0);

	/*Clear start bit &Clear interrupt flag to start the previous operation*/
	TWCR =0x84;

	/*Polling on the interrupt flag*/
	while((GET(TWCR,TWCR_TWINT))==0);

	/*check on the operation status ID*/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_Error= SlaveAddressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_Error;
}

TWI_ErrorStatus TWI_MstrSendDataByte(uint8 Copy_u8Data)
{
	TWI_ErrorStatus Local_Error= NoError;

	/*Write the data in the data register*/
	TWDR= Copy_u8Data;

	/*Clear interrupt flag to start the previous operation*/
	SET(TWCR,TWCR_TWINT);

	/*Polling on the interrupt flag*/
	while((GET(TWCR,TWCR_TWINT))==0);

	/*check on the operation status ID*/
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_Error= MstrWriteByteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_MstrReadDataByte(uint8 *Copy_pu8Data)
{
	TWI_ErrorStatus Local_Error= NoError;
 if (Copy_pu8Data != NULL)
 {
	 /*Enable Acknowledge bit generation of master receiver*/
	 SET(TWCR,TWCR_TWEA);

	 /*Polling on the interrupt flag*/
	 while((GET(TWCR,TWCR_TWINT))==0);

	 /*check on the operation status ID*/
	 if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	 {
		 Local_Error= MstrReadByteWithAckErr;
	 }
	 else
	 {
		 *Copy_pu8Data= TWDR;
	 }
 }
 else
 {
	Local_Error=NULLPOINTERDATA;
 }
	return Local_Error;
}

void TWI_SendStopCondition(void)
{


	/*Set the stop condition bit*/
	SET(TWCR,TWCR_TWSTO);

	/*Clear interrupt flag to start the previous operation*/
	SET(TWCR,TWCR_TWINT);
}

/************************************************************************/
/* EEPROM External 24c                                                                     */
/************************************************************************/
//write data on EEPROM by TWI
TWI_ErrorStatus EEPROM_SendDataByte(uint16 Copy_u16Adress,uint8 Copy_u8Data)
{
	TWI_ErrorStatus Local_Error =NoError;
	//Set the start condition

	if ( TWI_SendStartCondition() != NoError)
	{
		 Local_Error = StartConditionErr;
	}

	//Set the  EEPROM Address
	uint8 EEPROMAdress;
#if EEPROME_24C_TYPE == EEPROME_24C02
// EEPROME Device Address
 EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | (EEPROM_A1_VALUE<<1) | (EEPROM_A0_VALUE));
#elif EEPROME_24C_TYPE == EEPROME_24C04
// EEPROME Device Address
 EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | (EEPROM_A1_VALUE<<1) | ((Copy_u16Adress>>8) & 0x1);
#elif EEPROME_24C_TYPE == EEPROME_24C08
// EEPROME Device Address
 EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | ((Copy_u16Adress>>8) & 0x3);
 #elif EEPROME_24C_TYPE == EEPROME_24C16
// EEPROME Device Address
 EEPROMAdress = EEPROM_FIXED_ADD_PART | ((Copy_u16Adress>>8) & 0x7);
#endif

	if ( TWI_SendSlaveAddressWithWrite(EEPROMAdress) != NoError)
	{
		 Local_Error = SlaveAddressWithWriteErr;
	}

	if ( TWI_MstrSendDataByte((uint8)Copy_u16Adress) != NoError)
	{
		 Local_Error = SlaveAddressWithWriteErr;
	}

	if ( TWI_MstrSendDataByte(Copy_u8Data) != NoError)
	{
		 Local_Error = MstrWriteByteErr;
	}


 TWI_SendStopCondition();

_delay_ms(10);
	  return Local_Error;
}

//Read data from EEPROM by TWI
TWI_ErrorStatus EEPROM_ReadDataByte(uint16 Copy_u16Adress,uint8 *Copy_pu8Data)
{
	TWI_ErrorStatus Local_Error =NoError ;
	//Set the start condition

	if ( TWI_SendStartCondition() != NoError)
	{Local_Error = StartConditionErr;
			}

	//Set the  EEPROM Address
	uint8 EEPROMAdress;
	#if EEPROME_24C_TYPE == EEPROME_24C02
	// EEPROME Device Address
	EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | (EEPROM_A1_VALUE<<1) | (EEPROM_A0_VALUE));
	#elif EEPROME_24C_TYPE == EEPROME_24C04
	// EEPROME Device Address
	EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | (EEPROM_A1_VALUE<<1) | ((Copy_u16Adress>>8) & 0x1);
	#elif EEPROME_24C_TYPE == EEPROME_24C08
	// EEPROME Device Address
	EEPROMAdress = EEPROM_FIXED_ADD_PART | (EEPROM_A2_VALUE<<2) | ((Copy_u16Adress>>8) & 0x3);
	#elif EEPROME_24C_TYPE == EEPROME_24C16
	// EEPROME Device Address
	EEPROMAdress = EEPROM_FIXED_ADD_PART | ((Copy_u16Adress>>8) & 0x7);
	#endif

	if ( TWI_SendSlaveAddressWithWrite(EEPROMAdress) != NoError)
	{
		Local_Error = SlaveAddressWithWriteErr;
	}

	if ( TWI_MstrSendDataByte((uint8)Copy_u16Adress) != NoError)
	{
		 Local_Error = SlaveAddressWithWriteErr;
	}

	if ( TWI_SendRepeatedStart() != NoError)
	{
		 Local_Error = RepeatedStartError;
	}

	if ( TWI_SendSlaveAddressWithRead(EEPROMAdress) != NoError)
	{
		 Local_Error = SlaveAddressWithReadErr;
	}

	if ( TWI_MstrReadDataByte(Copy_pu8Data) != NoError)
	{
		 Local_Error = MstrWriteByteErr;
	}

	TWI_SendStopCondition();

	return Local_Error;
}
