#include<stdio.h>


int main() {
	int a = 10;
	int *ptr = &a;
	printf("The number a: %d\n", a);
	printf("The address a: %p\n", (void *) &ptr);
	printf("Dereferencing a ptr: %d\n", *ptr);
	return 0;

}
