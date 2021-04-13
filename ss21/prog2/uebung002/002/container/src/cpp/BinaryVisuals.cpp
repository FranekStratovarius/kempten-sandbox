#include <limits.h>
#include <stdio.h>

#include "ViewPortGL.h"
#include "BinaryVisuals.h"

void BinaryVisuals::prepareBit(ViewPortGL& vp, int xk, int yk, int width, int height, bool isOne){
	if(isOne){
		vp.prepareBlock(
			xk,yk,width,height,
			255,255,255
		);
	}else{
		vp.prepareLine(
			xk,yk,
			xk+width,yk,
			255,255,255
		);
		vp.prepareLine(
			xk+width,yk,
			xk+width,yk+height,
			255,255,255
		);
		vp.prepareLine(
			xk+width,yk+height,
			xk,yk+height,
			255,255,255
		);
		vp.prepareLine(
			xk,yk+height,
			xk,yk,
			255,255,255
		);
	}
}

void BinaryVisuals::prepareRepresentation(ViewPortGL& vp, unsigned char value, int xk, int yk, int width, int height){
	float miniwidth=(float)width/CHAR_BIT;
	float bitwidth=width/(CHAR_BIT+0.2f*CHAR_BIT);
	unsigned char mask=1<<(CHAR_BIT-1);
	for(int i=0;i<CHAR_BIT;i++){
		bool isOne=false;
		if((value&mask)>0){
			isOne=true;
		}
		BinaryVisuals::prepareBit(
			vp,
			xk+miniwidth*i,yk,
			bitwidth,height,
			isOne
		);
		mask=mask>>1;
	}
}

void BinaryVisuals::prepareRepresentation(ViewPortGL& vp, unsigned int value, int xk, int yk, int width, int height){
	float miniwidth=(float)width/sizeof(value);
	float bitwidth=width/(sizeof(value)+0.2f*sizeof(value));
	for(long unsigned int i=0;i<sizeof(value);i++){
		//bits so hinschieben dass die gewollten 8 am ende stehen
		unsigned char charvalue=value>>(CHAR_BIT*sizeof(value)-CHAR_BIT*(i+1));
		BinaryVisuals::prepareRepresentation(
			vp,charvalue,
			xk+miniwidth*i,yk,
			bitwidth,height
		);
	}
}
