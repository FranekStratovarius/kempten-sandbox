#include <stdexcept>
#include "Color.h"

Color::Color(){
	red=0;
	green=0;
	blue=0;
}

Color::Color(int r, int g, int b){
	if(r >= 0 && r <=255){	//check colorrange
		red=r;
	}else{
		throw std::logic_error("Color RED not in range [0,255].");
	}
	if(g >= 0 && g <=255){	//check colorrange
		green=g;
	}else{
		throw std::logic_error("Color GREEN not in range [0,255].");
	}
	if(b >= 0 && b <=255){	//check colorrange
		blue=b;
	}else{
		throw std::logic_error("Color BLUE not in range [0,255].");
	}
}

int Color::getRed(){
	return red;
}

int Color::getGreen(){
	return green;
}

int Color::getBlue(){
	return blue;
}

void Color::setRed(int r){
	if(r >= 0 && r <=255){	//check colorrange
		red=r;
	}else{
		throw std::logic_error("Color RED not in range [0,255].");
	}
}

void Color::setGreen(int g){
	if(g >= 0 && g <=255){	//check colorrange
		green=g;
	}else{
		throw std::logic_error("Color GREEN not in range [0,255].");
	}
}

void Color::setBlue(int b){
	if(b >= 0 && b <=255){	//check colorrange
		blue=b;
	}else{
		throw std::logic_error("Color BLUE not in range [0,255].");
	}
}

Color Color::darken(int amount){
	red-=amount;
	if(red<0){
		red=0;
	}
	green-=amount;
	if(green<0){
		green=0;
	}
	blue-=amount;
	if(blue<0){
		blue=0;
	}
	return *this;
}

Color Color::lighten(int amount){
	red+=amount;
	if(red>255){
		red=255;
	}
	green+=amount;
	if(green>255){
		green=255;
	}
	blue+=amount;
	if(blue>255){
		blue=255;
	}
	return *this;
}
