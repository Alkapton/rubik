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

void yellow_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx = 0, maxy = 0;
	int corners = 0;

	getmaxyx(stdscr, maxy, maxx);
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Yellow Corners");
	refresh();

	do {
		corners = 0;
		if(bottom[0] % 10 == 6) corners++;
		if(bottom[2] % 10 == 6) corners++;
		if(bottom[6] % 10 == 6) corners++;
		if(bottom[8] % 10 == 6) corners++;
		if(corners < 4) {
			if(corners == 1) {
				if(bottom[0] % 10 == 6) {
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if(bottom[6] % 10 == 6) {
					cmove(BOT_C, top, bottom, left, right, front, back);
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if(bottom[8] % 10 == 6) {
					cmove(BOT_A, top, bottom, left, right, front, back);
				}
			} else if(corners == 2) {
				if((left[8] % 10 == 6) && (left[6] % 10 != 6)) {
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if((back[8] % 10 == 6) && (back[6] % 10 != 10)) {
					cmove(BOT_C, top, bottom, left, right, front, back);
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if((right[8] % 10 == 6) && (right[6] % 10 != 10)) {
					cmove(BOT_A, top, bottom, left, right, front, back);
				} else if((left[8] % 10 == 6) && (left[6] % 10 == 6)) {
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if((back[8] % 10 == 6) && (back[6] % 10 == 6)) {
					cmove(BOT_C, top, bottom, left, right, front, back);
					cmove(BOT_C, top, bottom, left, right, front, back);
				} else if((right[8] % 10 == 6) && (right[6] % 10 == 6)) {
					cmove(BOT_A, top, bottom, left, right, front, back);
				}
			}
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		}
	} while(corners != 4); 
}
