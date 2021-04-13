#include "Disk.h"
#include <math.h>
#define PI 3.14159265

Disk::Disk(int r,int g,int b):Shape(r,g,b){}

void Disk::prepare(ViewPortGL& vp,int cx,int cy,int size){
	for(int i=0;i<=size*2;i++){
		int y=cy-size+i;
		vp.prepareLine(
			cx-size*cos(asin((y-cy+0.f)/size)),y,
			cx+size*cos(asin((y-cy+0.f)/size)),y,
			red,green,blue
		);
	}
}
/*
ausgangsrechnung:
x=cx+r*cos(winkel)
y=cy+r*sin(winkel)
winkel=asin((y-cy)/r)
*/

/*
Pythagoras:
double rsq=radius*radius;
--über radius iterieren
x=sqrt(rsq-(y*y))
untere linie und obere linie simultan malen
*/
