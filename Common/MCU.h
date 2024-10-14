/*
 * MCU.h
 *
 * Created: 8/16/2023 6:21:50 PM
 *  Author: Esraa Ali
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

#ifndef MCU_H_
#define MCU_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*************************************** GPIO Registers ************************************************/
#define PHYSICAL_GPIO_ACCESS(addr)      (*(volatile uint8_t*)(addr))
#define GPIOA_BASE_ADDRRESS             (0X39)
#define GPIOB_BASE_ADDRRESS             (0X36)
#define GPIOC_BASE_ADDRRESS             (0X33)
#define GPIOD_BASE_ADDRRESS             (0X30)

#define GPIO_INPUT_REGISTER_PIN         (0X00)
#define GPIO_DIRCETION_REGISTER_DDR     (0X01)
#define GPIO_OUTPUT_REGISTER_PORT       (0X02)
/*******************************************************************************************************/

/*************************************** EXTERNAL INT Registers ****************************************/
#define  SREG   (*(volatile uint8_t*)(0X5F))
#define  GICR   (*(volatile uint8_t*)(0X5B))
#define  MCUCR  (*(volatile uint8_t*)(0X55))
#define  MCUCSR (*(volatile uint8_t*)(0X54))
/*******************************************************************************************************/

/*************************************** ADC Registers ************************************************/
#define ADMUX                      (*(volatile uint8_t *)(0x27))
#define ADCSRA                     (*(volatile uint8_t *)(0x26))
#define ADCH                       (*(volatile uint8_t *)(0x25))
#define ADCL                       (*(volatile uint8_t *)(0x24))
#define ADC_INPUT_16BIT_ACCESS    (*(volatile uint16_t*)(0x24))
#define SFIOR                      (*(volatile uint8_t *)(0x50))
/**************************************** Timers *****************************************************/
typedef union {
	struct
	{
		uint8_t CS00 :1;
		uint8_t CS01 :1;
		uint8_t CS02 :1;
		uint8_t WGM01:1;
		uint8_t COM00:1;
		uint8_t COM01 :1;
		uint8_t WGM00 :1;
		uint8_t FOC0 :1;
	};
	struct{
		uint8_t CS:3 ;
		uint8_t    :1;
		uint8_t COM:2;
		uint8_t   :1;
		uint8_t    :1;
	};
}TCCR0_t;

#define TCCR0_bits (*(volatile TCCR0_t*)(0x53))
#define TCNT0               (*(volatile uint8_t*)(0x52))
#define TCCR0               (*(volatile uint8_t*)(0x53))
#define OCR0                (*(volatile uint8_t*)(0x5C))
typedef struct
{
	uint8_t _TOIE0 :1;
	uint8_t OCIE0 :1;
	uint8_t TOIE1 :1;
	uint8_t OCIE1B:1;
	uint8_t OCIE1A:1;
	uint8_t _TICIE1:1;
	uint8_t TOIE2 :1;
	uint8_t OCIE2 :1;
}TIMSK_bits_t;
#define TIMSK_bits (*(volatile TIMSK_bits_t*)(0x59))
#define TIMSK               (*(volatile uint8_t*)(0x59))
typedef struct
{
	uint8_t TOV0 :1;
	uint8_t OCF0 :1;
	uint8_t TOV1 :1;
	uint8_t OCF1B:1;
	uint8_t OCF1A:1;
	uint8_t ICF1 :1;
	uint8_t TOV2 :1;
	uint8_t OCF2 :1;
}TIFR_bits_t;
#define TIFR_bits (*(volatile TIFR_bits_t*)(0x58))
#define TIFR (*(volatile uint8_t*)(0x58))

#define TCCR1A              (*(volatile uint8_t* )(0x4F))

