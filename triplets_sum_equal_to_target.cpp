#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>> n;
	int arr[n] = {0};
	for(int i = 0; i < n; i++)
		cin>> arr[i];
	int target;
	cin>> target;

	sort(arr, arr + n);

	for(int i = 0; i < n; i++){
		int start = i+1, end = n-1;
		while(start < end){
			int sum = arr[i] + arr[start] + arr[end];
			if(sum == target){
				cout<< arr[i]<< ", "<< arr[start]<< " and "<< arr[end]<< endl;
				start += 1; end -= 1;
			}
			else if(sum > target)
				end -= 1;
			else
				start += 1;
		}
	}

	return 0;
}

// Sample Input:
// 9
// 5 7 9 1 2 4 6 8 3
// 10
// Sample Output:
// 1, 2 and 7
// 1, 3 and 6
// 1, 4 and 5
// 2, 3 and 5