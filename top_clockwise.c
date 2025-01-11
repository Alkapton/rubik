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

void top_clockwise(int top[8], int left[8], int right[8], int front[8], int back[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = top[n];
	}

	top[0] = buffer[6];
	top[1] = buffer[3];
	top[2] = buffer[0];

	top[3] = buffer[7];
	top[4] = buffer[4];
	top[5] = buffer[1];

	top[6] = buffer[8];
	top[7] = buffer[5];
	top[8] = buffer[2];


	buffer[0] = front[0];
	buffer[1] = front[1];
	buffer[2] = front[2];

	front[0] = right[0];
	front[1] = right[1];
	front[2] = right[2];


	right[0] = back[0];
	right[1] = back[1];
	right[2] = back[2];


	back[0] = left[0];
	back[1] = left[1];
	back[2] = left[2];


	left[0] = buffer[0];
	left[1] = buffer[1];
	left[2] = buffer[2];

}
