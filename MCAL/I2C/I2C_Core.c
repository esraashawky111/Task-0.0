/*
 * I2C_Core.c
 *
 * Created: 10/7/2023 4:24:29 PM
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
#include "I2C_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
void I2C_MasterInit(void)
{
 /*Init SCL 400KHz  / TWBR =   0x0C */
 /*Init SCL 100KHz  / TWBR =   0x28 */
 TWBR = 0x0C ;
 CLR_BIT(TWSR , 0);
 CLR_BIT(TWSR , 1);
 
 
 /*enable Acknowledge I2c*/
 SET_BIT(TWCR , 6);
 /*enable I2c*/
 SET_BIT(TWCR , 2);
}

void I2C_StartCondition(void)
{
  /*generate Start Cond*/
  SET_BIT(TWCR , 5);
  
  /*enable I2c*/
  /*Trigger Flag / Clear Flag*/
  TWCR = 0X84 ;
  
  /*Monitor Flag*/
  while(GET_BIT(TWCR , 7) == 0);
  
  /*Check Operation Status*/
  while((TWSR &0XF8) != START_ACK);
}

void I2C_RepeatedStart(void)
{
  /*generate Repeated Start Cond*/
  SET_BIT(TWCR , 5);
  
  /*enable I2c*/
  /*Trigger Flag / Clear Flag*/
  TWCR |= 0X84 ;
  
  /*Monitor Flag*/
  while(GET_BIT(TWCR , 7) == 0);
  
  /*Check Operation Status*/
  while((TWSR &0XF8) != REP_START_ACK);
}

void I2C_SendAddress_WriteOperation(uint8_t addr)
{
	/*Send Slave Addr with Write Operation*/
	TWDR = (addr << 1);
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != SLAVE_ADD_AND_WR_ACK);

}
 
 void I2C_SendAddress_ReadOperation(uint8_t addr)
 {
	/*Send Slave Addr with Read Operation*/
	TWDR = (addr << 1) | (0x01) ;
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != SLAVE_ADD_AND_RD_ACK); 
	
 }

void I2C_WriteByte(uint8_t data)
{
	/*Send Data Operation*/
	TWDR = data;
	
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != WR_BYTE_ACK);
}

uint8_t I2C_ReadByte(void)
{
	uint8_t Data = 0;
	/*enable I2c*/
	/*Trigger Flag / Clear Flag*/
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != RD_BYTE_WITH_ACK);
	Data  = TWDR;
	return Data ;
}

void I2C_StopCondition(void)
{
  
  /*enable I2c*/
  /*Trigger Flag / Clear Flag*/
  TWCR = 0X94 ;
  
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
