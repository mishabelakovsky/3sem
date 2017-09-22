/* 1) build and examine this code
   2) correct the mistake: it is possible to hang on wait. Why and when? (see "man fork")
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
	pid_t pid;
   	int status, died;
   	switch(pid = fork()) {
   		case 0: 
			execl("/bin/ls","ls","-l",NULL); // this is the code the child runs 
		case -1:
			printf("EROR!!!111!11!");
			exit(-1);
   		default: 
			wait(&status); // this is the code the parent runs
   	}
	return 0;
}
