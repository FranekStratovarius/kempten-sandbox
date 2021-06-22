#pragma once
#include <iostream>

template<class T, unsigned int sizeFakt, unsigned int initialSize>
class FlexArray {

	public:
		FlexArray(T defaultV) {
			size = initialSize;
			data = new T[size];
			defaultValue = defaultV;
			for (unsigned int i = 0; i < size; i++) {
				data[i] = defaultV;
			}
		}


		~FlexArray() {
			delete[] data;
		}

		void set(unsigned int pos, T value) {
			while (pos >= size) enlarge();
			data[pos] = value;
		}

		T get(unsigned int pos) {
			while (pos >= size) enlarge();
			return data[pos];
		}

		void print() {
			for (unsigned int i = 0; i < size; i++) {
				std::cout << data[i];
				if (i != size - 1) std::cout << ", ";
			}
			std::cout << std::endl;
		}

		void exchange(unsigned int i, unsigned int j) {
			while (i >= size || j >= size) enlarge();
			T temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		//new
		class FlexArrayIterator{
			friend FlexArray;
			public:
				FlexArrayIterator(FlexArray* array,unsigned int pos){
					this->array=array;
					this->pos=pos;
				}
				inline T operator*()const{return array->data[pos];}
				inline T operator->()const{return **this;}
				inline FlexArrayIterator& operator++(){if(array->size>pos)pos++;return *this;}	//prefix
				/*
				FlexArrayIterator& operator++(int){	//postfix
					FlexArrayIterator* tmp=new FlexArrayIterator(array,pos);
					++*this;
					return *tmp;
				}
				*/
				inline FlexArrayIterator& operator--(){if(pos>0)pos--;return *this;}	//prefix
				/*
				FlexArrayIterator& operator--(int){	//postfix
					FlexArrayIterator tmp=FlexArrayIterator(array,pos);
					--*this;
					return tmp;
				}
				*/
				inline bool operator==(const FlexArrayIterator& other)const	{return other.pos==this->pos;}
				inline bool operator!=(const FlexArrayIterator& other)const	{return !(*this==other);}
				inline T operator[](int n)									{return array->data[pos+n];}
				inline FlexArrayIterator operator+(const unsigned int& n)	{return FlexArrayIterator(this->array,this->pos+n);}
				inline FlexArrayIterator operator-(const unsigned int& n)	{return FlexArrayIterator(this->array,this->pos-n);}
				inline FlexArrayIterator& operator+=(unsigned int& n)		{return *this+n;}
				inline FlexArrayIterator& operator-=(unsigned int& n)		{return *this-n;}
				inline bool operator<(const FlexArrayIterator& other)		{return this->pos<other.pos;}
				inline bool operator>(const FlexArrayIterator& other)		{return this->pos>other.pos;}
				inline bool operator<=(const FlexArrayIterator& other)		{return this->pos==other.pos||this->pos<other.pos;}
				inline bool operator>=(const FlexArrayIterator& other)		{return this->pos==other.pos||this->pos>other.pos;}
			private:
				FlexArray* array;
				unsigned int pos;
		};

		//new
		inline FlexArrayIterator begin(){return FlexArrayIterator(this,0);}
		inline FlexArrayIterator end(){return FlexArrayIterator(this,size);}

	private:
		void enlarge() {
			T* newData = new T[size * sizeFakt];
			for (unsigned int i = 0; i < size; i++) {
				newData[i] = data[i];
			}
			for (unsigned int i = size; i < sizeFakt * size; i++) {
				newData[i] = defaultValue;
			}
			delete[] data;
			data = newData;
			size *= sizeFakt;
		}

		T defaultValue;
		T* data;
		unsigned int size;
};

