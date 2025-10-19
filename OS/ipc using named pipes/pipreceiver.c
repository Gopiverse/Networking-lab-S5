#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
	int res, n;
	char buffer[100];
	res = open("FIFO", O_RDONLY);
	read(res, buffer, 100);
	printf("Receiver process with pid %d receives the message %s", getpid(), buffer);
	close(res);
} 
