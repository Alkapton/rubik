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

#define TOP_C 1 
#define TOP_A 2
#define BOT_C 3
#define BOT_A 4
#define LEF_C 5
#define LEF_A 6
#define RIG_C 7
#define RIG_A 8
#define FRO_C 9
#define FRO_A 10
#define BAK_C 11
#define BAK_A 12
#define SLX_C 13
#define SLX_A 14
#define SLY_C 15
#define SLY_A 16
#define SLZ_C 17
#define SLZ_A 18

struct scores {
	long int p_scores;
	long int c_scores;
	int hours;
	int minuites;
	int seconds;
};

extern int delay;
extern int moves;
extern int state;


void do_resize(int dummy);

struct scores read_scores(void);

void write_scores(long int c_scores, long int p_scores, int hours, int minuites, int seconds);

void game(int don, int info, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

int label_cube(int don, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

int validate_cube(int don, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void cmove(int direction, int top[8], int bottom[8], int left [8], int right[8], int front[8], int back[8]);

void init_cube(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void print_cube(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void manipulate_cube(int don, int info, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);


void top_clockwise(int top[8], int left[8], int right[8], int front[8], int back[8]);

void top_anticlockwise(int top[8], int left[8], int right[8], int front[8], int back[8]);

void bottom_clockwise(int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void bottom_anticlockwise(int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void left_clockwise(int top[8], int bottom[8], int left[8], int front[8], int back[8]);

void left_anticlockwise(int top[8], int bottom[8], int left[8], int front[8], int back[8]);

void right_clockwise(int top[8], int bottom[8], int right[8], int front[8], int back[8]);

void right_anticlockwise(int top[8], int bottom[8], int right[8], int front[8], int back[8]);

void front_clockwise(int top[8], int bottom[8], int left[8], int right[8], int front[8]);

void front_anticlockwise(int top[8], int bottom[8], int left[8], int right[8], int front[8]);

void back_clockwise(int top[8], int bottom[8], int left[8], int right[8], int back[8]);

void back_anticlockwise(int top[8], int bottom[8], int left[8], int right[8], int back[8]);

void slicex_clockwise(int left[8], int right[8], int front[8], int back[8]);

void slicex_anticlockwise(int left[8], int right[8], int front[8], int back[8]);

void slicey_clockwise(int top[8], int bottom[8], int front[8], int back[8]);

void slicey_anticlockwise(int top[8], int bottom[8], int front[8], int back[8]);

void slicez_clockwise(int top[8], int bottom[8], int left[8], int right[8]);

void slicez_anticlockwise(int top[8], int bottom[8], int left[8], int right[8]);


void scramble_cube(int smoves, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]); 

void white_cross(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void white_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void white_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void middle_layer(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void yellow_cross(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void yellow_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void orientate_corners(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);

void last_edges(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]);
