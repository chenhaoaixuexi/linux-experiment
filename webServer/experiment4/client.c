/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  client
 *
 *        Version:  1.0
 *        Created:  10/18/18 21:22:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "connect_to_server.h" 

int talk_with_server(int fd)
{

}

int main(int ac, char* av[])
{
	char * host = av[1];
	/** int atoi(const char *nptr); */
	int port = atoi(av[2]) ;
	int fd ;
	fd = connect_to_server(host,port);
	if(-1 == fd)
		exit(0);
	talk_with_server(fd);
	close(fd);
}


