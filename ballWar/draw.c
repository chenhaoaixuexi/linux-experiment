/*
 * =====================================================================================
 *
 *       Filename:  draw.c
 *
 *    Description:  draw
 *
 *        Version:  1.0
 *        Created:  10/20/18 17:47:05
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

#define ELEMENT * 
#define  AMMUNITION  o



static int draw_horizontal_line(int begin , int end)
{
	char horizontal_line[COLS/8];
	int i;
	for (i = 0; i< COLS/8; i++)
	{
		horizontal_line[i] = ELEMENT;
	}
}

static int draw_vertical_line(int begin , int end)
{
	char vertical_line[LINES/8];

}


int initinal()
{
       /** int clear(void); */
	clear();
}
