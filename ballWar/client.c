/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  client-biubiubiu
 *
 *        Version:  1.0
 *        Created:  10/22/18 17:17:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <curses.h>
#include <pthread.h>
#include "connect_to_server.h"
#include "draw.h"

pthread_t t1, t2;
int main(int ac, int av)
{
	initscr();
	cbreak();
	nonl();
	noecho();
	curs_set(0);
	clear();
	//begin
	/** int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg); */
	pthread_create(&t1,NULL,draw_line_v,NULL);
	/** [> int pthread_join(pthread_t thread, void **retval); <] */
	pthread_join(t1,NULL);
	while(1);
	curs_set(1);
	endwin();

}
