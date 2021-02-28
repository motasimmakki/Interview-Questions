#include<iostream>
using namespace std;

int getLongestSubArraySum(int arr[], int size){
	int currentSum = arr[0];
	int bestSum = arr[0];

	for(int i = 1; i < size; i++){
		if(currentSum >= 0)
			currentSum += arr[i];
		else
			currentSum = arr[i];

		if(currentSum > bestSum)
			bestSum = currentSum;
	}

	return bestSum;
}

int main(){

	// int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	// int arr[] = {4, 3, -2, 6, -14, 7, -1, 4, 5, 7, -10, 2, 9, -10, -5, -9, 6, 1};
	int arr[] = {4, 3, -2, 6, 7, -10, -10, 4, 5, 9, -3, 4, 7, -28, 2, 9, 3, 2, 11};

	printf("\nArray Is : \n");
	for(int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
		printf("[%d]\t", arr[i]);

	printf("\n\nLongest Sub-Array In An Array Is : %d\n", getLongestSubArraySum(arr, (sizeof(arr)/sizeof(int))));

	return 0;
}