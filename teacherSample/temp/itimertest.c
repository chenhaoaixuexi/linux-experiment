#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void wakeup(int signum){
	printf("Wake up!\n");
}

main(){
	struct itimerval itv;
	signal(SIGALRM, wakeup);

	itv.it_interval.tv_sec=1;	
	itv.it_interval.tv_usec=500000;	
	itv.it_value.tv_sec=5;
	itv.it_value.tv_usec=0;

	setitimer(ITIMER_REAL, &itv, NULL);

	while(1){
		printf("About to sleep!\n");
		pause();
	}
}
