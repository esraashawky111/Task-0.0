
/**********************************************************************************************************************
 *  FILE DESCRIPTION
/*
 * EVENT_SYS.c
 *
 * Created: 03/10/2024 05:12:13 
 *  Author: Esraa Ali
 * Version :VO
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EVENT_SYS.h"

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
 uint8_t EVEN_Set_EVEN[3] = {0};
	
static void Event_Push_Elem(uint8_t index) 
	{
		 EVEN_Set_EVEN[index]++;
	}
	
static void Event_Pop_Elem(uint8_t index)
 {
	if(EVEN_Set_EVEN[index]!=0)
	{
		
	EVEN_Set_EVEN[index]--;
	
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
void Buttons_Pressed_Check(){
  static uint8_t flag0_pre=0, flag1_pre=0, flag2_pre=0;
  static uint8_t flag2_current = 0, flag1_current = 0, flag0_current = 0;
	  flag0_current = BTN_GetValue(PORTD_PIN0);
	  flag1_current = BTN_GetValue(PORTD_PIN1);
	  flag2_current = BTN_GetValue(PORTD_PIN2);
	if(flag0_current == 0 && flag0_pre == 1 ){
		//LCD_WriteChar('F');
		Event_Push_Elem(EVENT_SW0_PRESSED);
		flag0_pre = flag0_current;
	}
	else if(flag0_current == 1)
	{
		
		flag0_pre = 1;
		
	}
	else
	 {
		
	}
	
	
	if(flag1_current == 0 && flag1_pre == 1 )
	{
		//LCD_WriteChar('g');
		Event_Push_Elem(EVENT_SW1_PRESSED);
		flag1_pre = flag1_current;
	}
	else if(flag1_current == 1)
	{
		
		flag1_pre = 1;
		
	}
	else 
	{
		
	}
	

	if(flag2_current == 0 && flag2_pre == 1 )
	{
		//LCD_WriteChar('h');
		Event_Push_Elem(EVENT_SW2_PRESSED);
		flag2_pre = flag2_current;
	}
	else if(flag2_current == 1)
	{
		
		flag2_pre = 1;
		
	}
	else 
	{
		
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
void APP_Handle_Event(void){
	   //uint8_t E = 0;

		while(EVEN_Set_EVEN[EVENT_SW0_PRESSED] != 0)
		{
		//LCD_WriteChar('A');
		LED_Toggle(PORTC_PIN0);
		Event_Pop_Elem(EVENT_SW0_PRESSED);
		}
		
		while(EVEN_Set_EVEN[EVENT_SW1_PRESSED] != 0)
		{
	    // LCD_WriteChar('B');
		LED_Toggle(PORTC_PIN1);
		Event_Pop_Elem(EVENT_SW1_PRESSED);
		}
		
		while(EVEN_Set_EVEN[EVENT_SW2_PRESSED] != 0)
		{
		//LCD_WriteChar('C');
		LED_Toggle(PORTC_PIN2);
		Event_Pop_Elem(EVENT_SW2_PRESSED);
		}
		
		
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
