/*
#include <cstdio>	//TMP
#include "GridViewer.h"
int main(int argc, char* argv[]){
	int size=512;
	int cellwidth=64;
	GridViewer gv=GridViewer("Übung 004",size,cellwidth);
	gv.setCell(1,1,0b1111111000000001111111100000000);
	gv.setCell(7,5,0b1111111000000001111111100000000);
	gv.setCell(7,7,0b111111100000000);
	for(int x=0;x<size/cellwidth;x++){
		for(int y=0;y<size/cellwidth;y++){
			int color;//=255.f/((1024.f/64.f)/x);
			color=(int)(255.f/(((float)size/cellwidth)/x))<<8;
			color=color | (int)(255.f/(((float)size/cellwidth)/y))<<24;
			gv.setCell(x,y,color);
		}
	}
	printf("%i\n",gv.getCell(7,5));
	while(!gv.windowShouldClose()){
		gv.clearViewPort();
		gv.draw();
		//send shapes to GPU
		gv.sendTriangles();
		gv.sendLines();
		gv.sendPixels();

		gv.swapBuffers();

	}
	return 0;
}
*/
