/*
 * AutoTrackingLDR.c
 *
 * Created: 28-Oct-17 6:18:32 PM
 * Author : ScorpionIPX
 */ 

#include "global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "adc_driver.h"
#include "hx1230.h"
#include "hx_8x6_characters.h"
#include "graphics.h"
#include "light.h"
#include "pwm_driver.h"

void uC_init(void);

int main(void)
{
	uC_init();
	long int ls_1, ls_2;
	
	turn_on_pwm_channels();
	OCR1A = 32;
	
	DDRB = 0x00;
	PORTB = 0xFF;
	
    while (1) 
    {
		_delay_ms(90);
		ls_1 = get_light_intensity(LS_UP_LEFT);
		ls_2 = get_light_intensity(LS_UP_RIGHT);
		display_light_sensor_data(LS_UP_LEFT, ls_1);
		display_light_sensor_data(LS_UP_RIGHT, ls_2);
		display_light_sensor_data(LS_DOWN_LEFT, OCR1A);
		int dif = ls_2-ls_1;
		display_light_sensor_data(LS_DOWN_RIGHT, dif);
		
		if(dif >= 10 || dif <= 10)
		{
			OCR1A += dif / 10;
		}
		
		
		if(bit_is_clear(PINB, 0))
		{
			OCR1A ++;
		}
		if(bit_is_clear(PINB, 1))
		{
			OCR1A --;
		}
    }
}

void uC_init(void)
{
	// Wait for system to get fully powered up
	_delay_ms(100);
	
	// initialize required modules
	ADC_init();
	_delay_ms(50);
	
	init_pwm_channels();
	_delay_ms(50);
	
	init_hx1230_control();
	_delay_ms(50);
	hx_fill_screen();
	_delay_ms(500);
	hx_clear_screen();
	_delay_ms(150);
	
	display_title();
	display_data_menu();
	
	
}

