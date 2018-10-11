#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main(){
	int fd;
	fd=open("wholist.txt", O_WRONLY|O_CREAT, 0644);
	close(1);
	dup(fd);
	close(fd);
	execlp("who", "who", NULL);
}
