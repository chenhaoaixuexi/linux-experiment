/*{{{
 * =====================================================================================
 *
 *       Filename:  message.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/18 19:33:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/

#include <stdlib.h>/*{{{*/
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>/*}}}*/

#define MSGKEY  75

struct msgform
{
	long mtype;// message type
	char mtext[1000];//message text
}msg;

int msgqid;//message descriptor

void client()
{
	int i;

       /** int msgget(key_t key, int msgflg); */
	msgqid = msgget(MSGKEY,0777);// open 75# message quequ
	for(i = 10; i >=1; i--)
	{
		msg.mtype = i;
		printf("(client) sent\n");
       	/** int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg); */
		 /** If (msgflg & IPC_NOWAIT) is 0, the calling thread shall suspend execution */
		msgsnd(msgqid,&msg,1024,0); // send message, will sleep when kernal run-out
	}
	exit(0);
}
int main()
{
	client();
}


