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
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void printBinary(unsigned num);
void printBinary(unsigned num){
	int remainder[20] = {0};
	int index= 0;
    while(0 != num){
		remainder[index]=num % 2 ;
		num = num / 2;
		index ++;
	}
	int count = 0;
	for(int i=--index;i>=0;i--){
		if(0 == count%4){
			printf(",");
		}
		count ++;	
		printf("%d",remainder[i]);
	}
	printf("\n");
}
int main(){
		
	signal(SIGTERM,SIG_IGN);
	printf("the parent process id : %d\n",getpid());
	int fork_id = fork();// mark is not prarent
	if(-1 == fork_id){
		perror("fork fail\n");// when the memorry is full
	}else{
		int state;
		if(0 != fork_id){//parent process is runing
			int wait_id =wait(&state);
			printf("i am parent process , my id is %d,the wait function return value is %d\n ",getpid(),wait_id);
			printf("the exit num :");
			printBinary(state);
		}

		if(0 == fork_id){// child process is runing
			printf("i am child process , my id is %d \n",getpid());
			printf("child process about to sleep 10 second\n");
			sleep(10);
			exit(17);
		}
	}

}
