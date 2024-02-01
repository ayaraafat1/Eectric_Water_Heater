/*
 * i2c_priv.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Aya Raafat
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_
#include"../../Serv/std.h"

#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
// #define SLAVE_ADD_AND_WR_NOT_ACK 0x20 /* Master transmit ( slave address + Write request ) NOT ACK */  //NOT USE
// #define SLAVE_ADD_AND_RD_NOT_ACK 0x48 /* Master transmit ( slave address + Read request )  NOT ACK */  //NOT USE
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */

#define SLAVE_MIN_RESERVED_ADD   0x78 /* the first reserved address 0b01111000  */
#define SLAVE_GEN_CALL_ADD       0x00 /* the general call reserved address 0b0000 0000  */

#define  EEPROM_FIXED_ADD_PART  0x50 /* the fixed part of EEPROM address 0b0101 0000  */

#if EEPROME_24C_TYPE == EEPROME_24C02
// EEPROME Device Address
//can to have 8
#define  EEPROM_A2_VALUE 0
#define  EEPROM_A1_VALUE 0
#define  EEPROM_A0_VALUE 0

#elif EEPROME_24C_TYPE == EEPROME_24C04
// EEPROME Device Address
//can to have 4
#define  EEPROM_A2_VALUE 0
#define  EEPROM_A1_VALUE 0

#elif EEPROME_24C_TYPE == EEPROME_24C08
// EEPROME Device Address
//can to have 2
#define EEPROM_A2_VALUE 0

#elif EEPROME_24C_TYPE == EEPROME_24C16
// EEPROME Device Address
//can only one
#endif


#endif /* MCAL_I2C_I2C_PRIV_H_ */
