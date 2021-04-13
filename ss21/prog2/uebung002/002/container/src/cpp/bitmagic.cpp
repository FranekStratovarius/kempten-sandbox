#include <stdio.h>
#include <limits.h>

#include "bitmagic.h"

unsigned int exchangeHalves(unsigned int value, int fromBit, int toBit){
	if(fromBit>toBit){
		int tmp=fromBit;
		fromBit=toBit;
		toBit=tmp;
	}
	if((unsigned int)toBit>=sizeof(unsigned int)*CHAR_BIT || fromBit<0){
		return value;
	}
	int length=(toBit-fromBit+1)/2;
	unsigned int mask1=0;
	//maske befüllen
	for(int i=0;i<length;i++){mask1=(mask1 << 1)|1;}
	//maske für den unteren bereich hinschieben
	unsigned int mask2=mask1 << (fromBit);
	//maske für oberen bereich hinschieben
	mask1=mask1 << (toBit-length+1);
	//rückgabe mit masken
	return (value&~(mask1|mask2)) | ((value << (toBit-fromBit+1-length))&mask1) | ((value >> (toBit-fromBit+1-length))&mask2);
}

unsigned int reverse(unsigned int b){
	return reverserec(b,sizeof(unsigned int)*CHAR_BIT-1,sizeof(unsigned int)*CHAR_BIT);
}

unsigned int reverserec(unsigned int b, int idx, int length){
	if(length==1){
		return b;
	}else{
		return reverserec(reverserec(exchangeHalves(b,idx,idx-length+1),idx-length/2,length/2),idx,length/2);
	}
}

/*
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
	return exchangeHalves(b,0,sizeof(int)*CHAR_BIT-1);
}
*/
