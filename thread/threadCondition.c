/*{{{
 * ===================================================================================
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
#include <pthread.h>
/*}}}*/

// public variable
int count = 100;


// mutex lock
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


// operator the public variable
void * show(void * a){
	pthread_mutex_lock(&mutex);
	while(count >0 ){
		if (100 != count){
			pthread_cond_wait(&cond,&mutex);
		}
		printf("%d : %d\n",(int)pthread_self(),count --);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		sleep(1);
	}	
}


int main()
{
	void * show(void *);

	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1,NULL,show,NULL);
	pthread_create(&t2,NULL,show,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
