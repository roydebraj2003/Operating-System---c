#include<stdio.h>
#include<string.h>
#include<sys/shm.h>

#define KEY 12345
#define SIZE 50
int main () 
{
	char buffer[SIZE];
	char* ptr;
	int id = shmget(KEY, SIZE, IPC_CREAT | 0666);
	if(id != -1) {
		ptr = (char *)shmat(id, NULL, 0);
		strcpy(buffer, ptr);
		printf("%s", buffer);
		shmdt(ptr);
	}
	return 0;
}
