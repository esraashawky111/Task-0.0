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
#define TCNT0               (*(volatile uint8_t*)(0x52))
#define TCCR0               (*(volatile uint8_t*)(0x53))
#define OCR0                (*(volatile uint8_t*)(0x5C))
#define TIMSK               (*(volatile uint8_t*)(0x59))
#define TCCR1A              (*(volatile uint8_t* )(0x4F))
#define TCCR1B              (*(volatile uint8_t* )(0x4E))
#define TCNT1H              (*(volatile uint8_t* )(0x4D))
#define TCNT1L              (*(volatile uint8_t* )(0x4C))
#define TCNT1_16BIT_ACCESS  (*(volatile uint16_t*)(0x4C))
#define OCR1AH              (*(volatile uint8_t*)(0x4B))
#define OCR1AL              (*(volatile uint8_t*)(0x4A))
#define OCR1A_16BIT_ACCESS  (*(volatile uint16_t*)(0x4A))
#define OCR1BH              (*(volatile uint8_t*)(0x49))
#define OCR1BL              (*(volatile uint8_t*)(0x48))
#define OCR1B_16BIT_ACCESS  (*(volatile uint16_t*)(0x48))
#define ICR1H               (*(volatile uint8_t*)(0x47))
#define ICR1L               (*(volatile uint8_t*)(0x46))
#define ICR1_16BIT_ACCESS   (*(volatile uint16_t*)(0x46))

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