#define TCCR1_bits (*(volatile TCCR1_t*)(0x4E))
#define TCCR1B              (*(volatile uint8_t* )(0x4E))
#define TCNT1H              (*(volatile uint8_t* )(0x4D))
#define TCNT1L              (*(volatile uint8_t* )(0x4C))
#define TCNT1_16BIT_ACCESS  (*(volatile uint16_t*)(0x4C))


typedef union {
	struct
	{
		uint8_t CS10 :1;
		uint8_t CS11 :1;
		uint8_t CS12 :1;
		uint8_t WGM12:1;
		uint8_t WGM13:1;
		uint8_t      :1;
		uint8_t _ICES1 :1;
		uint8_t ICNC1 :1;
		uint8_t WGM10 :1;
		uint8_t WGM11 :1;
		uint8_t FOC1B :1;
		uint8_t FOC1A:1;
		uint8_t COM1B0:1;
		uint8_t COM1B1 :1;
		uint8_t COM1A0 :1;
		uint8_t COM1A1 :1;
	};
	struct{
		uint8_t CS :3;
		uint8_t :1;
		uint8_t :1;
		uint8_t      :1;
		uint8_t :1;
		uint8_t :1;
		uint8_t  :1;
		uint8_t :1;
		uint8_t :1;
		uint8_t :1;
		uint8_t COM1B:2;
		uint8_t COM1A :2;
	};
	
}TCCR1_t;

#define OCR1AH              (*(volatile uint8_t*)(0x4B))
#define OCR1AL              (*(volatile uint8_t*)(0x4A))
#define OCR1A_16BIT_ACCESS  (*(volatile uint16_t*)(0x4A))
 typedef union {
	struct
	{
		uint8_t _CS20 :1;
		uint8_t _CS21 :1;
		uint8_t _CS22 :1;
		uint8_t _WGM21:1;
		uint8_t _COM20:1;
		uint8_t _COM21 :1;
		uint8_t _WGM20 :1;
		uint8_t _FOC2 :1;
	};
	struct{
		uint8_t _CS2:3 ;
		uint8_t    :1;
		uint8_t _COM2:2;
		uint8_t    :1;
		uint8_t    :1;
	};
}TCCR2_t;

#define TCCR2_bits (*(volatile TCCR2_t*)(0x45))
#define TCCR2 (*(volatile uint8_t*)(0x45))
#define OCR1BH              (*(volatile uint8_t*)(0x49))
#define OCR1BL              (*(volatile uint8_t*)(0x48))
#define OCR1B_16BIT_ACCESS  (*(volatile uint16_t*)(0x48))
#define ICR1H               (*(volatile uint8_t*)(0x47))
#define ICR1L               (*(volatile uint8_t*)(0x46))
#define ICR1_16BIT_ACCESS   (*(volatile uint16_t*)(0x46))
#define TCNT2 (*(volatile uint8_t*)(0x44))
#define TCNT1 (*(volatile uint16_t*)(0x4C))

/************************************  UART  *****************************************************************/

#define UBRRH   (*((volatile uint8_t*)0x40))
#define UBRRL   (*((volatile uint8_t*)0x29))
#define UCSRA   (*((volatile uint8_t*)0x2B))
#define UCSRB   (*((volatile uint8_t*)0x2A))
#define UCSRC   (*((volatile uint8_t*)0x40))
#define UDR     (*((volatile uint8_t*)0x2C))

/************************************  SPI  *****************************************************************/

typedef struct
{
	unsigned char SPCR;
	unsigned char SPSR;
	unsigned char SPDR;
}SPI_REGISTERS;

#define  SPI   ((volatile SPI_REGISTERS*)(0x2D))

/*************************************  I2C  ***********************************/
#define TWCR    (*((volatile uint8_t*)0x56))
#define TWDR    (*((volatile uint8_t*)0x23))
#define TWAR    (*((volatile uint8_t*)0x22))
#define TWBR    (*((volatile uint8_t*)0x20))
#define TWSR    (*((volatile uint8_t*)0x21))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/



