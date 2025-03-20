#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void * test() {
	printf("Hello threads...\n");
}
int main() {
	int n;
	pthread_t ar[2];
	n = pthread_create(&ar[0], NULL, &test, NULL);
	if(n == 0) {
		printf("Thread created successfully ...\n");
		sleep(1);
	}
	return 0;
}
