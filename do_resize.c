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
#include <signal.h>
#include <stdlib.h>

#include "rubik.h"

void do_resize(int dummy) {
	int maxy =0, maxx = 0;

	endwin();
	initscr();
	clear();	
	curs_set(0);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr, maxy, maxx);
	if((maxy < 24) || (maxx < 80)) {
		endwin();
		printf("\nUnfortunately you have made your terminal too small within which to run rubik.\n\n");
		exit(0);
	}
	if(state > 42) {
		mvprintw((maxy / 2) - 1, (maxx / 2) - 25, "Please do not resize the terminal while running rubik.");
		mvprintw((maxy / 2) + 1, (maxx / 2) - 19, "\"It hurts us hobbitis, it hurts us.\"");
		mvprintw((maxy / 2) + 3, (maxx / 2) - 13, "Press any key to continue.");
		state = 1;
	}
	refresh();
	if(!state) state = 1;
}

