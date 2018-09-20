#include <stdio.h>

main(){
	int rv;
	printf("I am %d. About to fork:\n", getpid());
	rv=fork();
	if(0==rv){
		printf("I am child. I am %d\n", getpid());
	}else{
		printf("I am father. My child is %d\n", rv);
	}
}
