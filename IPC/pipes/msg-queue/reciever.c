#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Listening for messages...\n");

    // Continuous receive loop (non-blocking)
    while (1) {
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) != -1) {
            printf("Received: %s", message.msg_text);

            if (strncmp(message.msg_text, "exit", 4) == 0) {
                break;  // Exit the loop if "exit" message is received
            }
        }
        usleep(500000);  // Sleep for 500ms to prevent CPU overuse
    }

    // Cleanup
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

