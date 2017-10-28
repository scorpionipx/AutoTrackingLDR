/*
 * graphics.c
 *
 * Created: 28-Oct-17 6:25:15 PM
 *  Author: ScorpionIPX
 */ 

#include "hx1230.h"

void display_title(void)
{
	hx_set_coordinates(0, 0);
	hx_write_string("AutoTracking LDR");
	hx_set_coordinates(0, 1);
	hx_write_string("  ScorpionIPX");
}

void display_data_menu(void)
{
	hx_set_coordinates(0, 3);
	hx_write_string("Light s1: n/a%");
	hx_set_coordinates(0, 4);
	hx_write_string("Light s2: n/a%");
	hx_set_coordinates(0, 5);
	hx_write_string("Light s3: n/a%");
	hx_set_coordinates(0, 6);
	hx_write_string("Light s4: n/a%");
}

void display_light_sensor_data(uint8_t sensor, int data)
{
	hx_set_coordinates(60, 3 + sensor);
	
	hx_write_char('0' + (data / 1000));
	hx_write_char('0' + ((data / 100) % 10));
	hx_write_char('0' + ((data / 10) % 10));
	hx_write_char('0' + (data % 10));
}