#include<iostream>
#include <cmath>
using namespace std;

int getOperationToReduce(string s){
	int opr = 0, num = 0;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == '1')
			num += pow(2, (s.length()-1)-i);
	}
	// cout<< "\nNum : "<< num<< endl;

	if(num > 1){	
		while(num != 1){
			if(num%2)
				num += 1;
			else
				num /= 2;
			opr += 1;
		}
	}

	return opr;
}

int main(){

	// cout<< "\nTotal Operation Required :  "<< getOperationToReduce("1101")<< endl; // 6
	cout<< "\nTotal Operation Required :  "<< getOperationToReduce("1011")<< endl; // 6
	// cout<< "\nTotal Operation Required :  "<< getOperationToReduce("0001")<< endl; // 0
	// cout<< "\nTotal Operation Required :  "<< getOperationToReduce("0010")<< endl; // 1

	return 0;
}