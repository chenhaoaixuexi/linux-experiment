/*{{{
 * =====================================================================================
 *
 *       Filename:  signal_pipe2.c
 *
 *    Description:  study pipe 
 *      	parent write to pipe
 *      	child 1,2 read from pipe
 *   
 *        Version:  1.0
 *        Created:  10/17/18 11:44:39
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

int fd[2];// file descriptor of pipe
int pid1, pid2;
char buffer[50];

int writePipe()
{
	lockf(fd[1],1,0);
       /** ssize_t write(int fildes, const void *buf, size_t nbyte); */
	write(fd[1],buffer,50);
	lockf(fd[1],0,0);
}

int readPipe()
{
	lockf(fd[1],1,0);
       /** ssize_t read(int fildes, void *buf, size_t nbyte); */
	read(fd[0],buffer,50);
	sleep(3);
	printf("%s",buffer);
	lockf(fd[1],0,0);
}

int main(int argc, char *argv[])
{
	pipe(fd);
	while(-1 == (pid1 = fork()));
	if (0 == pid1)// in child process 1
	{	
		printf("the child process 1 is reading\n");
		readPipe();
		exit(0);
	}
	else
	{
		while (-1 == (pid2 = fork())); 
		if ( 0 == pid2 )// in child process 2
		{
			printf("the child process 2 is reading\n");
			readPipe();
			exit(0);
		}
		else// in parent process
		{	
			printf("the parent is writing \n");
			sprintf(buffer,"I am parent , I am writing in the pipe file\n");
			writePipe();
			printf("the parent has wrote\n");
			/** wait(0); */
			/** wait(0)**/
			sleep(100);
		}
	}
	return 0;
}
