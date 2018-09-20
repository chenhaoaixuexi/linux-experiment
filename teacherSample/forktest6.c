#include <stdio.h>
#include <unistd.h>

int main(){
	int rv, rv_wait;
	printf("About to cook:\n");
	rv=fork();
	if(0==rv){
		int i;
		for(i=0;i<50;i++){	
			printf("Go shopping\n");
			sleep(1);
		}

		return 10;
	}else{
		int status;
		rv_wait=wait(&status);
		printf("%d is back. status: %0x\n", rv_wait, status);
	}
	return 0;
}
