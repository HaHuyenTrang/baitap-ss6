#include<stdio.h>
#include<stdlib.h>
//#define MAX 5


typedef struct{
	int data;
	struct Node *next;
}Node;

//	con tro top -> null
Node *top = NULL;

//	kiem tra ngan xep rong
int isEmpty(){
	if(top == NULL){
		return 1;
	}
	return 0;
}

//	them phan tu
void push( int value){
//	tao node moi
	Node *newNode =(Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = top;
}

//	xoa phan tu
void pop(){
	if(inEmpty()==1){
		printf("ngan xep rong");
		return;
	}
	Node *temp = top;
	top = top->next;
	free(temp);
	printf("lay khoi ngan xep thanh cong");
}

//	lay
int peek(){
	if(isEmpty()==1){
		printf("ngan xep rong");
		return -2;
	}
	return top->data;
}
int main(){
	
}

