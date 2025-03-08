#include<stdio.h>
#include<stdlib.h>
int main() {
	int *arr = (int *)malloc(5 * sizeof(int));
	int *ptr = arr;

	for(int i = 0; i< 5; i++) {
		*(arr + i) = i + 1;
		printf("%d\n", *ptr);
		*ptr++;
	}
	free(arr);
	return 0;
}
