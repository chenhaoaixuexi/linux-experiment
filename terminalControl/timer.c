/*
 * =====================================================================================
 *
 *       Filename:  timer.c
 *
 *    Description:  using interval timeer
 *
 *        Version:  1.0
 *        Created:  09/20/18 19:32:09
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
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

int main(){
    void wakeUP(int);
//	  int getitimer(int which, struct itimerval *curr_value);
//    int setitimer(int which, const struct itimerval *new_value,
//                     struct itimerval *old_value);

	signal(SIGALRM, wakeUP);
	struct itimerval myTimer;
	// initiante myTimer
	myTimer.it_interval.tv_sec = 1; // period time setting
	myTimer.it_interval.tv_usec = 100;
	myTimer.it_value.tv_sec = 1; // delay time setting
	myTimer.it_value.tv_usec = 100;
	setitimer(ITIMER_REAL,&myTimer, NULL )	;// note the point 

	while (1){
		printf("about to sleep ~\n ");
		pause();
	}
	return 1;

}


void wakeUP(int signum){
	printf("wake up ! man !\n");
}
