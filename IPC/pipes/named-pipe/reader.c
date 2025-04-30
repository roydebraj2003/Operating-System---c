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
	char buffer[100];

	fd = open(fifo, O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	printf("The message is: %s\n", buffer);
	close(fd);
	return 0;

}
