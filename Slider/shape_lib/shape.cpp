#include "shape.h"

void circle(float x , float y , float radius, int fill){
	if(fill == 0){//no fill
		glBegin(GL_LINE_STRIP);
	}
	else glBegin(GL_POLYGON);
	for(int i = 0 ; i <361 ; i++ ){
		glVertex2f(radius*cos(i*M_PI/180)+ x ,radius*sin(i*M_PI/180)+ y);
	}
	glEnd();
}
void circle_stroke(float x , float y , float radius, float stroke){
	glPointSize(stroke);
	glBegin(GL_POINTS);
	for(int i = 0 ; i <361 ; i++ ){
		glVertex2f(radius*cos(i*M_PI/180)+ x ,radius*sin(i*M_PI/180)+ y);
	}
	glEnd();
}
void line(float x1, float y1 , float x2, float y2){
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}
void line_stroke(float x1, float y1 , float x2, float y2,float stroke){
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x2+stroke,y2+stroke);
	glVertex2f(x1+stroke,y1+stroke);
	glEnd();
}
