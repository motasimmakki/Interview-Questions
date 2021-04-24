#include <iostream>
using namespace std;

bool isReachableToEnd(int arr[], int len){

	int reachable = 0;

	for(int i = 0; i < len; i++){
		if(i > reachable)
			return false;
		if((i + arr[i]) > reachable){
			reachable = i + arr[i];
			// cout<< reachable<< "\t"<< i<< "\n";
			if(reachable == len-1)
				return true;
		}
	}
	return false;
}

int main(){

	// int arr[] = {1, 1, 2, 5, 2, 1, 0, 0, 1, 3}; //True
	int arr[] = {1, 1, 2, 3, 2, 1, 0, 0, 1, 3}; //False
	int len  = sizeof(arr)/sizeof(int);

	cout<< "\nArray Is : "<< endl;
	for(int i = 0; i < len; i++)
		cout<< arr[i] << "  ";

	if(isReachableToEnd(arr, len))
		cout<< "\n\nYes, we are able to reach at the end!" <<endl;
	else
		cout<< "\n\nNo, we won't be able to reach at the end!" <<endl;

	return 0;
}