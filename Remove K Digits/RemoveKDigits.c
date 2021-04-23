#include <stdio.h>
#include<string.h>
#include "MyStack.c"

void printStack(Stack *S){
	while(!isEmpty(S)){
		char num = pop(S);
		printStack(S);
		printf("%c", num);
	}
}

int main(){

	Stack *S = createStack(10);

	char num[20];
	printf("Enter A Number : ");
	scanf("%s", &num);

	int k;
	printf("How many digits you wanna remove : ");
	scanf("%d", &k);
	
	printf("\nMinimum Number Formed After Removing %d Digits Is : ", k);

	if(k > 0){
		for(int i = 0; i < strlen(num); i++){
			if(i == 0 && num[i] != '0')
				push(S, num[i]);
			else{
				while((!isEmpty(S)) && (num[i] < peek(S)) && (k > 0)){
					pop(S);
					k--;
				}
				if(num[i]!='0')
					push(S, num[i]);
				else if(!isEmpty(S))
					push(S, num[i]);
			}
		}
	}
	printStack(S);

	return 0;
}

// Test Case: 01
// 14301620 4
// 120

// Test Case: 02
// 1230987 2
// 10987

// Test Case: 03
// 1230987 3
// 987

// Test Case: 04
// 372181 2
// 2181