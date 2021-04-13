#include "ViewPortGL.h"

void recDraw(ViewPortGL& vp,float x,float y,float width,float height){
	int wwidth=1000;
	int wheight=1000;
	vp.prepareTriangle(
		x+width*0.25,y+height/2,
		x+width/2,y+height/2,
		x+width/2,y+height,
		(y+height/2)/wheight*255,(x+width/2)/wwidth*255,0
	);
	vp.prepareTriangle(
		x+width*0.75,y+height/2,
		x+width/2,y+height/2,
		x+width/2,y+height,
		(y+height/2)/wheight*255,(x+width/2)/wwidth*255,0
	);
	if(width>wwidth/50){
		recDraw(vp,x,y+height/2,width/2,height/2);			//bottom-left
		recDraw(vp,x+width/2,y+height/2,width/2,height/2);	//bottom-right
		recDraw(vp,x+width/4,y,width/2,height/2);			//top-middle
	}
}

int main() {
	ViewPortGL vp=ViewPortGL("Übung 0024",1000,1000);
	while (!vp.windowShouldClose()){
		//vp.clearViewPort();	//not needed because background is drawn
		//white background
		vp.prepareBlock(0,0,1000,1000,255,255,255);
		//start triangle-recursion
		recDraw(vp,0,0,1000,1000);
		//send shapes to GPU
		vp.sendTriangles();
		vp.sendLines();
		vp.sendPixels();
		//swap buffer to active buffer
		vp.swapBuffers();
	}
	return 0;
}
