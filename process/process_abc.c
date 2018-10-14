/*
 * =====================================================================================
 *
 *       Filename:  process_abc.c
 *
 *    Description:  
 *   
 *
 *        Version:  1.0
 *        Created:  10/13/18 19:07:58
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

int main(){
	int p1,p2;
	while(-1 == (p1 = fork()));
	if (0 == p1) {// in child process
		putchar('b');
	}else{
		while(-1== (p2 = fork()));
		if (0 == p2)// in child process
			putchar('c');
		else {
			putchar('a');
		}
	}
	fflush(stdout);
}
