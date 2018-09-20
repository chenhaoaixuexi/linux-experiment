#include <stdio.h>
#include <unistd.h>

main(){
	printf("About to execute ls /\n");
	execlp("ls","ls","/",NULL);	
	printf("Done!\n");
}
