/*
 * PORT_LCFG.c
 *
 * Created: 8/19/2023 3:47:25 PM
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
#include "PORT_LCFG.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const PIN_PARAMETERS PORT_Initialization[DEFINED_PINS] = {
     /*LCD Pins
	{ PORTB_PIN1 , PIN_OUTPUT },
	{ PORTB_PIN2 , PIN_OUTPUT },
	{ PORTB_PIN3 , PIN_OUTPUT },*/
    { PORTA_PIN1 , PIN_OUTPUT },
	{ PORTA_PIN2 , PIN_OUTPUT },
	{ PORTA_PIN3 , PIN_OUTPUT },
	{ PORTA_PIN4 , PIN_OUTPUT },
	{ PORTA_PIN5 , PIN_OUTPUT },
	{ PORTA_PIN6 , PIN_OUTPUT },
	//PWM0 Pins
	{ PORTB_PIN3 , PIN_OUTPUT },
	/*DC Motor Pins
    { PORTB_PIN2 , PIN_OUTPUT },
	{ PORTB_PIN1 , PIN_OUTPUT },*/
	//PWM1 Pins
	{ PORTD_PIN5 , PIN_OUTPUT },
	/*ICU PIN
	{ PORTD_PIN6 , PIN_INPUT },*/
	/*Ultrasonic Trigger PIN
	{ PORTD_PIN4 , PIN_OUTPUT }*/
	//I2C Pins
	{PORTC_PIN0 , PIN_OUTPUT },
	{PORTC_PIN1 , PIN_OUTPUT}
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
