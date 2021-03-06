/let*
 * ====================================================================================
 *
 *
 *    Description:  socket stydy
 *
 *        Version:  1.0
 *        Created:  09/30/18 21:12:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>
#define PORT 9998

struct sockaddr_in  addr;
int lock = 1;
int count= 100;
/** int getSocket(); */
/** int bindSocket(int ); */
/** int myListenAccept(int,int); */
int getSocket(){
	int socketID = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == socketID){
		perror("get socket fail");
		return -1 ;
	}
	return socketID;		
}
int bindSocket(int socketID){
	memset(&addr,'\0',sizeof(struct sockaddr));	// clear the structure

	addr.sin_family = AF_INET;  /* Internet地址族 */   
	addr.sin_port = htons(PORT);  /* 端口号 */    
	addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
	if (-1 == bind(socketID,(struct sockaddr *) &addr,
				sizeof(struct sockaddr))){
		perror("bindSocket fail");
		return -1;
	}
	return 0;
}
int myListenAccept(int socket, int limit){
	if(listen(socket,limit) == -1){
		perror("listen fail");
		return -1;
	}
	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	//int fd = accept(socket,( struct sockaddr *)&addr,sizeof(addr));
	int fd = accept(socket,NULL,NULL);
	if (-1 == fd){
		perror("accept fail");
		return -1;
	}
	return fd;
}

int operator (int fd){
	FILE *  fp = fdopen(fd,"w");	
	if (NULL == fp){
		perror("open fail");	
		return -1 ;
	}
	count --;
	fprintf(fp , "the count: %d",count);
	fprintf(fp,"this is  OK\n");
	return 0 ;
}
void  func(int signum){
	printf("handle signal : %d",signum);
	exit(0);
}
int main(){
	int socketID = getSocket();
	int result = bindSocket(socketID); 
	signal(SIGINT,SIG_DFL);
	if(listen(socketID,1) == -1){
		perror("listen fail");
		return -1;
	}
	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	while(1){
		//int fd = accept(socket,( struct sockaddr *)&addr,sizeof(addr));
		int fd = accept(socketID,NULL,NULL);
		if (-1 == fd){
			perror("accept fail");
			return -1;
		}
		int forkID = fork();
		if(0 == forkID){ 
			operator(fd);
			return 0;
		}else{
			continue;
		}
	}
	return 0; 

}
