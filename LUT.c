
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module: LUT.h
 *       Date  :Created: 29/09/2024 08:15:51 
        Version: V0
 *  Description:    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LUT.h"
#include <math.h>

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
const uint16_t sine_lookup_table[LUT_SIZE] = {
	0, 17, 35, 52, 70, 87, 105, 122, 139, 156, 174, 191, 208, 225, 242, 259,
	275, 292, 309, 325, 342, 358, 374, 390, 406, 422, 438, 453, 469, 484,
	499, 515, 529, 544, 559, 573, 587, 601, 615, 629, 642, 656, 669, 682,
	695, 707, 719, 731, 743, 755, 766, 777, 788, 798, 809, 819, 829, 838,
	848, 857, 866, 874, 883, 891, 898, 906, 913, 920, 927, 933, 939, 945,
	951, 956, 961, 966, 970, 975, 979, 983, 986, 989, 992, 994, 996, 998,
999, 1000 };
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
uint16_t Counter1 = 0;
uint16_t Counter2 = 0;

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
static double sine_lookup(int angle) {
	  
	/*	if (angle < 0 || angle > 360) {
			return 0;  // Invalid angle
		}
		if (angle > 90 && angle <= 180)
		 {
			return sine_lookup(180 - angle);
		 }
		 else if (angle > 180 && angle <= 270)
			  {
		 return -sine_lookup(angle - 180);
			} 
			else if (angle > 270 && angle <= 360)
			 {
			return -sine_lookup(360 - angle);
		   }
		return (double)sine_lookup_table[angle] / 1000.0 ;*/
	  if (angle < 0 || angle > 90)
	  {
		  return 0;
	  }
	  // Get sine from the lookup table, dividing by 1000 to convert to a float
	  return (double)sine_lookup_table[angle] / 1000.0;
  
  
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
void  Sine_with_lut(){
	GPT_Init(); 
	while(1){
	// Setup timer
	double sine_from_table = 0.00;
	//DIO_WriteChennel(PORTC_PIN1,PIN_HIGH);
	//TCNT0 = 0;
	for (uint16_t i = 0; i < 1000; i++) {
		sine_from_table = sine_lookup_table[45];
	}
	//Counter1 = TCNT0;
	//LCD_WriteInteger(Counter1);
	//LCD_WriteString(" ");
	// DIO_WriteChennel(PORTC_PIN1,PIN_LOW);
	sine_from_table = (double) sine_from_table/1000.0;
	// Display counter if need
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
void  Sine_without_lut(){
   GPT_Init(); 
	while(1){
	//every tick is 0.125 us
	double angle_in_radians = ANGLE * (PI / 180.0);  // Convert degrees to radians
	DIO_WriteChennel(PORTC_PIN0,PIN_HIGH);
	//TCNT0=0;
	for(uint16_t i=0; i < 1000 ;i++)
	{
		double sine_from_math_lib = sin(angle_in_radians);
	}
	//Counter2=TCNT0;
	
	DIO_WriteChennel(PORTC_PIN0,PIN_LOW);
	//244  us
	//LCD_WriteInteger(Counter2);
	//LCD_WriteString(" ");
	
}
   
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
