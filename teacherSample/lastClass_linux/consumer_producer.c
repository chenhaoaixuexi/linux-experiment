#include <stdio.h>
#include <pthread.h>

#define NUM 5

int buf[NUM]={0};
int num=0;

pthread_mutex_t mutex_lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t flag=PTHREAD_COND_INITIALIZER;

void *producer(void *useless){
	int count=0;
	while(1){
		pthread_mutex_lock(&mutex_lock);
		if(num<NUM){
			buf[num]=count;
			count++;
			printf("put %d\n", buf[num]);	
			num++;
			fflush(stdout);
			pthread_cond_signal(&flag);
		}else{
			pthread_cond_wait(&flag, &mutex_lock);	
		}
		sleep(1);
		pthread_mutex_unlock(&mutex_lock);
	}
}

void *consumer(void *useless){
	while(1){
		pthread_mutex_lock(&mutex_lock);
		if(num>0){
			num--;
			printf("get %d\n", buf[num]);	
			buf[num]=0;
			fflush(stdout);
			sleep(1);
			pthread_cond_signal(&flag);
		}else{
			pthread_cond_wait(&flag, &mutex_lock);	
			sleep(1);
		}
		pthread_mutex_unlock(&mutex_lock);
	}
}
main(){
	pthread_t t1, t2;
        pthread_create(&t1, NULL, consumer, NULL);
        pthread_create(&t2, NULL, producer, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
}
