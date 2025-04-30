#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#define MAX 100
struct msg_buffer {
	long msg_type;
	char msg_text[MAX];
} message;

int main() {
	key_t key;
	int msgid;


	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1) 
	{
		printf("Enter your message: \n");
		fgets(message.msg_text, MAX, stdin);
		message.msg_type = 1;
		msgsnd(msgid, &message, sizeof(message.msg_text), 0);
		if(strncmp(message.msg_text, "exit", 4) == 0){
			break;
		}
	}

	return 0;


}

