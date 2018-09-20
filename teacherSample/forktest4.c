#include <stdio.h>
#include <unistd.h>

main(){
	int rv, rv_wait;
	printf("About to execute ls /:\n");
	rv=fork();
	if(0==rv){
		execlp("ls","ls","/", NULL);
	}else{
		rv_wait=wait(NULL);
		printf("%d is back. Done\n", rv_wait);
	}
}
