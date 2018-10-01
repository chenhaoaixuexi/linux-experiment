#include <stdio.h>
#include <unistd.h>

main(){
	int rv, rv_wait;
	printf("About to cook:\n");
	rv=fork();
	if(0==rv){
		int i;
		for(i=0;i<50;i++){	
			printf("Go shopping\n");
			sleep(1);
		}
	}else{
		rv_wait=wait(NULL);
		printf("%d is back. Done\n", rv_wait);
	}
}
