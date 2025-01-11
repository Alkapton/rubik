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

void bottom_clockwise(int bottom[8], int left[8], int right[8], int front[8], int back[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = bottom[n];
	}

	bottom[0] = buffer[6];
	bottom[1] = buffer[3];
	bottom[2] = buffer[0];

	bottom[3] = buffer[7];
	bottom[4] = buffer[4];
	bottom[5] = buffer[1];

	bottom[6] = buffer[8];
	bottom[7] = buffer[5];
	bottom[8] = buffer[2];


	buffer[6] = front[6];
	buffer[7] = front[7];
	buffer[8] = front[8];


	front[6] = left[6];
	front[7] = left[7];
	front[8] = left[8];


	left[6] = back[6];
	left[7] = back[7];
	left[8] = back[8];


	back[6] = right[6];
	back[7] = right[7];
	back[8] = right[8];


	right[6] = buffer[6];
	right[7] = buffer[7];
	right[8] = buffer[8];

}
