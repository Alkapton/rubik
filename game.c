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
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <string.h>
#include <time.h>

#include "rubik.h"

void game(int don, int info, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	time_t nseconds, mseconds;

	int seconds, minuites, hours;
	int fseconds, fminuites, fhours;
	struct scores the_scores;

	int to[9], bo[9], le[9], ri[9], fr[9], ba[9];
	int c_moves, p_moves, old_delay;
	int maxx = 0, maxy = 0;
	int ch, end = 0, stateis = 0;
	int p_score, c_score;
	
	char hostname[1024];
	char *username, *place, the_place[1024], p_dir[1024];
	
	struct passwd *pw = getpwuid(getuid());
	struct stat st = {0};
	char player_home[1024]; 
        const char *homedir;
       
	homedir = pw->pw_dir;	

	hostname[1024] = '\0';
	strcpy(player_home, homedir);
	gethostname(hostname, 1023);
	username = getlogin();
//	This disgusting kludge is needed because if this program is run under Microcrap's
//	'Windows Services for Linux' there is no means to get the user name.  So we get
//	users home directory and strip the leading part to hopefully get the users name.
//	UGGGG disgusting!   Yes compiler, I actually do mean what I say!!!
	if(!username) {
		place = strrchr(homedir, '/');
		memcpy(the_place, place + 1, sizeof(place));
		username = the_place;
	}

	if (stat(p_dir, &st) == -1) {
		strcpy(p_dir, player_home);
		strcat(player_home, "/.rubik");
		mkdir(player_home, 0700);
	} 
	chdir(player_home);

	the_scores = read_scores();
	c_score = the_scores.c_scores;
	p_score = the_scores.p_scores;
	fhours = the_scores.hours;
	fminuites = the_scores.minuites;
	fseconds = the_scores.minuites;

	old_delay = delay;
	delay = 10;
	getmaxyx(stdscr, maxy, maxx);
	attron(COLOR_PAIR(7));
	mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "                ");
	mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "                ");
	mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "                "); 

	do {
		nodelay(stdscr, TRUE);
		scramble_cube(75, top, bottom, left, right, front, back);

		for(int n = 0; n < 9; n++) {
			to[n] = top[n];
			bo[n] = bottom[n];
			le[n] = left[n];
			ri[n] = right[n];
			fr[n] = front[n];
			ba[n] = back[n];
		}
		moves = 0;		
		white_cross(top, bottom, left, right, front, back);
		white_corners(top, bottom, left, right, front, back);
		middle_layer(top, bottom, left, right, front, back);
		yellow_cross(top, bottom, left, right, front, back);
		yellow_corners(top, bottom, left, right, front, back);
		orientate_corners(top, bottom, left, right, front, back);
		last_edges(top, bottom, left, right, front, back);
		mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "            ");
		mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "           ");
		for(int n = 0; n < 9; n++) {
			top[n] = to[n];
			bottom[n] = bo[n];
			left[n] = le[n];
			right[n] = ri[n];
			front[n] = fr[n];
			back[n] = ba[n];
		}
		print_cube(top, bottom, left, right, front, back);
		c_moves = moves;
		p_moves = 0;
		mvprintw(maxy - 1, (maxx / 2) - 34, "I can solve this scramble in %d moves.   How many will it take you?", moves); 
		nseconds = time(NULL);

		keypad(stdscr, TRUE);
		if(strlen(hostname) > 10) hostname[11] = '\0';
		if(strlen(username) > 7) username[8] = '\0';

		do {
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
			attron(COLOR_PAIR(7));
			if(info) {
				mvprintw((maxy / 2) - 9, 3, "      ");
				mvprintw((maxy / 2) - 7, 1, "                                ");
				mvprintw((maxy / 2) - 6, 1, "                                ");
				mvprintw((maxy / 2) - 5, 1, "                                ");
				mvprintw((maxy / 2) + 5, 3, "                    ");
				mvprintw((maxy / 2) + 7, 1, "                                ");
				mvprintw((maxy / 2) + 8, 1, "                                ");
				mvprintw((maxy / 2) - 9, (maxx / 2) - 39, "'1' - Top Clockwise");
				mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "'2' - Top Anticlockwise");
				mvprintw((maxy / 2) - 7, (maxx / 2) - 39, "'3' - Bottom Clockwise");
				mvprintw((maxy / 2) - 6, (maxx / 2) - 39, "'4' - Bottom Anticlockwise");
				mvprintw((maxy / 2) - 5, (maxx / 2) - 39, "'5' - Left Clockwise    ");
				mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "'6' - Left AntiClockwise");
				mvprintw((maxy / 2) + 4, (maxx / 2) - 39, "'7' - Right Clockwise");
				mvprintw((maxy / 2) + 5, (maxx / 2) - 39, "'8' - Right Anticlockwise");
				mvprintw((maxy / 2) + 6, (maxx / 2) - 39, "'9' - Front Clockwise");
				mvprintw((maxy / 2) + 7, (maxx / 2) - 39, "'0' - Front Anticlockwise");
				mvprintw((maxy / 2) + 8, (maxx / 2) - 39, "'Q' - Back Clockwise");
				mvprintw((maxy / 2) + 9, (maxx / 2) - 39, "'W' - Back Anticlockwise");
				mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "'E' - SliceX Clockwise");
				mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "'R' - SliceX Anticlockwise");
				mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "'T' - SliceY Clockwise");
				mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "'Y' - SliceY Anticlockwise");
				mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "'U' - SliceZ Clockwise");
				mvprintw((maxy / 2) - 4, (maxx / 2) + 4, "'I' - SliceZ Anticlockwise");
				mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "Arrow Keys Rotate Entire Cube    ");
				mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "'F' - Cube Solved and Positioned");
			} else {
				mvprintw((maxy / 2) - 9, (maxx / 2) - 39, "                    ");
				mvprintw((maxy / 2) - 8, (maxx / 2) - 39, "                        ");
				mvprintw((maxy / 2) - 7, (maxx / 2) - 39, "                       ");
				mvprintw((maxy / 2) - 6, (maxx / 2) - 39, "                           ");
				mvprintw((maxy / 2) - 5, (maxx / 2) - 39, "                      ");
				mvprintw((maxy / 2) - 4, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) + 4, (maxx / 2) - 39, "                         ");
			       	mvprintw((maxy / 2) + 5, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) + 6, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) + 7, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) + 8, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) + 9, (maxx / 2) - 39, "                          ");
				mvprintw((maxy / 2) - 9, (maxx / 2) + 4, "                           ");
				mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "GAME MODE                  ");
				mvprintw((maxy / 2) - 7, (maxx / 2) + 4, "                           ");
				mvprintw((maxy / 2) - 6, (maxx / 2) + 4, "                           ");
				mvprintw((maxy / 2) - 5, (maxx / 2) + 4, "                           ");
				mvprintw((maxy / 2) - 4, (maxx / 2) + 4, "                           ");
				mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'F' - Cube Solved and Positioned");
				mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "                                ");
				mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'A' - Cowardly Abort Your Solve   ");
			}
			if(info) {
				mvprintw(8, (maxx / 2) - 49, "         ");
				mvprintw(7, (maxx / 2) - 49, "         ");
				mvprintw((maxy / 2) + 7, (maxx / 2) - 49, "          ");
				mvprintw((maxy / 2) + 8, (maxx / 2) - 49, "          ");
				attroff(COLOR_PAIR(7));
			} else {
				mvprintw((maxy / 2) - 9, 3, "Scores");
				mvprintw((maxy / 2) - 7, 1, "%s: %d", hostname, c_score);
				mvprintw((maxy / 2) - 6, 1, "%s: %d", username, p_score);
				if((fhours == 0) && (fminuites == 0) && (fseconds == 0)) mvprintw((maxy / 2) - 5, 1, "Fastest time - __:__:__");
				else mvprintw((maxy / 2) - 5, 1, "Fastest time - %d:%02d:%02d", fhours, fminuites, fseconds);
				mvprintw((maxy / 2) + 5, 3, "This Scramble");
				mvprintw((maxy / 2) + 8, 1, "%s has taken %d moves.", username, p_moves);
				mvprintw((maxy / 2) + 7, 1, "%s took %d moves.", hostname, c_moves);
			}
			refresh();
			nodelay(stdscr, TRUE);
			ch = getch();
			signal(SIGWINCH, do_resize);
			if(state) {
				mvprintw((maxy / 2) - 9, 3, "      ");
				mvprintw((maxy / 2) - 7, 1, "                             ");
				mvprintw((maxy / 2) - 6, 1, "                             ");
				mvprintw((maxy / 2) - 5, 1, "                             ");
				mvprintw((maxy / 2) + 5, 3, "                              ");
				mvprintw((maxy / 2) + 7, 1, "                              ");
				mvprintw((maxy / 2) + 8, 1, "                              ");
				getmaxyx(stdscr, maxy, maxx);
				print_cube(top, bottom, left, right, front, back);
				mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
				mvprintw(1, (maxx / 2) - 10, "--------------------");
				mvprintw(maxy - 1, (maxx / 2) - 34, "I can solve this scramble in %d moves.   How many will it take you?", moves);
			       if(!info) {	
					if((fhours == 0) && (fminuites == 0) && (fseconds == 0)) mvprintw((maxy / 2) - 5, 1, "Fastest time - __:__:__");
					else mvprintw((maxy / 2) - 5, 1, "Fastest time - %d:%02d:%02d, fhours, fminuites, fseconds");
					mvprintw((maxy / 2) + 5, 3, "This Scramble");
					mvprintw((maxy / 2) + 8, 1, "%s has taken %d moves.", username, p_moves);
					mvprintw((maxy / 2) + 7, 1, "%s took %d moves.", hostname, c_moves);
					mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'A' - Cowardly Abort Your Solve");
					mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'F' - Cube Solved and Positioned");
				} else {
					mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'A' - Cowardly Abort Your Solve");
					mvprintw((maxy / 2) + 7, (maxx / 2) + 4, "'F' - Cube Solved and Positioned");
				}
				refresh();
				state = 0;
			}
			if((ch == 'a') || (ch == 'A') || (ch =='f') || (ch == 'F')) end = 1;
			else if((ch == 'h') || (ch == 'H')) {
				if(info) info = 0;
				else info = 1;
			} else if(ch == '1') {
				top_clockwise(top, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '2') {
				top_anticlockwise(top, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '3') {
				bottom_clockwise(bottom, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '4') {
				bottom_anticlockwise(bottom, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '5') {
				left_clockwise(top, bottom, left, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '6') {
				left_anticlockwise(top, bottom, left, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '7') {
				right_clockwise(top, bottom, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '8') {
				right_anticlockwise(top, bottom, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '9') {
				front_clockwise(top, bottom, left, right, front);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == '0') {
				front_anticlockwise(top, bottom, left, right, front);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'q' || ch == 'Q')) {
				back_clockwise(top, bottom, left, right, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'w') || (ch == 'W')) {
				back_anticlockwise(top, bottom, left, right, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'e') || (ch == 'E')) {
				slicex_clockwise(left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'r') || (ch == 'R')) {
				slicex_anticlockwise(left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 't') || (ch == 'T')) {
				slicey_clockwise(top, bottom, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'y') || (ch == 'Y')) {
				slicey_anticlockwise(top, bottom, front, back);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'u') || (ch == 'U')) {
				slicez_clockwise(top, bottom, left, right);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if((ch == 'i') || (ch == 'I')) {
				slicez_anticlockwise(top, bottom, left, right);
				print_cube(top, bottom, left, right, front, back);
				p_moves++;
			} else if(ch == 260) {
				top_clockwise(top, left, right, front, back);
				slicex_clockwise(left, right, front, back);
				bottom_anticlockwise(bottom, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
			} else if(ch == 261) {
				top_anticlockwise(top, left, right, front, back);
				slicex_anticlockwise(left, right, front, back);
				bottom_clockwise(bottom, left, right, front, back);
				print_cube(top, bottom, left, right, front, back);
			} else if(ch == 259) {
				left_anticlockwise(top, bottom, left, front, back);
				slicey_clockwise(top, bottom, front, back);
				right_clockwise(top, bottom, right, front, back);
				print_cube(top, bottom, left, right, front, back);
			} else if(ch == 258) {
				left_clockwise(top, bottom, left, front, back);
				slicey_anticlockwise(top, bottom, front, back);
				right_anticlockwise(top, bottom, right, front, back);
				print_cube(top, bottom, left, right, front, back);
			}
 		} while(!end);
		mvprintw(maxy - 1, 3, "                                                                         ");
		if((ch == 'a') || (ch == 'A')) {
			mvprintw(maxy - 1, (maxx / 2) - 22, "Ha! that's %d points to me for your cowardice.                       ", c_moves);
			c_score = c_score + c_moves;
			refresh();
			stateis = 8;
		} else if((ch == 'f') || (ch == 'F')) {
			moves = 0;
			white_cross(top, bottom, left, right, front, back);
			white_corners(top, bottom, left, right, front, back);
			middle_layer(top, bottom, left, right, front, back);
			yellow_cross(top, bottom, left, right, front, back);
			yellow_corners(top, bottom, left, right, front, back);
			orientate_corners(top, bottom, left, right, front, back);
			last_edges(top, bottom, left, right, front, back);
			if(moves == 0) {
				if(p_moves == c_moves) {
					mvprintw(maxy - 1, (maxx / 2) - 11, "A draw!    Try again.");
					stateis = 9;
					refresh();
				} else if(p_moves < c_moves) {
					if(don) {
						mvprintw(maxy - 1, (maxx / 2) - 15, "Well done! You win %d points.", (c_moves - p_moves) * 2);
						p_score = p_score + ((c_moves - p_moves) * 2);
						refresh();
						stateis = 10;
					} else {
						mvprintw(maxy - 1, (maxx / 2) - 15, "You beat me.  You get %d points.", c_moves - p_moves);
						p_score = p_score + (c_moves - p_moves);
						refresh();
						stateis = 11;
					}
				} else {
					mvprintw(maxy - 1, (maxx / 2) - 31, "You solved the cube but took too many moves.  %d points to me.", p_moves - c_moves);
					c_score = c_score + (p_moves - c_moves);
					refresh();
					stateis = 12;
				}
				mseconds = time(NULL);
				nseconds = mseconds - nseconds;
				seconds = nseconds % 60;
				minuites = (nseconds - seconds) / 60;
				hours = minuites / 60;
				minuites = minuites - (hours * 60);
					
				if((hours < fhours) || ((hours == fhours) && (minuites < fminuites)) || ((hours == fhours) && (minuites == fminuites) && (seconds < fseconds)) || !((fhours == 0) && (fminuites == 0) && (fseconds == 0))) {
					if(hours > 24) {
						stateis = 13;
						mvprintw(maxy - 1, (maxx / 2) - 38, "You may have beaten me in record time, but you took took way too  long.");	
					} else {
						hours = hours;
						fminuites = minuites;
						fseconds = seconds;
						stateis = 14;
						mvprintw(maxy - 1, (maxx / 2) - 38, "Congratulations!   You completed the cube in a record time.   Have 23 points.");
						p_score = p_score + 23;
					}
				}
			} else {
				mvprintw(maxy - 1, (maxx / 2) - 15, "Cheater!     %d points for me!", c_score = c_score + c_moves);
				stateis = 15;
				c_score = c_score + c_moves;
				refresh();
			}
		}
		FILE *fp = fopen("High_Scores.dat", "w+");
		write_scores(c_score, p_score, fhours, fminuites, fseconds);
		fclose(fp);
		nodelay(stdscr, FALSE);
		mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'X' - Return To Main Menu      ");
		mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'G' - Solve Another Scramble    ");
		nodelay(stdscr, TRUE);
		do {	
			state = 0;
			ch = wgetch(stdscr);
			signal(SIGWINCH, do_resize);
			if(state) {
				print_cube(top, bottom, left, right, front, back);
				getmaxyx(stdscr, maxy, maxx);
				mvprintw(0, (maxx / 2) - 10, "RUBIK CUBE SIMULATOR");
				mvprintw(1, (maxx / 2) - 10, "--------------------");
				mvprintw((maxy / 2) - 9, 3, "Scores");
				mvprintw((maxy / 2) - 7, 1, "%s: %d", hostname, c_score);
				mvprintw((maxy / 2) - 6, 1, "%s: %d", username, p_score); 
				if((fhours == 0) && (fminuites == 0) && (fseconds == 0)) mvprintw((maxy /  2) - 5, 1, "Fastest time - __:__:__");
				else mvprintw((maxy / 2) - 5, 1, "Fastest time : %d:%02d:%02d", fhours, fminuites, fseconds);
	// What is wrong with gcc?  This exact same line occurs three times.
	// This is the only time fhours, fminuites and fseconds have been
	// accussed of changing type.  If the type has changed it has
	// changed from int to int.          Get over it!
				mvprintw((maxy / 2) + 5, 3, "This Scramble");
				mvprintw((maxy / 2) + 8, 1, "%s has taken %d moves.", username, p_moves);
				mvprintw((maxy / 2) + 7, 1, "%s took %d moves.", hostname, c_moves);
				mvprintw((maxy / 2) - 8, (maxx / 2) + 4, "Game Mode");
				mvprintw((maxy / 2) + 5, (maxx / 2) + 4, "'G' - Solve Another Scramble");
				mvprintw((maxy / 2) + 9, (maxx / 2) + 4, "'X' - Return to Main Menu"); 
				if(stateis == 8) {
					mvprintw(maxy - 1, (maxx / 2) - 22, "Ha! that's %d points to me for your cowardice.", c_moves);
				} else if(stateis == 9) {
					mvprintw(maxy - 1, (maxx / 2) - 11, "A draw!   Try again.");
				} else if(stateis == 10) {
					mvprintw(maxy - 1, (maxx / 2) - 15, "Well done! You win %d points.", (c_moves - p_moves) * 2);
				} else if(stateis == 11) {
					mvprintw(maxy - 1, (maxx / 2) - 15, "You beat me.   You get %d points.", c_moves - p_moves);
				} else if(stateis == 12) {
					mvprintw(maxy - 1, (maxx / 2) - 31, "You solved the cube but took too many moves.  %d points to me,", p_moves - c_moves);
				} else if(stateis == 13) {
					mvprintw(maxy - 1, (maxx / 2) - 38, "You may have beaten me in a record time, but you took way too long.");
				} else if(stateis  == 14) {
					mvprintw(maxy - 1, (maxx / 2) - 38, "Congratulations!   You completed the cube in a record time.   Have 23 points.");
				} else if(stateis == 15) {
					mvprintw(maxy - 1, (maxx /2) - 15, "Cheater!    %d pointss for me!", c_moves);
				}
				refresh();
			}
			state = 0;
		} while((ch != 'x') && (ch != 'X') && (ch != 'g') && (ch != 'G'));
		mvprintw(maxy - 1, 3, "                                                                          ");
		end = 0;
	} while ((ch != 'x') && (ch != 'X'));

	mvprintw((maxy / 2) + 7, (maxx / 2) - 49, "                          ");
	mvprintw((maxy / 2) + 8, (maxx / 2) - 49, "                          ");
	mvprintw(7, (maxx / 2) - 49, "                          ");
	mvprintw(8, (maxx / 2) - 49, "                          ");
	nodelay(stdscr, TRUE);
	delay = old_delay;
}
