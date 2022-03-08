/**
 * Problem Statement:
 * 
 * Given the small phone with the keypad in which inorder to write a specific 
 * message user have to press the keys several number of time, as shown in the
 * hashmap `keys` in the solution below.
 * 
 * keys can be pressed several number of times, it will operate circularly,
 * means if the user continue pressing the key even after position of the last 
 * letter than it will get the very first letter and so on.
 * 
 * In order to the start next letter between words the '_' character if given.
 * 
 * You have been given the string the numeric for and you have to decode the 
 * string and return the original text generated those keys press.
 * 
 * /

#include <bits/stdc++.h>
using namespace std;


/*
 * Complete the 'keypadDecode' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. STRING keypad
 */

string keypadDecode(string keypad) {
    string decodedStr = "";
    unordered_map<char, vector<char>> keys {
        {'1', {',', '@'}},
        {'2', {'A', 'B', 'C', 'a', 'b', 'c', '2'}},
        {'3', {'D', 'E', 'F', 'd', 'e', 'f', '3'}},
        {'4', {'G', 'H', 'I', 'g', 'h', 'i', '4'}},
        {'5', {'J', 'K', 'L', 'j', 'k', 'l', '5'}},
        {'6', {'M', 'N', 'O', 'm', 'n', 'o', '6'}},
        {'7', {'P', 'Q', 'R', 'S', 'p', 'q', 'r', 's',  '7'}},
        {'8', {'T', 'U', 'V', 't', 'u', 'v', '8'}},
        {'9', {'W', 'X', 'Y', 'Z', 'w', 'x', 'y', 'z', '9'}},
        {'0', {' ', '0'}}
    };

    vector<pair<char, int>> keyFreq;
    int freq = 1;
    for(int i = 1; i < keypad.size(); i++) {
        if(keypad[i] != keypad[i-1]) {
            keyFreq.push_back({keypad[i-1], freq});
            freq = 1;
            if(keypad[i] == '_')
                i += 1;
        } else {
            freq += 1;
        }
    }
    keyFreq.push_back({keypad[keypad.size()-1], freq});
    // for(auto &x: keyFreq)
    //     cout<< x.first<< ": "<< x.second<< endl;
        
    for(auto &x: keyFreq) {
        int idx = (x.second-1) % keys[x.first].size();
        decodedStr += keys[x.first][idx];
    }
    
    return decodedStr;
}
int main()
{
    int testCase;
    cin>> testCase;

    string keypadStr = "";
    while(testCase--) {
        cin>> keypadStr;
        cout<< keypadDecode(keypadStr)<< endl;
    }

    return 0;
}
