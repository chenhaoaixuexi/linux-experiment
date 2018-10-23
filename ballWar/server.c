/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description: server-biubiubiu  
 *
 *        Version:  1.0
 *        Created:  10/22/18 17:17:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include "makeSocket.h"
#include <pthread.h>
#include <process.h>

pthread_t t1;
pthread_t t2;

struct FD
{
	int fd1;
	int fd2;
};


int main(int ac, char* av[])
{
	/** int atoi(const char *nptr); */
	int port = atoi(av[1]);
	int sock , fd1,fd2;
	sock = make_server_socket(port) ;
	if (-1 == sock)
		exit(0);
	while(1)
	{
		/** int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len); */
		fd1 = accept(sock, NULL,NULL);
		fd2 = accept(sock, NULL,NULL);
		struct FD fd;
		if (-1 == fd1)
			break;
		if (-1 == fd2)
			break;
		fd.fd1 = fd1;
		fd.fd2 = fd2; 
		pthread_create(&t1,NULL,process,(void *)&fd);
		fd.fd1 = fd2;
		fd.fd2 = fd1;
		pthread_create(&t1,NULL,process,(void *)&fd);

		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
		close(fd1);
		close(fd2);
	}
}


