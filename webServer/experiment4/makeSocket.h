/*{{{
 * =====================================================================================
 *
 *       Filename:  makeSocket.c
 *
 *    Description:  web sockid make
 *
 *        Version:  1.0
 *        Created:  10/18/18 17:24:39
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
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <strings.h>
#include <unistd.h>/*}}}*/

#define HOSTLEN 256
#define BACKLOG 1

int make_server_socket_q(int ,int);

int make_server_socket(int portnum)
{
	return make_server_socket_q(portnum,BACKLOG);	
}

int make_server_socket_q(int portnum, int backlog)
{
	struct sockaddr_in saddr; // build our address here
	struct hostent *hp; // part of address
	char hostname[HOSTLEN] ;// address
	int sock_id;// socket

	sock_id = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sock_id)
		return -1;

	bzero((void *)&saddr,sizeof(saddr));// clear out structure

	/** int gethostname(char *name, size_t namelen); */
	gethostname(hostname,HOSTLEN);

	/** struct hostent *gethostbyname(const char *name); */
	hp = gethostbyname(hostname);

	/** void bcopy(const void *src, void *dest, size_t n); */
	bcopy((void *)hp->h_addr,(void *)&saddr.sin_addr,hp->h_length);
	saddr.sin_family = AF_INET;

	if (0 != bind(sock_id,(struct sockaddr *)&saddr,sizeof(saddr))) {
		return -1;
	}

	if(0 != listen(sock_id,backlog)){
		return -1;
	}

	return sock_id;
}
