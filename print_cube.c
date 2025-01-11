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
#include <ncurses.h>

#include "rubik.h"

void print_cube(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxy = 0, maxx = 0;

	getmaxyx(stdscr, maxy, maxx);
// top
	attron(COLOR_PAIR(top[0] % 10));
	mvprintw((maxy / 2) - 9, (maxx / 2) - 11, " %d ", top[0] / 10 + 1);
	attroff(COLOR_PAIR(top[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(top[1] % 10));
	printw(" %d ", top[1] / 10 + 1);
	attroff(COLOR_PAIR(top[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(top[2] % 10));
	printw(" %d ", top[2] / 10 + 1);
	attroff(COLOR_PAIR(top[2] % 10));

	attron(COLOR_PAIR(top[3] % 10));
	mvprintw((maxy / 2) - 7, (maxx / 2) - 11, " %d ", top[3] / 10 + 1);
	attroff(COLOR_PAIR(top[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(top[4] % 10));
	printw(" %d ", top[4] / 10 + 1);
	attroff(COLOR_PAIR(top[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(top[5] % 10));
	printw(" %d ", top[5] / 10 + 1);
	attroff(COLOR_PAIR(top[5] % 10));

	attron(COLOR_PAIR(top[6] % 10));
	mvprintw((maxy / 2) - 5, (maxx / 2) - 11, " %d ", top[6] / 10 + 1);
	attroff(COLOR_PAIR(top[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(top[7] % 10));
	printw(" %d ", top[7] / 10 + 1);
	attroff(COLOR_PAIR(top[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(top[8] % 10));
	printw(" %d ", top[8] / 10 + 1);
	attroff(COLOR_PAIR(top[8] % 10));
//   BLUE
	attron(COLOR_PAIR(left[0] % 10));
	mvprintw((maxy / 2) - 2, (maxx / 2) - 25, " %d ", left[0] / 10 + 1);
        attroff(COLOR_PAIR(left[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");	
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[1] % 10));
	printw(" %d ", left[1] / 10 + 1);
	attroff(COLOR_PAIR(left[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[2] % 10));
	printw(" %d ", left[2] / 10 + 1);
	attroff(COLOR_PAIR(left[2] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(front[0] % 10));
	printw(" %d ", front[0] / 10 + 1);
	attroff(COLOR_PAIR(front[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[1] % 10));
	printw(" %d ", front[1] / 10 + 1);
	attroff(COLOR_PAIR(front[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[2] % 10));
	printw(" %d ", front[2] / 10 + 1);
	attroff(COLOR_PAIR(front[2] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(right[0] % 10));
	printw(" %d ", right[0] / 10 + 1);
	attroff(COLOR_PAIR(right[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(right[1] % 10));
	printw(" %d ", right[1] / 10 + 1);
	attroff(COLOR_PAIR(right[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	
	attron(COLOR_PAIR(right[2] % 10));
	printw(" %d ", right[2] / 10 + 1);
	attroff(COLOR_PAIR(right[2] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");

	attron(COLOR_PAIR(back[0] % 10));
	printw(" %d ", back[0] / 10 + 1);
	attroff(COLOR_PAIR(back[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[1] % 10));
	printw(" %d ", back[1] / 10 + 1);
	attroff(COLOR_PAIR(back[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[2] % 10));
	printw(" %d ", back[2] / 10 + 1);
	attroff(COLOR_PAIR(back[2] % 10));

	attron(COLOR_PAIR(left[3] % 10));
	mvprintw(maxy / 2, (maxx / 2) - 25, " %d ", left[3] / 10 + 1);
	attroff(COLOR_PAIR(left[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[4] % 10));
	printw(" %d ", left[4] / 10 + 1);
	attroff(COLOR_PAIR(left[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[5] % 10));
	printw(" %d ", left[5] / 10 + 1);
	attroff(COLOR_PAIR(left[5] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(front[3] % 10));
	printw(" %d ", front[3] / 10 + 1);
	attroff(COLOR_PAIR(front[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[4] % 10));
	printw(" %d ", front[4] / 10 + 1);
	attroff(COLOR_PAIR(front[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[5] % 10));
	printw(" %d ", front[5] / 10 + 1);
	attroff(COLOR_PAIR(front[5] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");

	attron(COLOR_PAIR(right[3] % 10));
	printw(" %d ", right[3] / 10 + 1);
	attroff(COLOR_PAIR(right[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(right[4] % 10));
	printw(" %d ", right[4] / 10 + 1);
	attroff(COLOR_PAIR(right[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(right[5] % 10));
	printw(" %d ", right[5] / 10 + 1);
	attroff(COLOR_PAIR(right[5] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(back[3] % 10));
	printw(" %d ", back[3] / 10 + 1);
	attroff(COLOR_PAIR(back[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[4] % 10));
	printw(" %d ", back[4] / 10 + 1);
	attroff(COLOR_PAIR(back[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[5] % 10));
	printw(" %d ", back[5] / 10 + 1);
	attroff(COLOR_PAIR(back[5] % 10));

	attron(COLOR_PAIR(left[6] % 10));
	mvprintw((maxy / 2) + 2, (maxx / 2) - 25, " %d ", left[6] / 10 + 1);
	attroff(COLOR_PAIR(left[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[7] % 10));
	printw(" %d ", left[7] / 10 + 1);
	attroff(COLOR_PAIR(left[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(left[8] % 10));
	printw(" %d ", left[8] / 10 + 1);
	attroff(COLOR_PAIR(left[8] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(front[6] % 10));
	printw(" %d ", front[6] / 10 + 1);
	attroff(COLOR_PAIR(front[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[7] % 10));
	printw(" %d ", front[7] / 10 + 1);
	attroff(COLOR_PAIR(front[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(front[8] % 10));
	printw(" %d ", front[8] / 10 + 1);
	attroff(COLOR_PAIR(front[8] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(right[6] % 10));
	printw(" %d ", right[6] / 10 + 1);
	attroff(COLOR_PAIR(right[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(right[7] % 10));
	printw(" %d ", right[7] / 10 + 1);
	attroff(COLOR_PAIR(right[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(right[8] % 10));
	printw(" %d ", right[8] / 10 + 1);
	attroff(COLOR_PAIR(right[8] % 10));
	attron(COLOR_PAIR(7));
	printw("   ");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(back[6] % 10));
	printw(" %d ", back[6] / 10 + 1);
	attroff(COLOR_PAIR(back[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[7] % 10));
	printw(" %d ", back[7] / 10 + 1);
	attroff(COLOR_PAIR(back[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(back[8] % 10));
	printw(" %d ", back[8] / 10 + 1);
	attroff(COLOR_PAIR(back[8] % 10));

	attron(COLOR_PAIR(bottom[0] % 10));
	mvprintw((maxy / 2) + 5, (maxx / 2) - 11, " %d ", bottom[0] / 10 + 1);
	attroff(COLOR_PAIR(bottom[0] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");	
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[1] % 10));
	printw(" %d ", bottom[1] / 10 + 1);
	attroff(COLOR_PAIR(bottom[1] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[2] % 10));
	printw(" %d ", bottom[2] / 10 + 1);
	attroff(COLOR_PAIR(bottom[2] % 10));

	
	attron(COLOR_PAIR(bottom[3] % 10));
	mvprintw((maxy / 2) + 7, (maxx / 2) - 11, " %d ", bottom[3] / 10 + 1);
	attroff(COLOR_PAIR(bottom[3] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[4] % 10));
	printw(" %d ", bottom[4] / 10 + 1);
	attroff(COLOR_PAIR(bottom[4] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[5] % 10));
	printw(" %d ", bottom[5] / 10 + 1);
	attroff(COLOR_PAIR(bottom[5] % 10));

	attron(COLOR_PAIR(bottom[6] % 10));
	mvprintw((maxy / 2) + 9, (maxx / 2) - 11, " %d ", bottom[6] / 10 + 1);
	attroff(COLOR_PAIR(bottom[6] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[7] % 10));
	printw(" %d ", bottom[7] / 10 + 1);
	attroff(COLOR_PAIR(bottom[7] % 10));
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(bottom[8] % 10));
	printw(" %d ", bottom[8] / 10 + 1);
	attroff(COLOR_PAIR(bottom[8] % 10));
	refresh();
}
