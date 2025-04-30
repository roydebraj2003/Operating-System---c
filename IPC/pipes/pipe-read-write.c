#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main() {
	int fd[2];

	char buffer[100];

	if(pipe(fd) == -1) {
		perror("Pipe failed");
		return 1;
	}
	pid_t pid = fork();


	if(pid < 0) {
		printf("Fork failed");
		return 1;
	}


	if(pid == 0) {
		//child process
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		 printf("Child received: %s\n", buffer);
        	close(fd[0]);
	}else {
		//parent process
		close(fd[0]);
		char message[] = "Hello pipes!!";
		write(fd[1], message, strlen(message)+ 1);
		close(fd[1]);
	}

	return 0;
}
