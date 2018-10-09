/*
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
#include <string.h>
#include <arpa/inet.h>
#define PORT 9999

struct sockaddr_in  addr;
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
int fileOperator (int fd){
	FILE *  fp = fdopen(fd,"w");	
	if (NULL == fp){
		perror("open fail");	
		return -1 ;
	}
	fprintf(fp , "sucessfully fuck\n");

}
int main(){
	int socketID = getSocket();
	int result = bindSocket(socketID); 
	int fd = myListenAccept(socketID,1);
	fileOperator(fd);
	return 0;

}
