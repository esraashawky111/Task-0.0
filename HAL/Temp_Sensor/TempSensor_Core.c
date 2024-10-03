/*
 * TempSensor_Core.c
 *
 * Created: 9/9/2023 5:32:02 PM
 *  Author:Esraa Ali
 */ 
#include "TempSensor_Core.h"

void TempSensor_Init(void)
{
	ADC_Init();
}

uint16_t TempSensor_Read(void)
{
	uint16_t Temprature = 0;
	
	ADC_Read();
	Temprature = (ADC_Vin_Value_mv / 10);
	
	return Temprature;
	
}