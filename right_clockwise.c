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

void right_clockwise(int top[8], int bottom[8], int right[8], int front[8], int back[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = right[n];
	}

	right[0] = buffer[6];
	right[1] = buffer[3];
	right[2] = buffer[0];


	right[3] = buffer[7];
	right[4] = buffer[4];
	right[5] = buffer[1];

	
	right[6] = buffer[8];
	right[7] = buffer[5];
	right[8] = buffer[2];

	
	buffer[2] = top[2];
	buffer[5] = top[5];
	buffer[8] = top[8];


	top[2] = front[2];
	top[5] = front[5];
	top[8] = front[8];


	front[2] = bottom[2];
	front[5] = bottom[5];
	front[8] = bottom[8];


	bottom[2] = back[6];
	bottom[5] = back[3];
	bottom[8] = back[0];


	back[0] = buffer[8];
	back[3] = buffer[5];
	back[6] = buffer[2];

}
