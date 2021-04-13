#include "PulsatingAnimation.h"

PulsatingAnimation::PulsatingAnimation(int x, int y, int min, int max){
	posX=x;
	posY=y;
	minSize=min;
	maxSize=max;
}

void PulsatingAnimation::animate(ViewPortGL& vp, Shape& s){
	double newtime=glfwGetTime();
	double dt=newtime-time;
	time=newtime;

	if(expand && currsize<=maxSize){
		currsize+=dt*speed;
	}else if(currsize>=minSize){
		expand=false;
		currsize-=dt*speed;
	}else{
		expand=true;
	}

	s.prepare(vp,posX,posY,currsize);
}
