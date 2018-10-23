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
#include "position.h"
#include <pthread.h>

struct POSITION_TANK_WALL POSITION[16] ;
int count_position = 0; // count line (had drawed

struct LINE
{
	int y;
	int x;
	int speed;
};
/*{{{*/
/** static int draw_horizontal_line(int begin , int end) */
/** { */
/**     char horizontal_line[COLS/8]; */
/**     int i; */
/**     for (i = 0; i< COLS/8; i++) */
/**     { */
/**         horizontal_line[i] = ELEMENT; */
/**     } */
/** } */
/**  */
/** static int draw_vertical_line(int begin , int end) */
/** { */
/**     char vertical_line[LINES/8]; */
/**  */
/** } *//*}}}*/

static void * initinate_vline(void * input)// vertical line
{
	struct LINE *line= input;
	int y = line->y;
	int x = line->x;
	int speed = line->speed;
	/** move(row,col);  */
	/** int mvvline(int y, int x, chtype ch, int n); */
	mvvline(y,x,'#',LINES/8);
	refresh();
	usleep(1000 * speed);
	int distance = y;
	int step = LINES/8;
	while(1)
	{
		mvvline(distance,x,' ',LINES/8);
		if(distance+LINES/8 >=LINES)// at button
		{

			step = - LINES/8;
		}
		if(distance <= 0)// at top
		{
			step = LINES/8;
		}
		distance = distance + step;
		mvvline(distance,x,'#',LINES/8);
		POSITION[count_position].x1 = x;
		POSITION[count_position].x2 = x;
		POSITION[count_position].y1 = distance;
		POSITION[count_position].y2 = distance+LINES/8;
		count_position ++;
		usleep(1000 * speed);
		refresh();
	}
}


static void * initinate_hline(void * input)// vertical line
{
	struct LINE *line= input;
	int y = line->y;
	int x = line->x;
	int speed = line->speed;
	/** move(row,col);  */
	/** int mvvline(int y, int x, chtype ch, int n); */
	mvhline(y,x,'#',COLS/8);
	while(1)
	{
		mvvline(y,x,' ',COLS/8);
		mvvline(y,x,'#',COLS/8);
		POSITION[count_position].x1 = x;
		POSITION[count_position].x2 = x+COLS/8;
		POSITION[count_position].y1 = y;
		POSITION[count_position].y2 = y;
		count_position ++;
		usleep(1000/speed);
		refresh();
	}
}
// // debug-1
// int count = 0;
// void * show (void *a)
// {
//     printf("%d\n",count ++);
//     sleep(1);
// }
// //debug -2
static void * draw_line_v(void * input)
{
	int i;
	pthread_t t[7];
	for (i = 0; i < 7; ++i) {
		srand((unsigned)i);
		struct LINE line = {
			.x = i * (COLS/8),
			// void srand(unsigned int seed);
			.y = rand()%LINES,
			.speed = rand()%1000
		};
		/** int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg); */
		pthread_create(&t[i],NULL,initinate_vline,&line);
		// pthread_create(&t[i],NULL,show,NULL);
	}
	while(1);
	for(i = 0;i<7;++i)
	{
		pthread_join(t[i],NULL);
	}
}

static void * draw_line_h(void * line)

{

}


// int main()

//     struct LINE line=
//     {
//         .y = COLS/8;
//         .x = LINES/8;
//         .speed = 1000
//     };
//     initinate_vline(line);
// }
