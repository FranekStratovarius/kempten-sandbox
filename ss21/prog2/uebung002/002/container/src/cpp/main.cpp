#include <stdio.h>
#include "ViewPortGL.h"
//ue1
#include "Square.h"
#include "Disk.h"
#include "EquiliteralTriangle.h"
#include "PulsatingAnimation.h"
//ue2
#include "BinaryVisuals.h"
#include "bitmagic.h"


int main() {
	ViewPortGL vp=ViewPortGL("Übung 002",1000,1000);

	unsigned char uc=0b00101110;
	unsigned int ui=0;
	//unsigned int ui=4294966296;

	double time=0.0;
	float counter=0.f;

	unsigned int before=2383392409;
	unsigned int after001=exchangeHalves(
		before,
		12,7
	);
	unsigned int after002=exchangeHalves(
		before,
		6,12
	);
	unsigned int reversed=reverse(before);

	while (!vp.windowShouldClose()){
		
		double newtime=glfwGetTime();
		double dt=newtime-time;
		time=newtime;
		counter+=dt;
		if(counter>0.5){
			counter=0.f;
			ui++;
		}

		vp.clearViewPort();

		BinaryVisuals::prepareBit(vp,500,500,100,200,true);
		BinaryVisuals::prepareBit(vp,650,500,100,200,false);

		BinaryVisuals::prepareRepresentation(vp,uc,100,700,500,100);

		BinaryVisuals::prepareRepresentation(vp,ui,100,820,500,100);

		BinaryVisuals::prepareRepresentation(vp,before,100,20,800,50);
		BinaryVisuals::prepareRepresentation(vp,after001,100,80,800,50);
		BinaryVisuals::prepareRepresentation(vp,after002,100,140,800,50);
		BinaryVisuals::prepareRepresentation(vp,reversed,100,200,800,50);

		//send shapes to GPU
		vp.sendTriangles();
		vp.sendLines();
		vp.sendPixels();
		//swap buffer to active buffer
		vp.swapBuffers();
	}
	return 0;
}
