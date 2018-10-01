#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void handle_404(int fd){
	write(fd, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n"));
	close(fd);
}
void handle_400(int fd){

}

void handle_200(int fd, char *file_name){
	int ffd;
	char buf[1024];
	int n;
	if((ffd=open(file_name+1, O_RDONLY))==-1){
		handle_404(fd);
		return;
	}
	write(fd, "HTTP/1.0 200 OK\r\n\r\n", strlen("HTTP/1.0 200 OK\r\n\r\n"));
	while((n=read(ffd, buf, sizeof(buf)))>0){
		write(fd, buf, n);
	}
	close(ffd);
	close(fd);	
}

void handle_request(int fd, char *request){
	char cmd[1024];
	char file_name[1024];
	sscanf(request, "%s%s", cmd, file_name);
	if(strcmp(cmd, "GET")==0)
		handle_200(fd, file_name);
	else
		handle_400(fd);	
}

main(int ac, char *av[]){
	int tcp_socket;
	struct sockaddr_in addr;
	int fd;
	char request[1024];
int n;
	tcp_socket  =  socket(AF_INET,  SOCK_STREAM, 0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(av[1]));
	addr.sin_addr.s_addr=INADDR_ANY;

	if(bind(tcp_socket, (const struct sockaddr *)&addr, sizeof(addr))==-1){
		perror("cannot bind");
		exit(1);
	}

	listen(tcp_socket, 1);

	while(1){
		fd=accept(tcp_socket, NULL, NULL);

		n=read(fd, request, sizeof(request));	
		handle_request(fd, request);

		close(fd);	
	}
}
