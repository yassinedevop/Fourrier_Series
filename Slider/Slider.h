/*
 * Slider.h
 *
 *  Created on: Sep 27, 2020
 *      Author: yassine
 */
#include <GL/gl.h>
#include <SDL/SDL.h>
#include "shape_lib/shape.h"
#ifndef SRC_SLIDER_H_
#define SRC_SLIDER_H_

class Slider {
public:
	Slider(int min , int max, float y1 );
	int value(SDL_Event event);
	int minvalue, maxvalue,interval;
//	float factor;
	float poy;
	float x , y , prevx ;
	float radius = 0.03;
};

#endif /* SRC_SLIDER_H_ */
