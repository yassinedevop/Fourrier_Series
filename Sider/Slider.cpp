/*
 * Slider.cpp
 *
 *  Created on: Sep 27, 2020
 *      Author: yassine
 */

#include "shape_lib/shape.h"
#include "Slider.h"

Slider::Slider(int min , int max,float y1 ) {
	// TODO Auto-generated constructor stub
	minvalue = min;
	maxvalue = max;
//	factor = min*0.45/(max*0.05);
	interval = max - min;
	x = 50;
	y = 50;
	prevx = 50;
	poy = y1;
}
int Slider::value(SDL_Event event){
	x = event.button.x ;
	y = event.button.y ;
	glColor3f(1,0,1);
	if(event.button.button == SDL_BUTTON_LEFT){
		if(x<50){
			x = 50;
		}
		if(x>450){
			x = 450;
		}
			circle(-1 + x*2/1000, poy , radius , 1);
			prevx = x;
	}
	else{
		circle(-1 + prevx*2/1000, poy , radius , 1);
	}


	line(-100.0/1000.0, poy ,-900.0/1000.0,poy);


	return ((prevx-50)*interval/400) + minvalue ;
}
