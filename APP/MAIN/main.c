/*
 * 
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Esraa Ali
 */ 
#define  F_CPU  16000000U
#include <util/delay.h>
#include "LED.h"
#include "BTN.h"
#include "PORT_Core.h"
#include "IRQH_Core.h"
#include "ADC_Core.h"
#include "LCD_Core.h"
#include "GPT_Core.h"
#include "PWM_Core.h"
#include "Ultrasonic.h"
#include "UART_Core.h"
#include "EEPROM_Core.h"
//#include <math.h>
#include "FXP.h"
#include "LUT.h"

/*void Temp_Func(void)
{
	LED_Toggle(LED_GREEN);
}*/
/*
static uint8_t EXE_TIM_FLOAT = 0;
static uint8_t EXE_TIM_FIXED= 0;

int main() 
{
	PORT_Init();
	LCD_Init();
	GPT_Init();
	float a =3.31, b = 1.1,result = 0;
	float c =3.31, d = 1.1,res=0;
	//while (1)
	//{
  // LCD_WriteString("FXP");
   
   // DIO_WriteChennel(PORTC_PIN1,PIN_LOW);
    uint32_t ff = fixed_mult(a,b);
     TCNT0 = 0;
	//LCD_WriteInteger(a*100);
	//LCD_WriteString(" ");
	//LCD_WriteInteger(b*100);
    //LCD_GoTo(1,0);
	
    for (int i =0;i<1000;i++)
	{
	
	 result=fixed_to_float(ff);
	 }
	 EXE_TIM_FIXED=TCNT0;
	 TCNT0=0;
	 // LCD_WriteInteger(result*100);
	//  LCD_WriteString(" ");
	//  CNT=TCNT0;
	/// LCD_WriteChar(CNT);
	//   DIO_WriteChennel(PORTC_PIN1,PIN_HIGH);
	   for (int i =0;i<1000;i++)
	   {
		   result= a*b;
	   }
	   EXE_TIM_FLOAT =TCNT0;
	  
	   LCD_WriteInteger(EXE_TIM_FIXED);
	    LCD_WriteString(" ");
		LCD_WriteInteger(EXE_TIM_FLOAT);*/
	//}
	 

    /*   ff = fixed_sub(a,b);
       result=fixed_to_float(ff);
      LCD_WriteInteger(result*100);
      LCD_WriteString(" ");
	  
	   ff = fixed_mult(a,b);
	   result=fixed_to_float(ff);
	  LCD_WriteInteger(result*100);
	  LCD_WriteString(" ");
	  
	 ff = fixed_DIV(a,b);
	 result=fixed_to_float(ff);
	LCD_WriteInteger(result*100);
	LCD_WriteString(" ");
	
	return 0;*/
//}

int main() {
	PORT_Init();
	LCD_Init();
  // Sine_with_lut();
   Sine_without_lut();
	return 0;
}

//LCD_WriteInteger((b*100));
// 	// Perform fixed-point addition
//	uint32_t fixed_sum = fixed_add(a,b);

//
// 	// Perform fixed-point Subtraction
// 	uint32_t fixed_subt= fixed_sub(a,b);
//
// 	// Perform fixed-point multiplication
// 	uint32_t fixed_product = fixed_mult(a,b);
// 	// Perform fixed-point division
//     uint32_t fixed_div = fixed_DIV(a,b);
//     LCD_WriteChar(fixed_sum);
// 	LCD_WriteInteger(fixed_sum);
//     LCD_WriteString("/");
// 	LCD_WriteInteger(fixed_subt);
// 	LCD_WriteString("/");
// 	LCD_WriteInteger(fixed_product);
// 	LCD_WriteString("/");
// 	//LCD_WriteInteger(100);
// 	LCD_WriteChar(fixed_div);
// 	LCD_WriteString("/");