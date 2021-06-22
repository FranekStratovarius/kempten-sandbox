#include <iostream>

#include "FlexArray.h"
#include "SimpleList.h"

int main(int argn,char* args[]){
	FlexArray<int,2,5> flar=FlexArray<int,2,5>(0);
	flar.set(0,23);
	flar.set(1,20);
	flar.set(2,34);
	flar.set(3,76);
	flar.set(4,3);
	flar.print();

	/*
	auto iter=flar.begin();
	auto end=flar.end();
	std::cout<<*iter<<std::endl;
	std::cout<<*++iter<<std::endl;
	std::cout<<*++iter<<std::endl;
	std::cout<<*--end<<std::endl;
	//*/
	/*
	iter=flar.begin();
	std::cout<<*iter++<<std::endl;
	iter++;
	std::cout<<*iter<<std::endl;
	//*/



	/*
	for (auto i:flar)
		std::cout<<i<<std::endl;
	//*/
	//*
	int ctr=0;
	for(FlexArray<int,2,5>::FlexArrayIterator it=flar.begin(),end=flar.end();it!=end;++it){
		const int i=*it;
		std::cout<<i<<" ctr: "<<ctr++<<std::endl;
	}
	//*/

	return 0;
}
