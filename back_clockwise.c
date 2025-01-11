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

void back_clockwise(int top[8], int bottom[8], int left[8], int right[8], int back[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = back[n];
	}

	back[0] = buffer[6];
	back[1] = buffer[3];
	back[2] = buffer[0];

	back[3] = buffer[7];
	back[4] = buffer[4];
	back[5] = buffer[1];

	back[6] = buffer[8];
	back[7] = buffer[5];
	back[8] = buffer[2];


	buffer[0] = top[0];
	buffer[1] = top[1];
	buffer[2] = top[2];


	top[0] = right[2];
	top[1] = right[5];
	top[2] = right[8];


	right[2] = bottom[8];
	right[5] = bottom[7];
	right[8] = bottom[6];


	bottom[6] = left[0];
	bottom[7] = left[3];
	bottom[8] = left[6];


	left[0] = buffer[2];
	left[3] = buffer[1];
	left[6] = buffer[0];

}
