#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main(){
	close(1);
	open("wholist.txt", O_WRONLY|O_CREAT, 0644);
	execlp("who", "who", NULL);
}
