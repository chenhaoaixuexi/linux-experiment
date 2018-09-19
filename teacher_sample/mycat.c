#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main(int ac, char *av[]){
	int fd;
	char buf[512];
	int n;
	if(ac<2){
		printf("USE: CMD file_name\n");
		exit(0);
	}

	if((fd=open(av[1], O_RDONLY))==-1){
		perror("cannot open");
		exit(0);
	}

	while((n=read(fd, buf, sizeof(buf)))>0){
		printf("%.*s\n", n, buf);
	}
		
	close(fd);
}
