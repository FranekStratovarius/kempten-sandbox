#include "Square.h"

Square::Square(int r,int g,int b):Shape(r,g,b){
	//Shape(r,g,b);
}

void Square::prepare(ViewPortGL& vp,int centerX,int centerY,int size){
	vp.prepareTriangle(
		centerX-size,centerY-size,
		centerX-size,centerY+size,
		centerX+size,centerY-size,
		red,green,blue
	);
	vp.prepareTriangle(
		centerX+size,centerY+size,
		centerX-size,centerY+size,
		centerX+size,centerY-size,
		red,green,blue
	);
}
