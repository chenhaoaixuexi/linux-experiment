/*
 * =====================================================================================
 *
 *       Filename:  bounceStudy.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/26/18 19:37:46
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
 #include <sys/time.h>
 #include <curses.h>
 #include <string.h>
#include <unistd.h>

#define MESSAGE "hello"
#define BLANK "     "

int row;
int col;
int dir;

int main(){
  int delay;
  int ndelay;
  int c;

  void move_msg(int);
  initscr();
  crmode();
  noecho();
  clear();

  row = 10;
  col = 0;
  dir = 1;
  delay = 200;

  move(row,col);
  addstr(MESSAGE);
  signal (SIGALRM, move_msg);
}
