/*{{{
 * =====================================================================================
 *
 *       Filename:  signal_pipe.c
 *
 *    Description: pipe using study
 *    		
 *    		child process send message
 *				 1==> child 1 is sengding message
 *				 2==> child 2 is sengding message
 *    		parent process read from pipe and print
 *
 *        Version:  1.0
 *        Created:  10/17/18 10:42:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/

#include <stdlib.h>/*{{{*/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
/*}}}*/

int pid1,pid2;

int main()
{
	int fd[2];
	char OutPipe[100],InPipe[100];
	pipe(fd);
	while(-1 == (pid1= fork()));
	if (pid1 == 0)// in child process 1
	{
		/** int lockf(int fd, int cmd, off_t len); */
		lockf(fd[1],1,0);// lock output file descriptor
		/** write to the  character string str. */
		sprintf(OutPipe, "child 1 process is sengding message\n");
		write(fd[1],OutPipe,50);
		sleep(5);
		lockf(fd[1],0,0);
		exit(0);
	}	
	else
	{
		while(-1 == (pid2 = fork()));
		if(pid2 == 0)// in child process 2
		{
			lockf(fd[1],1,0);
			sprintf(OutPipe, "child 2 process is sengding message\n")	;
			write(fd[1],OutPipe,50);
			sleep(5);
			lockf(fd[1],0,0);
			exit(0);
		}
		else// in parent process
		{
			wait(0);
			printf("the follow is child process words\n");
			read(fd[0],InPipe,50);
			printf("%s\n",InPipe);
			wait(0);
			read(fd[0],InPipe,50);
			printf("%s\n",InPipe);
			exit(0);
		}
	}
}
