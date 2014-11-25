// this is the main function for the memorySimulation program
// Frankie Gauthier
// CS2010 Lab 4
#include "memory.h"

int main(){

        memory m(defaultSize);
        m.dump();

        for(int i =0;i<m.sizeOf();i+=2)m.store(i,0);
        printf("making the even entries 0..\n");
        m.dump();
        m.memCopy(20,40,15);
        printf("copying 15 units of memory from location 20 to 40..\n");
        printf("dumping location 40 to 55..\n");
        m.dump(40,55);
        printf("dumping entire array..\n");
        m.dump();
	cout << m;	
        
return 0;
}

