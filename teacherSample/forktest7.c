#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
	int rv, rv_wait;
	printf("About to cook:\n");
	rv=fork();
	if(0==rv){
		int i;

		return 10;
	}else{
		signal(SIGCHLD, SIG_IGN);
		while(1){
			sleep(1);
		}
	}
	return 0;
}
