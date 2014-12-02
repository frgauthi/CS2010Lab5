// This header file contains the template for the memory simulation program using vectors and overloaded operators
// Frankie Gauthier
// CS2010 Lab 5

#ifndef memory_h
#define memory_h

#include<stdlib.h>
#include<vector>
#include<stdio.h>
#include <iostream>
using namespace std;

// default size for the memory class
#define defaultSize 100

//the memory class implemented with vectors
class memory{

        private:
	int size;
        vector<int> m;
	void copy(memory&);	

        public:
        explicit memory(int);
        explicit memory(void);
	void dump(int,int);
	void dump(void);
	void store(int,int);
	void memCopy(int,int,int);
	int sizeOf(void);
	int getElement(int);
	bool memEqual(memory&);

	int &operator[](int);
	const int &operator[](int) const;
	
};

std::ostream &operator<<(std::ostream &, const memory&);
memory operator+(memory&, memory&);
bool operator==(memory&,memory&);


#endif
