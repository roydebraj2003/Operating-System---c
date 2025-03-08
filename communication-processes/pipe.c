#include<stdio.h>
#include<unistd.h>
int main() {
	int fd[2];
	if(pipe(fd) == -1){
		printf("Error: couldnt open pipe \n");
		return 1;
	}

	int pid = fork();
	if(pid == 0){
		close(fd[0]);
		int x;
		printf("Enter a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}else {
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process: %d", y);
	}

	return 0;
}
