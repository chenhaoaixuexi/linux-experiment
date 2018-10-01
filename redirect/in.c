/*
 * =====================================================================================
 *
 *       Filename:  in.c
 *
 *    Description:  close then open
 *
 *        Version:  1.0
 *        Created:  09/28/18 19:24:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
	char  temp[10];
	fgets(temp,10,stdin);
	int a = strlen(temp);
	printf("std output : %s", temp);

	close(0);// close stdin 

	int fd = open("./temp.txt",O_RDWR);
	fgets(temp,strlen(temp),stdin);
	printf("file output : %s", temp);
}
