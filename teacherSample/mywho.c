#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <utmp.h>
#include <time.h>


main(int ac, char *av[]){
	int fd;
	struct utmp buf;

	if((fd=open("/var/run/utmp", O_RDONLY))==-1){
		perror("cannot open");
		exit(0);
	}

	while(read(fd, &buf, sizeof(buf))>0){
		if(buf.ut_type==USER_PROCESS)	
			printf("%s\t%s\t%.15s (%s)\n", buf.ut_user, buf.ut_line, 4+ctime((const time_t *)&(buf.ut_time)), buf.ut_host);
	}
		
	close(fd);
}
