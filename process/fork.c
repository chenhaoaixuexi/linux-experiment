/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/28/18 13:29:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void myPrint(int fork_id,char output){
	if (0 == fork_id){// child process
		printf("I am child ,my id is %d , the fork return value is %d",getpid(),fork_id);
	}else{
		printf("I am parent, my id is %d , the fork return value is %d",getpid(),fork_id);
	}
	printf(" my char is %c\n",output);
}

int isParent(int fork_id){
	if (0 == fork_id) {
		return 0;	
	}else{
		return fork_id;
	}
}
int main(int ac, char *av[]){
	int i;
	char * output_set = av[1];
	int fork_id = fork();
	myPrint(fork_id,output_set[0]);
	for (i = 0; i < 3; ++i) {
		if (!isParent(fork_id)) {
			fork_id = fork();
			myPrint(fork_id,output_set[i+1]);
		}else{
			wait(NULL);
		}
	}
	return 0;
}
