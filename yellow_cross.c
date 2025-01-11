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

#include "rubik.h"

void yellow_cross(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx = 0, maxy = 0;
	int sides = 0;

	getmaxyx(stdscr, maxy, maxx);
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Yellow Cross");
	do {
		sides = 0;
		if(bottom[1] % 10 == 6) sides++;
		if(bottom[3] % 10 == 6) sides++;
		if(bottom[5] % 10 == 6) sides++;
		if(bottom[7] % 10 == 6) sides++;
		if(sides < 4) {
			if(sides == 0) {
				cmove(BAK_C, top, bottom, left, right, front, back);
				cmove(RIG_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(RIG_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(BAK_A, top, bottom, left, right, front, back);
			} 
			if((bottom[3] % 10 == 6) && (bottom[1] % 10 == 6)) {
				cmove(BAK_C, top, bottom, left, right, front, back);
				cmove(RIG_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(RIG_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(BAK_A, top, bottom, left, right, front, back);
			} else if((bottom[1] % 10 == 6) && (bottom[5] % 10 == 6)) {
				cmove(LEF_C, top, bottom, left, right, front, back);
				cmove(BAK_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(BAK_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(LEF_A, top, bottom, left, right, front, back);
			} else if((bottom[5] % 10 == 6) && (bottom[7] % 10 == 6)) {
				cmove(FRO_C, top, bottom, left, right, front, back);
				cmove(LEF_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(LEF_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(FRO_A, top, bottom, left, right, front, back);
			} else if((bottom[7] % 10 == 6) && (bottom[3] % 10 == 6)) {
				cmove(RIG_C, top, bottom, left, right, front, back);
				cmove(FRO_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(FRO_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(RIG_A, top, bottom, left, right, front, back);
			} else if((bottom[1] % 10 == 6) && (bottom[7] % 10 == 6)) {
				cmove(LEF_C, top, bottom, left, right, front, back);
				cmove(BAK_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(BAK_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(LEF_A, top, bottom, left, right, front, back);
			} else if((bottom[3] % 10 == 6) && (bottom[5] % 10 == 6)) {
				cmove(BAK_C, top, bottom, left, right, front, back);
				cmove(RIG_C, top, bottom, left, right, front, back);
				cmove(BOT_C, top, bottom, left, right, front, back);
				cmove(RIG_A, top, bottom, left, right, front, back);
				cmove(BOT_A, top, bottom, left, right, front, back);
				cmove(BAK_A, top, bottom, left, right, front, back);
			}
		}
	} while (sides != 4);
}
