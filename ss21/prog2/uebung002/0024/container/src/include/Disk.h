#include "Shape.h"

class Disk:public Shape{
	public:
		Disk(int red,int green,int blue);
		void prepare(ViewPortGL& vp,int centerX,int centerY,int size) override;
};
