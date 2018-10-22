/*
* =====================================================================================
*
*       Filename:  bounce.c
*
*    Description:  simulate one-dimensional bounce-ball
* 		Algorithm:
* 				TODO:
* 					use clock (set/getitimer) delay to realize the ball speed control
* 					use curses.h to control the screan scene
* 					use signaction to get the user operator
* 				FUNCTION:
* 					//sucess return 0; fail return -1
* 					int operator(char operator);
* 					int paint(char ball[]);
* 					int set_second(int num_millisecond)
*        Version:  1.0
*        Created:  09/20/18 18:27:28
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

#define rowLeftBoundary 0

#define colUpBoundary  0

#define ball  "o"


int initiate()	;
int paint(char *);
int setDelay(int);
void movestr2(int);
int position;
char * item_blank;
void movestr();
int delay = 200;
int StepLength = 10;

int initiate(){
	clear();
	move(rowLeftBoundary,colUpBoundary);// at upper left point

	for(int i = rowLeftBoundary;i< LINES;  ){
		addstr("#");
		move(i,COLS-1);// at lower left
		addstr("#");
		move(++i,colUpBoundary);
	}
	for(int j =colUpBoundary; j < COLS; ){
		addstr("#");
		move(LINES-1,j);
		addstr("#");
		move(rowLeftBoundary,++j);
	}
	refresh();
}

int paint(char item[]){
	int length = strlen(item);
	void * temp = calloc(length,1);
	item_blank = (char *)temp;// dynamically allocate memory
	for (size_t i = 0; i < length ; i++) {
		item_blank[i] = ' ';
	}
	position = rowLeftBoundary + 1;
	move(LINES/2, position);

	addstr(item);
	refresh();

	// operator
	char operator = getchar();
	signal(SIGALRM,movestr2);

	setDelay(delay);
	while (1) {
		if(operator == 'q'){
			clear();
			exit(0);
		}
		switch (operator) {
			case 'f':
			delay = delay / 2;
			break;
			case 's':
			delay = delay * 2;
			break;
			case ' ':
			StepLength = 0 - StepLength;
			break;
			default:
			move(0,0);
			printf("please input correct !" );
			operator = getchar();
			continue;
		}
		operator = getchar();
	}
	return 0 ;
}
void movestr2(int signum){
	signal(SIGALRM,movestr2);
	char * item = "o";
	if (position >= COLS ) {
		StepLength = -StepLength;
	}
	if (position <=  1) {
		StepLength = -StepLength;
	}
	move(LINES/2,position);
	addstr(item_blank);
	position = position + StepLength;
	refresh();

	move(LINES/2,position);
	addstr(item);
	refresh();
}
int setDelay(int num_millisecond){
	struct itimerval myDelay;
	long n_sec , n_usec;
	n_sec = num_millisecond / 1000;
	n_usec = (num_millisecond%1000) * 1000;
	myDelay.it_interval.tv_sec = n_sec;
	myDelay.it_interval.tv_usec = n_usec;
	myDelay.it_value.tv_sec = n_sec;
	myDelay.it_value.tv_usec = n_usec;
	setitimer(ITIMER_PROF,&myDelay,NULL);
}

int main(){
	initscr();
	noecho();
	crmode();

	initiate();
	signal(SIGALRM, movestr2);
	paint(ball);

	endwin();
}
