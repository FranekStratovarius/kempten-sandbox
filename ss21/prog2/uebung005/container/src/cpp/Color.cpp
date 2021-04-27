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

int Color::getRed() const{
	return red;
}

int Color::getGreen() const{
	return green;
}

int Color::getBlue() const{
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

Color Color::averageWith(const Color& other) const{
	//average of two colors
	return Color(
		(this->getRed()+other.getRed())/2,
		(this->getGreen()+other.getGreen())/2,
		(this->getBlue()+other.getBlue())/2
	);
}

Color Color::averageWith(const Color& other1, const Color& other2, const Color& other3) const{
	//average of four colors
	return Color(
		(this->getRed()+other1.getRed()+other2.getRed()+other3.getRed())/4,
		(this->getGreen()+other1.getGreen()+other2.getGreen()+other3.getGreen())/4,
		(this->getBlue()+other1.getBlue()+other2.getBlue()+other3.getBlue())/4
	);
}

Color Color::randomlyChange(int maxAmount) const{
	//random distortion
	int red=this->getRed()+rand()%(maxAmount*2)-maxAmount;
	if(red<0){
		red=0;
	}else if(red>255){
		red=255;
	}

	int green=this->getGreen()+rand()%(maxAmount*2)-maxAmount;
	if(green<0){
		green=0;
	}else if(green>255){
		green=255;
	}

	int blue=this->getBlue()+rand()%(maxAmount*2)-maxAmount;
	if(blue<0){
		blue=0;
	}else if(blue>255){
		blue=255;
	}

	return Color(red,green,blue);
}

inline bool Color::equals(const Color& other) const{
	//check if all three colorchannels are the same
	if(
		this->getRed()==other.getRed()
		&&
		this->getGreen()==other.getBlue()
		&&
		this->getBlue()==other.getBlue()
	){
		return true;
	}else{
		return false;
	}
}

//define not initialized color (not working because of logic error color range [0,255])
//const Color Color::nullColor=Color(-1,-1,-1);
const Color Color::nullColor=Color(0,0,0);
