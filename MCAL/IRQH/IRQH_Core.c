/*
 * IRQH_Core.c
 *
 * Created: 9/1/2023 5:47:29 PM
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
#include "IRQH_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/




/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
void(*CallBack_PtrFunc[20])(void) = {Null};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32_t TIMER0_Number_OVRflows_g ;
extern uint32_t TIMER0_Init_Value_g ;

 uint32_t TIMER1_Number_OVRflows_g = 0;

extern volatile uint32_t Captured_Readings_1;

extern volatile uint32_t Captured_Readings_2;

extern volatile uint32_t Captured_Readings_3;

extern volatile uint32_t Capture_Flag;

extern uint8_t TX_STATUS_FLAG ;
extern uint8_t TX_Cnt;
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
void IRQH_SetGlobalINT(uint8_t Global_INT_Status)
{
	switch(Global_INT_Status)
	{
		case INT_ENABLE:
		SET_BIT(SREG , 7);
		break;
		
		case INT_DISABLE:
		CLR_BIT(SREG , 7);
		break;
		
		default:
		break;
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
void IRQH_SetExternalINT(void)
{
	#if (EXT_INT_0 == INT_ENABLE)
	SET_BIT(GICR , 6);
	
	  #if (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)
	   CLR_BIT(MCUCR , 0);
	   CLR_BIT(MCUCR , 1);
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
	   SET_BIT(MCUCR , 0);
	   CLR_BIT(MCUCR , 1);	  
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	   CLR_BIT(MCUCR , 0);
	   SET_BIT(MCUCR , 1);	  
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	   SET_BIT(MCUCR , 0);
	   SET_BIT(MCUCR , 1);	
	
	 #endif /*if (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)*/
	#endif /*if (EXT_INT_0 == INT_ENABLE)*/
	
	#if (EXT_INT_1 == INT_ENABLE)
	SET_BIT(GICR , 7);
	
	  #if (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)
	   CLR_BIT(MCUCR , 2);
	   CLR_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
	   SET_BIT(MCUCR , 2);
	   CLR_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	   CLR_BIT(MCUCR , 2);
	   SET_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	   SET_BIT(MCUCR , 2);
	   SET_BIT(MCUCR , 3);	
	 #endif /*#if (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)*/
	#endif /*#if (EXT_INT_1 == INT_ENABLE)*/
		
	#if (EXT_INT_2 == INT_ENABLE)
	SET_BIT(GICR , 5);
	
	 #if (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	  CLR_BIT(MCUCSR , 6);
	 #elif (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	  SET_BIT(MCUCSR , 6);
	 #endif /*#if (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)*/	
	#endif /*(EXT_INT_2 == INT_ENABLE)*/
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


void IRQH_Set_CallBack(uint8_t Interrupt_Vector_Index , void(*p)(void))
{
	CallBack_PtrFunc[Interrupt_Vector_Index] = p;
}



ISR(INT0_vect)
{
	
	if(CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX] != Null)
	{
		(*CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX])();
	}
}

ISR(ADC_vect)
{
	
	if(CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX] != Null)
	{
		uint32_t ADC_Digital_Value = ADC_INPUT_16BIT_ACCESS;
		ADC_Vin_Value_mv = (ADC_Digital_Value * 5000) / 1023;
		(*CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX])();
	}
}

ISR(TIMER0_OVF_vect)
{
	/*
	static uint8_t INT_CNT_l = 0;
	
	INT_CNT_l++;
	
	if(INT_CNT_l == TIMER0_Number_OVRflows_g)
	{
		(*CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX])();
		INT_CNT_l = 0;
		TCNT0 = TIMER0_Init_Value_g ;
		*/
	static uint32_t cnt =0 ;
	cnt++;
	if (cnt==Timer0_Total_num_ovfs)
	{
		cnt=0;
		TCNT0=Timer0_Init_Value;
		if(CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX]!=Null){
			(CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX])();
			
		}
	}
	
}


ISR(TIMER1_COMPA_vect)
{

	static uint8_t INT_CNT_l = 0;
	INT_CNT_l++;
	if(INT_CNT_l == 1)
	{
		(*CallBack_PtrFunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX])();
		INT_CNT_l = 0;
	}
}

ISR (TIMER1_OVF_vect){

   TCNT1= 60000;
  if(CallBack_PtrFunc[Timer_Counter1_Overflow_VECTOR_INDEX] != Null)
  {
	  (*CallBack_PtrFunc[Timer_Counter1_Overflow_VECTOR_INDEX])();
  }
}


ISR(TIMER1_CAPT_vect)
{
 
	Capture_Flag++;

	if(Capture_Flag == 1)
	{
		Captured_Readings_1 = ICR1_16BIT_ACCESS;
		TIMER1_Number_OVRflows_g = 0;
		/*detect falling edge*/
		CLR_BIT(TCCR1B,6);
	}
	else if(Capture_Flag == 2)
	{
		Captured_Readings_2 = ICR1_16BIT_ACCESS + (TIMER1_Number_OVRflows_g * 65535);
		/*detect rising edge*/
		SET_BIT(TCCR1B,6);

	}
	else if(Capture_Flag == 3)
	{
		Captured_Readings_3= ICR1_16BIT_ACCESS + (TIMER1_Number_OVRflows_g * 65535);
		
		CLR_BIT(TIMSK,5);
	}

}
ISR(TIMER2_OVF_vect){
	static uint32_t cnt =0 ;
	cnt++;
	if (cnt== Timer2_Total_num_ovfs)
	{
		cnt=0;
		TCNT2=Timer2_Init_Value;
		if(CallBack_PtrFunc[Timer_Counter2_Overflow_VECTOR_INDEX]!=Null){
			(CallBack_PtrFunc[Timer_Counter2_Overflow_VECTOR_INDEX])();
		}
	}
}

ISR(TIMER2_COMP_vect){
	static uint32_t cnt =0 ;
	if (Timer2_Total_num_compare_match>=1)
	{
		OCR2 = TIMER2_COUNTING_REG_CAPACITY;
		if (cnt == Timer2_Total_num_compare_match)
		{
			if(CallBack_PtrFunc[Timer_Counter2_Compare_Match_VECTOR_INDEX]!=Null){
				(CallBack_PtrFunc[Timer_Counter2_Compare_Match_VECTOR_INDEX])();
			}
			cnt=0;
			OCR2 = Timer2_compare_Reg_init;
		}
		else cnt++;
	}
	else {
		if(CallBack_PtrFunc[Timer_Counter2_Compare_Match_VECTOR_INDEX]!=Null){
			(CallBack_PtrFunc[Timer_Counter2_Compare_Match_VECTOR_INDEX])();
			OCR2 = Timer2_Total_num_of_ticks -1;
		}
	}
}

ISR(USART_RXC_vect)
{
 	if(CallBack_PtrFunc[USART_Rx_Complete_VECTOR_INDEX] != Null)
    {
	 	(*CallBack_PtrFunc[USART_Rx_Complete_VECTOR_INDEX])();
 	}	
}


ISR(USART_TXC_vect)
{
	TX_STATUS_FLAG = 1;
	TX_Cnt ++;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
