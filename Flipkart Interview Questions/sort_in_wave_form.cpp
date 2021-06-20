#include<iostream>
using namespace std;

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void convertToWave(int *arr, int n){
    for(int i = 1; i < n; i++){
        if((i%2) && (arr[i-1] < arr[i])){
            swap(arr[i-1], arr[i]);
            // cout<< arr[i-1] << "---"<< arr[i]<< endl;
        }
        else if(!(i%2) && (arr[i-1] > arr[i])){
            swap(arr[i-1], arr[i]);
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< "\nArray before rearranging: \n";
    for(int i = 0; i < size; i++)
        cout<< arr[i]<< " ";

    convertToWave(arr, size);

    cout<< "\nArray after rearranging: \n";
    for(int i = 0; i < size; i++)
        cout<< arr[i]<< " ";

    return 0;
}