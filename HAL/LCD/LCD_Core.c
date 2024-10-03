/*
 * LCD.c
 *
 * Created:  11:43:01 PM
 *  Author:Esraa Ali
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
#include "LCD_Core.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define F_CPU  16000000
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

void LCD_Init(void)
{



#if (LCD_OPERATION_MODE  == LCD_4BIT_MODE)

	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
#endif /*end of #if (LCD_OPERATION_MODE  == 4LCD_4BIT_MODE)*/

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

void LCD_WriteCommand(uint8_t cmnd)
{

	
#if (LCD_OPERATION_MODE  == LCD_4BIT_MODE)

	DIO_WriteChennel(RS_PIN, PIN_LOW);
	DIO_WriteChennel(E_PIN, PIN_LOW);
	
	DIO_WriteChennel(D4_PIN, GET_BIT(cmnd,4));
	DIO_WriteChennel(D5_PIN, GET_BIT(cmnd,5));
	DIO_WriteChennel(D6_PIN, GET_BIT(cmnd,6));
	DIO_WriteChennel(D7_PIN, GET_BIT(cmnd,7));

  /* DIO_ReadPORTValue( PORTA_PIN3 , &ActualPortDataValue);
   NewPortDataValue = (((cmnd >> 1) & 0x78) | (ActualPortDataValue & 0x87));
   DIO_WritePORTValue(PORTA_PIN3 , NewPortDataValue);*/
	
	DIO_WriteChennel(E_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(E_PIN, PIN_LOW);
	
	DIO_WriteChennel(D4_PIN, GET_BIT(cmnd,0));
	DIO_WriteChennel(D5_PIN, GET_BIT(cmnd,1));
	DIO_WriteChennel(D6_PIN, GET_BIT(cmnd,2));
	DIO_WriteChennel(D7_PIN, GET_BIT(cmnd,3));
 	/*DIO_ReadPORTValue( PORTA_PIN3 , &ActualPortDataValue);
 	NewPortDataValue = (((cmnd << 3) & 0x78) | (ActualPortDataValue & 0x87));
 	DIO_WritePORTValue(PORTA_PIN3 , NewPortDataValue);*/
	
	DIO_WriteChennel(E_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(E_PIN, PIN_LOW);
	
	_delay_ms(5);
	
#endif /*end of #if (LCD_OPERATION_MODE  == 4LCD_4BIT_MODE)*/


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

void LCD_WriteChar(uint8_t chr)
{
	

	
	#if (LCD_OPERATION_MODE  == LCD_4BIT_MODE)
	DIO_WriteChennel(RS_PIN, PIN_HIGH);
	DIO_WriteChennel(E_PIN, PIN_LOW);

 	/*DIO_ReadPORTValue( DIO_PORTA_PIN3 , &ActualPortDataValue);
 	NewPortDataValue = (((chr >> 1) & 0x78) | (ActualPortDataValue & 0x87));
 	DIO_WritePORTValue(DIO_PORTA_PIN3 , NewPortDataValue);*/
	DIO_WriteChennel(D4_PIN, GET_BIT(chr,4));
	DIO_WriteChennel(D5_PIN, GET_BIT(chr,5));
	DIO_WriteChennel(D6_PIN, GET_BIT(chr,6));
	DIO_WriteChennel(D7_PIN, GET_BIT(chr,7));
	
	DIO_WriteChennel(E_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(E_PIN, PIN_LOW);
		
 	/*DIO_ReadPORTValue( DIO_PORTA_PIN3 , &ActualPortDataValue);
 	NewPortDataValue = (((chr << 3) & 0x78) | (ActualPortDataValue & 0x87));
 	DIO_WritePORTValue(DIO_PORTA_PIN3 , NewPortDataValue);*/
	DIO_WriteChennel(D4_PIN, GET_BIT(chr,0));
	DIO_WriteChennel(D5_PIN, GET_BIT(chr,1));
	DIO_WriteChennel(D6_PIN, GET_BIT(chr,2));
	DIO_WriteChennel(D7_PIN, GET_BIT(chr,3));
	
	DIO_WriteChennel(E_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(E_PIN, PIN_LOW);
	
	_delay_ms(5);
	
	#endif /*end of #if (LCD_OPERATION_MODE  == 4LCD_4BIT_MODE)*/

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

void LCD_WriteString(sint8_t* str)
{
	
	uint8_t i = 0;
	
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
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
void LCD_WriteInteger(uint32_t intgr)
{

	sint32_t y = 1;
	if(intgr == 0)
	{
		LCD_WriteChar('0');
	}

	else if(intgr < 0)
	{
		LCD_WriteChar('-');
		intgr *= -1;
	}

    else{
	
	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
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

void LCD_GoTo(uint8_t Row, uint8_t Col)
{
	uint8_t arr[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(arr[Row]+Col);
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

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/



