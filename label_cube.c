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

#include "rubik.h"

int label_cube(int don, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int ch, errors = 0, end = 0;
	int maxy = 0, maxx = 0, count;
	int times = 0;

	if(!don) {
		init_pair(1, COLOR_BLACK, COLOR_WHITE);
		init_pair(2, COLOR_BLACK, COLOR_BLUE);
		init_pair(3, COLOR_BLACK, COLOR_RED);
		init_pair(4, COLOR_BLACK, COLOR_GREEN);
		init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
		init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	}
	clear();
	getmaxyx(stdscr, maxy, maxx);
	curs_set(1);
	nodelay(stdscr, FALSE);
	keypad(stdscr, TRUE);
	attron(COLOR_PAIR(7));
	mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
	mvprintw(1, (maxx / 2) - 10, "--------------------");
	mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "PLACE LABELS");
	mvprintw((maxy / 2) - 9, (maxx / 2) - 39, "'1' - White");
	mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "'2' - Blue");
	mvprintw((maxy / 2) - 7, (maxx / 2) - 39, "'3' - Red");
	mvprintw((maxy / 2) - 6, (maxx / 2) - 39, "'4' - Green");
	mvprintw((maxy / 2) - 5, (maxx / 2) - 39, "'5' - Orange");
	mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "'6' - Yellow");
	do {
		curs_set(1);
		if(!times) {
			mvprintw((maxy / 2) - 9, (maxx / 2) - 11, " o   o   o ");
			mvprintw((maxy / 2) - 7, (maxx / 2) - 11, " o   o   o ");
			mvprintw((maxy / 2) - 5, (maxx / 2) - 11, " o   o   o ");
			mvprintw((maxy / 2) - 2, (maxx / 2) - 25, " o   o   o     o   o   o     o   o   o     o   o   o ");
			mvprintw(maxy / 2, (maxx / 2) - 25, " o   o   o     o   o   o     o   o   o     o   o   o ");
			mvprintw((maxy / 2) + 2, (maxx / 2) - 25, " o   o   o     o   o   o     o   o   o     o   o   o ");
			mvprintw((maxy / 2) + 5, (maxx / 2) - 11, " o   o   o ");
			mvprintw((maxy / 2) + 7, (maxx / 2) - 11, " o   o   o ");
			mvprintw((maxy / 2) + 9, (maxx / 2) - 11, " o   o   o ");
			refresh();
		} else {
			mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "Press Space or Right Arrow");
			mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "to skip to next label");
			attron(COLOR_PAIR(top[0]));
			mvprintw((maxy / 2) - 9, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(top[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[1]));
			printw(" o ");
			attroff(COLOR_PAIR(top[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[2]));
			printw(" o ");
			attroff(COLOR_PAIR(top[2]));

			attron(COLOR_PAIR(top[3]));
			mvprintw((maxy / 2) - 7, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(top[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[4]));
			printw(" o ");
			attroff(COLOR_PAIR(top[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[5]));
			printw(" o ");
			attroff(COLOR_PAIR(top[5]));
	
			attron(COLOR_PAIR(top[6]));
			mvprintw((maxy / 2) - 5, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(top[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[7]));
			printw(" o ");
			attroff(COLOR_PAIR(top[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(top[8]));
			printw(" o ");
			attroff(COLOR_PAIR(top[8]));

			attron(COLOR_PAIR(left[0]));
			mvprintw((maxy / 2) - 2, (maxx / 2) - 25, " o ");
			attroff(COLOR_PAIR(left[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[1]));
			printw(" o ");
			attroff(COLOR_PAIR(left[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[2]));
			printw(" o ");
			attroff(COLOR_PAIR(left[2]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(front[0]));
			printw(" o ");
			attroff(COLOR_PAIR(front[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[1]));
			printw(" o ");
			attroff(COLOR_PAIR(front[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[2]));
			printw(" o ");
			attroff(COLOR_PAIR(front[2]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(right[0]));
			printw(" o ");
			attroff(COLOR_PAIR(right[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[1]));
			printw(" o ");
			attroff(COLOR_PAIR(right[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[2]));
			printw(" o ");
			attroff(COLOR_PAIR(right[2]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(back[0]));
			printw(" o ");
			attroff(COLOR_PAIR(back[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[1]));
			printw(" o ");
			attroff(COLOR_PAIR(back[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[2]));
			printw(" o ");
			attroff(COLOR_PAIR(back[2]));

			attron(COLOR_PAIR(left[3]));
			mvprintw(maxy / 2, (maxx / 2) - 25, " o ");
			attroff(COLOR_PAIR(left[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[4]));
			printw(" o ");
			attroff(COLOR_PAIR(left[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[5]));
			printw(" o ");
			attroff(COLOR_PAIR(left[5]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(front[3]));
			printw(" o ");
			attroff(COLOR_PAIR(front[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[4]));
			printw(" o ");
			attroff(COLOR_PAIR(front[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[5]));
			printw(" o ");
			attroff(COLOR_PAIR(front[5]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(right[3]));
			printw(" o ");
			attroff(COLOR_PAIR(right[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[4]));
			printw(" o ");
			attroff(COLOR_PAIR(right[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[5]));
			printw(" o ");
			attroff(COLOR_PAIR(right[5]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(back[3]));
			printw(" o ");
			attroff(COLOR_PAIR(back[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[4]));
			printw(" o ");
			attroff(COLOR_PAIR(back[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[5]));
			printw(" o ");
			attroff(COLOR_PAIR(back[5]));

			attron(COLOR_PAIR(left[6]));
			mvprintw((maxy / 2) + 2, (maxx / 2) - 25, " o ");
			attroff(COLOR_PAIR(left[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[7]));
			printw(" o ");
			attroff(COLOR_PAIR(left[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(left[8]));
			printw(" o ");
			attroff(COLOR_PAIR(left[8]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(front[6]));
			printw(" o ");
			attroff(COLOR_PAIR(front[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[7]));
			printw(" o ");
			attroff(COLOR_PAIR(front[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(front[8]));
			printw(" o ");
			attroff(COLOR_PAIR(front[8]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(right[6]));
			printw(" o ");
			attroff(COLOR_PAIR(right[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[7]));
			printw(" o ");
			attroff(COLOR_PAIR(right[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(right[8]));
			printw(" o ");
			attroff(COLOR_PAIR(right[8]));
			attron(COLOR_PAIR(7));
			printw("   ");
			attroff(COLOR_PAIR(7));

			attron(COLOR_PAIR(back[6]));
			printw(" o ");
			attroff(COLOR_PAIR(back[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[7]));
			printw(" o ");
			attroff(COLOR_PAIR(back[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(back[8]));
			printw(" o ");
			attroff(COLOR_PAIR(back[8]));

			attron(COLOR_PAIR(bottom[0]));
			mvprintw((maxy / 2) + 5, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(bottom[0]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[1]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[1]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[2]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[2]));

			attron(COLOR_PAIR(bottom[3]));
			mvprintw((maxy / 2) + 7, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(bottom[3]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[4]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[4]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[5]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[5]));

			attron(COLOR_PAIR(bottom[6]));
			mvprintw((maxy / 2) + 9, (maxx / 2) - 11, " o ");
			attroff(COLOR_PAIR(bottom[6]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[7]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[7]));
			attron(COLOR_PAIR(7));
			printw(" ");
			attroff(COLOR_PAIR(7));
			attron(COLOR_PAIR(bottom[8]));
			printw(" o ");
			attroff(COLOR_PAIR(bottom[8]));	
	   	}
		state = 43;
		count = 0;
		for(int y = (maxy / 2) - 9; y < (maxy / 2) - 3; y = y + 2) {
			for(int x = (maxx / 2) - 10; x < (maxx / 2) - 1; x = x + 4) {
				do {
					ch = mvgetch(y, x);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
				} while((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5') && (ch != '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(top[count]));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(top[count]));
				} else {
					ch = ch - 48;	
					top[count] = ch;
					attron(COLOR_PAIR(ch));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(ch));
				}
				count++;
		       }
		}
		count = 0;
		for(int y = (maxy / 2) - 2; y < (maxy / 2) + 4; y = y + 2) {
		       for(int x = (maxx / 2) - 24; x < (maxx / 2) - 14; x = x + 4) {
				do {
					ch = mvgetch(y, x);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
				} while((ch != '1') && (ch != '2') && (ch != '3') && (ch == '4') && (ch == '5') && (ch == '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(left[count]));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(left[count]));
				} else {
					ch = ch - 48;
					left[count] = ch;
					attron(COLOR_PAIR(ch));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(ch));
				}
				count++;
		       }
		}
		count = 0;
		for(int y = (maxy / 2) - 2; y < (maxy / 2) + 4; y = y + 2) {
			for(int x = (maxx / 2) - 10; x < maxx / 2; x = x + 4) {
				do {
					ch = mvgetch(y, x);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
				} while((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5') && (ch != '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(front[count]));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(front[count]));
				} else {
					ch = ch - 48;
					front[count] = ch;
					attron(COLOR_PAIR(ch));
					mvprintw(y, x - 1, "   ");
					attroff(COLOR_PAIR(ch));
				}
				count++;	
			}
		}
		count = 0;
		for(int y = (maxy / 2) - 2; y < (maxy / 2) + 4; y = y + 2) {
	 		for(int x = (maxx / 2) + 3; x < (maxx / 2) + 13; x = x + 4) {
	 			do {
	 				ch = mvgetch(y, x + 1);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
	 			} while((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5') && (ch != '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(right[count]));
					mvprintw(y, x, "   ");
					attroff(COLOR_PAIR(right[count]));
				} else {
					ch = ch - 48;
	 				right[count] = ch;
	 				attron(COLOR_PAIR(ch));
	 				mvprintw(y, x, "   ");
	 				attroff(COLOR_PAIR(ch));
				}
	 			count++;
	 		}
		}
		count = 0;
		for(int y = (maxy / 2) - 2; y < (maxy / 2) + 4; y = y + 2) {
			for(int x = (maxx / 2) + 17; x < (maxx / 2) + 26; x = x + 4) {
				do {
					ch = mvgetch(y, x + 1);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
				} while((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5') && (ch != '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(back[count]));
					mvprintw(y, x, "   ");
					attroff(COLOR_PAIR(back[count]));
				} else {
					ch = ch - 48;
					back[count] = ch;
					attron(COLOR_PAIR(ch));
					mvprintw(y, x, "   ");
					attroff(COLOR_PAIR(ch));
				}
				count++;
			}
		}
		count = 0;
		for(int y = (maxy / 2) + 5; y < (maxy / 2) + 10; y = y + 2) {
			for(int x = (maxx / 2) - 11; x < (maxx / 2); x = x + 4) {
				do {
					ch = mvgetch(y, x + 1);
					signal(SIGWINCH, do_resize);
					if(state == 1) return(43);
					if(times && ((ch == 32) || (ch == 261))) ch = 923;
				} while((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5') && (ch != '6') && (ch != 923));
				if(ch == 923) {
					attron(COLOR_PAIR(bottom[count]));
					mvprintw(y, x, "   ");
					attroff(COLOR_PAIR(bottom[count]));
				} else {
					ch = ch - 48;
					bottom[count] = ch;
					attron(COLOR_PAIR(ch));
					mvprintw(y, x, "   ");
					attroff(COLOR_PAIR(ch));
				}
				count++;
		       }
		}
		curs_set(0);
		mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "                              ");
		mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "                              ");
		nodelay(stdscr, FALSE);
		errors = validate_cube(don, top, bottom, left, right, front, back);
		
		if(errors) {
			if(errors == 1) {
				mvprintw(maxy - 1, (maxx / 2) - 29, "ERROR:- There must be 9 labels of each colour on the cube.");
			} else if(errors == 7) {
				mvprintw(maxy - 1, (maxx / 2) - 23, "ERROR:- There must be one center of each colour.");
			} else if(errors == 2) {
				mvprintw(maxy - 1, (maxx / 2) - 24, "ERROR:- Opposite centers are incorrect.");	
			} else if(errors == 3) {
				mvprintw(maxy - 1, (maxx / 2) - 22, "ERROR:- The corners are labeled incorrectly.");
			} else if(errors == 4) {
				mvprintw(maxy - 1, (maxx / 2) - 21, "ERROR:- The edges are labeled incorrectly.");
			} else if(errors == 5) {
				mvprintw(maxy - 1, (maxx / 2) - 29, "ERROR:- A corner is twisted makeing a solution impossible.");
			} else if(errors == 6) {
				mvprintw(maxy - 1, (maxx / 2) - 29, "ERROR:- An edge has been rotated making a solution impossible.");
			}
			mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "Press any key to try again");
			mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'Q' - Return to Cube Manipulation");
			refresh();
			ch = getch();
			signal(SIGWINCH, do_resize);
			if(state == 1) return(43);
			if((ch == 'q') || (ch == 'Q')) {
				end = 1;
			} else {
				for(int n = 0; n < 9; n++) {
					top[n] = top[n] % 10;
					bottom[n] = bottom[n] % 10;
					left[n] = left[n] % 10;
					right[n] = right[n] % 10;
					front[n] = front[n] % 10;
					back[n] = back[n] % 10;	
				}
				times = 1;
			}
			mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "                           ");
			mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "                                  ");
			mvprintw(maxy - 1, (maxx / 2) - 29, "                                                              ");
		}
	} while(errors && !end);
	if(errors) init_cube(top, bottom, left, right, front, back);
	print_cube(top, bottom, left, right, front, back);
	nodelay(stdscr, TRUE);
	if(!don) {
		init_pair(1, COLOR_WHITE, COLOR_WHITE);
		init_pair(2, COLOR_BLUE, COLOR_BLUE);
		init_pair(3, COLOR_RED, COLOR_RED);
		init_pair(4, COLOR_GREEN, COLOR_GREEN);
		init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
		init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	}
	state = 0;
	return(0);
}
