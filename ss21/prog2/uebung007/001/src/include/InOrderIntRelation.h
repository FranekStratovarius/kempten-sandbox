#include "BinaryRelation.h"

class InOrderIntRelation : BinaryRelation<unsigned int,unsigned int>{
	public:
		bool inRelation(unsigned int a,unsigned int b) override;
};

bool InOrderIntRelation::inRelation(unsigned int a,unsigned int b){
	return a<b;
}
