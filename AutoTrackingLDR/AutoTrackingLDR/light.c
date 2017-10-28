/*
 * light.c
 *
 * Created: 28-Oct-17 7:02:05 PM
 *  Author: ScorpionIPX
 */ 

#include <avr/io.h>
#include "light.h"
#include "adc_driver.h"

long int get_light_intensity(uint8_t sensor)
{
	uint16_t adc_value = ADC_get_value(sensor);
	adc_value = adc_value*((long)1000)/1023;
	adc_value = 1000 - adc_value;
	return adc_value;
}