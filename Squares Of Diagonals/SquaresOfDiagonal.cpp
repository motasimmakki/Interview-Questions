#include<iostream>
using namespace std;

#define N 3

int main(){

	int matrix[N][N] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int leftDiagonal[N];
	int rightDiagonal[N];

	int left = 0, right = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j)
				leftDiagonal[left++] = (matrix[i][j]*matrix[i][j]);
			
			if(i+j == N-1)
				rightDiagonal[right++] = (matrix[i][j]*matrix[i][j]);
			
		}	
	}

	cout<< "\nSquares of Sirst Left Diagonal are : "<< endl;
	for(int i = 0; i < N; i++)
		cout<< leftDiagonal[i]<< "  ";
	
	cout<< "\n\nSquares of Sirst Right Diagonal are : "<< endl;
	for(int i = 0; i < N; i++)
		cout<< rightDiagonal[i]<< "  ";
	
	return 0;
}