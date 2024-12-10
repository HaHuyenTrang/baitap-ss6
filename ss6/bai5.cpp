#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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

// Ham lay ky tu ra khoi ngan xep
char pop(Stack* stack) {
    if (!isEmpty(stack)) {  // Kiem tra neu ngan xep khong rong
        return stack->array[(stack->top)--];  // Tra ve ky tu tren cung va giam chi so top
    }
    return '\0';  // Tra ve ky tu null neu ngan xep rong
}

//	duyet, in stack 
void printStack(Stack* stack){
	for(int i = stack->top; i>=0; i--){
		printf("%d\n", stack->array[i]);
	}
}

int main(){
  Stack stack;  // Khoi tao ngan xep
    inital(&stack);  // Goi ham khoi tao ngan xep

    char input[MAX], reversed[MAX];  // Mang luu chuoi nhap vao va chuoi dao nguoc
    printf("Nhap chuoi ky tu: ");
    fgets(input, MAX, stdin);  // Nhap chuoi tu ban phim

    // Loai bo ky tu xuong dong neu co
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';  // Thay ky tu xuong dong bang ky tu null
        len--;
    }

    // Them tung ky tu vao ngan xep
    for (int i = 0; i < len; i++) {
        push(&stack, input[i]);
    }

    // Lay cac ky tu ra khoi ngan xep de tao chuoi dao nguoc
    for (int i = 0; i < len; i++) {
        reversed[i] = pop(&stack);  // Lay ky tu tu ngan xep va luu vao mang dao nguoc
    }
    reversed[len] = '\0';  // Them ky tu null de ket thuc chuoi dao nguoc

    // In chuoi dao nguoc
    printf("Chuoi dao nguoc: %s\n", reversed);

    return 0;
} 
