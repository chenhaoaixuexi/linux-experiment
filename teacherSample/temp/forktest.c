#include <stdio.h>

main(){
	printf("I am %d. About to fork:\n", getpid());
	fork();
	printf("After fork. I am %d.\n", getpid());
}
