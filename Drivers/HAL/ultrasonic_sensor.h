/***************************************************************************************************************
 * ultrasonic_sensor.h
 * Author: Muhammed Ayman
 * Module: Ultrasonic Sensor
 **************************************************************************************************************/

#ifndef HAL_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_H_

#include "../Standard_Types/standard_types.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
/* For ultrasonic 1 using ICU. */
#define TRIGGER_PORT_CONNECTION1				PORTD_ID
#define TRIGGER_PIN1							PIN7_ID
#define ECHO_PORT_CONNECTION					PORTD_ID
#define ECHO_PIN								PIN6_ID
/* For ultrasonic 2 using External Interrupts. */
#define TRIGGER_PORT_CONNECTION2				PORTB_ID
#define TRIGGER_PIN2							PIN1_ID


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	ICU, EXT_INT
}Ultrasonic_Use;

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Set up ICU Configuration.
 * Initialize ICU.
 * Set call back function.
 * */
void Ultrasonic_init(Ultrasonic_Use use);

/*
 * Send the trigger pulse by using the Ultrasonic_Trigger function.
 * Start the measurement process via the ICU driver.
 * The measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(Ultrasonic_Use use);

#endif /* HAL_ULTRASONIC_SENSOR_H_ */
