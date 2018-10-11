/*
 * =====================================================================================
 *
 *       Filename:  shareMemory.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/18 14:18:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int seg_id = shmget (99,128,0777)	;
	return 0;
}
