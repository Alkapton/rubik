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

void slicez_anticlockwise(int top[8], int bottom[8], int left[8], int right[8]) {
	
	int buffer[3];

	buffer[0] = top[3];
	buffer[1] = top[4];
	buffer[2] = top[5];


	top[3] = right[1];
        top[4] = right[4];
	top[5] = right[7];


	right[1] = bottom[5];
	right[4] = bottom[4];
	right[7] = bottom[3];


	bottom[3] = left[1];
	bottom[4] = left[4];
	bottom[5] = left[7];


	left[7] = buffer[0];
	left[4] = buffer[1];
	left[1] = buffer[2];

}
