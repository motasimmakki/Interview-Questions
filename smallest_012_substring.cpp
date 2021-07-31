// Paytm Interview Question.
#include<iostream>
using namespace std;

int smallestSubstring(string S) {
    if(S.length() < 3)
        return -1;
    int ptr0 = -1, ptr1 = -1, ptr2 = -1;
    int result = INT_MAX;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == '0')
            ptr0 = i;
        else if(S[i] == '1')
            ptr1 = i;
        else if(S[i] == '2')
            ptr2 = i;
        if(ptr0 != -1 and ptr1 != -1 and ptr2 != -1)
            result = min(result, i-min(ptr0, min(ptr1, ptr2))+1);
    }
    if(result == INT_MAX)
        return -1;
    return result;
}

int main(){
    // string str = "01212";
    string str = "1210";
    // string str = "12121";

    cout<< "\nLength of Smallest Substring containing 0, 1, & 2 Is: "<< smallestSubstring(str)<< endl;

    return 0;
}

// Sample Input 01:
// 01212
// Sample Output:
// 3

// Sample Input 02:
// 1210
// Sample Output:
// 3

// Sample Input 03:
// 12121
// Sample Output:
// -1