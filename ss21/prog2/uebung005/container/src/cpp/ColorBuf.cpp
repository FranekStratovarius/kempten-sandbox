#include <cstdio>

#include "ViewPortGL.h"
#include "ColorBuf.h"

ColorBuf::ColorBuf(unsigned int widthP, unsigned int heightP) : width(widthP), height(heightP){
	colorState=new Color*[widthP];
	for(unsigned int x=0;x<width;x++){
		colorState[x]=new Color[heightP];
	}
}

ColorBuf::~ColorBuf(){
	for(unsigned int x=0;x<width;x++){
		for(unsigned int y=0;y<height;y++){
			//delete colorState[x][y];
		}
		delete colorState[x];
	}
	delete colorState;
}

Color& ColorBuf::get(unsigned int x, unsigned int y){
	return colorState[x][y];
}

void ColorBuf::set(unsigned int x, unsigned int y, const Color& c){
	colorState[x][y]=c;
}

void ColorBuf::drawTo(ViewPortGL& vp){
	int pixn=0;
	for(unsigned int x=0;x<width;x++){
		for(unsigned int y=0;y<height;y++){
			vp.preparePix(x,y,
				colorState[x][y].getRed(),
				colorState[x][y].getGreen(),
				colorState[x][y].getBlue()
			);
			if(++pixn>=vp.getMaxNumberOfPreparedPixels()){
				pixn=0;
				vp.sendPixels();
			}
		}
	}
	vp.sendPixels();
}

void ColorBuf::clear(){
	for(unsigned int x=0;x<width;x++){
		for(unsigned int y=0;y<height;y++){
			colorState[x][y]=Color(0,0,0);
		}
	}
}

void ColorBuf::buildColorPic(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, ColorBuf& cBuf){
	int xm=x1+(x2-x1)/2;
	int ym=y1+(y2-y1)/2;

	int p5x=xm;
	int p5y=y1;
	int p8x=xm;
	int p8y=y2;
	int p6x=x1;
	int p6y=ym;
	int p7x=x2;
	int p7y=ym;
	int p9x=xm;
	int p9y=ym;

	printf("x1: %i, xm: %i, x2: %i\ny1: %i, ym: %i, y2: %i\n\n",x1,xm,x2,y1,ym,y2);
	printf("if: %i, %i\n\n",x2-x1,y2-y1);

	if(
		((x2-x1)>1)
		||
		((y2-y1)>1)
	){
		printf("drawing...\n");
		if((x1-x2)!=0){
			if(cBuf.get(p5x,p5y).getRed()==0&&cBuf.get(p5x,p5y).getGreen()==0&&cBuf.get(p5x,p5y).getBlue()==0){
				cBuf.set(p5x,p5y,cBuf.get(x1,y1).averageWith(cBuf.get(x2,y1)).randomlyChange(20));
			}
			if(cBuf.get(p8x,p8y).getRed()==0&&cBuf.get(p8x,p8y).getGreen()==0&&cBuf.get(p8x,p8y).getBlue()==0){
				cBuf.set(p8x,p8y,cBuf.get(x1,y2).averageWith(cBuf.get(x2,y2)).randomlyChange(20));
			}
			//printf("p5: %i, %i, p8: %i, %i\n",p5x,p5y,p6x,p6y);
			//cBuf.set(p5x,p5y,Color(255,255,255));
			//cBuf.set(p8x,p8y,Color(255,255,255));
		}
		if((y1-y2)!=0){
			if(cBuf.get(p6x,p6y).getRed()==0&&cBuf.get(p6x,p6y).getGreen()==0&&cBuf.get(p6x,p6y).getBlue()==0){
				cBuf.set(p6x,p6y,cBuf.get(x1,y1).averageWith(cBuf.get(x1,y2)).randomlyChange(20));
			}
			if(cBuf.get(p7x,p7y).getRed()==0&&cBuf.get(p7x,p7y).getGreen()==0&&cBuf.get(p7x,p7y).getBlue()==0){
				cBuf.set(p7x,p7y,cBuf.get(x2,y1).averageWith(cBuf.get(x2,y2)).randomlyChange(20));
			}
			//printf("p6: %i, %i, p7: %i, %i\n",p5x,p5y,p6x,p6y);
			//cBuf.set(p6x,p6y,Color(255,255,255));
			//cBuf.set(p7x,p7y,Color(255,255,255));
		}
		cBuf.set(p9x,p9y,cBuf.get(p5x,p5y).averageWith(
			cBuf.get(p8x,p8y),
			cBuf.get(p6x,p6y),
			cBuf.get(p7x,p7y)
		));

		cBuf.buildColorPic(x1,y1,xm,ym,cBuf);		//oben links
		cBuf.buildColorPic(xm,y1,x2,ym,cBuf);		//oben rechts
		cBuf.buildColorPic(x1,ym,xm,y2,cBuf);		//unten links
		cBuf.buildColorPic(xm,ym,x2,y2,cBuf);		//unten rechts
	}
	//printf("draw: x1: %i, y1: %i, x2: %i, y2: %i\n",x1+(x2-x1)/2+1,y1,x2,y1+(y2-y1)/2);
	//cBuf.buildColorPic(x1+(x2-x1)/2+1,y1,x2,y1+(y2-y1)/2,cBuf);	//oben rechts
	//cBuf.buildColorPic(x1+1,,cBuf);	//unten links
	//cBuf.buildColorPic(p5x,p5y,p7x,p7y,cBuf);	//oben rechts
	//cBuf.buildColorPic(p6x,p6y,p8x,p8y,cBuf);	//unten links
	//cBuf.buildColorPic(p9x,p9y,x2,y2,cBuf);		//unten rechts
}
