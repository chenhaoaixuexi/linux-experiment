/*
 * =====================================================================================
 *
 *       Filename:  open.c
 *
 *    Description:  creat file
 *
 *        Version:  1.0
 *        Created:  09/19/18 16:19:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (){
	
	  //int open(const char *pathname, int flags, mode_t mode);
	int in_flag; // file description of new creat file	  
	char str_in[10];
	if (-1 ==(in_flag = open ("my_new_file",O_CREAT|O_WRONLY,S_IRWXU)) ){
		printf("open file fail !");
		return -1;
	}
	scanf("%s",str_in);
	//       ssize_t write(int fd, const void *buf, size_t count);
	write(in_flag, str_in, strlen(str_in));
	//        int close(int fd);
	close(in_flag);
	return 1;
}
