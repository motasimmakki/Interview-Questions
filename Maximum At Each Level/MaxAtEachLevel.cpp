#include<iostream>
#include<vector>
#include "./BT/BinaryTree.cpp"
using namespace std;

// Time Complexity: O(N)
// Auxiliary Space: O(H)
void solve(BT *root, vector<int> &result, int level){
    if(root == NULL)
        return;
    if(result.size() == level)
        result.push_back(root->data);
    else
        result[level] = max(result[level], root->data);

    solve(root->left, result, level+1);
    solve(root->right, result, level+1);
}

vector<int> getMaxAtEachLevel(BT *root){    
    vector<int> result;
    int level = 0;

    solve(root, result, level);

    return result;
}

int main(){
    // Test Case: 01
    // BT *root=createNewNode(1);
    // root->left=createNewNode(2);
    // root->right=createNewNode(3);
    // 1 3

    // Test Case: 02
    // BT *root=createNewNode(1);
    // root->left=createNewNode(2);
    // root->right=createNewNode(3);
    // root->right->left=createNewNode(4);
    // root->right->right=createNewNode(6);
    // root->right->right->left=createNewNode(5);
    // root->right->right->left->right=createNewNode(7); 
    // 1 3 6 5 7

    // Test Case: 03
    BT *root=createNewNode(4);
    root->left=createNewNode(9);
    root->right=createNewNode(2);
    root->left->left=createNewNode(3);
    root->left->right=createNewNode(5);
    root->right->right=createNewNode(7);
    // 4 9 7

    cout<< "Inorder: "<< endl;
    inorder(root);

    vector<int> result = getMaxAtEachLevel(root);

    cout<< "\n\nMaximum At Each Node Is: "<< endl;
    for(auto x: result)
        cout<< "["<< x<< "]\t";

    return 0;
}