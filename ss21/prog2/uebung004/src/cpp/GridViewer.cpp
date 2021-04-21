#include <stdexcept>
#include <cmath>
#include <cstdio>	//TMP

#include "GridViewer.h"

GridViewer::GridViewer(string titleP, int size, int tileSizeP) : ViewPortGL(titleP,size,size), tileSize(tileSizeP), gridSize(size/tileSizeP){
	//error checking for input variables
	double logsize = log2(size);
	if(!((int)logsize - logsize == 0))
		throw logic_error("size no power of 2.");
	if(!(logsize >= 4 || logsize <=10))
		throw logic_error("size not in range [4,1024].");
	logsize = log2(tileSizeP);
	if(!((int)logsize - logsize == 0))
		throw logic_error("tileSizeP no power of 2.");
	if(!(logsize >= 4 || logsize <=10))
		throw logic_error("tileSizeP not in range [4,1024].");
	if(tileSizeP>size)
		throw logic_error("tileSizeP biger than size.");
	content=new unsigned int[gridSize*gridSize];	//create array with size gridSize^2
	for(int i=0;i<gridSize*gridSize;i++){	//set all cells to 0
		content[i]=0;
	}
}

GridViewer::~GridViewer(){
	delete[] content;	//delete dynamically allocated array
}

Color GridViewer::colorFor(unsigned int value) {
	int red,green,blue;
	red=(value >> 24)&0b11111111;
	green=(value >> 16)&0b11111111;
	blue=(value >> 8)&0b11111111;
	return Color(red,green,blue);
}

void GridViewer::prepareCell(int x, int y) {
	Color color=colorFor(this->getCell(x,y));
	//printf("x: %i, y: %i, size: %i\n",x*tileSize,y*tileSize,tileSize);
	//prepareBlock(x*tileSize,y*tileSize,tileSize,tileSize,color.getRed(),color.getGreen(),color.getBlue());	//tilesize+1 for overlapping blocks. they draw with black lines
	prepareBlock(
		x*tileSize,
		y*tileSize,
		tileSize+1,
		tileSize+1,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
}

void GridViewer::prepareCellBorder(int x, int y) {
	Color color=colorFor(this->getCell(x,y));
	color.lighten(40);
	//oberer rand
	prepareBlock(
		x*tileSize,
		y*tileSize,
		tileSize+1,
		(tileSize)/8,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	//rechter rand
	prepareBlock(
		x*tileSize+tileSize/8*7,
		y*tileSize,
		tileSize/8+1,
		tileSize+1,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	color=colorFor(this->getCell(x,y));
	color.darken(40);
	//unterer rand
	prepareBlock(
		x*tileSize,
		y*tileSize+tileSize/8*7,
		tileSize+1,
		tileSize/8+1,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	//rechter rand
	prepareBlock(
		x*tileSize,
		y*tileSize,
		tileSize/8,
		tileSize,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	color=colorFor(this->getCell(x,y));
	color.lighten(80);
	//oben-rechts
	prepareBlock(
		x*tileSize+(tileSize)/8*7,
		y*tileSize,
		(tileSize)/8+1,
		(tileSize)/8,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	color=colorFor(this->getCell(x,y));
	//unten-rechts
	prepareBlock(
		x*tileSize+(tileSize)/8*7,
		y*tileSize+(tileSize)/8*7,
		(tileSize)/8+1,
		(tileSize)/8+1,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	//oben-links
	prepareBlock(
		x*tileSize,
		y*tileSize,
		(tileSize)/8,
		(tileSize)/8,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
	color=colorFor(this->getCell(x,y));
	color.darken(80);
	//unten-rechts
	prepareBlock(
		x*tileSize,
		y*tileSize+(tileSize)/8*7,
		(tileSize)/8,
		(tileSize)/8+1,
		color.getRed(),
		color.getGreen(),
		color.getBlue()
	);	//tilesize+1 for overlapping blocks. they draw with black lines
}

unsigned int GridViewer::getCell(int x, int y) {
	if(x < 0)
		throw logic_error("x smaller than 0.");
	if(y < 0)
		throw logic_error("y smaller than 0.");
	if(x >= gridSize)
		throw logic_error("x bigger than gridSize-1.");
	if(y >= gridSize)
		throw logic_error("y bigger than gridSize-1.");
	return content[gridSize*y+x];	//zellen pro zeile * zeile + spalte
}


void GridViewer::setCell(int x, int y, unsigned int value) {
	if(x < 0)
		throw logic_error("x smaller than 0.");
	if(y < 0)
		throw logic_error("y smaller than 0.");
	if(x >= gridSize)
		throw logic_error("x bigger than gridSize-1.");
	if(y >= gridSize)
		throw logic_error("y bigger than gridSize-1.");
	//testCoordinates(x, y);
	content[y * gridSize + x] = value;
}

void GridViewer::draw() {
	int count = 0;
	static const int maxPreparedTriangles = getMaxNumberOfPreparedTriangles();
	static const int maxPreparedLines = getMaxNumberOfPreparedLines();
	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			prepareCell(x, y);
			prepareCellBorder(x, y);
			count++;
			if (maxPreparedTriangles - 1 <= count*2 || maxPreparedLines - 3 <= count * 4) {
				sendTriangles();
				sendLines();
				sendPixels();
				count = 0;
			}
		}
	}
	if (count > 0) {
		sendTriangles();
		sendLines();
		sendPixels();
	}
}

int GridViewer::getGridSize() {
	return gridSize;
}
