/*
 * GPT_Core.c
 *
 * Created: 9/15/2023 5:03:21 PM
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
#include "GPT_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32_t TIMER0_Number_OVRflows_g = 0;
uint32_t TIMER0_Init_Value_g = 0;
uint16_t Timer0_Prescaler_value =0;
uint16_t Timer1_Prescaler_value =0;
uint16_t Timer2_Prescaler_value =0;
volatile uint32_t Timer0_Total_num_ovfs;
volatile uint32_t Timer0_Init_Value;
volatile uint32_t Timer0_Total_num_compare_match;
volatile uint32_t Timer0_compare_Reg_init;
volatile uint32_t Timer0_TickTime;
volatile uint32_t Timer0_Total_num_of_ticks;

volatile uint32_t Timer1_Total_num_compare_match;
volatile uint32_t Timer1_compare_Reg_init;
volatile uint32_t Timer1_OVF_Cnt;
volatile uint32_t Timer1_Total_num_ovfs;
volatile uint32_t Timer1_Init_Value;
volatile uint32_t Timer1_TickTime;


volatile uint32_t Timer2_Total_num_ovfs;
volatile uint32_t Timer2_Init_Value;
volatile uint32_t Timer2_Total_num_compare_match;
volatile uint32_t Timer2_compare_Reg_init;
volatile uint32_t Timer2_TickTime;
volatile uint32_t Timer2_Total_num_of_ticks;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if (Timer0_State == TIMER_ENABLE)
static void TIMER0_Prescaler_Select (void);

static void TIMER0_Mode_Select (void);

static void TIMER0_Interrupt_Init (void);

#endif

#if (Timer2_State == TIMER_ENABLE)
static void TIMER2_Prescaler_Select (void);

static void TIMER2_Mode_Select (void);

static void TIMER2_Interrupt_Init (void);

#endif

#if (Timer1_State == TIMER_ENABLE)
static void TIMER1_Prescaler_Select (void);

static void TIMER1_Mode_Select (void);

static void TIMER1_Interrupt_Init (void);

#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#if (Timer0_State == TIMER_ENABLE)
static void TIMER0_Prescaler_Select (void){
	#if TIMER0_PRESCALER == NO_CLK_SRC
	TIMER0_SET_NO_CLK_SRC();
	#elif TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING
	TIMER0_SET_PRESCALER_OFF();
	Timer0_Prescaler_value = CLK_SRC_WITH_NO_PRESCALING;
	#elif TIMER0_PRESCALER == CLK_SRC_PRESCALING_8
	TIMER0_SET_PRESCALER_8();
	Timer0_Prescaler_value =CLK_SRC_PRESCALING_8;
	#elif TIMER0_PRESCALER == CLK_SRC_PRESCALING_64
	TIMER0_SET_PRESCALER_64();
	Timer0_Prescaler_value =CLK_SRC_PRESCALING_64;
	#elif TIMER0_PRESCALER ==CLK_SRC_PRESCALING_256
	TIMER0_SET_PRESCALER_256();
	Timer0_Prescaler_value =CLK_SRC_PRESCALING_256;
	#elif TIMER0_PRESCALER ==CLK_SRC_PRESCALING_1024
	TIMER0_SET_PRESCALER_1024();
	Timer0_Prescaler_value =CLK_SRC_PRESCALING_1024;
	#elif TIMER0_PRESCALER == EXT_INT_TRIGGER_FALLING_EDGE
	TIMER0_SET_EXT_CLK_T0_FALLING_EDGE();
	#elif TIMER0_PRESCALER == EXT_INT_TRIGGER_RISING_EDGE
	TIMER0_SET_EXT_CLK_T0_RISING_EDGE();
	#endif
}

static void TIMER0_Mode_Select (void){
	#if TIMER0_MODE == NORMAL_MODE
	SET_TIMER0_NORMAL_MODE();
	#elif TIMER0_MODE == CTC_MODE
	SET_TIMER0_CTC_MODE();
	#endif
}

static void TIMER0_Interrupt_Init (void){
	
	#if TIMER0_MODE == NORMAL_MODE
	#if TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER0_OVF_INTERRUPT_ENABLE();
	#elif TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER0_OVF_INTERRUPT_DISABLE();
	#endif
	#elif TIMER0_MODE == CTC_MODE
	#if TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER0_CTC_INTERRUPT_ENABLE();
	#elif TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER0_CTC_INTERRUPT_DISABLE();
	#endif
	#endif
	
}
#endif

#if (Timer2_State == TIMER_ENABLE)
static void TIMER2_Prescaler_Select (void){
	#if TIMER2_PRESCALER == NO_CLK_SRC
	TIMER2_SET_NO_CLK_SRC();
	#elif TIMER2_PRESCALER == CLK_SRC_WITH_NO_PRESCALING
	TIMER2_SET_PRESCALER_OFF();
	Timer2_Prescaler_value = CLK_SRC_WITH_NO_PRESCALING;
	#elif TIMER2_PRESCALER ==CLK_SRC_PRESCALING_8
	TIMER2_SET_PRESCALER_8();
	Timer2_Prescaler_value = CLK_SRC_PRESCALING_8;
	#elif TIMER2_PRESCALER == CLK_SRC_PRESCALING_32
	TIMER2_SET_PRESCALER_32();
	Timer2_Prescaler_value =CLK_SRC_PRESCALING_32;
	#elif TIMER2_PRESCALER == CLK_SRC_PRESCALING_64
	TIMER2_SET_PRESCALER_64();
	Timer2_Prescaler_value =CLK_SRC_PRESCALING_64;
	#elif TIMER2_PRESCALER == CLK_SRC_PRESCALING_128
	TIMER2_SET_PRESCALER_128();
	Timer2_Prescaler_value =CLK_SRC_PRESCALING_128;
	#elif TIMER2_PRESCALER == CLK_SRC_PRESCALING_256
	TIMER2_SET_PRESCALER_256();
	Timer2_Prescaler_value = CLK_SRC_PRESCALING_256;
	#elif TIMER2_PRESCALER == CLK_SRC_PRESCALING_1024
	TIMER2_SET_PRESCALER_1024();
	Timer2_Prescaler_value = CLK_SRC_PRESCALING_1024;
	#endif
}

static void TIMER2_Mode_Select (void){
	#if TIMER2_MODE == NORMAL_MODE
	SET_TIMER2_NORMAL_MODE();
	#elif TIMER2_MODE == CTC_MODE
	SET_TIMER2_CTC_MODE();
	#elif TIMER2_MODE == Fast_PWM
	SET_PWM2_FAST_MODE() ;
	SET_PWM2_NON_INVERTED_MODE();
	#endif
}

static void TIMER2_Interrupt_Init (void){
	
	#if TIMER2_MODE == NORMAL_MODE
	#if TIMER2_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER2_OVF_INTERRUPT_ENABLE();
	#elif TIMER2_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER2_OVF_INTERRUPT_DISABLE();
	#endif
	#elif TIMER2_MODE == CTC_MODE
	#if TIMER2_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER2_CTC_INTERRUPT_ENABLE();
	#elif TIMER2_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER2_CTC_INTERRUPT_DISABLE();
	#endif
	#endif
}
#endif
static void TIMER1_Prescaler_Select (void){
	#if TIMER1_PRESCALER == NO_CLK_SRC
	TIMER1_SET_NO_CLK_SRC();
	#elif TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING
	TIMER1_SET_PRESCALER_OFF();
	Timer1_Prescaler_value =CLK_SRC_WITH_NO_PRESCALING;
	#elif TIMER1_PRESCALER == CLK_SRC_PRESCALING_8
	TIMER1_SET_PRESCALER_8();
	Timer1_Prescaler_value =CLK_SRC_PRESCALING_8;
	#elif TIMER1_PRESCALER == CLK_SRC_PRESCALING_64
	TIMER1_SET_PRESCALER_64();
	Timer1_Prescaler_value =CLK_SRC_PRESCALING_64;
	#elif TIMER1_PRESCALER == CLK_SRC_PRESCALING_256
	TIMER1_SET_PRESCALER_256();
	Timer1_Prescaler_value =CLK_SRC_PRESCALING_256;
	#elif TIMER1_PRESCALER == CLK_SRC_PRESCALING_1024
	TIMER1_SET_PRESCALER_1024();
	Timer1_Prescaler_value = CLK_SRC_PRESCALING_1024;
	#elif TIMER1_PRESCALER == EXT_INT_TRIGGER_FALLING_EDGE
	TIMER1_SET_EXT_CLK_T0_FALLING_EDGE();
	#elif TIMER1_PRESCALER == EXT_INT_TRIGGER_RISING_EDGE
	TIMER1_SET_EXT_CLK_T0_RISING_EDGE();
	#endif
}

static void TIMER1_Mode_Select (void){
	#if TIMER1_MODE == NORMAL_MODE
	SET_TIMER1_NORMAL_MODE();
	#elif TIMER1_MODE == CTC_MODE
	SET_TIMER1_CTC_MODE();
	#endif
}

static void TIMER1_Interrupt_Init (void){
	#if (TIMER1_MODE == NORMAL_MODE)
	#if TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER1_OVF_INTERRUPT_ENABLE();
	#elif TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER1_OVF_INTERRUPT_DISABLE();
	#endif
	#elif (TIMER1_MODE == CTC_MODE)
	#if TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED
	SET_TIMER1_CTC_INTERRUPT_ENABLE();
	#elif TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED
	SET_TIMER1_CTC_INTERRUPT_DISABLE();
	#endif
	#endif
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
void GPT_Init(void)
{
	#if Timer0_State == TIMER_ENABLE
	TIMER0_Prescaler_Select();
	TIMER0_Mode_Select();
	TIMER0_Interrupt_Init();
	#endif
	#if Timer1_State == TIMER_ENABLE
	TIMER1_Mode_Select();
	TIMER1_Interrupt_Init();
	TIMER1_Prescaler_Select();
	#endif
	#if Timer2_State == TIMER_ENABLE
	TIMER2_Mode_Select();
	TIMER2_Interrupt_Init();
	TIMER2_Prescaler_Select();
	#endif
		
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
void GPT_SetTime(void)
{
	#if (Timer0_State == TIMER_ENABLE)
	#if TIMER0_MODE == NORMAL_MODE
	uint32_t Timer0_TickTime = ((TIMER0_PRESCALER)/(16000000/1000000));
	uint32_t Timer0_Time = TIMER0_COUNTED_MS;
	uint32_t Timer0_Total_num_of_ticks= (Timer0_Time*1000)/Timer0_TickTime;
	Timer0_Total_num_ovfs= Timer0_Total_num_of_ticks/256;
	Timer0_Init_Value = 255-(Timer0_Total_num_of_ticks%256);
	TCNT0 = Timer0_Init_Value;
	if(Timer0_Init_Value!=256){
		Timer0_Total_num_ovfs++;
	}
	
	#elif (TIMER0_MODE == CTC_MODE)
	Timer0_TickTime = ((TIMER0_PRESCALER)/(16000000/1000000));
	uint32_t Timer0_Time = TIMER0_COUNTED_MS;
	Timer0_Total_num_of_ticks= (Timer0_Time*1000)/Timer0_TickTime;
	Timer0_Total_num_compare_match= Timer0_Total_num_of_ticks/TIMER0_COUNTING_REG_CAPACITY;
	Timer0_compare_Reg_init = Timer0_Total_num_of_ticks%TIMER0_COUNTING_REG_CAPACITY;
	if (Timer0_Total_num_compare_match >=1 ){
		OCR0 = Timer0_compare_Reg_init;
	}
	else OCR0 = Timer0_Total_num_of_ticks-1;
	#endif
	#endif
	
	#if (Timer2_State == TIMER_ENABLE)
	#if TIMER2_MODE == NORMAL_MODE
	uint32_t Timer2_TickTime = ((TIMER2_PRESCALER)/(16000000/1000000));
	uint32_t Timer2_Time = TIMER2_COUNTED_MS;
	uint32_t Timer2_Total_num_of_ticks= (Timer2_Time*1000)/Timer2_TickTime;
	Timer2_Total_num_ovfs= Timer2_Total_num_of_ticks/256;
	Timer2_Init_Value = 255-(Timer2_Total_num_of_ticks%256);
	TCNT2 = Timer2_Init_Value;
	if(Timer2_Total_num_ovfs== 0 && Timer2_Total_num_of_ticks > 0){
		Timer2_Total_num_ovfs++;
	}
	#elif (TIMER2_MODE == CTC_MODE)
	Timer2_TickTime = ((TIMER2_PRESCALER)/(16000000/1000000));
	uint32_t Timer2_Time = TIMER2_COUNTED_MS;
	Timer2_Total_num_of_ticks= (Timer2_Time*1000)/Timer2_TickTime;
	Timer2_Total_num_compare_match= Timer2_Total_num_of_ticks/TIMER2_COUNTING_REG_CAPACITY;
	Timer2_compare_Reg_init = Timer2_Total_num_of_ticks%TIMER2_COUNTING_REG_CAPACITY;
	if (Timer2_Total_num_compare_match >=1 ){
		OCR2 = Timer2_compare_Reg_init;
	}
	else OCR2 = Timer2_Total_num_of_ticks-1;
	#endif
	#endif
	
	#if (Timer1_State == TIMER_ENABLE)
	#if (TIMER1_MODE == NORMAL_MODE)
	Timer1_TickTime = ((TIMER1_PRESCALER)/(16000000/1000000));
	//uint32_t Timer1_Time = TIMER1_COUNTED_MS;
	//uint32_t Timer1_Total_num_of_ticks= (Timer1_Time*1000)/Timer1_TickTime;
	//Timer1_Total_num_ovfs= Timer1_Total_num_of_ticks/TIMER1_COUNTING_REG_CAPACITY;
	//Timer1_Init_Value = TIMER1_COUNTING_REG_CAPACITY-(Timer1_Total_num_of_ticks%TIMER1_COUNTING_REG_CAPACITY);//Timer1_Init_Value
	//TCNT1 = 15000 ;
	//if(Timer1_Init_Value!=TIMER1_COUNTING_REG_CAPACITY){
		Timer1_Total_num_ovfs++;
	//}
	#elif (TIMER1_MODE == CTC_MODE)
	Timer1_TickTime = ((TIMER1_PRESCALER)/(16000000/1000000));
	uint32_t Timer1_Time = TIMER1_COUNTED_MS;
	uint32_t Timer1_Total_num_of_ticks= (Timer1_Time*1000)/Timer1_TickTime;
	Timer1_Total_num_compare_match= Timer1_Total_num_of_ticks/TIMER1_COUNTING_REG_CAPACITY;
	Timer1_compare_Reg_init = Timer1_Total_num_of_ticks%TIMER1_COUNTING_REG_CAPACITY;
	if (Timer1_Total_num_compare_match >=1){
		OCR1A_16BIT_ACCESS = Timer1_compare_Reg_init;
	}
	else OCR1A_16BIT_ACCESS = Timer1_Total_num_of_ticks-1;

	#endif

	#endif
	
	
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/

