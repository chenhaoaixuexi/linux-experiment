/*
 * =====================================================================================
 *
 *       Filename:  curses_study.c
 *
 *    Description:  cartoon result by curses
 *
 *        Version:  1.0
 *        Created:  09/18/18 19:39:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	initscr();//initial screan
	clear();
	if (start_color()==OK) 
	{	
		init_pair(1,COLOR_BLUE,COLOR_GREEN);
		attron(COLOR_PAIR(1)); /*开启字符输出颜色*/
		box(stdscr, ACS_VLINE, ACS_HLINE); /*draw a box*/
		for (int i =0 ;i<LINES-1 ; i = i +10 ){
			clear();
			move(i,i+1);
			addstr("hello world !");
			refresh();
			sleep(1);
		}
		for (int i = LINES -1 ; i > 0 ; i = i-10 ){
			clear ();
			move(i,i+1);
			addstr("hello world !");
			refresh();
			sleep(1);
		}
		attroff(COLOR_PAIR(1)); /*关闭颜色显示*/
	}
	endwin();
	return 1;
}
