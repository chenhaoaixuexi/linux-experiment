/*
 * =====================================================================================
 *
 *       Filename:  signalSay.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/18 21:52:37
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
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int wait_mark;
void waiting(int wait_mark)
{
	while(0 != wait_mark);
}
void stop(int signum)
{
	wait_mark = 0;
}
int main(){
	int p1,p2;
       //void (*signal(int sig, void (*func)(int)))(int);
	signal(SIGINT,stop);
	while(-1 == (p1=fork()));// create child process UNTILL ok
	if (p1 > 0)// in parent
	{
		while(-1 == (p2 = fork()));// create child process UNTILL ok
		if (p2>0)  // in parent
		{
			// lock UNITLL wait_mark = 0
			wait_mark = 1;
			waiting();

			kill(p1,10);
			kill(p2,12);
			wait();
			wait();
			
			printf("parent process is killed!\n");
			exit(0);
		}
		else
		{
			wait_mark = 1;
			signal(12,stop);
			waiting();
			lockf(1,1,0)
		}
	}
}
