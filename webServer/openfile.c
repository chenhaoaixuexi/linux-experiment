/*
 * =====================================================================================
 *
 *       Filename:  openfile.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/18 19:39:33
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
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	printf("%d",open("1.html",O_RDONLY));
	return 0;
}
