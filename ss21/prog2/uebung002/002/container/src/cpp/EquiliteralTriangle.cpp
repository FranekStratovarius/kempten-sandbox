#include "EquiliteralTriangle.h"
#include <math.h>
#define PI 3.14159265f

EquiliteralTriangle::EquiliteralTriangle(int r,int g,int b):Shape(r,g,b){}

void EquiliteralTriangle::prepare(ViewPortGL& vp,int centerX,int centerY,int size){
	float a=PI/6.f;
	vp.prepareTriangle(
		centerX,centerY-size,
		centerX,centerY+size*sin(a),
		centerX-size*cos(a),centerY+size*sin(a),
		red,green,blue
	);
	vp.prepareTriangle(
		centerX,centerY-size,
		centerX,centerY+size*sin(a),
		centerX+size*cos(a),centerY+size*sin(a),
		red,green,blue
	);
}
