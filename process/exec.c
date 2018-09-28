/*
 * =====================================================================================
 *
 *       Filename:  exec.c
 *
 *    Description:  study exec function family
 *
 *        Version:  1.0
 *        Created:  09/28/18 19:08:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
int main(){
	execl("/bin/ls","ls","-al","./",NULL);
}
