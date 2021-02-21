#include<iostream>
using namespace std;

// Test Cases : 
// 2 4 5 3 4 -7 14
// 1 2 6 4 0 -1
int getEquilibrium(int *arr, int size){

	if (size == 1)
		return arr[0];

	int sum[size];
	sum[0] = arr[0];

	for(int i = 1; i < size; i++)
		sum[i] = (sum[i-1] + arr[i]);

	// for(int i = 0; i < size; i++)
	// 	cout<< sum[i]<< "   ";

	int total = sum[size-1];

	for (int i = 1; i < size; i++){
		int leftSum = sum[i-1];
		int rightSum = total - sum[i];

		if (leftSum == rightSum){
			cout<< "\nEquilibrium Point is : "<< i<< endl;
			return arr[i];
		}
	}

	return 0;
}

int main(){
	int size;

	if (size == 2){
		cout<< "\nEquilibrium Point is NOT pssible."<< endl;
		return 0;
	}

	cout<< "\nEnter the Size of an Array : ";
	cin>> size;
	
	int arr[size] = {0};

	cout<< "\nEnter "<< size<< " elements in an Array : "<< endl;

	for(int i = 0; i < size; i++)
		cin>> arr[i];
	
	cout<< "Equilibrium number in an Array is : "<< getEquilibrium(arr, size)<< endl;
	
	return 0;
}