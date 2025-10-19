#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main() {
	int res;
	char msg[] = "Good day\n";
	res = open("FIFO", O_WRONLY);
	write(res, msg, sizeof(msg));
	printf("Sender process with pid %d sent the message\n",getpid());
	close(res);
}