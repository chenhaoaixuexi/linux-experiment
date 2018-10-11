/*{{{
 * =====================================================================================
 *
 *       Filename:  thread.c
 *
 *    Description:  thread connect with confition varibale  study
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
 *//*}}}*/
#include <netinet/in.h>/*{{{*/
#include <netinet/ip.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>/*}}}*/


// public variable
int count = 100;

// mutex lock
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// operator the public variable
void * show(void * a){
	while(1){
		pthread_mutex_lock(&mutex);
		if (count > 0 ) {

			printf("%s",(char *)a);
			printf("%d : %d\n",(int)pthread_self(),count --);
			fflush(stdout);
		}
		pthread_mutex_unlock(&mutex);
	}
}


int main(int argc, char *argv[])
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1,NULL,show,(void *)"hello");
	pthread_create(&t2,NULL,show,(void *)"world");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
