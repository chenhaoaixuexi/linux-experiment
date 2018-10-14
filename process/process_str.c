/*
 * =====================================================================================
 *
 *       Filename:  process_abc.c
 *
 *    Description:  
 *   
 *
 *        Version:  1.0
 *        Created:  count/13/18 19:07:58
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
#include <unistd.h>

int main(int ac, char * av[]){
	int p1,p2;
	int i;
	int count = atoi(av[1]);
	while(-1 == (p1 = fork()));
	if (0 == p1) {// in child process
		for (i = 0; i < count; ++ i) {
			printf("daughter %d\n",i);	
			//fflush(stdout);
		}
	}else{
		while(-1== (p2 = fork()));
		if (0 == p2)// in child process
			for (i = 0; i < count; ++ i) {
				printf("son%d\n",i);			
				//fflush(stdout);
			}
		else {
			for (i = 0; i < count; ++i) {
				printf("parents%d\n",i);	
				//fflush(stdout);
			}
		}
	}
}
