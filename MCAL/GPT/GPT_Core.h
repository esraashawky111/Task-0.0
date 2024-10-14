/*
 * GPT_Core.h
 *
 * Created: 9/15/2023 5:02:20 PM
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
#ifndef GPT_CORE_H_
#define GPT_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPT_Cfg.h"
#include "MCU.h"
#include "BIT_MATH.h"
#include "STD.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TIMER_ENABLE                 1U
#define TIMER_DISABLE                0U

#define NORMAL_MODE                  0U
#define CTC_MODE                     1U
#define PWM_Phase_Frequency_Correct  2U
#define PWM_Phase_Correct            3U
#define Fast_PWM                     4U

#define NO_CLK_SRC                   0U
#define CLK_SRC_WITH_NO_PRESCALING	 1U
#define CLK_SRC_PRESCALING_8		 8U
#define CLK_SRC_PRESCALING_32 		 32U
#define CLK_SRC_PRESCALING_64 		 64U
#define CLK_SRC_PRESCALING_128 		 128U
#define CLK_SRC_PRESCALING_256 		 256U
#define CLK_SRC_PRESCALING_1024      1024U

#define INTERRUPT_ENABLED            1U
#define INTERRUPT_DISABLED           0U

#define TIMER0_OVF_INTERRUPT_BIT     0U
#define TIMER0_OC_INTERRUPT_BIT      1U
#define TIMER1_OVF_INTERRUPT_BIT     2U
#define TIMER1_OC_INTERRUPT_BIT      4U
#define TIMER2_OVF_INTERRUPT_BIT     6U
#define TIMER2_OC_INTERRUPT_BIT      7U

#define TIMER0_COUNTING_REG_CAPACITY   256U
#define TIMER1_COUNTING_REG_CAPACITY   65535U
#define TIMER2_COUNTING_REG_CAPACITY   256U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define TIMER0_SET_NO_CLK_SRC() (TCCR0_bits.CS=0)
#define TIMER0_SET_PRESCALER_OFF() (TCCR0_bits.CS=1)
#define TIMER0_SET_PRESCALER_8() (TCCR0_bits.CS=2)
#define TIMER0_SET_PRESCALER_64() (TCCR0_bits.CS=3)
#define TIMER0_SET_PRESCALER_256 () (TCCR0_bits.CS=4)
#define TIMER0_SET_PRESCALER_1024() (TCCR0_bits.CS=5)
#define TIMER0_SET_EXT_CLK_T0_FALLING_EDGE() (TCCR0_bits.CS=6)
#define TIMER0_SET_EXT_CLK_T0_RISING_EDGE()  (TCCR0_bits.CS=7)

#define TIMER1_SET_NO_CLK_SRC() (TCCR1_bits.CS=0)
#define TIMER1_SET_PRESCALER_OFF() (TCCR1_bits.CS=1)
#define TIMER1_SET_PRESCALER_8() (TCCR1_bits.CS=2)
#define TIMER1_SET_PRESCALER_64() (TCCR1_bits.CS=3)
#define TIMER1_SET_PRESCALER_256 () (TCCR1_bits.CS=4)
#define TIMER1_SET_PRESCALER_1024() (TCCR1_bits.CS=5)
#define TIMER1_SET_EXT_CLK_T0_FALLING_EDGE() (TCCR1_bits.CS=6)
#define TIMER1_SET_EXT_CLK_T0_RISING_EDGE()  (TCCR1_bits.CS=7)

#define TIMER2_SET_NO_CLK_SRC()    (TCCR2_bits. _CS2=0)
#define TIMER2_SET_PRESCALER_OFF()  (TCCR2_bits._CS2=1)
#define TIMER2_SET_PRESCALER_8()   (TCCR2_bits. _CS2=2)
#define TIMER2_SET_PRESCALER_32()   (TCCR2_bits._CS2=3)
#define TIMER2_SET_PRESCALER_64()   (TCCR2_bits._CS2=4)
#define TIMER2_SET_PRESCALER_128()  (TCCR2_bits._CS2=5)
#define TIMER2_SET_PRESCALER_256 () (TCCR2_bits._CS2=6)
#define TIMER2_SET_PRESCALER_1024() (TCCR2_bits._CS2=7)


#define SET_TIMER0_NORMAL_MODE() TCCR0_bits.WGM00=0;TCCR0_bits.WGM01=0
#define SET_TIMER0_CTC_MODE() TCCR0_bits.WGM00=0;TCCR0_bits.WGM01=1

#define SET_TIMER2_NORMAL_MODE() TCCR2_bits._WGM20=0;TCCR2_bits._WGM21=0
#define SET_TIMER2_CTC_MODE() TCCR2_bits._WGM20=0;TCCR2_bits._WGM21=1
#define SET_PWM2_FAST_MODE() TCCR2_bits._WGM20=1;TCCR2_bits._WGM21=1
#define SET_PWM2_NON_INVERTED_MODE() TCCR2_bits._COM2=2

#define SET_TIMER1_NORMAL_MODE() TCCR1_bits.WGM13=0;TCCR1_bits.WGM12=0;TCCR1_bits.WGM11=0;TCCR1_bits.WGM10=0
#define SET_TIMER1_CTC_MODE() TCCR1_bits.WGM13=0;TCCR1_bits.WGM12=1;TCCR1_bits.WGM11=0;TCCR1_bits.WGM10=0


#define SET_TIMER0_OVF_INTERRUPT_ENABLE() TIMSK_bits._TOIE0=INTERRUPT_ENABLED
#define SET_TIMER0_OVF_INTERRUPT_DISABLE() TIMSK_bits._TOIE0=INTERRUPT_DISABLED
#define SET_TIMER0_CTC_INTERRUPT_ENABLE() TIMSK_bits.OCIE0=INTERRUPT_ENABLED
#define SET_TIMER0_CTC_INTERRUPT_DISABLE() TIMSK_bits.OCIE0=INTERRUPT_DISABLED

#define SET_TIMER2_OVF_INTERRUPT_ENABLE()  TIMSK_bits.TOIE2=INTERRUPT_ENABLED
#define SET_TIMER2_OVF_INTERRUPT_DISABLE() TIMSK_bits.TOIE2=INTERRUPT_DISABLED
#define SET_TIMER2_CTC_INTERRUPT_ENABLE()  TIMSK_bits.OCIE2=INTERRUPT_ENABLED
#define SET_TIMER2_CTC_INTERRUPT_DISABLE() TIMSK_bits.OCIE2=INTERRUPT_DISABLED

#define SET_TIMER1_OVF_INTERRUPT_ENABLE() TIMSK_bits.TOIE1=INTERRUPT_ENABLED
#define SET_TIMER1_OVF_INTERRUPT_DISABLE() TIMSK_bits.TOIE1=INTERRUPT_DISABLED
#define SET_TIMER1_CTC_INTERRUPT_ENABLE() TIMSK_bits.OCIE1A=INTERRUPT_ENABLED
#define SET_TIMER1_CTC_INTERRUPT_DISABLE() TIMSK_bits.OCIE1A=INTERRUPT_DISABLED
#define CLEAR_TIMER1_COUNTING_REG() TCNT1 =0


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern volatile uint32_t Timer0_Total_num_ovfs;
extern volatile uint32_t Timer0_Init_Value;
extern volatile uint32_t Timer0_Total_num_compare_match;
extern volatile uint32_t Timer0_compare_Reg_init;
extern volatile uint32_t Timer0_Total_num_of_ticks;
extern volatile uint32_t Timer1_Total_num_compare_match;
extern volatile uint32_t Timer1_compare_Reg_init;
extern volatile uint32_t Timer1_OVF_Cnt;
extern volatile uint32_t Timer1_Total_num_ovfs;
extern volatile uint32_t Timer1_Init_Value;
extern uint16_t Timer1_Prescaler_value;

extern volatile uint32_t Timer2_Total_num_ovfs;
extern volatile uint32_t Timer2_Init_Value;
extern volatile uint32_t Timer2_Total_num_compare_match;
extern volatile uint32_t Timer2_compare_Reg_init;
extern volatile uint32_t Timer2_TickTime;
extern volatile uint32_t Timer2_Total_num_of_ticks;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPT_Init(void);
void GPT_SetTime(void);
 
#endif /* GPT_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/




