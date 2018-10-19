/*{{{
 * =====================================================================================
 *       Filename:  socket.c
 *
 *    Description:  web server implement
 *
 *        Version:  1.0
 *        Created:  10/08/18 12:08:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>   
#include <sys/socket.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
/*}}}*/

int make_server_socket (int port){
	int state_socket ;
	int state_bind;
	int state_listen;

	struct sockaddr_in addr ;
	int  fd;

	if (-1 != (state_socket = socket(AF_INET,  SOCK_STREAM,0))){
		addr.sin_family=AF_INET;
		addr.sin_port=htons(port);
		addr.sin_addr.s_addr=INADDR_ANY;

		if(bind(state_socket, (const struct sockaddr *)&addr, sizeof(addr))==-1){
			perror("cannot bind");
			exit(1);
		}else {
			state_listen = listen(state_socket, 1);
			if (-1 == state_listen) {
				perror("cannot listen ")	;
				exit(3);
			}
			return state_socket;
		}
	}else {
		perror("cannot get socket")	;
		exit(2);
	}
}

