/*
 * =====================================================================================
 *
 *       Filename:  signalControl.c
 *
 *    Description:  signal control by function
 *
 *        Version:  1.0
 *        Created:  09/20/18 10:26:16
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
#include <signal.h>
#include <unistd.h>


int main(){

	void funcCalled(int); // function declare
	signal(SIGINT,funcCalled); // install the handle

	
	for(int i = 0; i <5 ; i ++){
		printf("hello world !\n");
		sleep(1);
	}
}

void funcCalled(int signum){
		
	printf("OUCH\n");
}
