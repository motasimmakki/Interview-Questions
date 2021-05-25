#include<iostream>
using namespace std;

int getSetBits(int num){
    int count = 0;
    while(num){
        num = num & (num-1);
        count++;
    }
    return count;
}

int is_bleak(int n)
{
    for(int i = 0; i < n; i++){
        if((i + getSetBits(i)) == n)
            return 0;
    }
    
    return 1;
}

int main(){

	cout<< is_bleak(4)<< endl;// 1

	cout<< is_bleak(3)<< endl;// 0
	
	return 0;
}