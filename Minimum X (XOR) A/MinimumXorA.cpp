#include<iostream>
#include<cmath>
using namespace std;

int getSetBits(int num){
    int count = 0;
    while(num){
        num = num & (num-1);
        count++;
    }
    return count;
}

int getTotalBits(int num){
    int count = 0;
    while(num){
        num >>= 1;
        count++;
    }
    return count;
}

int minVal(int a, int b) {
    int num = 0, count = getSetBits(b), A = a;

    while(count > 0){
        if(a > 0){
        	// cout<< "run"<< endl;
            int mask = 1;
            mask<<= (getTotalBits(a)-1);
            // cout<< mask<< endl;
            num |= mask;
            
            int unsetRight = (pow(2, (getTotalBits(a)-1))-1);
            a &= unsetRight;        
        }
        else{
        	int rightmostUnset = ~A & (A+1);
            // num += pow(2, getTotalBits(rightmostUnset-1));
            num ^= (1 << (getTotalBits(rightmostUnset)-1));
            A ^= (1 << (getTotalBits(rightmostUnset)-1));
        	// cout<< (rightmostUnset-1)<< "---"<< num<< "---"<<A << endl;
        }
        count--;
    }
    
    return num;
}

int main(){

	cout<< minVal(9, 7)<< endl; // 11
	cout<< minVal(640, 974)<< endl; // 671
	
	return 0;
}