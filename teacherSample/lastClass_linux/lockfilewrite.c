#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int fd;
	if((fd=open("forlock", O_WRONLY))==-1){
		perror("cannot open");
		exit(1);
	}

	struct flock lockinfo;
	lockinfo.l_type=F_WRLCK;// write file lock
	lockinfo.l_len=0;
	lockinfo.l_pid=getpid();
	lockinfo.l_whence=SEEK_SET;
	lockinfo.l_start=0;
	
	// write file lock
	if(fcntl(fd, F_SETLKW, &lockinfo)==-1){
		perror("cannot lock");
		exit(1);
	}

	int i;
	for(i=0; i<5; i++){
		write(fd, "Hello world\n", strlen("Hello world\n"));
	}
	printf("wrote\n");

	sleep(10);

	// write file lock
	lockinfo.l_type=F_UNLCK;
	if(fcntl(fd, F_SETLKW, &lockinfo)==-1){
			perror("cannot lock");
			exit(1);
	}
	
	close(fd);
		
}
