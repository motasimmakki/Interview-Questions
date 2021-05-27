#include<iostream>
using namespace std;

long long sumBitDifferences(int A[], int N) {
    long long int BitDiffSum = 0;
    for(int i = 0; i < 32; i++){
        long long int setCount = 0, unsetCount = 0;
        for(int j = 0; j < N; j++){
            if(A[j]%2)
                setCount++;
            else
                unsetCount++;
            A[j] >>= 1;
        }
        BitDiffSum += (setCount*unsetCount*2);
    }
    
    return BitDiffSum;
}

int main(){

	// int A[] = {1, 2};
	int A[] = {1, 3, 5};

	int N = sizeof(A)/sizeof(A[0]);

	cout<< sumBitDifferences(A, N)<< endl;

	return 0;
}