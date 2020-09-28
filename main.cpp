#include "Slider/shape_lib/shape.h"
#include <vector>
#include <iostream>
#include "Slider/Slider.h"
#define vecteur std::vector<float>
float Rad;
int x = 0,n ,iteration = 1;
float x2 = 0 ,  y2 = 0 ,prevx , prevy;




int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Fourrier Series" , NULL);
	SDL_SetVideoMode(1000,1000,32,SDL_OPENGL);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	vecteur wave;
	SDL_EnableKeyRepeat(0,0);

	SDL_Event event;
	Slider slid(1,100,-0.8);
	while(1){

		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();


		while(SDL_PollEvent(&event)){
		switch (event.type) {
			case SDL_QUIT :
				SDL_Quit();
				exit(0);
			default:
				break;
		}
		}
		x2 = 0;
		y2 = 0;
		iteration = slid.value(event) ;
		glTranslatef(-0.4 , 0,0);
		for(int i = 0 ;  i< iteration ; i++){
			n = 2*i+1;
			Rad = 0.3*4/(M_PI * n);
			prevx = x2;
			prevy = y2;

			x2 += Rad*cos(n*x*M_PI/180);
			y2 += Rad*sin(n*x*M_PI/180);



			glColor3f(1,0,0);
			circle(prevx,prevy,Rad ,0);
			glColor3f(0,1,0);
			line(prevx,prevy,x2,y2);
			circle(x2,y2,Rad/40 , 1);
		}
		wave.insert(wave.begin() , y2);
			glColor3f(1,1,0);
			line(x2,y2,0.6,y2);

			glTranslatef(0.6,0,0);
			glBegin(GL_LINE_STRIP);


			for(unsigned int i = 0 ; i< wave.size() ; i++){

				glVertex2f(i*0.001,wave[i]);

			}



		if(wave.size()> 1000){
			wave.pop_back();
		}

		glEnd();

		glFlush();
		SDL_GL_SwapBuffers();



		x+=1;
	}



	return 0;
}
