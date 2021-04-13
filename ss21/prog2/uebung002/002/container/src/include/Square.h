#include "Shape.h"

class Square:public Shape{
	public:
		Square(int red,int green,int blue);
		void prepare(ViewPortGL& vp,int centerX,int centerY,int size) override;
};
