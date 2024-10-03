/*
 * EEPROM_Core.h
 *
 * Created: 10/7/2023 7:13:07 PM
 *  Author:Esraa Ali
 */ 




/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef EEPROM_CORE_H_
#define EEPROM_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "I2C_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   EEPROM_ADDRESS  0B01010000

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void EEPROM_WriteByte(uint8_t Data , uint8_t Address , uint8_t Byte_Loc );
 
void EEPROM_WriteMultipleBytes(uint8_t *Data ,uint8_t Data_Size, uint8_t Address , uint8_t Byte_Loc ); 
 
uint8_t EEPROM_ReadByte(uint8_t Address , uint8_t Byte_Loc );

#endif /* EEPROM_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/




