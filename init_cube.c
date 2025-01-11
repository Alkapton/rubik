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

void init_cube(int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {
	for(int n = 0; n < 9; n++) {
		top[n] = (n * 10) + 1;
		bottom[n] = (n * 10) + 6;
		left[n] = (n * 10) + 2;
		right[n] = (n * 10) + 4;
		front[n] = (n * 10) + 5;
		back[n] = (n * 10) + 3;
	}


}
