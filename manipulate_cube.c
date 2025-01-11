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
#include <signal.h>

#include "rubik.h"

void manipulate_cube(int don, int info, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {
	int ch, resized = 0;
	int maxy = 0, maxx = 0;

		keypad(stdscr, TRUE);
		nodelay(stdscr, TRUE);
	do {
		ch = wgetch(stdscr);
		signal(SIGWINCH, do_resize);
		getmaxyx(stdscr, maxy, maxx);
		if(don) {
			init_pair(1, COLOR_BLACK, COLOR_WHITE);
			init_pair(2, COLOR_BLACK, COLOR_BLUE);
			init_pair(3, COLOR_BLACK, COLOR_RED);
			init_pair(4, COLOR_BLACK, COLOR_GREEN);
			init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
			init_pair(6, COLOR_BLACK, COLOR_YELLOW);
		} else {
			init_pair(1, COLOR_WHITE, COLOR_WHITE);
			init_pair(2, COLOR_BLUE, COLOR_BLUE);
			init_pair(3, COLOR_RED, COLOR_RED);
			init_pair(4, COLOR_GREEN, COLOR_GREEN);
			init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
			init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
		}
		init_pair(7, COLOR_WHITE, COLOR_BLACK);
		mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
		mvprintw(1, (maxx / 2) - 10, "--------------------");
		print_cube(top, bottom, left, right, front, back);
		refresh();
		attron(COLOR_PAIR(7));
		if(info) {
			mvprintw((maxy / 2) - 9, (maxx / 2) - 39, "'1' - Top Clockwise");
      			mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "'2' - Top Anticlockwise");
			mvprintw((maxy / 2) - 7, (maxx / 2) - 39, "'3' - Bottom Clockwise");
			mvprintw((maxy / 2) - 6, (maxx / 2) - 39, "'4' - Bottom Anticlockwise");
			mvprintw((maxy / 2) - 5, (maxx / 2) - 39, "'5' - Left Clockwise");
			mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "'6' - Left Anticlockwise");
			mvprintw((maxy / 2) + 4, (maxx / 2) - 39, "'7' - Right Clockwise");
			mvprintw((maxy / 2) + 5, (maxx / 2) - 39, "'8' - Right Anticlockwise");
			mvprintw((maxy / 2) + 6, (maxx / 2) - 39, "'9' - Front Clockwise");
			mvprintw((maxy / 2) + 7, (maxx / 2) - 39, "'0' - Front Anticlockwise");
			mvprintw((maxy / 2) + 8, (maxx / 2) - 39, "'Q' - Back Clockwise");
			mvprintw((maxy / 2) + 9, (maxx / 2) - 39, "'W' - Back AntiClockwise");
			mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "'E' - SliceX Clockwise");
       			mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "'R' - SliceX Anticlockwise");
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "'T' - SliceY Clockwise");
			mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "'Y' - SliceY Anticlockwise");
			mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "'U' - SliceZ Clockwise");
			mvprintw((maxy / 2) - 4, (maxx / 2) + 4, "'I' - SliceZ Anticlockwise");
			mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'X' - Main Menu");
			mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "Arrow keys rotate entire cube.");
			mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "'L' - Place Labels");
		} else {
                        mvprintw((maxy / 2) - 9, (maxx / 2) - 39, "                   ");
      			mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "                       ");
			mvprintw((maxy / 2) - 7, (maxx / 2) - 39, "                      ");
			mvprintw((maxy / 2) - 6, (maxx / 2) - 39, "                          ");
			mvprintw((maxy / 2) - 5, (maxx / 2) - 39, "                     ");
			mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "                        ");
			mvprintw((maxy / 2) + 4, (maxx / 2) - 39, "                         ");
			mvprintw((maxy / 2) + 5, (maxx / 2) - 39, "                           ");
			mvprintw((maxy / 2) + 6, (maxx / 2) - 39, "                        ");
			mvprintw((maxy / 2) + 7, (maxx / 2) - 39, "                            ");
			mvprintw((maxy / 2) + 8, (maxx / 2) - 39, "                      ");
			mvprintw((maxy / 2) + 9, (maxx / 2) - 39, "                        ");
			mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "                       ");
       			mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "MANIPULATE CUBE           ");
			mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "                      ");
			mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "                          ");
			mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "                        ");
			mvprintw((maxy / 2) - 4, (maxx / 2) + 4, "                           ");
			mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'X' - Main Menu");
			mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "                  ");
			mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'L' - Place Labels            ");
		}
		if(info) attroff(COLOR_PAIR(7));
		refresh();
		if((ch == 'h') || (ch == 'H')) {
			if(info) info = 0;
			else info = 1;
		} 
		if(ch == '1') {
			cmove(TOP_C, top, bottom, left, right, front, back);
		} else if(ch == '2') {
			cmove(TOP_A, top, bottom, left, right, front, back);
		} else if(ch == '3') {
			cmove(BOT_C, top, bottom, left, right, front, back);
		} else if(ch == '4') {
			cmove(BOT_A, top, bottom, left, right, front, back);
		} else if(ch == '5') {
			cmove(LEF_C, top, bottom, left, right, front, back);
		} else if(ch == '6') {
			cmove(LEF_A, top, bottom, left, right, front, back);
		} else if(ch == '7') {
			cmove(RIG_C, top, bottom, left, right, front, back);
		} else if(ch == '8') {
			cmove(RIG_A, top, bottom, left, right, front, back);
		} else if(ch == '9') {
			cmove(FRO_C, top, bottom, left, right, front, back);
		} else if(ch == '0') {
			cmove(FRO_A, top, bottom, left, right, front, back);
		} else if((ch == 'q') || (ch == 'Q')) {
			cmove(BAK_C, top, bottom, left, right, front, back);
		} else if((ch == 'w') || (ch == 'W')) {
			cmove(BAK_A, top, bottom, left, right, front, back);
		} else if((ch == 'e') || (ch == 'E')) {
			cmove(SLX_C, top, bottom, left, right, front, back);
		} else if((ch == 'r') || (ch == 'R')) {
			cmove(SLX_A, top, bottom, left, right, front, back);
		} else if((ch == 't') || (ch == 'T')) {
			cmove(SLY_C, top, bottom, left, right, front, back);
		} else if((ch == 'y') || (ch == 'Y')) {
			cmove(SLY_A, top, bottom, left, right, front, back);
		} else if((ch == 'u') || (ch == 'U')) {
			cmove(SLZ_C, top, bottom, left, right, front, back);
		} else if((ch == 'i') || (ch == 'I')) {
			cmove(SLZ_A, top, bottom, left, right, front, back);
		} else if((ch == 'l') || (ch == 'L')) {
			do {
				resized = label_cube(don, top, bottom, left, right, front, back);
			} while (resized == 43); 
		} else if(ch == 260) {
			top_clockwise(top, left, right, front, back);
			slicex_clockwise(left, right, front, back);
			bottom_anticlockwise(bottom, left, right, front, back);
		} else if(ch == 261) {
			top_anticlockwise(top, left, right, front, back);
			slicex_anticlockwise(left, right, front, back);
			bottom_clockwise(bottom, left, right, front, back);
		} else if(ch == 259) {
			left_anticlockwise(top, bottom, left, front, back);
			slicey_clockwise(top, bottom, front, back);
			right_clockwise(top, bottom, right, front, back);
		} else if(ch == 258) {
			left_clockwise(top, bottom, left, front, back);
			slicey_anticlockwise(top, bottom, front, back);
			right_anticlockwise(top, bottom, right, front, back);
		}
	} while((ch != 'x') && (ch !='X'));
}
