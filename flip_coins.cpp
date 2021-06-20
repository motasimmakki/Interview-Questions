#include<iostream>
using namespace std;

string flipCoins(int N, string s){
    int countSilver = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == '0')
            countSilver++;
    }
    
    return (countSilver%2)? "No": "Yes";
}

int main(){
    string coins = "11001100";
    // string coins = "10010100";
    int N = 8;

    cout<< flipCoins(N, coins);

    return 0;
}