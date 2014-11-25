// This header file contains the template for the memory simulation program using vectors
// Frankie Gauthier
// CS2010 Lab 4

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
};

std::ostream &operator<<(std::ostream &, const memory&);


#endif
