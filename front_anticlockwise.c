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

#include "rubik.h"

void front_anticlockwise(int top[8], int bottom[8], int left[8], int right[8], int front[8]) {
	int buffer[8];

	for(int n = 0; n < 9; n++){
		buffer[n] = front[n];
	}

	front[0] = buffer[2];
	front[1] = buffer[5];
	front[2] = buffer[8];

	front[3] = buffer[1];
	front[4] = buffer[4];
	front[5] = buffer[7];

	front[6] = buffer[0];
	front[7] = buffer[3];
	front[8] = buffer[6];


	buffer[6] = top[6];
	buffer[7] = top[7];
	buffer[8] = top[8];


	top[6] = right[0];
	top[7] = right[3];
	top[8] = right[6];


	right[0] = bottom[2];
	right[3] = bottom[1];
	right[6] = bottom[0];


	bottom[0] = left[2];
	bottom[1] = left[5];
	bottom[2] = left[8];


	left[8] = buffer[6];
	left[5] = buffer[7];
	left[2] = buffer[8];

}
