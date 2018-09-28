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
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	printf("the parent id is :%d\n",getpid());
	printf("calling fork\n");
	sleep(1);
	//call fork
	int fork_id = fork();// the child process begin 
	printf("my id is %d , the fork return value is %d\n",getpid(),fork_id);
	return 0;
}
