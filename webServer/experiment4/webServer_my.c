/*{{j
 * =====================================================================================
 *
 *       Filename:  webServer.c
 *
 *    Description:  webserver 
 *
 *        Version:  1.0
 *        Created:  10/18/18 22:01:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "makeSocket_my.h"
#include "process.h"/*}}}*/

static int read_until_crnl(FILE *fp)
{
	char buf[BUFSIZ];
	while(NULL != fgets(buf,BUFSIZ,fp)&& 0!=strcmp(buf,"\r\n"));
}

int main(int ac, char* av[])
{
	/** int atoi(const char *nptr); */
	int port = atoi(av[1]);
	int sock , fd;
	FILE * fpin;
	char  request[BUFSIZ];

	if (1 == ac ) {
		perror("NO PROT USED");
		exit(1);
	}

	sock = make_server_socket(port) ;
	if (-1 == sock)
		exit(2);
	while(1)
	{
		/** int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len); */
		fd = accept(sock, NULL,NULL);
		if (-1 == fd)
			break;

		/** FILE *fdopen(int fd, const char *mode); */
		fpin = fdopen(fd,"r");
		/** char *fgets(char *s, int size, FILE *stream); */
		fgets(request,BUFSIZ,fpin);
		printf("got a call : request = %s",request);
		read_until_crnl(fpin);

		/** process task */
		myprocess(request,fd);

		close(fd);
	}
}

