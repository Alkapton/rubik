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

void middle_layer(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int maxx =0, maxy = 0;

	getmaxyx(stdscr, maxy, maxx);
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "Middle Layer ");
	if(left[4] != 42) {

		if(front[4] == 42) {
			cmove(SLX_C, top, bottom, left, right, front, back);
		} else if(right[4] == 42) {
			cmove(SLX_C, top, bottom, left, right, front, back);
			cmove(SLX_C, top, bottom, left, right, front, back);
		} else if(back[4] == 42) {
			cmove(SLX_A, top, bottom, left, right, front, back);
		}
	}
	if(left[3] != 32) {
		if(back[5] == 32) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if((left[5] == 32) || (front[3] == 32)) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if((front[5] == 32) || (right[3] == 32)) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if((right[5] == 32) || (back[3] == 32)) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
		if(front[7] == 32) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(right[7] == 32) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(back[7] == 32) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[1] == 32) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 32) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(bottom[5] == 32) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		}
		if(left[7] == 32) {
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if(bottom[7] == 32) {
			cmove(LEF_A, top, bottom, left, front, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
		}
		
	}
	if(front[3] != 35) {
		if(left[5] == 35) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if((front[5] == 35) || (right[3] == 35)) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if((right[5] == 35) || (back[3] == 35)) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
		if(left[7] == 35) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(right[7] == 35) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(back[7] == 35) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[1] == 35) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(bottom[5] == 35) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 35) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		}
		if(front[7] == 35) {
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(LEF_C, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(bottom[3] == 35) {
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
		}
	}
	if(right[3] != 34) {
		if(front[5] == 34) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if((right[5] == 34) || (back[3] == 34)) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
		if(left[7] == 34) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(front[7] == 34) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(back[7] == 34) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(bottom[3] == 34) { 
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[5] == 34) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(bottom[7] == 34) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);

		}
		if(right[7] == 34) {
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(FRO_C, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if(bottom[1] == 34) {
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
		}
	}
	if(back[3] != 33) {
		if(right[5] == 33) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
		if(left[7] == 33) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(front[7] == 33) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(right[7] == 33) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[1] == 33) {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[3] == 33) {
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(bottom[7] == 33) {
			cmove(BOT_A, top, bottom, left, right, front, back);
		}
		if(back[7] == 33) {
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLZ_C, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
			cmove(BOT_C, top, bottom, left, right, front, back);
			cmove(RIG_C, top, bottom, left, right, front, back);
			cmove(SLZ_A, top, bottom, left, right, front, back);
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(bottom[5] == 33) {
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_C, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
			cmove(BOT_A, top, bottom, left, right, front, back);
			cmove(BAK_A, top, bottom, left, right, front, back);
			cmove(SLY_A, top, bottom, left, right, front, back);
			cmove(BAK_C, top, bottom, left, right, front, back);
		}
	} 
}
