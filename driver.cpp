// this is the main function for the memorySimulation program that demonstrates overloaded operators
// Frankie Gauthier
// CS2010 Lab 5
#include "memory.h"

int main(){

	printf("memory A(100);\nmemory B;\n");
        memory A(100);
    	memory B;
	printf("\nPrinting Memory B\n");
	cout << B;
	printf("\n Fill first half of B with 5's \n");
	for(int i =0;i<50;i++){
		B[i] = 5;
	}
	printf("\nA = B\n");
	A = B;
	printf("\nA==B?: %d\n", A==B);
	
	printf("\nA[0] = 999\n");
	A[0] = 999;
	printf("\nA[0]: %d\n",A[0]);

	printf("A==B?: %d\n", A==B);
	
	printf("\nprinting A: \n");
	cout << A;
	printf("\nprinting B: \n");
	cout << B;
	printf("\nMemory C = A\n");
	memory C = A;
	printf("\nprinting C: \n");
	cout << C;
	printf("\nC = C + A \n");
	C = C + A;
	printf("\nprinting C: \n");
	cout << C;
		
        
return 0;
}

