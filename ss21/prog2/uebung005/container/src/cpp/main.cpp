
#include <iostream>
#include <cmath>
#include <thread>
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


int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	/*
    try {
        //diagonalTest();
        //circleTest(1024, 16, 31);
        paletteGridViewerTest();
    } catch (...) {
        cout << "Unknown error" << endl;
        getchar();
    }
	*/
	int width=500;
	int height=500;

	ViewPortGL vp=ViewPortGL("übung",width,height);
	ColorBuf cb=ColorBuf(width,height);
	cb.clear();
	cb.set(0,0,Color(128,128,128).randomlyChange(128));
	cb.set(0,height-1,Color(128,128,128).randomlyChange(128));
	cb.set(width-1,0,Color(128,128,128).randomlyChange(128));
	cb.set(width-1,height-1,Color(128,128,128).randomlyChange(128));
	cb.buildColorPic(0,0,width-1,height-1,cb);
	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			if(cb.get(x,y).getRed()==0){
				printf("mist... x: %i, y:%i\n",x,y);
			}
		}
	}
	while(!vp.windowShouldClose()){
		vp.clearViewPort();
		cb.drawTo(vp);
		vp.swapBuffers();
	}
	return 0;
}
