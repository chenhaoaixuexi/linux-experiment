/*{{{
 * =====================================================================================
 *
 *       Filename:  connect_to_server.c
 *
 *    Description:  connect to server
 *
 *        Version:  1.0
 *        Created:  10/18/18 19:41:35
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

int connect_to_server(char *host,int portnum)
{
	int sock;
	struct sockaddr_in servadd;  // the num to call
	struct hostent *hp;

	/** get socket   */
       /** int socket(int domain, int type, int protocol); */
 	sock = socket(AF_INET,SOCK_STREAM,0);
	if (-1 == sock)
		return -1;
	
	/** connect to server */
       /** void bzero(void *s, size_t n); */
	bzero(&servadd,sizeof(servadd));
       /** struct hostent *gethostbyname(const char *name); */
	hp = gethostbyname(host);
	if(NULL == hp)
		return -1;	
	bcopy(hp->h_addr,(struct sockaddr *)&servadd.sin_addr,hp->h_length);
	servadd.sin_port = htons(portnum);
	servadd.sin_family = AF_INET;
       /** int connect(int socket, const struct sockaddr *address, socklen_t address_len); */
	if (0 != connect(sock,(struct sockaddr *)&servadd,sizeof(servadd))) 
		return -1;

	return sock;	
}
