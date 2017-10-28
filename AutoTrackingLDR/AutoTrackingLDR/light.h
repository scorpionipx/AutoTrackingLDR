/*
 * light.h
 *
 * Created: 28-Oct-17 7:02:15 PM
 *  Author: ScorpionIPX
 */ 


#ifndef LIGHT_H_
#define LIGHT_H_

#define LS_UP_LEFT    0
#define LS_UP_RIGHT   1
#define LS_DOWN_LEFT  2
#define LS_DOWN_RIGHT 3

long int get_light_intensity(uint8_t sensor);

#endif /* LIGHT_H_ */