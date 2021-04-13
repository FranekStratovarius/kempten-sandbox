#include "Shape.h"

class EquiliteralTriangle:public Shape{
	public:
		EquiliteralTriangle(int red,int green,int blue);
		void prepare(ViewPortGL& vp,int centerX,int centerY,int size) override;
};
