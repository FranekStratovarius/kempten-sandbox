
#include <iostream>
#include <cmath>
#include <thread>
#include <cstdio>	//TMP
#include "GridViewer.h"
#include "PaletteGridViewer.h"
#include "ViewPortGL.h"
#include "ColorBuf.h"

void paletteGridViewerTest() {
    try {
        int size = 1024;
        PaletteGridViewer pGrid = PaletteGridViewer("Palette Grid", size, 128, 255);

        pGrid.setColor(0, Color(0,0,0));
        pGrid.setColor(1, Color(255, 255, 255));
        pGrid.setColor(2, Color(128, 128, 128));
        pGrid.setColor(3, Color(128, 0, 128));
        bool isRunning = true;
        int line = 0;
        while (isRunning) {
            isRunning = !pGrid.windowShouldClose();
            pGrid.clearViewPort();
            for (int i = 0; i < pGrid.getGridSize(); i++) {
                for (int j = 0; j < pGrid.getGridSize(); j++) {
                    pGrid.setCell(i, j, 2);
                }
            }

            for (int i = 0; i < pGrid.getGridSize(); i++)
                pGrid.setCell(i, line, 3);
            pGrid.draw();
            pGrid.swapBuffers();
            line = (line + 1) % pGrid.getGridSize();
            std::this_thread::sleep_for(100ms);
        }
    } catch (exception exc) {
        cout << exc.what() << endl;
        getchar();
    }
}

void circleTest(int gridSize, int tileSize, int radius) {
    try {
        GridViewer grid = GridViewer("Grid", gridSize, tileSize);

        bool isRunning = true;
        while (isRunning) {
            isRunning = !grid.windowShouldClose();
            grid.clearViewPort();
            int radiusSquared = radius * radius;
            int mid = grid.getGridSize() / 2;
                for (int i = 0; i < radius; i++) {
                int x = static_cast<int>(round(sqrt(radiusSquared - (i * i))));
                for (int j= -x; j <= x; j++) { 
                    int r = static_cast<int>(round(static_cast<double>(i)/radius * 255));
                    int g = static_cast<int>(round(static_cast<double>(j + x) / (2*radius) * 255));
                    grid.setCell(mid + j, mid + i, (r << 24) | (g << 16) | (g << 8));
                    grid.setCell(mid + j, mid - i, (r << 24) | (g << 16) | (g << 8));
                }
            }
            grid.draw();
            grid.swapBuffers();
        }
    } catch (exception exc) {
        cout << exc.what() << endl;
        getchar();
    }
}



void diagonalTest() {
    try {
        int size = 1024;
        GridViewer grid = GridViewer("Grid", size, 128);

        bool isRunning = true;
        while (isRunning) {
            isRunning = !grid.windowShouldClose();
            grid.clearViewPort();
            for (int i = 0; i < grid.getGridSize(); i++) 
                grid.setCell(i, i, 0xa0a00000);
            grid.draw();
            grid.swapBuffers();
        }
    } catch (exception exc) {
        cout << exc.what() << endl;
        getchar();
    }
}

Color colorFor(unsigned int value){
	int red,green,blue;
	red=(value >> 24)&0b11111111;
	green=(value >> 16)&0b11111111;
	blue=(value >> 8)&0b11111111;
	return Color(red,green,blue);
}

unsigned int toColornumber(Color c){
	unsigned int red=c.getRed();
	unsigned int green=c.getGreen();
	unsigned int blue=c.getBlue();

	unsigned int result=red<<8;
	result=(result|green)<<8;
	result=(result|blue)<<8;
	
	return result;
}

