/*
 * =====================================================================================
 *
 *       Filename:  mycp.c
 *
 *    Description:  simulate linux cmd cp
 *
 *        Version:  1.0
 *        Created:  09/09/18 16:35:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE  512
//#define COPYMODE  0644

int main(int ac , char * av[]){
		int s_sig;
		int t_sig;
		int read_num;
		char buf[BUFFERSIZE];
		int temp_num;

		if (3 != ac) {
				printf("input error"); 
				return -1;
		}

		if (-1 ==(s_sig = open(av[1],O_RDONLY))) {
				printf("open source file fail");
				return -1;
		}

		if (-1 == (t_sig = open(av[2],O_CREAT,S_IRWXU))) {
				printf("open target file fail") ;
				printf("t_sig : %d",t_sig);
				return -1;
		}
		while((read_num = read(s_sig,buf,BUFFERSIZE))> 0){
				write( t_sig, buf, read_num );
		}
		printf("  copy file sucessfully ! ");
		return 0;
}
