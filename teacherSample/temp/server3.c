#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <stdio.h>

main(int ac, char *av[]){
	int tcp_socket;
	struct sockaddr_in addr;
	int fd;
	char buf[1024];
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

		n=read(fd, buf, sizeof(buf));	
		printf("%.*s", n, buf);

		close(fd);	
	}
}
