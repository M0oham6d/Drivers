/***************************************************************************************************************
 * ultrasonic_sensor.c
 * Author: Muhammed Ayman
 * Module: Ultrasonic Sensor
 **************************************************************************************************************/

#include "ultrasonic_sensor.h"
#include <util/delay.h>
#include "../MCAL/icu.h"
#include "../MCAL/gpio.h"
#include "../MCAL/external_interrupts.h"
#include "../MCAL/timer.h"

/*******************************************************************************
 *                      			Variables                                  *
 *******************************************************************************/
volatile static uint8 g_edgeTime_ICU = 0;			/* Tracks the number of edges detected. */
volatile static uint16 g_highTime_ICU = 0;			/* Stores the high time (pulse width). */
volatile static uint8 g_edgeTime_EXT_INT = 0; 		/* Tracks the number of edges detected. */
volatile static uint8 timer_overflow_count = 0; 	/* Counts the number of timer overflows. */
volatile static uint16 g_highTime_ICU_EXT_INT = 0;  /* Stores the high time (pulse width). */

/*******************************************************************************
 *                      	Functions Prototypes (Private)                     *
 *******************************************************************************/
static void Ultrasonic_edgeProcessing(void);
static void Ultrasonic_edgeProcessing_EXT_INT(void);
static void timer0_setCallBack(void);

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Function to initialize ultrasonic sensor.
 */
void Ultrasonic_init(Ultrasonic_Use use)
{
	if(use == ICU)
	{
		/*
		 * Set up ICU Configuration.
		 * Initialize ICU.
		 * Set call back function.
		 */
		ICU_ConfigType ICU_Configurations = {ICU_F_CPU_8, RAISING};
		ICU_setCallBack(Ultrasonic_edgeProcessing);
		ICU_init(&ICU_Configurations);
	}
	else
	{
		EXT_INT_ConfigType EXT_INT_Configrations = {INT_2, RISING_EDGE_INT2};
		external_interrupt_setCallBack(Ultrasonic_edgeProcessing_EXT_INT, INT_2);
		external_interrupt_init(&EXT_INT_Configrations);
	}
	/* Set up pin direction for trigger pin as output. */
	GPIO_setupPinDirection(TRIGGER_PORT_CONNECTION1, TRIGGER_PIN1, PIN_OUTPUT);
	GPIO_setupPinDirection(TRIGGER_PORT_CONNECTION2, TRIGGER_PIN2, PIN_OUTPUT);
}

/* Timer0 overflow callback function */
static void timer0_setCallBack(void)
{
	/* Increment overflow count on each timer overflow. */
	timer_overflow_count++;
}

/*
 * Send the trigger pulse to the ultrasonic sensor.
 */
static void Ultrasonic_Trigger(Ultrasonic_Use use)
{
	if(use == ICU)
	{
		GPIO_writePin(TRIGGER_PORT_CONNECTION1, TRIGGER_PIN1, LOGIC_HIGH);
		_delay_us(10);
		GPIO_writePin(TRIGGER_PORT_CONNECTION1, TRIGGER_PIN1, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(TRIGGER_PORT_CONNECTION2, TRIGGER_PIN2, LOGIC_HIGH);
		_delay_us(10);
		GPIO_writePin(TRIGGER_PORT_CONNECTION2, TRIGGER_PIN2, LOGIC_LOW);
	}
}

/*
 * Send the trigger pulse by using the Ultrasonic_Trigger function.
 * Start the measurement process via the ICU driver.
 * The measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(Ultrasonic_Use use)
{
	if(use == ICU)
	{
		Ultrasonic_Trigger(ICU);
		return (g_highTime_ICU / 117.6) + 1;
	}
	else
	{
		Ultrasonic_Trigger(EXT_INT);
		return (g_highTime_ICU_EXT_INT / 117) + 1;
	}
}

/*
 * This is the callback function called by the ICU driver.
 * It calculates the high time (pulse time) generated by the ultrasonic sensor.
 */
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeTime_ICU++;
	if(g_edgeTime_ICU == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(2 == g_edgeTime_ICU)
	{
		g_highTime_ICU = ICU_getInputCaptureValue();		/* Get the high time. */

		/* Detect falling edge */
		ICU_setEdgeDetectionType(RAISING);

		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();

		g_edgeTime_ICU = 0;			/* Clear the counter to start from zero again. */
	}
}

static void Ultrasonic_edgeProcessing_EXT_INT(void)
{
	g_edgeTime_EXT_INT++;

	if (1 == g_edgeTime_EXT_INT) {
		/* Rising edge detected */
		Timer_deInit(TIMER0_ID);

		external_interrupt_deinit(INT_2);
		EXT_INT_ConfigType EXT_INT_Configrations = {INT_2, FALLING_EDGE_INT2};
		external_interrupt_init(&EXT_INT_Configrations);

		Timer_ConfigType Timer_Configrations = {0, 0, TIMER0_ID, F_CPU_8, NORMAL_MODE};
		Timer_setCallBack(timer0_setCallBack, TIMER0_ID);
		timer_overflow_count = 0;
		Timer_init(&Timer_Configrations);

	} else if (2 == g_edgeTime_EXT_INT) {
		/* Falling edge detected */
		g_highTime_ICU_EXT_INT = (timer_overflow_count * 256) + Timer_getTimerValue(TIMER0_ID);

		Timer_deInit(TIMER0_ID);
		timer_overflow_count = 0;

		external_interrupt_deinit(INT_2);
		EXT_INT_ConfigType EXT_INT_Configrations = {INT_2, RISING_EDGE_INT2};
		external_interrupt_init(&EXT_INT_Configrations);

		g_edgeTime_EXT_INT = 0;
	}
}