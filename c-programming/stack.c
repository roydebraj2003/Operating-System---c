#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int *stack;

int top = -1;
void push(int value) {
	if(top == MAX -1) {
		printf("Stack overflow\n");
	}

	*(stack ++) = value;
	printf("Pushed to stack: %d\n", value);
}

int pop() {
	if(top == -1) {
		printf("Stack is empty\n");
	}

	return *(stack --);
}


void display() {

	if(top == -1) {
		printf("Stack is empty");
	}

	for(int i = 0; i< MAX; i++){
		printf("Elmt:%d, value: %d, address: %p\n", i, stack[i], &stack[i]);
	}
}

int main() {
	stack = (void *)malloc(MAX * sizeof(int));
	push(1);
	push(2);
	push(3);
	display();
	int a = pop();
	printf("%d\n", a);
	display();
	return 0;

}

