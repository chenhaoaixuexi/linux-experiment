#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main(int ac, char *av[]){
	int fdin, fdout;
	char buf[512];
	int n;
	if(ac<2){
		printf("USE: CMD file_name\n");
		exit(0);
	}

	if((fdin=open(av[1], O_RDONLY))==-1){
		perror("cannot open input file");
		exit(0);
	}
	if((fdout=open(av[2], O_WRONLY|O_CREAT, 0640))==-1){
		perror("cannot open output file");
		exit(0);
	}
	while((n=read(fdin, buf, sizeof(buf)))>0){
		write(fdout, buf, n);
	}
		
	close(fdin);
	close(fdout);
}
