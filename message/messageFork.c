/*{{{
 * =====================================================================================
 *
 *       Filename:  messageFork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/18 15:15:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/

/*{{{*/
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>/*}}}*/

#define MSGKEY 75 

struct msgform
{
	long mtype;
	char mtext[1000];
}msg;

int msgqid;
int pid;

int main(int argc, char *argv[])
{
	while(-1 == (pid = fork()))	;
	if (pid > 0 )// in parent
	{
		msgqid = msgget(MSGKEY, 0777|IPC_CREAT);
		do 
		{
			if(-1 == msgrcv(msgqid,&msg,1024,0,0)){
				continue;
			}
			sleep(1);
			printf("(server)received: ");
			printf("%s\n",msg.mtext);
		}while(msg.mtype!=1);
		msgctl(msgqid,IPC_RMID,0);
		wait(NULL);
		exit(0);
	}
	else// in child
	{
		int i;
		msgqid = msgget(MSGKEY,0777);
		for(i= 10;i>=1;i--)
		{
			msg.mtype = i;
			printf("(client)sent\n");
			sleep(1);
			strcpy(msg.mtext, "client send message");
			msgsnd(msgqid,&msg,1024,0);
		}
		exit(0);
	}
	return 0;
}
