/*
 * UART_Core.c
 *
 * Created: 2/28/2023 7:26:07 AM
 *  Author:Esraa Ali
 */ 


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TX_BUFFER_SIZE  7
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8_t UART_RECEIVED_DATA[10] ;
uint8_t UART_TRANSMITE_DATA[7] ;
uint8_t RECEIVE_STATUS_FLAG = 0;
uint8_t TX_STATUS_FLAG = 0;
uint8_t TX_Cnt = 0;
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
void  UART_Init(void)
{
	
uint8_t BaudRate_Value_l = 0;	
	
#if (UART_POLARITY_STATE ==  ENABLE)
 #if (UART_PARITY_TYPE ==   PARITY_ODD)
   UCSRC |= 0XD0;
 #elif (UART_PARITY_TYPE ==   PARITY_EVEN)
   UCSRC |= 0XA0;
 #endif /*if (UART_POLARITY_TYPE ==   POLARITY_ODD)*/
#endif /*if (UART_POLARITY_STATE ==  ENABLE)*/

#if (UART_DATA_BYTES   ==    UART_DATA_BYTES_5)
  UCSRC |= 0X80;
#elif (UART_DATA_BYTES   ==    UART_DATA_BYTES_6)
  UCSRC |= 0X82;
#elif (UART_DATA_BYTES   ==    UART_DATA_BYTES_7)
  UCSRC |= 0X84;
#elif (UART_DATA_BYTES   ==    UART_DATA_BYTES_8)
  UCSRC |= 0X86;
#endif /*if (UART_DATA_BYTES   ==    UART_DATA_BYTES_5)*/

#if (UART_INTERRUPT_STATE ==  ENABLE)
  SET_BIT(UCSRB , 6);  /*Tx INT Enable*/
  SET_BIT(UCSRB , 7);  /*Rx INT Enable*/
#elif (UART_INTERRUPT_STATE ==  DISABLE)
  CLR_BIT(UCSRB , 6); /*Tx INT DISable*/
  CLR_BIT(UCSRB , 7); /*Rx INT DISable*/
#endif

SET_BIT(UCSRB , 4); /*RX Enable*/
SET_BIT(UCSRB , 3); /*TX Enable*/

BaudRate_Value_l = ((160000U) / (UART_BAUD_RATE * 16U)) - 1;
UBRRL =  BaudRate_Value_l ;

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
void UART_InitiateTx(void)
{
  SET_BIT(UCSRB , 6); /*ENABLE TX INT*/
  TX_STATUS_FLAG = 1;
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
void UART_SendData(void)
{
	
	if( TX_Cnt == TX_BUFFER_SIZE)
	{
      TX_Cnt  = 0;
	  TX_STATUS_FLAG = 0;
	  CLR_BIT(UCSRB , 6); /*DISABLE TX INT*/
	}
	if(TX_STATUS_FLAG == 1)
	{
		UDR = UART_TRANSMITE_DATA[TX_Cnt];
		TX_STATUS_FLAG = 0;
	}
	
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

void UART_ReceiveData(void)
{
  static uint8_t REC_COUNTER = 0;
  UART_RECEIVED_DATA[REC_COUNTER] = UDR;
  REC_COUNTER++;
  
  if(UDR == '.')
  {
	  REC_COUNTER = 0;
	  RECEIVE_STATUS_FLAG = 1;
  }

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

uint8_t UART_ReceiveStatus(void)
{
  uint8_t Rec_Status_l = 0;
  
  if(RECEIVE_STATUS_FLAG == 1)
  {
	  RECEIVE_STATUS_FLAG = 0;
	  Rec_Status_l = 1;
  }
  
  return Rec_Status_l;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
