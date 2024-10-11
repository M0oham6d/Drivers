/*
 * lm35_sensor.h
 * Author: Muhammed Ayman
 * Module: Temperature Sensor
 */

#ifndef HAL_LM35_SENSOR_H_
#define HAL_LM35_SENSOR_H_

#include "../MCAL/adc.h"
#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);


#endif /* HAL_LM35_SENSOR_H_ */
