#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int count;
void merge(long long int arr[], long long int low, long long int mid, long long int high){ 
    long long int i = low,j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
            count = count + (mid + 1 - i); //N-i=count
            j++;
        }
        else
            i++;
    }
    sort(arr + low, arr + high + 1);
    
    return;
}

void mergesort(long long int arr[], long long int low, long long int high){
    if(low == high)
        return;
        
    long long int mid = (high + low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

long long int inversionCount(long long arr[], long long N){
// Your Code Here
    if(N == 0){
        return 0;
    }
    count = 0;
    mergesort(arr, 0, N-1);
    
    return count;
}

int main(){

	int arr[42] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
	
	count<< "Inversion in an Array is : "<< inversionCount(arr, 42);

	return 0;
}

// 42
// 468 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323