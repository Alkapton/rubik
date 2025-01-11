/*
# Copyright (C) 2025 Chris Gibbs
#
# This file is part of rubik.
#
#    rubik is free software: you can redistribute it and/or modify 
# it under the terms of the GNU General Public License as 
# published  by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
#    rubik is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
#    You should have received a copy of the GNU General Public
# License along with rubik. If not, see <https://www.gnu.org/
# licenses/>. 
#
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#include "rubik.h"

int delay = 500000;
int moves = 0;
int state = 0;

int main(int argc, char *argv[]) {

	int ch, single_step = 0;
	int maxx = 0, maxy = 0, info = 0, nmoves = 0, smoves = 100;
	int top[9], bottom[9], left[9], right[9], front[9], back[9];
	int dswap = 0, don = 0;
	int base = 10;
	char *endptr;
	long val;

	initscr();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	srand((unsigned int)time(NULL));

	if(!(has_colors())) {
		printf("\nAborting - Terminal not capable of displaying colours.\n\n");
		getch();
		endwin();
		exit(1);
	}
	
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	if(argc > 1) {
	    for(int n = 1; n < argc; n++) {
		if (!strcmp(argv[n], "-n")) {
			dswap = 1;
		} else if(!strcmp(argv[n], "-t")) {
			if(argc == n + 1) {
				endwin();
				printf("\n-t requires a time to deay moves.\n\n");
				exit(0);
			}
			val = strtol(argv[n + 1], &endptr, base);
			if((errno == 0) && (endptr != argv[n + 1]) && (*endptr == '\0')) {
				delay = val * 1000;
				n++;
			} else {
				endwin();
				printf("\n Invalid time given.\n\n");
				exit(0);
			}
		} else if(!strcmp(argv[n], "-r")) {
			if(argc == n + 1) {
				endwin();
				printf("\n '-r' requires a number of moves to sramble the cube.\n\n");
				exit(0);
			}
			val = strtol(argv[n + 1], &endptr, base);
			if((errno == 0) && (endptr != argv[n + 1]) && (*endptr == '\0')) {
				smoves = val;
				n++;
			} else {
				endwin();
				printf("\n Invalid number of moves to scramble.\n\n");
				exit(0);
			}
		} else if(!strcmp(argv[n], "-v")) {
			endwin();
			printf("\nRubik Cube Simulator Version 1.0\n\n");
			exit(0);
		} else if(!strcmp(argv[n], "-i")) {
			info = 1;
		} else if(!strcmp(argv[n], "-h") || !strcmp(argv[n], "-?")) {
			endwin();
			printf("\n RUBIK CUBE SIMULATOR V. 1.0\n\n");
			printf("   -h, -?      - Display this help.\n");
			printf("   -i          - Display manipulation keys.\n");
			printf("   -n          - Display position numbers on 'labels'.\n");
			printf("   -p          - Display the number of moves taken to solve the cube.\n");
			printf("   -r nnn      - Set number of moves to scramble the cube.  Defaults to 100.\n");
			printf("   -s          - Single step through solutions.\n");
			printf("   -t nnn.nnn  - Set delay in milliseconds for each 'move'.  Defaults to 500.\n");
			printf("   -v          - Display version.\n\n");
			exit(0);
		} else if(!strcmp(argv[n], "-p")) {
			nmoves = 1;
		} else if(!strcmp(argv[n], "-s")) {
			single_step = 1;
		} else {
			endwin();
			printf("\n Invalid option given:\n     rubik -h\n\n");
			exit(0);
		}
	    }
	}
	getmaxyx(stdscr, maxy, maxx);
	if((maxy < 24) || (maxx < 80)) {
		endwin();
		printf("\nYour terminal is too small within which to run rubik.  Sorry.\n\n");
		return(0);
	}
	init_cube(top, bottom, left, right, front, back);
        do {
		ch = wgetch(stdscr);	
		signal(SIGWINCH, do_resize);
		getmaxyx(stdscr, maxy, maxx);
		init_pair(7, COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR(7));
		mvprintw(0, 0, "                                             ");
		mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
		attroff(COLOR_PAIR(6));
		mvprintw(1, (maxx / 2) - 10, "--------------------");
		attroff(COLOR_PAIR(7));
		if(dswap) {
			endwin();
			initscr();
			noecho();
			curs_set(0);
			nodelay(stdscr, TRUE);
			if(!don) {     
				init_pair(1, COLOR_BLACK, COLOR_WHITE);
				init_pair(2, COLOR_BLACK, COLOR_BLUE);
				init_pair(3, COLOR_BLACK, COLOR_RED);
				init_pair(4, COLOR_BLACK, COLOR_GREEN);
				init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
				init_pair(6, COLOR_BLACK, COLOR_YELLOW);
				don = 1;
			} else {
				init_pair(1, COLOR_WHITE, COLOR_WHITE);
				init_pair(2, COLOR_BLUE, COLOR_BLUE);
				init_pair(3, COLOR_RED, COLOR_RED);
				init_pair(4, COLOR_GREEN, COLOR_GREEN);
				init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
				init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
				don = 0;
			}
			init_pair(7, COLOR_WHITE, COLOR_BLACK);
			dswap = 0;
		}
		attron(COLOR_PAIR(7));
		mvprintw(2, (maxx / 2) - 34, "                                                                     ");
		mvprintw(3, 3, "                                      ");
		mvprintw(4, 3, "                                      ");
		mvprintw(10, (maxx / 2) - 49, "                        ");
		mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "'M' - Manipulate Cube ");
		mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "                          ");
		mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "'S' - Scramble Cube   ");
		mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "                          ");
		mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "'Z' - Solve Cube      ");
		mvprintw((maxy / 2) - 4, (maxx / 2) + 4, "                          "); 
		mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'R' - Reset Cube                 ");
		mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "'G' - Play Game       	");
		mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'X' - Exit                      ");
		mvprintw((maxy / 2) - 11, (maxx / 2) - 39, "                   ");
		mvprintw((maxy / 2) - 10, (maxx / 2) - 39, "                       ");
		mvprintw((maxy / 2) - 9, 3, "                           ");
		mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "                        ");
		mvprintw((maxy / 2) - 7, 1, "                       ");
		mvprintw((maxy / 2) - 6, 1, "                                  ");
		mvprintw((maxy / 2) - 5, 1, "                        ");
		mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "                          ");
		mvprintw((maxy / 2) + 4, (maxx / 2) - 39, "                        ");
		mvprintw((maxy / 2) + 5, 3, "                                  ");
		mvprintw((maxy / 2) + 6, (maxx / 2) - 39, "                        ");
		mvprintw((maxy / 2) + 7, 1, "                           ");
	       	mvprintw((maxy / 2) + 8, 1, "                          ");
		mvprintw((maxy / 2) + 9, (maxx / 2) - 39, "                          ");
		attroff(COLOR_PAIR(7));
		print_cube(top, bottom, left, right, front, back);
		refresh();
		ch = wgetch(stdscr);
		if((ch == 'm') || (ch == 'M')) {
			manipulate_cube(don, info, top, bottom, left, right, front, back);
			refresh();
		} else if((ch == 'r') || (ch == 'R')) {
			init_cube(top, bottom, left, right, front, back);
			print_cube(top, bottom, left, right, front, back);
		} else if((ch == 's') || (ch == 'S')) {
			scramble_cube(smoves, top, bottom, left, right, front, back);
			print_cube(top, bottom, left, right, front, back);
		} else if((ch == 'z') || (ch == 'Z')) {
			if(single_step) nodelay(stdscr, FALSE);
		     	moves = 0;
			if(single_step) state = 43;
			else state = 2;
			white_cross(top, bottom, left, right, front, back);
			if(single_step) state = 44;
			else state = 3;
			white_corners(top, bottom, left, right, front, back);
			if(single_step) state = 45;
			else state = 4;
			middle_layer(top, bottom, left, right, front, back);
			if(single_step) state = 46;
			else state = 5;
			yellow_cross(top, bottom, left, right, front, back);
			if(single_step) state = 47;
			else state = 6;
			yellow_corners(top, bottom, left, right, front, back);
			if(single_step) state = 48;
			else state = 7;
			orientate_corners(top, bottom, left, right, front, back);
			if(single_step) state = 49;
else state = 8;
			last_edges(top, bottom, left, right, front, back);
			state = 0;
			if(nmoves) {
				attron(COLOR_PAIR(7));
				mvprintw(maxy - 1, (maxx / 2) - 29, "Cube solved in %d moves.       Press any key to continue.", moves);
				attroff(COLOR_PAIR(7));
				refresh();
				state = 43;
				nodelay(stdscr, FALSE);
				ch = wgetch(stdscr);
				signal(SIGWINCH, do_resize);
				nodelay(stdscr, TRUE);
				state = 0;
				clear();
				refresh();
			}
			if(single_step) nodelay(stdscr, TRUE);
		} else if((ch == 'p') || (ch == 'P')) {
			if(nmoves == 1) nmoves = 0;
			else nmoves = 1;
		} else if((ch == 'd') || (ch == 'D')) {
			dswap = 1;
		} else if((ch == 'G') || (ch =='g')) {
			game(don, info, top, bottom, left, right, front, back);
		} else if(ch == ' ') {
			if(single_step) single_step = 0;
			else single_step = 1;
		}
	} while((ch != 'x') && (ch != 'X'));
	clear();
	refresh();
	endwin();
	return(0);
}
