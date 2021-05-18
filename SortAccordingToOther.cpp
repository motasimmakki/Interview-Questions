#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    int getFirstOccurrence(int data, vector<int> arr, int len){
    	int low = 0, upper = len-1;
    
    	while(low <= upper){
    		int mid = (low + upper)/2;
    
    		if(((mid == 0) || (arr[mid-1] < data)) && arr[mid] == data)
    			return mid;
    		else if(arr[mid] < data)
    			low = mid + 1;
    		else
    			upper = mid-1;
    	}
    	
    	return -1;
    }
    
    int getLastOccurrence(int data, vector<int> arr, int len){
    	int low = 0, upper = len-1;
    
    	while(low <= upper){
    		int mid = (low + upper)/2;
    
    		if(((mid == len-1) || (arr[mid+1] > data)) && arr[mid] == data)
    			return mid;
    		else if(arr[mid] <= data)
    			low = mid+1;
    		else
    			upper = mid-1;
    	}
    
    	return -1;
    }
    
    int getFrequency(int data, vector<int> arr, int len){
    
    	int low = getFirstOccurrence(data, arr, len);
    	int high = getLastOccurrence(data, arr, len);

        if((low == -1) || (high == -1))
            return 0;
        return (high - low) + 1;
    }
        
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {   
        sort(A1.begin(), A1.end());
        vector<int> sortedArr;

        for(int i = 0; i < M; i++){
            int freq = getFrequency(A2[i], A1, A1.size());
            
            for(int j = 0; j < freq; j++)
                sortedArr.push_back(A2[i]);
                
            A1.erase(remove(A1.begin(), A1.end(), A2[i]), A1.end());
            
            // for(int i = 0; i < A1.size(); i++)
            //     cout <<  A1[i]<< " "; 
            // cout<< "---"<<i<< endl;
        }
        
        for(int i = 0; i < A1.size(); i++)
            sortedArr.push_back(A1[i]);
        
        return sortedArr;
    
    } 
};  

int main(){
    Solution solution;

    // int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}, n = 11;
    // int arr2[] = {2, 1, 8, 3}, m = 4;

    int arr1[] = {14, 15, 111, 265, 125, 326, 594, 485, 592, 454, 787, 787, 121, 454, 787, 56, 852, 741, 963, 25, 852, 789, 456, 123, 111, 456, 852, 963, 852, 741, 852, 63, 852, 845, 865, 878, 456, 787, 45, 12, 852, 963, 85, 78, 111, 852, 741, 111}, n = 48;
    int arr2[] = {111, 963, 852, 85, 25}, m     = 5;

    vector<int> A1(arr1, (arr1 + n));
    vector<int> A2(arr2, (arr2 + m));

    A1 = solution.sortA1ByA2(A1, n, A2, m);

    for(int i = 0; i < A1.size(); i++)
        cout <<  A1[i]<< " ";
}