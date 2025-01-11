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

#include <ncurses.h>
#include <unistd.h>
#include <ncurses.h>

#include <signal.h>

#include "rubik.h"

void cmove(int direction, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {
	int maxy = 0, maxx = 0;

	wgetch(stdscr);
	signal(SIGWINCH, do_resize);
	getmaxyx(stdscr, maxy, maxx);
	if(state) {
		print_cube(top, bottom, left, right, front, back);
		mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
		mvprintw(1, (maxx / 2) - 10, "--------------------");
		mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "SOLVING CUBE");
		if((state == 2) ||(state == 43)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "White Cross");
		} else if((state == 3) || (state == 44)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "White Corners");
		} else if((state == 4) || (state == 45)) {	
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Middle Layer");
		} else if((state == 5) || (state == 46)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Yellow Cross");
		} else if((state == 6) || (state == 47)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Yellow Corners");
		} else if((state == 7) || (state == 48)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Orientating Corners");
		} else if((state == 8) || (state == 49)) {
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Last Edges");
		}
		refresh();
	}
	moves++;
	switch(direction) {
		case 1 :
			top_clockwise(top, left, right, front, back);
			break;
		case 2 :
			top_anticlockwise(top, left, right, front, back);
			break;
		case 3 :
			bottom_clockwise(bottom, left, right, front, back);
			break;
		case 4 :
			bottom_anticlockwise(bottom, left, right, front, back);
			break;
		case 5 :
			left_clockwise(top, bottom, left, front, back);
			break;
		case 6 :
			left_anticlockwise(top, bottom, left, front, back);
			break;
		case 7 :
			right_clockwise(top, bottom, right, front, back);
			break;
		case 8:
			right_anticlockwise(top, bottom, right, front, back);
			break;
		case 9: 
			front_clockwise(top, bottom, left, right, front);
			break;
		case 10 :
			front_anticlockwise(top, bottom, left, right, front);
			break;
		case 11 :
			back_clockwise(top, bottom, left, right, back);
			break;
		case 12 :
			back_anticlockwise(top, bottom, left, right, back);
			break;
		case 13 :
			slicex_clockwise(left, right, front, back);
			break;
		case 14 :
			slicex_anticlockwise(left, right, front, back);
			break;
		case 15 :
			slicey_clockwise(top, bottom, front, back);
			break;
		case 16 :
			slicey_anticlockwise(top, bottom, front, back);
			break;
		case 17 :
			slicez_clockwise(top, bottom, left, right);
			break;
		case 18 :
			slicez_anticlockwise(top, bottom, left, right);
			break;
	}
	print_cube(top, bottom, left, right, front, back);
	refresh();


	usleep(delay);

}
