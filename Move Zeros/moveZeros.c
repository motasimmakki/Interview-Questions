#include<stdio.h>

void swap(int *num1, int *num2) { 
    
    int temp = *num1; 
    
    *num1 = *num2; 
    *num2 = temp; 
} 

void moveZeros(int * myArray, int size){
	
	// SOLUTION 1 :
	// Time Complexity : O(nlogn)
	// Space Complexity : O(1)
	
	// int count = 0;

	// for(int i = 0; i < size-count; i++){
	// 	if(myArray[i] == 0){
	// 		for(int j = i; j+1 < (size-count); j++){
	// 			swap(&myArray[j], &myArray[j+1]);
	// 		}
	// 		count++;
	// 	}	
	// }
	
	// ******
	
	// SOLUTION 2 :
	// Time Complexity : O(n)
	// Space Complexity : O(1)

	int countZeros = 0;
	int newIndex = 0;

	for(int i = 0; i < size; i++){
		if(myArray[i] == 0)
			countZeros++;
		else
			myArray[newIndex++] = myArray[i];
	}

	while(newIndex != size)
		myArray[newIndex++] = 0;
	
	// ******

}

void printArray(int * myArray, int size){
	
	for(int i = 0; i < size; i++){
		printf("[%d]\t", myArray[i]);
	}
}

int main(){

	// int myArray[] = {0, 1, 0, 3, 12};
	// int myArray[] = {0, 1, 0, 3, 12, 0, 8};
	int myArray[] = {0, 1, 0, 3, 12, 0, 8, 17, 0};

	int size = (sizeof(myArray)/sizeof(int));

	printf("\nArray Is Before Moving Zeros Is :\n");
	printArray(myArray, size);


	moveZeros(myArray, size);

	printf("\n\nArray Is Before After Zeros Is :\n");
	printArray(myArray, size);

	return 0;
}