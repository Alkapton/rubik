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

#include "rubik.h"

void white_cross(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx = 0, maxy = 0;

	attron(COLOR_PAIR(7));
	getmaxyx(stdscr, maxy, maxx);
	mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "                      ");
	mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "SOLVING CUBE");
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "White Cross           ");
	mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "                ");
	mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "                ");
	mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "               ");
	mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "           ");
	attroff(COLOR_PAIR(7));
	refresh();
	wgetch(stdscr);
	usleep(delay);
	usleep(delay);
	if(!(top[4] == 41)) {
		if(left[4] == 41) {
			front_clockwise(top, bottom, left, right, front);
			slicez_clockwise(top, bottom, left, right);
			back_anticlockwise(top, bottom, left, right, back);
		} else if(front[4] == 41) {
			slicey_clockwise(top, bottom, front, back);
			right_clockwise(top, bottom, right, front, back);
			left_anticlockwise(top, bottom, left, front, back);
		} else if(right[4] == 41) {
			slicez_anticlockwise(top, bottom, left, right);
			front_anticlockwise(top, bottom, left, right, front);
			back_clockwise(top, bottom, left, right, back);
		} else if(back[4] == 41) {
			slicey_anticlockwise(top, bottom, front, back);
			right_anticlockwise(top, bottom, right, front, back);
			left_clockwise(top, bottom, left, front, back);
		} else if(bottom[4] == 41) {
			slicey_clockwise(top, bottom, front, back);
			right_clockwise(top, bottom, right, front, back);
			left_anticlockwise(top, bottom, left, front, back);
			print_cube(top, bottom, left, right, front, back);
			usleep(delay);
			slicey_clockwise(top, bottom, front, back);
			right_clockwise(top, bottom, right, front, back);
			left_anticlockwise(top, bottom, left, front, back);
		}
		print_cube(top, bottom, left, right, front, back);
		usleep(delay);
	}
	if(!(top[1] == 11)) {
		if(top[3] == 11) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if (top[5] == 11) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if (top[7] == 11) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		}
		else if(left[1] == 11){
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[1] == 11) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(right[1] == 11) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[1] == 11) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(left[3] == 11) {
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(left[5] == 11) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[3] == 11) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[5] == 11) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(right[3] == 11) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(right[5] == 11) {
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[3] == 11) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(back[5] == 11) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
		else if(left[7] == 11) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[7] == 11) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(right[7] == 11) { 
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[7] == 11) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		}
		else if(bottom[1] == 11) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 11) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(bottom[5] == 11) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 11) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
	}
	if(!(top[3] == 31)) {
		if(top[5] == 31) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(top[7] == 31) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(left[1] == 31) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(front[1] == 31) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(right[1] == 31) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(left[3] == 31) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(left[5] == 31) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(front[3] == 31) {
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(front[5] == 31) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(right[3] == 31) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(right[5] == 31) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(back[3] == 31) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		}else if(back[5] == 31) {
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(left[7] == 31) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(front[7] == 31) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(right[7] == 31) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(back[7] == 31) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		        cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(bottom[1] == 31) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 31) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(bottom[5] == 31) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 31) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);

		}	
	}
	if(!(top[5] == 51)) {
		if(top[7] == 51) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(front[1] == 51) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(right[1] == 51) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(left[3] == 51) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(left[5] == 51) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(front[3] == 51) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(front[5] == 51) {
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(right[3] == 51) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(right[5] == 51) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(back[3] == 51) {
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(back[5] == 51) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(left[7] == 51) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(front[7] == 51) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(right[7] == 51) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(back[7] == 51) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[1] == 51) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 51) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(bottom[5] == 51) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 51) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		}
	}
	if(!(top[7] == 71)) {
		if(front[1] == 71) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(left[3] == 71) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(left[5] == 71) {
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(front[3] == 71) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(front[5] == 71) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(right[3] == 71) {
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(right[5] == 71) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(back[3] == 71) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(back[5] == 71) {
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(left[7] == 71) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(front[7] == 71) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(right[7] == 71) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(back[7] == 71) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLX_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(bottom[1] == 71) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 71) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(bottom[5] == 71) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 71) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		}
	}
}
