/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description: server  
 *
 *        Version:  1.0
 *        Created:  10/18/18 21:46:12
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


int process_request(int fd)
{
	
}

int main()
{
	int sock , fd;
	if (-1 == sock)
		exit(0);
	while(1)
	{
		/** int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len); */
		fd = accept(sock, NULL,NULL);
		if (-1 == fd)
			break;
		process_request(fd);
		close(fd);
	}
}
