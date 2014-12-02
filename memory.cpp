// This file contains the function source code for the memory simulation program using vectors and overloaded operators
// Frankie Gauthier
// CS2010 Lab 5

#include "memory.h"


// overloading equality operator to determine if two memories contain the same elements
// takes two references to memory
// returns a boolean indicating the equality
bool operator==(memory& left, memory& right){
	return left.memEqual(right);
}



// overloading addition operator to allow adding corresponding elements of two memories together
// takes two references to memory
// returns copy of memory
memory operator+(memory &left, memory &right){
	memory m(defaultSize);
	
	for(int i = 0; i<right.sizeOf();i++){
		m.store(i,(left.getElement(i) + right.getElement(i)));
	}
	return m;

}




// over loading output operator to allow cout << memory;
// takes a reference to an output stream and a const reference to memory as parameters
// returns output stream
std::ostream &operator<<(std::ostream& out, const memory& m){
	((memory &)m).dump();
	return out;
}



// overloading subscript operator to return or modify the nth value of memory
// takes an int as a parameter
// returns int / const int
int &memory::operator[](int n){return m[n];}
const int &memory::operator[](int n) const {return m[n];}




// returns the value of the nth element of memory
// takes an int as a parameter
int memory::getElement(int n){
	return this->m[n];
}



//returns a true if two memories are equal in value
// takes a reference to memory as a parameter
bool memory::memEqual(memory& right){
	return (this->m == right.m);
}



// returns an int based on the number of memory locations allocated
// takes no parameters
int memory::sizeOf(){
	return this->size;
}



// constructor for memory class
// takes an int for the size of memory to allocate
// stores the location index inside the location of memory to start
// (m[1] == 1 ... m[99] == 99)
memory::memory(int size)
{
	
	this->m.resize(size, 0);
	//this->m.resize(size,0);
	this->size = size;
}



// default constructor for memory class
// takes no parameters
// allocates memory based on a default defined size
memory::memory(){
	this->m.resize(defaultSize,0);
	this->size = defaultSize;
}



// takes two ints as params indicating the start and end locations for dumping memory
// returns nothing
// dumps memory between the locations start and end inclusively
void memory::dump(int start, int end){	
printf("\n       ");
	for(int i = 0;i<10;i++){printf(" %5d ",i);}
	printf("\n\n");
	for(int row = 0; row < ( (start+end)/10+1); row++){
		printf("%05d: ",row);
		for(int col = 0; col < 10; col++){
		
			if( ((row*10)+col) < end){
				if( ((row*10)+col) >= start ){
					printf(" %05d ",this->m[col+(row*10)]);
				}else printf("       ");
			}
		}
		printf("\n");
	}
	
	printf("\n");
}



// calls dump on the entire range of allocated memory
// returns nothing
// takes no parameters
void memory::dump(void){
	dump(0,this->size);
}



// stores the value in memory @ loc
// takes two ints as params to indicate the value to be inserted and its location
// returns nothing
void memory::store(int loc, int val){
	this->m[loc] = val;	
}



// copies [size] number of locations from source to dest
// returns nothing
// takes three ints: source of the copy, dest of the copy and size of block to be copied
void memory::memCopy(int source, int dest, int size){
	vector<int> tmp(size);
	int tmpIndex = 0;

	//error checking
	if( (source >= this->size) || (source < 0) ){
	 	printf("memCopy ERROR: SOURCE is outside of the memory space!\n");
	 	return;	
	}

	if( (dest >= this->size) || (dest < 0) ){ 
		printf("memCopy ERROR: DEST is outside of the memory space!\n");
		return;
	}

	if( ((source + size) > this->size) ){
		printf("memCopy ERROR: SOURCE + SIZE is greater than the memory space!\n");
		return;
	}	
	
	if( ((dest + size) > this->size)){
	
		printf("memCopy ERROR: DEST + SIZE is greater than the memory space!\n");
		return;
	}

	// copy the values into tmp vector
	for(int i = source; i<source+size; i++){
		tmp[tmpIndex++] = this->m[i];
	}
	
	// copy the values to the destination	
	tmpIndex = 0;
	for(int i = dest; i<dest+size;i++){
		store(i,tmp[tmpIndex++]);
	}
}


