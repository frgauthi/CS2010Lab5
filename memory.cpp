// This file contains the function source code for the memory simulation program using vectors
// Frankie Gauthier
// CS2010 Lab 4

#include "memory.h"



void memory::copy(memory& mem){
	vector<int> tmp = mem.m;
	tmp.size = mem.size;
}

//over loading output operator to allow cout << memory;
std::ostream &operator<<(std::ostream& out, const memory& m){
	((memory &)m).dump();
	return out;
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
	for(int i =0; i<size; i++){
		this->m.push_back(i);
	}

	//this->m.resize(size,0);
	this->size = size;
}



// default constructor for memory class
// takes no parameters
// allocates memory based on a default defined size
memory::memory(){
	this->m.resize(defaultSize, 0);
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


