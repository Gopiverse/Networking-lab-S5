#include<stdio.h>
#include<unistd.h>
void main() {
	int fa[2], n;										//array converted to pipe later
	char buffer[100];									//buffer to store msg
	char msg[] = "Hii, This is my message";				//msg
	pid_t pid;											//process id of datatype pid_t
	pipe(fa);											//converting fa to a pipe
	pid = fork();										//creating childprocess
	if(pid != 0) {										//whenprocess created its pid=0 ,later its assigned a pid
		printf("Parent process with pid %d\n", getpid());
		write(fa[1], msg, sizeof(msg)); 				//writing msg size through stream 1
	} else {
		printf("Child process with pid %d\n", getpid());
		n = read(fa[0], buffer, 100);					//reading from buffer through stream 0
		write(1, buffer, n);	
	}
}

//here we r actually displaying the obj file. 
//thats y we r not using printf for printing msg