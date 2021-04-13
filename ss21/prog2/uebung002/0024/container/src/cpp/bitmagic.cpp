#include <stdio.h>

unsigned int exchangeHalves(unsigned int value, int fromBit, int toBit){
	if(fromBit>toBit){
		int tmp=fromBit;
		fromBit=toBit;
		toBit=tmp;
	}
	unsigned int mask=1;
	unsigned int reference=value;
	for(int i=0;i<=toBit-fromBit;i++){
		if((reference&mask<<(fromBit+i))>0){
			//einser setzen
			value|=mask<<(toBit-i);
		}else{
			//nuller setzen
			value&=~(mask<<(toBit-i));
		}
	}
	return value;
}

unsigned int reverse(unsigned int b){
	return b;
}
