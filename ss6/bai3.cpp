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

//	duyet, in stack 
void printStack(Stack* stack){
	for(int i = stack->top; i>=0; i--){
		printf("%d\n", stack->array[i]);
	}
}

int main(){
	Stack stack;
    inital(&stack);
    
    int n, value;
    printf("Nhap do luong phan tu (toi da %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("so luong > so luong toi da!\n");
        return 1;
    }
    if(n==0){
    	printf("ngan xep rong");
		return 1; 
	} 

    for (int i = 0; i < n; i++) {
        printf("Nap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    printStack(&stack);
    return 0;
} 
