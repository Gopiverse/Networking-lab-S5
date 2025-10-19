#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 50

struct msg {
	long msg_type;
	char msg_text[MAX];
} message;

void main() {
	key_t key;
	int mqid;
	key = ftok("hello.c", 55);
	mqid = msgget(key, 0666);
	msgrcv(mqid, &message, sizeof(message),1, 0);
	printf("Message received is : %s", message.msg_text);
	msgctl(key, IPC_RMID, NULL);
}

/*o/p
s529@plab43:~/OS/exp4$ ./a.out
Message received is : Hey guys
*/
