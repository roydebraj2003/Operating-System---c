#include<stdio.h>
#include<pthread.h>

#define MAX 5

void *test0() {
	printf("Thread 0: Start ....\n");
}
void *test1() {
	printf("Thread 1: Start ....\n");
}
void *test2() {
	printf("Thread 1: Start ....\n");
}
void *test3() {
	printf("Thread 1: Start ....\n");
}
void *test4() {
	printf("Thread 1: Start ....\n");
}

int main() {
	int i;
	pthread_t ar[MAX];
	void * (*test_functions[MAX])() = {test0, test1, test2, test3, test4};
	for(i = 0; i< MAX; i++) {
		pthread_create(&ar[i], NULL, test_functions[i], NULL);
	}

	for(int i = 0; i< MAX; i++) {
		pthread_join(ar[i], NULL);
	}

	return 0;

}