void buildColorPic(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, GridViewer& gv){
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

	if(
		((x2-x1)>1)
		||
		((y2-y1)>1)
	){
		int change=70;
		if((x1-x2)!=0){
			if(colorFor(gv.getCell(p5x,p5y)).getRed()==0&&colorFor(gv.getCell(p5x,p5y)).getGreen()==0&&colorFor(gv.getCell(p5x,p5y)).getBlue()==0
			){
				//set p5 (top)
				gv.setCell(p5x,p5y,toColornumber(colorFor(gv.getCell(x1,y1)).averageWith(colorFor(gv.getCell(x2,y1))).randomlyChange(change)));
			}
			if(colorFor(gv.getCell(p8x,p8y)).getRed()==0&&colorFor(gv.getCell(p8x,p8y)).getGreen()==0&&colorFor(gv.getCell(p8x,p8y)).getBlue()==0){
				//set p8 (bottom)
				gv.setCell(p8x,p8y,toColornumber(colorFor(gv.getCell(x1,y2)).averageWith(colorFor(gv.getCell(x2,y2))).randomlyChange(change)));
			}
		}
		if((y1-y2)!=0){
			if(colorFor(gv.getCell(p6x,p6y)).getRed()==0&&colorFor(gv.getCell(p6x,p6y)).getGreen()==0&&colorFor(gv.getCell(p6x,p6y)).getBlue()==0){
				//set p6 (left)
				gv.setCell(p6x,p6y,toColornumber(colorFor(gv.getCell(x1,y1)).averageWith(colorFor(gv.getCell(x1,y2))).randomlyChange(change)));
			}
			if(colorFor(gv.getCell(p7x,p7y)).getRed()==0&&colorFor(gv.getCell(p7x,p7y)).getGreen()==0&&colorFor(gv.getCell(p7x,p7y)).getBlue()==0){
				//set p7 (right)
				gv.setCell(p7x,p7y,toColornumber(colorFor(gv.getCell(x2,y1)).averageWith(colorFor(gv.getCell(x2,y2))).randomlyChange(change)));
			}
		}
		//set p9 with average of p5, p6, p7, p8
		gv.setCell(p9x,p9y,toColornumber(colorFor(gv.getCell(p5x,p5y)).averageWith(
			colorFor(gv.getCell(p8x,p8y)),
			colorFor(gv.getCell(p6x,p6y)),
			colorFor(gv.getCell(p7x,p7y))
		)));

		buildColorPic(x1,y1,xm,ym,gv);		//oben links
		buildColorPic(xm,y1,x2,ym,gv);		//oben rechts
		buildColorPic(x1,ym,xm,y2,gv);		//unten links
		buildColorPic(xm,ym,x2,y2,gv);		//unten rechts
	}
}

int main(int argn, char* argv[]){
	srand(static_cast<unsigned int>(time(nullptr)));

	if(argn>1){
		switch(std::stoi(argv[1])){
			case 1:	{
				//version without gridviewer
				int width=1000;
				int height=1000;

				ViewPortGL vp=ViewPortGL("übung",width,height);
				ColorBuf cb=ColorBuf(width,height);
				cb.clear();
				cb.set(0,0,Color(128,128,128).randomlyChange(128));
				cb.set(0,height-1,Color(128,128,128).randomlyChange(128));
				cb.set(width-1,0,Color(128,128,128).randomlyChange(128));
				cb.set(width-1,height-1,Color(128,128,128).randomlyChange(128));
				cb.buildColorPic(0,0,width-1,height-1,cb);
				while(!vp.windowShouldClose()){
					vp.clearViewPort();
					cb.drawTo(vp);
					vp.swapBuffers();
				}
				break;
			}
			case 2: {
				//version with gridviewer

				int width=64;
				int height=64;

				GridViewer gv=GridViewer("übung",1024,16);
				gv.setCell(0,0,toColornumber(Color(128,128,128).randomlyChange(128)));
				gv.setCell(0,height-1,toColornumber(Color(128,128,128).randomlyChange(128)));
				gv.setCell(width-1,0,toColornumber(Color(128,128,128).randomlyChange(128)));
				gv.setCell(width-1,height-1,toColornumber(Color(128,128,128).randomlyChange(128)));
				buildColorPic(0,0,width-1,height-1,gv);
				while(!gv.windowShouldClose()){
					gv.clearViewPort();
					gv.draw();
					gv.swapBuffers();
				}
				break;
			}
		}
	}

	return 0;
}
