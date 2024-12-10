#include<stdio.h>
#include<stdlib.h>
#define MAX 5

//	cau truc ngan xep
	typedef struct{
		int array[MAX];
		int top;
	}Stack;
	
//	khoi tao 1 stack rong
void inital(Stack* stack){
	stack->top = -1;
}

//	kiem tra stack rong
int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

//	kiem tra ngan xep day
int isFull(Stack* stack){
	if(stack->top >= MAX -1){
		return 1;
	}
	return 0;
}

//	them vao stack 
void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("ngan xep da day!");
		return;
	}
	stack->array[++(stack->top)] = value;
}

//	xoa stack
void popStack(Stack* stack){
	if(isEmpty(stack)){
		printf("ngan xep rong");
		return;
	}
	stack->array[--(stack->top)];
} 

//	lay phan tu dau tien
void topStack(Stack* stack){
	if(isEmpty(stack)){
		printf("ngan xep rong");
		return;
	}
	printf("phan tu dau tien: %d", stack->array[(stack->top)]);
} 

//	duyet, in stack 
void printStack(Stack* stack){
	for(int i = stack->top; i>=0; i--){
		printf("%d\n", stack->array[i]);
	}
}
int main(){
	int value;
	Stack stack;
	inital(&stack);
	do{
		printf("\n==================MENU==================\n");
		printf("1. them 1 phan tu vao ngan xep\n");
		printf("2. in ra ngan xep\n");
		printf("3. xoa phan tu\n");
		printf("4. lay phan tu dau\n");
		printf("0. thoat!\n");
		printf("moi ban chon: ");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 0:
				exit;
			case 1:
				printf("nhap gia tri can them: ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				printStack(&stack);
				break;
			case 3:
				popStack(&stack);
				break;
			case 4:
				topStack(&stack);
//				printf("phan tu dau tien: ");
				break;
			default:
				printf("moi chon lai-- ");	
		}
	}while(1==1);
	
}
