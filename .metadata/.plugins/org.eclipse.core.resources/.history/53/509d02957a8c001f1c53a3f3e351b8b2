/*
 * flame_sensor.c
 * Author: Muhammed Ayman
 * Module: Flame Sensor
 */

#include "flame_sensor.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Initializes the flame sensor.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT_CONNECTION, FLAME_PIN_CONNECTION, PIN_INPUT);
}

/*
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void)
{
	return GPIO_readPin(FLAME_PORT_CONNECTION, FLAME_PIN_CONNECTION);
}
