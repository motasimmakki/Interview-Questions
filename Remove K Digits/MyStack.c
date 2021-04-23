#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int capacity;
	int top;
	char *array;
};

typedef struct Stack Stack;

Stack * createStack(int capacity){
	Stack *S = (Stack *)malloc(sizeof(struct Stack));
	S->capacity = capacity;
	S->top = -1;
	S->array = malloc(sizeof(char)*capacity);
	return S;
}

void doubleStack(Stack *S){
		S->capacity *= 2;
		S->array = realloc(S->array, S->capacity);
}

int isFull(Stack *S){
	if(S->top == (S->capacity - 1))
		return 1;
	else
		return 0;
}

int isEmpty(Stack *S){
	if(S->top == -1)
		return 1;
	else
		return 0;
}

void push(Stack *S, int element){
	if(isFull(S)){
	//	printf("Stack is overflow\n");
		doubleStack(S);
	}
	S->top++;
	S->array[S->top] = element;
}

int pop(Stack *S){
	if(isEmpty(S)){
		printf("Stack is underflow\n");
		return -1;
	}
	return S->array[S->top--];
}

int peek(Stack *S){
	if(isEmpty(S)){
		printf("Stack is underflow\n");
		return -1;
	}
	return S->array[S->top];
}