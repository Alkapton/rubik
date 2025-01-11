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

#include "rubik.h"

void left_anticlockwise(int top[8], int bottom[8], int left[8], int front[8], int back[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = left[n];
	}

	left[0] = buffer[2];
	left[1] = buffer[5];
	left[2] = buffer[8];


	left[3] = buffer[1];
	left[4] = buffer[4];
	left[5] = buffer[7];


	left[6] = buffer[0];
	left[7] = buffer[3];
	left[8] = buffer[6];


	buffer[0] = top[0];
	buffer[3] = top[3];
	buffer[6] = top[6];


	top[0] = front[0];
	top[3] = front[3];
	top[6] = front[6];


	front[0] = bottom[0];
	front[3] = bottom[3];
	front[6] = bottom[6];


	bottom[6] = back[2];
	bottom[3] = back[5];
	bottom[0] = back[8];


	back[2] = buffer[6];
	back[5] = buffer[3];
	back[8] = buffer[0];


}
