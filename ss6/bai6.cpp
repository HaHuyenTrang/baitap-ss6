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

// Ham them phan tu vao ngan xep
void push(Stack* stack, char value) {
    if (stack->top < MAX - 1) {
        stack->array[++(stack->top)] = value;
    }
}


// Ham lay phan tu ra khoi ngan xep
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[(stack->top)--];
    }
    return '\0';  // Tra ve ky tu null neu ngan xep rong
}

////	them vao stack 
//void push(Stack* stack, int value){
//	if(isFull(stack) == 1){
//		printf("ngan xep da day!");
//		return;
//	}
//	stack->array[++(stack->top)] = value;
//}

////	lay phan tu tren cung
//void peek(Stack* stack){
//	if(isEmpty(stack) == 1){
//		printf("ngan xep rong");
//		return;
//	}
//	printf("phan tu dau tien: %d", stack->array[(stack->top)]);
//} 
//


// Ham kiem tra bieu thuc co hop le hay khong
int isValidExpression(const char* expression) {
    Stack stack;
    inital(&stack);  // Khoi tao ngan xep

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // Xem xet cac dau ngoac mo
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // Xem xet cac dau ngoac dong
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0;  // Tra ve 0 neu ngan xep rong, bieu thuc khong hop le
            }

            char top = pop(&stack);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return 0;  // Tra ve 0 neu dau ngoac dong khong phu hop
            }
        }
    }

    // Kiem tra neu ngan xep con phan tu, bieu thuc khong hop le
    return isEmpty(&stack);
}


//	duyet, in stack 
void printStack(Stack* stack){
	for(int i = stack->top; i>=0; i--){
		printf("%d\n", stack->array[i]);
	}
}

int main(){
   char expression[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expression, MAX, stdin);
    
    if (isValidExpression(expression)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }


    return 0;
} 
