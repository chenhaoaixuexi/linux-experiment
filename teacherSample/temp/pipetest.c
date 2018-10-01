#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(){
	int pipefd[2];
	int rv;
	pipe(pipefd);
	
	if((rv=fork())==-1){
		perror("cannot fork");
		exit(1);
	}else if(0==rv){
		close(pipefd[1]);
		close(0);
		dup(pipefd[0]);
		close(pipefd[0]);
		execlp("wc","wc", NULL);
	}else{
		close(pipefd[0]);
		close(1);
		dup(pipefd[1]);
		close(pipefd[1]);
		execlp("ls","ls","-l","/",NULL);
	}
}
