#include <stdexcept>

#include "PaletteGridViewer.h"

PaletteGridViewer::PaletteGridViewer(string title, int size, int tileSize, int paletteSizeP) : GridViewer(title, size, tileSize){
	if(paletteSizeP<1){
		throw logic_error("paletteSizeP smaller than 1.");
	}
	if(paletteSizeP>256){
		throw logic_error("paletteSizeP greater than 256.");
	}
	paletteSize=paletteSizeP;
	palette=new Color[paletteSize];
}

PaletteGridViewer::~PaletteGridViewer(){
	delete[] palette;	//delete array
}

void PaletteGridViewer::setColor(unsigned int value, Color c){
	if(value<0){
		throw logic_error("value smaller than 0.");
	}
	if(value>=paletteSize){
		throw logic_error("value greater than paletteSize-1.");
	}
	palette[value]=c;
}

Color PaletteGridViewer::getColor(unsigned int value){
	if(value<0){
		throw logic_error("value smaller than 0.");
	}
	if(value>=paletteSize){
		throw logic_error("value greater than paletteSize-1.");
	}
	return palette[value];
}

Color PaletteGridViewer::colorFor(unsigned int value){
	unsigned int palettevalue=value&0b11111111;
	if(palettevalue>=0&&palettevalue<paletteSize){
		return palette[palettevalue];
	}else{
		return GridViewer::colorFor(value);
	}
}
