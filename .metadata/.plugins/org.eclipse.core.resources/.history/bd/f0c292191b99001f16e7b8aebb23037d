/*
 * ldr_sensor.c
 * Author: Muhammed Ayman
 * Module: LDR Sensor
 */

#include "ldr_sensor.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void)
{
	uint16 ldr_value = 0;

	uint16 adc_value = 0;

	ADC_init();			/* Initializing ADC. */

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	ldr_value = (uint8)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

	return ldr_value;
}
