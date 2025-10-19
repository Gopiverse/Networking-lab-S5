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
	mqid = msgget(key, 0666|IPC_CREAT);
	message.msg_type = 1;
	printf("Enter message : ");
	fgets(message.msg_text, MAX, stdin);
	msgsnd(mqid, &message, sizeof(message), 0);
	printf("Message send is : %s", message.msg_text);
}

/*o/p
s529@plab43:~/OS/exp4$ ./a.out
Enter message : Hey guys 
Message send is : Hey guys
*/
