/*{{{
 * =====================================================================================
 *
 *       Filename:  signal_ignore.c
 *
 *    Description:  signal study 2
 *
 *        Version:  1.0
 *        Created:  10/15/18 17:31:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/
#include <stdlib.h>/*{{{*/
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>/*}}}*/
int pid1,pid2;
int EndFlag =0;
int pf1=0;
int pf2=0;
void IntDelete(int signum)
{
	kill(pid1,SIGUSR1);
	kill(pid2,SIGUSR2);
	EndFlag = 1;
}

void Int1(int signum)
{
	printf("child process 1 is killed by parent !\n");
	exit(0);
}
void Int2(int signum)
{
	printf("child process 2 is killed by parent !\n");
	exit(0);
}
int main()
{
	int exitcode;// store exit code
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	while(-1==(pid1= fork()));
	if(0== pid1)// in child 1
	{
		signal(SIGUSR1,Int1);
		signal(SIGINT,SIG_IGN);
		pause();
		exit(0);
	}
	else
	{
		while(-1 == (pid2=fork()));
		if(0 == pid2)// in child 2
		{
			signal(SIGUSR2,Int2);
			signal(SIGINT,SIG_IGN);
			pause();
			exit(0);
		}
		else
		{
			// in parent
			signal(SIGINT,IntDelete);
			waitpid(-1,&exitcode,0);
			waitpid(-1,&exitcode,0);
			printf("parent process is killed \n");
			exit(0);
		}
	}
}
