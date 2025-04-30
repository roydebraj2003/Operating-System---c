#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	char *fifo = "/tmp/myfifo";
	mkfifo(fifo, 0666);

	fd = open(fifo, O_WRONLY);

	char message[] = "Hello named pipes!!";

	write(fd, message, sizeof(message));
	printf("Message sent to reader.\n");

	close(fd);
	return 0;

}
