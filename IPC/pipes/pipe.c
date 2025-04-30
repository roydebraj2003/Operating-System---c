
#include<stdio.h>
#include<unistd.h>


int main() {
	int fd[2];

	if(pipe(fd) == -1) {
		 perror("pipe failed");
        	return 1;
	}


	printf("Pipe created successfully.\n");
	printf("Read end: %d, Write end: %d", fd[0], fd[1]);
	return 0;

}
