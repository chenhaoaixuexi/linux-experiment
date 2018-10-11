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
	addr.sin_port=htons(atoi(av[2]));
	addr.sin_addr.s_addr=inet_addr(av[1]);

	if(connect(tcp_socket, (const struct sockaddr *)&addr, sizeof(addr))==-1){
		perror("cannot connect");
		exit(1);
	}

	n=read(tcp_socket, buf, sizeof(buf));	
	
	printf("%.*s\n", n, buf);

	close(tcp_socket);
}
