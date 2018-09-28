/*
 * =====================================================================================
 *
 *       Filename:  wait.c
 *
 *    Description:  wait -- posix standard 
 *   		
 *
 *        Version:  1.0
 *        Created:  09/28/18 14:01:48
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
#include <sys/wait.h>
void printBinary(unsigned num);
void printBinary(unsigned num){
	int quotient = -1;
	char remainder[20];
	int index;
    while(0 != quotient){
		quotient = num / 2;
		remainder[index]= num % 2;
	}
}
int main(){
	/** printBinary(15); */
	printf("the parent process id : %d\n",getpid());
	int fork_id = fork();// mark is not prarent
	if(-1 == fork_id){
		perror("fork fail\n");// when the memorry is full
	}else{
		int state;
		if(0 != fork_id){//parent process is runing
			int wait_id =wait(&state);
			printf("i am parent process , my id is %d,the wait function return value is %d\n ",getpid(),wait_id);
			printf("the exit num :%d",state);
		}
		if(0 == fork_id){// child process is runing 
			printf("i am child process , my id is %d \n",getpid());
			printf("child process about to sleep 2 second\n");
			sleep(2);
			exit(255);
		}
	}

}
