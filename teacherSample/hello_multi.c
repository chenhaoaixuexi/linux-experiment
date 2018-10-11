#include <stdio.h>
#include <pthread.h>

void *print_msg(void *msg){
	int i;
	for(i=0;i<5;i++){
		printf("%s\n", (char *)msg);
		sleep(1);
	}
}

main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, print_msg, "hello");
	pthread_create(&t2, NULL, print_msg, "world");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
