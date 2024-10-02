
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module: FXP.h
 *       Date  :29/09/2024 08:16:13
        Version: V03
 *  Description:    
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FXP.h"

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
* \Syntax          :         
* \Description     :   Convert a fixed-point number to float                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

float fixed_to_float(uint32_t x)
{
	return ((float)x / ((uint32_t)1 << FP_SHIFT));
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     :  Convert a float to fixed-point
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint32_t float_to_fixed(float x)
{
	return ((uint32_t)(x * ((uint32_t)1 << FP_SHIFT)));
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     :  Add two fixed-point numbers
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint32_t fixed_add(float x,float y) 
{
	
	// Convert float to fixed-point
	uint32_t fixed_a = float_to_fixed(x);
	uint32_t fixed_b = float_to_fixed(y);
	return  fixed_a + fixed_b;
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     :  sub two fixed-point numbers
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint32_t fixed_sub(float x,float y) 
{
	uint32_t fixed_a = float_to_fixed(x);
	uint32_t fixed_b = float_to_fixed(y);
	return fixed_a - fixed_b;
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     :  Multiply two fixed-point numbers
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
long long fixed_mult(float x,float y)
 {
	 uint32_t a = float_to_fixed(x);
	 uint32_t b = float_to_fixed(y);
	return ((long long)a * (uint32_t)b) >> FP_SHIFT; 
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     :  Division two fixed-point numbers
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
long long fixed_DIV(float x,float y)
{   
	
	uint32_t a = float_to_fixed(x);
	uint32_t b = float_to_fixed(y);
	if (b==0) return 0;
	return ((long long)(long long) a << FP_SHIFT)/ b; 
}
	
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
