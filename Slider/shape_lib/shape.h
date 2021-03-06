/*
 * shape.h
 *
 *  Created on: Sep 22, 2020
 *      Author: yassine
 */
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <math.h>

#ifndef SHAPE_LIB_SHAPE_H_
#define SHAPE_LIB_SHAPE_H_

void circle(float x , float y , float radius, int fill);

void line(float x1, float y1 , float x2, float y2);
void circle_stroke(float x , float y , float radius, float stroke);
void line_stroke(float x1, float y1 , float x2, float y2,float stroke);

#endif /* SHAPE_LIB_SHAPE_H_ */
