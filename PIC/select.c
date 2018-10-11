/*{{{
 * =====================================================================================
 *
 *       Filename:  select.c
 *
 *        Version:  1.0
 *        Created:  10/10/18 20:09:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 *//*}}}*/
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
	 int fd1,fd2;
	 fd_set rfds;
	 int retval;
	 int n;
	 char buf[1024];

	 if (-1 == (fd1 = open ("/dev/input/mice",O_RDONLY))){
		 perror("cannot open");
		 exit(0);
	 }
	 if (-1 == (fd2 = open ("/dev/pts/0",O_RDONLY))){
		 perror("cannot open");
		 exit(0);
	 }
	 while(1){
		FD_ZERO (&rfds);
		FD_SET(fd1,&rfds);	
		FD_SET(fd2,&rfds);	
	 }
}
