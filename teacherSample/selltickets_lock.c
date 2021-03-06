#include <stdio.h>
#include <pthread.h>

int tickets=100;
pthread_mutex_t mutex_lock=PTHREAD_MUTEX_INITIALIZER;

void *print_msg(void *msg){
	while(1){
		pthread_mutex_lock(&mutex_lock);
		if(tickets>0){
			printf("%s sells No. %d ticket\n", (char *)msg, tickets);
			tickets--;
		}
		pthread_mutex_unlock(&mutex_lock);
	}
}

int main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, print_msg, "Shenyangnan");
	pthread_create(&t2, NULL, print_msg, "Shenyang");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
