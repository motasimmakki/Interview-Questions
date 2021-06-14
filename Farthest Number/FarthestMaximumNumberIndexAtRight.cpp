#include<iostream>
#include<vector>
using namespace std;

int getIndexViaBS(int suffixArr[], int size, int data, int startIndex, int endIndex){
    int possibleIndex = -1;
    while(startIndex <= endIndex){
        int mid = (startIndex+endIndex)/2;
        if(data > suffixArr[mid]){
            startIndex = mid+1;
            possibleIndex = mid;
        }
        else
            endIndex = mid-1;
    }
    
    return possibleIndex;
}

vector<int> getMaxAtRight(int arr[], int size){
    vector<int> result;
    int suffixArr[size];

    suffixArr[size-1] = arr[size-1];
    for(int i = size-2; i >= 0; i--)
        suffixArr[i] = min(arr[i], suffixArr[i+1]);

    cout<< "\nSuffix Array: "<< endl;
    for(int i = 0; i < size; i++)
        cout<< suffixArr[i]<< " ";

    for(int i = 0; i < size; i++){
        result.push_back(getIndexViaBS(suffixArr, size, arr[i], i+1, size-1));
    }

    return result;
}


int main(){
    // int arr[] = {10, 4, 2, 20, 40, 12, 30};
    int arr[] = {3, 1, 5, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> result = getMaxAtRight(arr, size);
    
    cout<< "\nResult: "<< endl;
    for(auto x: result)
        cout<< x<< " ";

    return 0;
}
