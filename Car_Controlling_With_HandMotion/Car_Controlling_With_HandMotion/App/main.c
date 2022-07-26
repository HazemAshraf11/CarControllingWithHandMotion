/*
 * Car_Controlling_With_HandMotion.c
 *
 * Created: 7/16/2022 2:47:32 AM
 * Author : DELL G3
 */ 

#include <avr/interrupt.h>
#define F_CPU 8000000
#include <util/delay.h>


#include "Dio.h"
#include "Hbridge.h"
#include "FlexSensor.h"
#include "HC-05.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Timer2.h"
#include "Uart.h"
#include "Adc.h"


// The main code for the microcontroller on the car
int main(void)
{
    H_Hbridge_Init();
	H_HC05_Init();
	u8 first_sensor_reading = 0;
	u8 second_sensor_reading = 0;
    while (1) 
    {
		// check if the reading comes from the sensor on the left or the sensor on the right
		     if (H_HC05_Receive() == 1) first_sensor_reading = H_HC05_Receive();
		else if (H_HC05_Receive() == 2) second_sensor_reading = H_HC05_Receive();
		
		// using a constant resistor of 39Kohms and the flex resistor ranges from 20 Kohms to 160 Kohms
		     if (first_sensor_reading <= 130 && second_sensor_reading <=130)     H_Hbridge_MoveForward();
		else if (first_sensor_reading >= 130 && second_sensor_reading <=130)     H_Hbridge_Turn(PWM_HIGH_VALUE,PWM_LOW_VALUE);  //turn right
		else if (first_sensor_reading <= 130 && second_sensor_reading >=130)     H_Hbridge_Turn(PWM_LOW_VALUE,PWM_HIGH_VALUE);  //turn left
		else if (first_sensor_reading >= 130 && second_sensor_reading >=130)     H_Hbridge_MoveBackward();
    }
}


// The main code for the microcontroller on the hand
/*
int main(void)
{
	H_FlexSensor_Init();
	H_HC05_Init();
	
	while (1)
	{
		H_HC05_Transmit(1);
		H_FlexSensor_Transmit(PA1);
		H_HC05_Transmit(2);
		H_FlexSensor_Transmit(PA2);
	}
}
*/

