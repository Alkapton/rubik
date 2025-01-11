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

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <ncurses.h>

#include "rubik.h"

void scramble_cube(int smoves, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx = 0, maxy = 0;
	int last_move = 99;
	srand((unsigned int)time(NULL));

	for(int n = 0; n < smoves; n++) {
		wgetch(stdscr);
		signal(SIGWINCH, do_resize);
		state = 0;
		getmaxyx(stdscr, maxy, maxx);
		attron(COLOR_PAIR(7));
		mvprintw(0, 0, "                                         ");
		mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
		mvprintw(1, (maxx / 2) - 10, "--------------------");
		mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "                      ");
		mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "SCRAMBLING CUBE");
		mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "                      ");
		mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "                 ");
		mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "                ");
		mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "               ");
		mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "             ");
		attroff(COLOR_PAIR(7));
		int r = rand() % 18;
		if(r != last_move) {
		    switch(r) {
			case 0 : 
				cmove(TOP_C, top, bottom, left, right, front, back);
				break;
			case 1 : 
				cmove(TOP_A, top, bottom, left, right, front, back);
				break;
			case 2 : 
				cmove(BOT_C, top, bottom, left, right, front, back);
				break;
			case 3 : 
				cmove(BOT_A, top, bottom, left, right, front, back);
				break;
			case 4 : 
				cmove(LEF_C, top, bottom, left, right, front, back);
				break;
			case 5 : 
				cmove(LEF_A, top, bottom, left, right, front, back);
				break;
			case 6 : 
				cmove(RIG_C, top, bottom, left, right, front, back);
				break;
			case 7 : 
				cmove(RIG_A, top, bottom, left, right, front, back);
				break;
			case 8 : 
				cmove(FRO_C, top, bottom, left, right, front, back);
				break;
			case 9 : 
				cmove(FRO_A, top, bottom, left, right, front, back);
				break;
			case 10 : 
				cmove(BAK_C, top, bottom, left, right, front, back);
				break;
			case 11 : 
				cmove(BAK_A, top, bottom, left, right, front, back);
				break;
			case 12 : 
				cmove(SLX_C, top, bottom, left, right, front, back);
				break;
			case 13 : 
				cmove(SLX_A, top, bottom, left, right, front, back);
				break;
			case 14 : 
				cmove(SLY_C, top, bottom, left, right, front, back);
				break;
			case 15 : 
				cmove(SLY_A, top, bottom, left, right, front, back);
				break;
			case 16 : 
				cmove(SLZ_C, top, bottom, left, right, front, back);
				break;
			case 17 : 
				cmove(SLZ_A, top, bottom, left, right, front, back);
				break;
		
		    }
		    // Don't want to make a move and imediately reverse it. 
		    if(r % 2) {
			    last_move = r - 1;
		    } else {
			    last_move = r + 1;
		    }
		} else n--;
	}
	mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "               ");
}
