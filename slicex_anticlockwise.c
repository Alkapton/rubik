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

void slicex_anticlockwise(int left[8], int right[8], int front[8], int back[8]) {
	
	int buffer[3];

	for(int n = 0; n < 3; n++) {
		buffer[n] = front[n + 3];
	}

	front[3] = left[3];
        front[4] = left[4];
	front[5] = left[5];


	left[3] = back[3];
	left[4] = back[4];
	left[5] = back[5];


	back[3] = right[3];
	back[4] = right[4];
	back[5] = right[5];


	right[3] = buffer[0];
	right[4] = buffer[1];
	right[5] = buffer[2];

}
