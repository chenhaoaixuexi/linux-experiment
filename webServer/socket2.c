/*
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

int make_server_connect (int port){
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
void MyWait(int signum){
	while(waitpid(-1,NULL,WNOHANG)>0);
}
int process (int fd,char * request){
	char  cmd[1024];
	char  file_name[1024];
	char temp[1024];
	int ffd;
	int n;
	char buf[1024];
	sscanf(request,"%s%s%s",cmd,file_name,temp);
	if(strcmp(cmd,"GET")== 0){
		if((ffd=open(file_name+1, O_RDONLY))==-1){
			//handle_404(fd);
			printf("404");
			write(fd, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n"));
			return 0;
		}
		printf("200");
		write(fd, "HTTP/1.0 200 OK\r\n\r\n", strlen("HTTP/1.0 200 OK\r\n\r\n"));
		while((n=read(ffd, buf, sizeof(buf)))>0){
				write(fd, buf, n);
			}
		close(ffd);
	}else{
		printf("400");
		write(fd, "HTTP/1.1 400 Operator Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n", strlen("HTTP/1.1 400 Operaor Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n"));
	}
	return 1;
}
int main(int argc, char *argv[])
{
	char  request[1024];
	int interrupt = 1;	
	int fd;
	signal (SIGCHLD,MyWait);
	int socket = make_server_connect(9999);
	if (-1 == socket) {
		perror("make server connect fail")	;
		exit(4);
	}
	int fork_id;
	while (1){
		fd = accept(socket,NULL,NULL);	
		read(fd,request,sizeof(request));
		if (interrupt == 1 || -1 != fd  ) {
			interrupt = process(fd,request);			
			close(fd);
		}else{
			break;
		}
	}
	return 0;
}
