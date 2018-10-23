/*
 * =====================================================================================
 *
 *       Filename:  thread.c
 *
 *    Description:  thread study
 *
 *        Version:  1.0
 *        Created:  10/09/18 21:23:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>


// public variable
int count = 100;

pthread_t t1;
pthread_t t2;

void * show2(void * a)
{
	printf("i am show2\n");
}
// operator the public variable
void * show(void * a){
	while(count >0 ){
		printf("%d : %d\n",(int)pthread_self(),count --);
		pthread_t t;
		pthread_create(&t,NULL,show2,NULL);
		sleep(1);
	}
}


int main(int argc, char *argv[])
{
	pthread_create(&t1,NULL,show,NULL);
	pthread_create(&t2,NULL,show,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
