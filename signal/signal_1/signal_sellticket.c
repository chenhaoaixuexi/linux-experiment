/*{{{
 * =====================================================================================
 *
 *       Filename:  signal_sellticket.c
 *
 *    Description:  external experiment - signal practices
 *    fork : create a child process -> seller
 *    		signal(SIGINT,func_handle);-->from driver 
 *    parent process -> driver
 *   	 	signal(SIGINT,func_handle);-->from seller
 *
 *        Version:  1.0
 *        Created:  10/16/18 15:01:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/
#include <stdlib.h>/*{{{*/
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>/*}}}*/

int loop_driver = 0;
int loop_seller = 0;
int fork_id;

void handle_driver(int signum)
{
	loop_driver = 1;
	printf("driver: bus has stop\n");
	kill(fork_id,SIGUSR1);

}

void handle_seller(int signum)
{
	loop_seller = 1;
	printf("seller: OK, it's busy time \n");
}

int main()
{
	signal(SIGINT,SIG_IGN);
	while(-1 == (fork_id = fork()));
	while(1){
		if (fork_id > 0)// in parent
		{
			signal(SIGINT,handle_driver);
			while(1 != loop_driver){
				sleep(1);
				printf("driver: keep driver\n");
			}
			loop_driver = 0;
		}
		else// in child
		{
			signal(SIGUSR1,handle_seller);
			while(1 != loop_seller){
				sleep(1);
				printf("seller: sell tickets or check account\n");
			}
			loop_seller = 0;
		}
	}
}
