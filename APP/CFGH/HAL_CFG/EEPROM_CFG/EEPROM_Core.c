/*
 * ICU.c
 *
 * Created:  11:35:42 PM
 *  Author: Esraa Ali
 */ 




/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EEPROM_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define F_CPU 16000000
#include <util/delay.h>
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void EEPROM_Init(void)
{
	I2C_MasterInit();
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void EEPROM_WriteByte(uint8_t addr , uint8_t Loc , uint8_t data)
{
	/*send start condition*/
	I2C_StartCondition();
	/*send EEPROM Module Address*/
	I2C_SendAddress_WriteOperation(addr);
	/*send location Address*/
	I2C_WriteByte(Loc);
	/*send data*/
	I2C_WriteByte(data);
	/*stop frame*/
	I2C_StopCondition();
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void EEPROM_WriteMuliByte(uint8_t addr , uint8_t Loc , uint8_t* data , uint8_t data_size)
{
	
	uint8_t cnt = 0;
	
	
	/*send start condition*/
	I2C_StartCondition();
	/*send EEPROM Module Address*/
	I2C_SendAddress_WriteOperation(addr);
	/*send location Address*/
	I2C_WriteByte(Loc);
	
	/*send data*/
	while(cnt < data_size)
	{
		I2C_WriteByte(data[cnt]);
		cnt++;
	}
	
	/*stop frame*/
	I2C_StopCondition();
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint8_t EEPROM_ReadByte(uint8_t addr , uint8_t Loc )
{
	uint8_t data = 0;
	
	/*start condition*/
	I2C_StartCondition();
	/*EEPROM Address*/
	I2C_SendAddress_WriteOperation(addr);
	
	/*location address*/
	I2C_WriteByte(Loc);
	
	/*Repeated Start*/
	I2C_RepeatedStart();
	
	/*EEPROM Address*/
	I2C_SendAddress_ReadOperation(addr);
	
	/*Read Received Byte*/
	data = I2C_ReadByte();
	I2C_StopCondition();
	
	return data ;
	
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
