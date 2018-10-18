/*{{{
 * =====================================================================================
 *
 *       Filename:  message2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/18 22:30:07
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

void server()
{
	//A message queue identifier, associated message  queue,  and  data  structure{{{
	//(see  <sys/msg.h>), shall be created for the argument key if one of the fol‐
	//lowing is true:
	//
	//	*  The argument key is equal to IPC_PRIVATE.
	//
	//	*  The argument key does not already have a message queue identifier  asso‐
	//	   ciated with it, and (msgflg & IPC_CREAT) is non-zero.}}}
	msgqid = msgget(MSGKEY,0777|IPC_CREAT);// create 75# message queqe
	do
	{
		/** ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg); */
		if (-1 == msgrcv(msgqid,&msg,1030,0,0)){
			continue;
			printf("(server)no message received\n");
			sleep(1);
		}
		printf("(server)received\n");
	}while(msg.mtype!=1);// break UNTILL mtype == 1
	//       IPC_RMID    Remove  the message queue identifier specified by msqid from the system and destroy the message queue and msqid_ds data structure associated with it.{{{
	//		   IPC_RMD can only be executed by a process with appropriate privileges or one that has an effective user ID equal to the  value  of  msg_perm.cuid  or
	//		   msg_perm.uid in the msqid_ds data structure associated with msqid.}}}
	msgctl(msgqid,IPC_RMID,0);
	exit(0);
}

int main()
{
	server();
}

