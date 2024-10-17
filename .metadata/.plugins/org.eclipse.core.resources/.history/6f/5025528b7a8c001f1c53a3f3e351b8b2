/*
 * flame_sensor.h
 * Author: Muhammed Ayman
 * Module: Flame Sensor
 */

#ifndef HAL_FLAME_SENSOR_H_
#define HAL_FLAME_SENSOR_H_

#include "../MCAL/gpio.h"
#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/

#define FLAME_PORT_CONNECTION					PORTD_ID
#define FLAME_PIN_CONNECTION					PIN2_ID

/*******************************************************************************
 *                      		Functions Prototypes                           *
 *******************************************************************************/

/*
 * Initializes the flame sensor.
 */
void FlameSensor_init(void);

/*
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);

#endif /* HAL_FLAME_SENSOR_H_ */
