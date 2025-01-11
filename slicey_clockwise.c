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

void slicey_clockwise(int top[8], int bottom[8], int front[8], int back[8]) {
	
	int buffer[3];

	buffer[0] = top[1];
	buffer[1] = top[4];
	buffer[2] = top[7];


	top[1] = front[1];
        top[4] = front[4];
	top[7] = front[7];


	front[1] = bottom[1];
	front[4] = bottom[4];
	front[7] = bottom[7];


	bottom[1] = back[7];
	bottom[4] = back[4];
	bottom[7] = back[1];


	back[7] = buffer[0];
	back[4] = buffer[1];
	back[1] = buffer[2];

}
