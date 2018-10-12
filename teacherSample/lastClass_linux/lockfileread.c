#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

main(){
	int fd;
	if((fd=open("forlock", O_RDONLY))==-1){
		perror("cannot open");
		exit(1);
	}

	struct flock lockinfo;
	lockinfo.l_type=F_RDLCK;
	lockinfo.l_len=0;
	lockinfo.l_pid=getpid();
	lockinfo.l_whence=SEEK_SET;
	lockinfo.l_start=0;
	
	if(fcntl(fd, F_SETLKW, &lockinfo)==-1){
		perror("cannot lock");
		exit(1);
	}

	char buf[512];
	int n;
	while((n=read(fd, buf, 512))>0){
		printf("%.*s", n, buf);	
	}

	sleep(10);

        lockinfo.l_type=F_UNLCK;

        if(fcntl(fd, F_SETLKW, &lockinfo)==-1){
                perror("cannot lock");
                exit(1);
        }
	
	close(fd);
		
}
