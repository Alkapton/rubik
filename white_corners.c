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

void white_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx =0, maxy = 0;

	getmaxyx(stdscr, maxy, maxx);
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "White Corners");
	if(top[0] != 1) {
		if(top[2] == 1) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(top[6] == 1) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(top[8] == 1) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(left[0] == 1) {
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(left[2] == 1) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[0] == 1) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[2] == 1) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(right[0] == 1) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		}else if(right[2] == 1) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(back[0] == 1) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(back[2] == 1) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(left[6] == 1) {
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(left[8] == 1) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(front[6] == 1) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(front[8] == 1) {
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(right[6] == 1) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(right[8] == 1) {
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(back[6] == 1) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(back[8] == 1) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(bottom[0] == 1) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(bottom[2] ==  1) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(bottom[6] == 1) {
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(bottom[8] == 1) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		}

	}
	if(top[2] != 21){
		if(top[6] == 21) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(top[8] == 21) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(left[2] == 21) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(front[0] == 21) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(front[2] == 21) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(right[0] == 21) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(right[2] == 21) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[0] == 21) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(left[6] == 21) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(left[8] == 21) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(front[6] == 21) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(front[8] == 21) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(right[6] == 21) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(right[8] == 21) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[6] == 21) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if(back[8] == 21) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[0] == 21) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[2] == 21) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[6] == 21) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[8] == 21) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		}
	}
	if(top[6] != 61) {
		if (top[8] == 61) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(left[2] == 61) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(front[0] == 61) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(front[2] == 61) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(right[0] == 61) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(left[6] == 61) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(left[8] == 61) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(front[6] == 61) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(front[8] == 61) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(right[6] == 61) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(right[8] == 61) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(back[6] == 61) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(back[8] == 61) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(bottom[0] == 61) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(bottom[2] == 61) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(bottom[6] == 61) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(bottom[8] == 61) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		}
	}
	if(top[8] != 81) {
		if(front[2] == 81) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(right[0] == 81) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(left[6] == 81) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(left[8] == 81) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(front[6] == 81) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(front[8] == 81) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(right[6] == 81) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(right[8] == 81) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(back[6] == 81) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(back[8] == 81) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(bottom[0] == 81) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(bottom[2] == 81) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(bottom[6] == 81) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(bottom[8] == 81) {
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		}
	}
}
