/***************************************************************************************************************
 * external_eeprom.h
 * Author: Muhammed Ayman
 * Module: External EEPROM
 **************************************************************************************************************/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 		0
#define SUCCESS 	1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function to write byte using I2C (TWI).
 */
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);

/*
 * Function to read byte using I2C (TWI).
 */
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
