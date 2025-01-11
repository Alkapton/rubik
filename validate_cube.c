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

#include <ncurses.h>

#include "rubik.h"

int validate_cube(int don, int top[8], int bottom[8], int left[8], int right[8], int front[8], int back[8]) {

	int white = 0, yellow = 0, blue = 0, green = 0, red = 0, orange = 0;
	int middle = 0, rotation = 0, count = 0;
// 9 of each color
//
	if(top[4] % 10 == 1) white++;
	else if(top[4] % 10 == 2) blue++;
	else if(top[4] % 10 == 3) red++;
	else if(top[4] % 10 == 4) green++;
	else if(top[4] % 10 == 5) orange++;
	else if(top[4] % 10 == 6) yellow++;

	if(left[4] % 10 == 1) white++;
	else if(left[4] % 10 == 2) blue++;
	else if(left[4] % 10 == 3) red++;
	else if(left[4] % 10 == 4) green++;
	else if(left[4] % 10 == 5) orange++;
	else if(left[4] % 10 == 6) yellow++;

	if(front[4] % 10 == 1) white++;
	else if(front[4] == 2) blue++;
	else if(front[4] == 3) red++;
	else if(front[4] == 4) green++;
	else if(front[4] == 5) orange++;
	else if(front[4] == 6) yellow++;

	if(right[4] % 10 == 1) white++;
	else if(right[4] % 10 == 2) blue++;
	else if(right[4] % 10 == 3) red++;
	else if(right[4] % 10 == 4) green++;
	else if(right[4] % 10 == 5) orange++;
	else if(right[4] % 10 == 6) yellow++;

	if(back[4] % 10 == 1) white++;
	else if(back[4] % 10 == 2) blue++;
	else if(back[4] % 10 == 3) red++;
	else if(back[4] % 10 == 4) green++;
	else if(back[4] % 10 == 5) orange++;
	else if(back[4] % 10 == 6) yellow++;

	if(bottom[4] % 10 == 1) white++;
	else if(bottom[4] % 10 == 2) blue++;
	else if(bottom[4] % 10 == 3) red++;
	else if(bottom[4] % 10 == 4) green++;
	else if(bottom[4] % 10 == 5) orange++;
	else if(bottom[4] % 10 == 6) yellow++;

	if(!(white && blue && red && green && orange && yellow)) {
		return(7);
	}
	white = 0;
	blue = 0;
	red = 0;
	green = 0;
	orange = 0;
	yellow = 0;
	for(int n = 0; n < 9; n++) {
		if(top[n] % 10 == 1) white++;
		else if(top[n] % 10 == 2) blue++;
		else if(top[n] % 10 == 3) red++;
		else if(top[n] % 10 == 4) green++;
		else if(top[n] % 10 == 5) orange++;
		else if(top[n] % 10 == 6) yellow++;

		if(left[n] % 10 == 1) white++;
		else if(left[n] % 10 == 2) blue++;
		else if(left[n] % 10 == 3) red++;
		else if(left[n] % 10 == 4) green++;
		else if(left[n] % 10 == 5) orange++;
		else if(left[n] % 10 == 6) yellow++;

		if(front[n] % 10 == 1) white++;
		else if(front[n] % 10 == 2) blue++;
		else if(front[n] % 10 == 3) red++;
		else if(front[n] % 10 == 4) green++;
		else if(front[n] % 10 == 5) orange++;
		else if(front[n] % 10 == 6) yellow++;

		if(right[n] % 10 == 1) white++;
		else if(right[n] % 10 == 2) blue++;
		else if(right[n] % 10 == 3) red++;
		else if(right[n] % 10 == 4) green++;
		else if(right[n] % 10 == 5) orange++;
		else if(right[n] % 10 == 6) yellow++;

		if(back[n] % 10 == 1) white++;
		else if(back[n] % 10 == 2) blue++;
		else if(back[n] % 10 == 3) red++;
		else if(back[n] % 10 == 4) green++;
		else if(back[n] % 10 == 5) orange++;
		else if(back[n] % 10 == 6) yellow++;

		if(bottom[n] % 10 == 1) white++;
		else if(bottom[n] % 10 == 2) blue++;
		else if(bottom[n] % 10 == 3) red++;
		else if(bottom[n] % 10 == 4) green++;
		else if(bottom[n] % 10 == 5) orange++;
		else if(bottom[n] % 10 == 6) yellow++;
	}
	if((white != 9) || (blue != 9) || (orange != 9) || (green != 9) || (red != 9) || (yellow != 9)) return(1);
// Each center has different color and correct opposite color
	if(((top[4] == 1) && (bottom[4] == 6)) || ((top[4] == 6) && (bottom[4] == 1))) middle++;
	else if(((top[4] == 2) && (bottom[4] == 4)) || ((top[4] == 4) && (bottom[4] == 2))) middle++;
	else if(((top[4] == 3) && (bottom[4] == 5)) || ((top[4] == 5) && (bottom[4] == 3))) middle++;
	
	if(((left[4] == 1) && (right[4] == 6)) || ((left[4] == 6) && (right[4] == 1))) middle++;
	else if(((left[4] == 2) && (right[4] == 4)) || ((left[4] == 4) && (right[4] == 2))) middle++;
	else if(((left[4] == 3) && (right[4] == 5)) || ((left[4] == 5) && (right[4] == 3))) middle++;
	
	if(((front[4] == 1) && (back[4] == 6)) || ((front[4] == 6) && (back[4] == 1))) middle++;
	else if(((front[4] == 2) && (back[4] == 4)) || ((front[4] == 4) && (back[4] == 2))) middle++;
	else if(((front[4] == 3) && (back[4] == 5)) || ((front[4] == 5) && (back[4] == 3))) middle++;
	if(middle != 3) return(2);
// give centers numbers
	if(top[4] == 1) {
		top[4] = 41;
		bottom[4] = 46;
	} else if(top[4] == 2) {
		top[4] = 42;
		bottom[4] = 44;
	} else if(top[4] == 3) {
		top[4] = 43;
		bottom[4] = 45;
	} else if(top[4] == 4) {
		top[4] = 44;
		bottom[4] = 42;
	} else if(top[4] == 5) {
		top[4] = 45;
		bottom[4] = 43;
	} else if(top[4] == 6) {
		top[4] = 46;
		bottom[4] = 41;
	}

	
	if(left[4] == 1) {
		left[4] = 41;
		right[4] = 46;
	} else if(left[4] == 2) {
		left[4] = 42;
		right[4] = 44;
	} else if(left[4] == 3) {
		left[4] = 43;
		right[4] = 45;
	} else if(left[4] == 4) {
		left[4] = 44;
		right[4] = 42;
	} else if(left[4] == 5) {
		left[4] = 45;
		right[4] = 43;
	} else if(left[4] == 6) {
		left[4] = 46;
		right[4] = 41;
	}


	if(front[4] == 1) {
		front[4] = 41;
		back[4] = 46;
	} else if(front[4] == 2) {
		front[4] = 42;
		back[4] = 44;
	} else if(front[4] == 3) {
		front[4] = 43;
		back[4] = 45;
	} else if(front[4] == 4) {
		front[4] = 44;
		back[4] = 42;
	} else if(front[4] == 5) {
		front[4] = 45;
		back[4] = 43;
	} else if(front[4] == 6) {
		front[4] = 46;
		back[4] = 41;
	}
// put correct numbers on each corner and edge label or return an error	
// corner 1	
	if(((top[0] == 1) && (left[0] == 2) && (back[2] == 3)) ||
	   ((top[0] == 2) && (left[0] == 3) && (back[2] == 1)) ||
	   ((top[0] == 3) && (left[0] == 1) && (back[2] == 2))) {
	   	if(top[0] == 1) top[0] = 1;
		else if(top[0] == 2) {
			top[0] = 2;
			rotation++;
		} else {
			top[0] = 23;
			rotation--;
		}

		if(left[0] == 1) left[0] = 1;
		else if(left[0] == 2) left[0] = 2;
		else left[0] = 23;

		if(back[2] == 1) back[2] = 1;
		else if(back[2] == 2) back[2] = 2; 
		else back[2] = 23;
	} else
	if(((top[0] == 1) && (left[0] == 3) && (back[2] == 4)) ||
	   ((top[0] == 3) && (left[0] == 4) && (back[2] == 1)) ||
	   ((top[0] == 4) && (left[0] == 1) && (back[2] == 3))) {
		if(top[0] == 1) top[0] = 21;
		else if(top[0] == 3) {
			top[0] = 3;
			rotation++;
		} else {
			top[0] = 24;
			rotation--;
		}

		if(left[0] == 1) left[0] = 21;
		else if(left[0] == 3) left[0] = 3;
		else left[0] = 24;

		if(back[2] == 1) back[2] = 21;
		else if(back[2] == 3) back[0] = 3;
		else back[2] = 24;
	} else
	if(((top[0] == 1) && (left[0] == 5) && (back[2] == 2)) ||
	   ((top[0] == 5) && (left[0] == 2) && (back[2] == 1)) ||
	   ((top[0] == 2) && (left[0] == 1) && (back[2] == 5))) {
		if(top[0] == 1) top[0] = 61;
		else if(top[0] == 5) {
			top[0] = 5;
			rotation++;
		} else {
			top[0] = 22;
			rotation--;
		}

		if(left[0] == 1) left[0] = 61;
		else if(left[0] == 5) left[0] = 5;
		else left[0] = 22;

		if(back[2] == 1) back[2] = 61;
		else if(back[2] == 5) back[2] = 5;
		else back[2] = 22;
	} else
	if(((top[0] == 1) && (left[0] == 4) && (back[2] == 5)) ||
	   ((top[0] == 4) && (left[0] == 5) && (back[2] == 1)) ||
	   ((top[0] == 5) && (left[0] == 1) && (back[2] == 4))) {
		if(top[0] == 1) top[0] = 81;
		else if(top[0] == 5) {
			top[0] = 25;
			rotation--;
		} else {
			top[0] = 4;
			rotation++;
		}

		if(left[0] == 1) left[0] = 81;
		else if(left[0] == 5) left[0] = 25;
		else left[0] = 4;

		if(back[2] == 1) back[2] = 81;
		else if(back[2] == 5) back[2] = 25;
		else back[2] = 4;
	} else
	if(((top[0] == 6) && (left[0] == 2) && (back[2] == 5)) ||
	   ((top[0] == 2) && (left[0] == 5) && (back[2] == 6)) ||
   	   ((top[0] == 5) && (left[0] == 6) && (back[2] == 2))) {
		if(top[0] == 6) top[0] = 6;
		else if(top[0] == 2) {
			top[0] = 82;
			rotation++;
		} else {
			top[0] = 65;
			rotation--;
		}

		if(left[0] == 6) left[0] = 6;
		else if(left[0] == 2) left[0] = 82;
		else left[0] = 65;

		if(back[2] == 6) back[2] = 6;
		else if(back[2] == 2) back[2] = 82;
		else back[2] = 65;
	} else
	if(((top[0] == 6) && (left[0] == 4) && (back[2] == 3)) ||
	   ((top[0] == 4) && (left[0] == 3) && (back[2] == 6)) ||
	   ((top[0] == 3) && (left[0] == 6) && (back[2] == 4))) {
		if(top[0] == 6) top[0] = 86;
		else if(top[0] == 4) {
			top[0] = 84;
			rotation++;
		} else {
			top[0] = 63;
			rotation--;
		}

		if(left[0] == 6) left[0] = 86;
		else if(left[0] == 4) left[0] = 84;
		else left[0] = 63;

		if(back[2] == 6) back[2] = 86;
		else if(back[2] == 4) back[2] = 84;
		else back[2] = 63;
	} else
	if(((top[0] == 6) && (left[0] == 3) && (back[2] == 2)) ||
	   ((top[0] == 3) && (left[0] == 2) && (back[2] == 6)) ||
	   ((top[0] == 2) && (left[0] == 6) && (back[2] == 3))) {
		if(top[0] == 6) top[0] = 66;
		else if(top[0] == 3) {
			top[0] = 83;
			rotation++;
		} else {
			top[0] = 62;
			rotation--;
		}

		if(left[0] == 6) left[0] = 66;
		else if(left[0] == 3) left[0] = 83;
		else left[0] = 62;

		if(back[2] == 6) back[2] = 66;
		else if(back[2] == 3) back[2] = 83;
		else back[2] = 62;
	} else
	if(((top[0] == 6) && (left[0] == 5) && (back[2] == 4)) ||
	   ((top[0] == 5) && (left[0] == 4) && (back[2] == 6)) ||
	   ((top[0] == 4) && (left[0] == 6) && (back[2] == 5))) {
		if(top[0] == 6) top[0] = 26;
		else if(top[0] == 5) {
			top[0] = 85;
			rotation++;
		} else {
			top[0] = 64;
			rotation--;
		}

		if(left[0] == 6) left[0] = 26;
		else if(left[0] == 5) left[0] = 85;
		else left[0] = 64;

		if(back[2] == 6) back[2] = 26;
		else if(back[2] == 5) back[2] = 85;
		else back[2] = 64;
	} else return(3);


// corner 2 
	if(((top[2] == 1) && (back[0] == 3) && (right[2] == 4)) ||
	   ((top[2] == 3) && (back[0] == 4) && (right[2] == 1)) ||
	   ((top[2] == 4) && (back[0] == 1) && (right[2] == 3))) {
		if(top[2] == 1) top[2] = 21;
		else if(top[2] == 3) {
			top[2] = 3;
			rotation++;
		} else {
			top[2] = 24;
			rotation--;
		}

		if(back[0] == 1) back[0] = 21;
		else if(back[0] == 3) back[0] = 3;
		else back[0] = 24;

		if(right[2] == 1) right[2] = 21;
		else if(right[2] == 3) right[2] = 3;
		else right[2] = 24;
	} else
	if(((top[2] == 1) && (back[0] == 5) && (right[2] == 2)) ||
	   ((top[2] == 5) && (back[0] == 2) && (right[2] == 1)) ||
	   ((top[2] == 2) && (back[0] == 1) && (right[2] == 5))) {
		if(top[2] == 1) top[2] = 61;
		else if(top[2] == 5) {
			top[2] = 5;
			rotation++;
		} else {
			top[2] = 22;
			rotation--;
		}

		if(back[0] == 1) back[0] = 61;
		else if(back[0] == 5) back[0] = 5;
		else back[0] = 22;

		if(right[2] == 1) right[2] = 61;
		else if(right[2] == 5) right[2] = 5;
		else right[2] = 22;
	} else
	if(((top[2] == 1) && (back[0] == 2) && (right[2] == 3)) ||
	   ((top[2] == 2) && (back[0] == 3) && (right[2] == 1)) ||
	   ((top[2] == 3) && (back[0] == 1) && (right[2] == 2))) {
		if(top[2] == 1) top[2] = 1;
		else if(top[2] == 2) {
			top[2] = 2;
			rotation++;
		} else {
			top[2] = 23;
			rotation--;
		}

		if(back[0] == 1) back[0] = 1;
		else if(back[0] == 2) back[0] = 2;
		else back[0] = 23;

		if(right[2] == 1) right[2] = 1;
		else if(right[2] == 2) right[2] = 2;
		else right[2] = 23;
	} else	
	if(((top[2] == 1) && (back[0] == 4) && (right[2] == 5)) ||
	   ((top[2] == 4) && (back[0] == 5) && (right[2] == 1)) ||
	   ((top[2] == 5) && (back[0] == 1) && (right[2] == 4))) {
		if(top[2] == 1) top[2] = 81;
		else if(top[2] == 5) {
			top[2] = 25;
			rotation--;
		} else {
			top[2] = 4;
			rotation++;
		}

		if(back[0] == 1) back[0] = 81;
		else if(back[0] == 5) back[0] = 25;
		else back[0] = 4;

		if(right[2] == 1) right[2] = 81;
		else if(right[2] == 5) right[2] = 25;
		else right[2] = 4;
	} else
	if(((top[2] == 6) && (back[0] == 2) && (right[2] == 5)) ||
	   ((top[2] == 2) && (back[0] == 5) && (right[2] == 6)) ||
   	   ((top[2] == 5) && (back[0] == 6) && (right[2] == 2))) {
		if(top[2] == 6) top[2] = 6;
		else if(top[2] == 2) {
			top[2] = 82;
			rotation++;
		} else {
			top[2] = 65;
			rotation--;
		}

		if(back[0] == 6) back[0] = 6;
		else if(back[0] == 2) back[0] = 82;
		else back[0] = 65;

		if(right[2] == 6) right[2] = 6;
		else if(right[2] == 2) right[2] = 82;
		else right[2] = 65;
	} else
	if(((top[2] == 6) && (back[0] == 4) && (right[2] == 3)) ||
	   ((top[2] == 4) && (back[0] == 3) && (right[2] == 6)) ||
	   ((top[2] == 3) && (back[0] == 6) && (right[2] == 4))) {
		if(top[2] == 6) top[2] = 86;
		else if(top[2] == 4) {
			top[2] = 84;
			rotation++;
		} else {
			top[2] = 63;
			rotation--;
		}

		if(back[0] == 6) back[0] = 86;
		else if(back[0] == 4) back[0] = 84;
		else back[0] = 63;

		if(right[2] == 6) right[2] = 86;
		else if(right[2] == 4) right[2] = 84;
		else right[2] = 63;
	} else
	if(((top[2] == 6) && (back[0] == 3) && (right[2] == 2)) ||
	   ((top[2] == 3) && (back[0] == 2) && (right[2] == 6)) ||
	   ((top[2] == 2) && (back[0] == 6) && (right[2] == 3))) {
		if(top[2] == 6) top[2] = 66;
		else if(top[2] == 3) {
			top[2] = 83;
			rotation++;
		} else {
			top[2] = 62;
			rotation--;
		}

		if(back[0] == 6) back[0] = 66;
		else if(back[0] == 3) back[0] = 83;
		else back[0] = 62;

		if(right[2] == 6) right[2] = 66;
		else if(right[2] == 3) right[2] = 83;
		else right[2] = 62;
	} else
	if(((top[2] == 6) && (back[0] == 5) && (right[2] == 4)) ||
	   ((top[2] == 5) && (back[0] == 4) && (right[2] == 6)) ||
	   ((top[2] == 4) && (back[0] == 6) && (right[2] == 5))) {
		if(top[2] == 6) top[2] = 26;
		else if(top[2] == 5) {
			top[2] = 85;
			rotation++;
		} else {
			top[2] = 64;
			rotation--;
		}

		if(back[0] == 6) back[0] = 26;
		else if(back[0] == 5) back[0] = 85;
		else back[0] = 64;

		if(right[2] == 6) right[2] = 26;
		else if(right[2] == 5) right[2] = 85;
		else right[2] = 64;
	} else return(3);

// corner 3

	if(((top[6] == 1) && (front[0] == 3) && (left[2] == 4)) ||
	   ((top[6] == 3) && (front[0] == 4) && (left[2] == 1)) ||
   	   ((top[6] == 4) && (front[0] == 1) && (left[2] == 3))) {
		if(top[6] == 1) top[6] = 21;
		else if(top[6] == 3) {
			top[6] = 3;
			rotation++;
		} else {
			top[6] = 24;
			rotation--;
		}

		if(front[0] == 1) front[0] = 21;
		else if(front[0] == 3) front[0] = 3;
		else front[0] = 24;

		if(left[2] == 1) left[2] = 21;
		else if(left[2] == 3) left[2] = 3;
		else left[2] = 24;
	} else
	if(((top[6] == 1) && (front[0] == 5) && (left[2] == 2)) ||
	   ((top[6] == 5) && (front[0] == 2) && (left[2] == 1)) ||
	   ((top[6] == 2) && (front[0] == 1) && (left[2] == 5))) {
		if(top[6] == 1) top[6] = 61;
		else if(top[6] == 5) {
			top[6] = 5;
			rotation++;
		} else {
			top[6] = 22;
			rotation--;
		}

		if(front[0] == 1) front[0] = 61;
		else if(front[0] == 5) front[0] = 5;
		else front[0] = 22;

		if(left[2] == 1) left[2] = 61;
		else if(left[2] == 5) left[2] = 5;
		else left[2] = 22;
	} else 
	if(((top[6] == 1) && (front[0] == 2) && (left[2] == 3)) ||
	   ((top[6] == 2) && (front[0] == 3) && (left[2] == 1)) ||
	   ((top[6] == 3) && (front[0] == 1) && (left[2] == 2))) {
		if(top[6] == 1) top[6] = 1;
		else if(top[6] == 2) {
			top[6] = 2;
			rotation++;
		} else {
			top[6] = 23;
			rotation--;
		}

		if(front[0] == 1) front[0] = 1;
		else if(front[0] == 2) front[0] = 2;
		else front[0] = 23;

		if(left[2] == 1) left[2] = 1;
		else if(left[2] == 2) left[2] = 2;
		else left[2] = 23;
	} else
	if(((top[6] == 1) && (front[0] == 4) && (left[2] == 5)) ||
	   ((top[6] == 4) && (front[0] == 5) && (left[2] == 1)) ||
	   ((top[6] == 5) && (front[0] == 1) && (left[2] == 4))) {
		if(top[6] == 1) top[6] = 81;
		else if(top[6] == 5) {
			top[6] = 25;
			rotation--;
		} else {
			top[6] = 4;
			rotation++;
		}

		if(front[0] == 1) front[0] = 81;
		else if(front[0] == 5) front[0] = 25;
		else front[0] = 4;

		if(left[2] == 1) left[2] = 81;
		else if(left[2] == 5) left[2] = 25;
		else left[2] = 4;
	} else
	if(((top[6] == 6) && (front[0] == 2) && (left[2] == 5)) ||
	   ((top[6] == 2) && (front[0] == 5) && (left[2] == 6)) ||
   	   ((top[6] == 5) && (front[0] == 6) && (left[2] == 2))) {
		if(top[6] == 6) top[6] = 6;
		else if(top[6] == 2) {
			top[6] = 82;
			rotation++;
		} else {
			top[6] = 65;
			rotation--;
		}

		if(front[0] == 6) front[0] = 6;
		else if(front[0] == 2) front[0] = 82;
		else front[0] = 65;

		if(left[2] == 6) left[2] = 6;
		else if(left[2] == 2) left[2] = 82;
		else left[2] = 65;
	} else
	if(((top[6] == 6) && (front[0] == 4) && (left[2] == 3)) ||
	   ((top[6] == 4) && (front[0] == 3) && (left[2] == 6)) ||
	   ((top[6] == 3) && (front[0] == 6) && (left[2] == 4))) {
		if(top[6] == 6) top[6] = 86;
		else if(top[6] == 4) {
			top[6] = 84;
			rotation++;
		} else {
			top[6] = 63;
			rotation--;
		}

		if(front[0] == 6) front[0] = 86;
		else if(front[0] == 4) front[0] = 84;
		else front[0] = 63;

		if(left[2] == 6) left[2] = 86;
		else if(left[2] == 4) left[2] = 84;
		else left[2] = 63;
	} else
	if(((top[6] == 6) && (front[0] == 3) && (left[2] == 2)) ||
	   ((top[6] == 3) && (front[0] == 2) && (left[2] == 6)) ||
	   ((top[6] == 2) && (front[0] == 6) && (left[2] == 3))) {
		if(top[6] == 6) top[6] = 66;
		else if(top[6] == 3) {
			top[6] = 83;
			rotation++;
		} else {
			top[6] = 62;
			rotation--;
		}

		if(front[0] == 6) front[0] = 66;
		else if(front[0] == 3) front[0] = 83;
		else front[0] = 62;

		if(left[2] == 6) left[2] = 66;
		else if(left[2] == 3) left[2] = 83;
		else left[2] = 62;
	} else
	if(((top[6] == 6) && (front[0] == 5) && (left[2] == 4)) ||
	   ((top[6] == 5) && (front[0] == 4) && (left[2] == 6)) ||
	   ((top[6] == 4) && (front[0] == 6) && (left[2] == 5))) {
		if(top[6] == 6) top[6] = 26;
		else if(top[6] == 5) {
			top[6] = 85;
			rotation++;
		} else {
			top[6] = 64;
			rotation--;
		}

		if(front[0] == 6) front[0] = 26;
		else if(front[0] == 5) front[0] = 85;
		else front[0] = 64;

		if(left[2] == 6) left[2] = 26;
		else if(left[2] == 5) left[2] = 85;
		else left[2] = 64;
	} else return(3);



// corner 4
	
	if(((top[8] == 1) && (right[0] == 3) && (front[2] == 4)) ||
	   ((top[8] == 3) && (right[0] == 4) && (front[2] == 1)) ||
   	   ((top[8] == 4) && (right[0] == 1) && (front[2] == 3))) {
		if(top[8] == 1) top[8] = 21;
		else if(top[8] == 3) {
			top[8] = 3;
			rotation++;
		} else {
			top[8] = 24;
			rotation--;
		}

		if(right[0] == 1) right[0] = 21;
		else if(right[0] == 3) right[0] = 3;
		else right[0] = 24;

		if(front[2] == 1) front[2] = 21;
		else if(front[2] == 3) front[2] = 3;
		else front[2] = 24;
	} else
	if(((top[8] == 1) && (right[0] == 5) && (front[2] == 2)) ||
	   ((top[8] == 5) && (right[0] == 2) && (front[2] == 1)) ||
	   ((top[8] == 2) && (right[0] == 1) && (front[2] == 5))) {
		if(top[8] == 1) top[8] = 61;
		else if(top[8] == 5) {
			top[8] = 5;
			rotation++;
		} else {
			top[8] = 22;
			rotation--;
		}

		if(right[0] == 1) right[0] = 61;
		else if(right[0] == 5) right[0] = 5;
		else right[0] = 22;

		if(front[2] == 1) front[2] = 61;
		else if(front[2] == 5) front[2] = 5;
		else front[2] = 22;
	} else
	if(((top[8] == 1) && (right[0] == 4) && (front[2] == 5)) ||
	   ((top[8] == 4) && (right[0] == 5) && (front[2] == 1)) ||
	   ((top[8] == 5) && (right[0] == 1) && (front[2] == 4))) {
		if(top[8] == 1) top[8] = 81;
		else if(top[8] == 5) {
			top[8] = 25;
			rotation--;
		} else {
			top[8] = 4;
			rotation++;
		}

		if(right[0] == 1) right[0] = 81;
		else if(right[0] == 5) right[0] = 25;
		else right[0] = 4;

		if(front[2] == 1) front[2] = 81;
		else if(front[2] == 5) front[2] = 25;
		else front[2] = 4;
	} else
	if(((top[8] == 1) && (front[2] == 3) && (right[0] == 2)) ||
	   ((top[8] == 3) && (front[2] == 2) && (right[0] == 1)) ||
	   ((top[8] == 2) && (front[2] == 1) && (right[0] == 3))) {
		if(top[8] == 1) top[8] = 1;
		else if(top[8] == 3) {
			top[8] = 23;
			rotation--;
		} else {
			top[8] = 2;
			rotation++;
		}

		if(front[2] == 1) front[2] = 1;
		else if(front[2] == 3) front[2] = 23;
		else front[2] = 2;

		if(right[0] == 1) right[0] = 1;
		else if(right[0] == 3) right[0] = 23;
		else right[0] = 2;
	} else 
	if(((top[8] == 6) && (right[0] == 2) && (front[2] == 5)) ||
	   ((top[8] == 2) && (right[0] == 5) && (front[2] == 6)) ||
   	   ((top[8] == 5) && (right[0] == 6) && (front[2] == 2))) {
		if(top[8] == 6) top[8] = 6;
		else if(top[8] == 2) {
			top[8] = 82;
			rotation++;
		} else {
			top[8] = 65;
			rotation--;
		}

		if(right[0] == 6) right[0] = 6;
		else if(right[0] == 2) right[0] = 82;
		else right[0] = 65;

		if(front[2] == 6) front[2] = 6;
		else if(front[2] == 2) front[2] = 82;
		else front[2] = 65;
	} else
	if(((top[8] == 6) && (right[0] == 4) && (front[2] == 3)) ||
	   ((top[8] == 4) && (right[0] == 3) && (front[2] == 6)) ||
	   ((top[8] == 3) && (right[0] == 6) && (front[2] == 4))) {
		if(top[8] == 6) top[8] = 86;
		else if(top[8] == 4) {
			top[8] = 84;
			rotation++;
		} else {
			top[8] = 63;
			rotation--;
		}

		if(right[0] == 6) right[0] = 86;
		else if(right[0] == 4) right[0] = 84;
		else right[0] = 63;

		if(front[2] == 6) front[2] = 86;
		else if(front[2] == 4) front[2] = 84;
		else front[2] = 63;
	} else
	if(((top[8] == 6) && (right[0] == 3) && (front[2] == 2)) ||
	   ((top[8] == 3) && (right[0] == 2) && (front[2] == 6)) ||
	   ((top[8] == 2) && (right[0] == 6) && (front[2] == 3))) {
		if(top[8] == 6) top[8] = 66;
		else if(top[8] == 3) {
			top[8] = 83;
			rotation++;
		} else {
			top[8] = 62;
			rotation--;
		}

		if(right[0] == 6) right[0] = 66;
		else if(right[0] == 3) right[0] = 83;
		else right[0] = 62;

		if(front[2] == 6) front[2] = 66;
		else if(front[2] == 3) front[2] = 83;
		else front[2] = 62;
	} else
	if(((top[8] == 6) && (right[0] == 5) && (front[2] == 4)) ||
	   ((top[8] == 5) && (right[0] == 4) && (front[2] == 6)) ||
	   ((top[8] == 4) && (right[0] == 6) && (front[2] == 5))) {
		if(top[8] == 6) top[8] = 26;
		else if(top[8] == 5) {
			top[8] = 85;
			rotation++;
		} else {
			top[8] = 64;
			rotation--;
		}

		if(right[0] == 6) right[0] = 26;
		else if(right[0] == 5) right[0] = 85;
		else right[0] = 64;

		if(front[2] == 6) front[2] = 26;
		else if(front[2] == 5) front[2] = 85;
		else front[2] = 64;
	} else return(3);


// corner 5

		
	if(((bottom[0] == 1) && (left[8] == 2) && (front[6] == 3)) ||
	   ((bottom[0] == 2) && (left[8] == 3) && (front[6] == 1)) ||
	   ((bottom[0] == 3) && (left[8] == 1) && (front[6] == 2))) {
	   	if(bottom[0] == 1) bottom[0] = 1;
		else if(bottom[0] == 2) {
			bottom[0] = 2;
			rotation++;
		} else {
			bottom[0] = 23;
			rotation--;
		}

		if(left[8] == 1) left[8] = 1;
		else if(left[8] == 2) left[8] = 2;
		else left[8] = 23;

		if(front[6] == 1) front[6] = 1;
		else if(front[6] == 2) front[6] = 2;
		else front[6] = 23;
	} else
	if(((bottom[0] == 1) && (left[8] == 3) && (front[6] == 4)) ||
	   ((bottom[0] == 3) && (left[8] == 4) && (front[6] == 1)) ||
	   ((bottom[0] == 4) && (left[8] == 1) && (front[6] == 3))) {
		if(bottom[0] == 1) bottom[0] = 21;
		else if(bottom[0] == 3) {
			bottom[0] = 3;
			rotation++;
		} else {
			bottom[0] = 24;
			rotation--;
		}

		if(left[8] == 1) left[8] = 21;
		else if(left[8] == 3) left[8] = 3;
		else left[8] = 24;

		if(front[6] == 1) front[6] = 21;
		else if(front[6] == 3) front[6] = 3;
		else front[6] = 24;
	} else
	if(((bottom[0] == 1) && (left[8] == 5) && (front[6] == 2)) ||
	   ((bottom[0] == 5) && (left[8] == 2) && (front[6] == 1)) ||
	   ((bottom[0] == 2) && (left[8] == 1) && (front[6] == 5))) {
		if(bottom[0] == 1) bottom[0] = 61;
		else if(bottom[0] == 5) {
			bottom[0] = 5;
			rotation++;
		} else {
			bottom[0] = 22;
			rotation--;
		}

		if(left[8] == 1) left[8] = 61;
		else if(left[8] == 5) left[8] = 5;
		else left[8] = 22;

		if(front[6] == 1) front[6] = 61;
		else if(front[6] == 5) front[6] = 5;
		else front[6] = 22;
	} else
	if(((bottom[0] == 1) && (left[8] == 4) && (front[6] == 5)) ||
	   ((bottom[0] == 5) && (left[8] == 1) && (front[6] == 4)) ||
	   ((bottom[0] == 4) && (left[8] == 5) && (front[6] == 1))) {
		if(bottom[0] == 1) bottom[0] = 81;
		else if(bottom[0] == 5) {
			bottom[0] = 25;
			rotation--;
		} else {
			bottom[0] = 4;
			rotation++;
		}

		if(left[8] == 1) left[8] = 81;
		else if(left[8] == 5) left[8] = 25;
		else left[8] = 4;

		if(front[6] == 1) front[6] = 81;
		else if(front[6] == 5) front[6] = 25;
		else front[6] = 4;
	} else
	if(((bottom[0] == 6) && (left[8] == 2) && (front[6] == 5)) ||
	   ((bottom[0] == 2) && (left[8] == 5) && (front[6] == 6)) ||
   	   ((bottom[0] == 5) && (left[8] == 6) && (front[6] == 2))) {
		if(bottom[0] == 6) bottom[0] = 6;
		else if(bottom[0] == 2) {
			bottom[0] = 82;
			rotation++;
		} else {
			bottom[0] = 65;
			rotation--;
		}

		if(left[8] == 6) left[8] = 6;
		else if(left[8] == 2) left[8] = 82;
		else left[8] = 65;

		if(front[6] == 6) front[6] = 6;
		else if(front[6] == 2) front[6] = 82;
		else front[6] = 65;
	} else
	if(((bottom[0] == 6) && (left[8] == 4) && (front[6] == 3)) ||
	   ((bottom[0] == 4) && (left[8] == 3) && (front[6] == 6)) ||
	   ((bottom[0] == 3) && (left[8] == 6) && (front[6] == 4))) {
		if(bottom[0] == 6) bottom[0] = 86;
		else if(bottom[0] == 4) {
			bottom[0] = 84;
			rotation++;
		} else {
			bottom[0] = 63;
			rotation--;
		}

		if(left[8] == 6) left[8] = 86;
		else if(left[8] == 4) left[8] = 84;
		else left[8] = 63;

		if(front[6] == 6) front[6] = 86;
		else if(front[6] == 4) front[6] = 84;
		else front[6] = 63;
	} else
	if(((bottom[0] == 6) && (left[8] == 3) && (front[6] == 2)) ||
	   ((bottom[0] == 3) && (left[8] == 2) && (front[6] == 6)) ||
	   ((bottom[0] == 2) && (left[8] == 6) && (front[6] == 3))) {
		if(bottom[0] == 6) bottom[0] = 66;
		else if(bottom[0] == 3) {
			bottom[0] = 83;
			rotation++;
		} else {
			bottom[0] = 62;
			rotation--;
		}

		if(left[8] == 6) left[8] = 66;
		else if(left[8] == 3) left[8] = 83;
		else left[8] = 62;

		if(front[6] == 6) front[6] = 66;
		else if(front[6] == 3) front[6] = 83;
		else front[6] = 62;
	} else
	if(((bottom[0] == 6) && (left[8] == 5) && (front[6] == 4)) ||
	   ((bottom[0] == 5) && (left[8] == 4) && (front[6] == 6)) ||
	   ((bottom[0] == 4) && (left[8] == 6) && (front[6] == 5))) {
		if(bottom[0] == 6) bottom[0] = 26;
		else if(bottom[0] == 5) {
			bottom[0] = 85;
			rotation++;
		} else {
			bottom[0] = 64;
			rotation--;
		}

		if(left[8] == 6) left[8] = 26;
		else if(left[8] == 5) left[8] = 85;
		else left[8] = 64;

		if(front[6] == 6) front[6] = 26;
		else if(front[6] == 5) front[6] = 85;
		else front[6] = 64;
	} else return(3);


// corner 6 
	if(((bottom[2] == 1) && (front[8] == 2) && (right[6] == 3)) ||
	   ((bottom[2] == 2) && (front[8] == 3) && (right[6] == 1)) ||
	   ((bottom[2] == 3) && (front[8] == 1) && (right[6] == 2))) {
		if(bottom[2] == 1) bottom[2] = 1;
		else if(bottom[2] == 2) {
			bottom[2] = 2;
			rotation++;
		} else {
			bottom[2] = 23;
			rotation--;
		}

		if(front[8] == 1) front[8] = 1;
		else if(front[8] == 2) front[8] = 2;
		else front[8] = 23;

		if(right[6] == 1) right[6] = 1;
		else if(right[6] == 2) right[6] = 2;
		else right[6] = 23;
	} else
	if(((bottom[2] == 1) && (front[8] == 3) && (right[6] == 4)) ||
	   ((bottom[2] == 3) && (front[8] == 4) && (right[6] == 1)) ||
	   ((bottom[2] == 4) && (front[8] == 1) && (right[6] == 3))) {
		if(bottom[2] == 1) bottom[2] = 21;
		else if(bottom[2] == 3) {
			bottom[2] = 3;
			rotation++;
		} else {
			bottom[2] = 24;
			rotation--;
		}

		if(front[8] == 1) front[8] = 21;
		else if(front[8] == 3) front[8] = 3;
		else front[8] = 24;

		if(right[6] == 1) right[6] = 21;
		else if(right[6] == 3) right[6] = 3;
		else right[6] = 24;
	} else
	if(((bottom[2] == 1) && (front[8] == 5) && (right[6] == 2)) ||
	   ((bottom[2] == 5) && (front[8] == 2) && (right[6] == 1)) ||
	   ((bottom[2] == 2) && (front[8] == 1) && (right[6] == 5))) {
		if(bottom[2] == 1) bottom[2] = 61;
		else if(bottom[2] == 5) {
			bottom[2] = 5;
			rotation++;
		} else {
			bottom[2] = 22;
			rotation--;
		}

		if(front[8] == 1) front[8] = 61;
		else if(front[8] == 5) front[8] = 5;
		else front[8] = 22;

		if(right[6] == 1) right[6] = 61;
		else if(right[6] == 5) right[6] = 5;
		else right[6] = 22;
	} else
	if(((bottom[2] == 1) && (front[8] == 4) && (right[6] == 5)) ||
	   ((bottom[2] == 4) && (front[8] == 5) && (right[6] == 1)) ||
	   ((bottom[2] == 5) && (front[8] == 1) && (right[6] == 4))) {
		if(bottom[2] == 1) bottom[2] = 81;
		else if(bottom[2] == 5) {
			bottom[2] = 25;
			rotation--;
		} else {
			bottom[2] = 4;
			rotation++;
		}

		if(front[8] == 1) front[8] = 81;
		else if(front[8] == 5) front[8] = 25;
		else front[8] = 4;

		if(right[6] == 1) right[6] = 81;
		else if(right[6] == 5) right[6] = 25;
		else right[6] = 4;
	} else
	if(((bottom[2] == 6) && (front[8] == 2) && (right[6] == 5)) ||
	   ((bottom[2] == 2) && (front[8] == 5) && (right[6] == 6)) ||
   	   ((bottom[2] == 5) && (front[8] == 6) && (right[6] == 2))) {
		if(bottom[2] == 6) bottom[2] = 6;
		else if(bottom[2] == 2) {
			bottom[2] = 82;
			rotation++;
		} else {
			bottom[2] = 65;
			rotation--;
		}

		if(front[8] == 6) front[8] = 6;
		else if(front[8] == 2) front[8] = 82;
		else front[8] = 65;

		if(right[6] == 6) right[6] = 6;
		else if(right[6] == 2) right[6] = 82;
		else right[6] = 65;
	} else
	if(((bottom[2] == 6) && (front[8] == 4) && (right[6] == 3)) ||
	   ((bottom[2] == 4) && (front[8] == 3) && (right[6] == 6)) ||
	   ((bottom[2] == 3) && (front[8] == 6) && (right[6] == 4))) {
		if(bottom[2] == 6) bottom[2] = 86;
		else if(bottom[2] == 4) {
			bottom[2] = 84;
			rotation++;
		} else {
			bottom[2] = 63;
			rotation--;
		}

		if(front[8] == 6) front[8] = 86;
		else if(front[8] == 4) front[8] = 84;
		else front[8] = 63;

		if(right[6] == 6) right[6] = 86;
		else if(right[6] == 4) right[6] = 84;
		else right[6] = 63;
	} else
	if(((bottom[2] == 6) && (front[8] == 3) && (right[6] == 2)) ||
	   ((bottom[2] == 3) && (front[8] == 2) && (right[6] == 6)) ||
	   ((bottom[2] == 2) && (front[8] == 6) && (right[6] == 3))) {
		if(bottom[2] == 6) bottom[2] = 66;
		else if(bottom[2] == 3) {
			bottom[2] = 83;
			rotation++;
		} else {
			bottom[2] = 62;
			rotation--;
		}

		if(front[8] == 6) front[8] = 66;
		else if(front[8] == 3) front[8] = 83;
		else front[8] = 62;

		if(right[6] == 6) right[6] = 66;
		else if(right[6] == 3) right[6] = 83;
		else right[6] = 62;
	} else
	if(((bottom[2] == 6) && (front[8] == 5) && (right[6] == 4)) ||
	   ((bottom[2] == 5) && (front[8] == 4) && (right[6] == 6)) ||
	   ((bottom[2] == 4) && (front[8] == 6) && (right[6] == 5))) {
		if(bottom[2] == 6) bottom[2] = 26;
		else if(bottom[2] == 5) {
			bottom[2] = 85;
			rotation++;
		} else {
			bottom[2] = 64;
			rotation--;
		}

		if(front[8] == 6) front[8] = 26;
		else if(front[8] == 5) front[8] = 85;
		else front[8] = 64;

		if(right[6] == 6) right[6] = 26;
		else if(right[6] == 5) right[6] = 85;
		else right[6] = 64;
	} else return(3);

// corner 7
	
	if(((bottom[6] == 1) && (back[8] == 3) && (left[6] == 4)) ||
	   ((bottom[6] == 3) && (back[8] == 4) && (left[6] == 1)) ||
   	   ((bottom[6] == 4) && (back[8] == 1) && (left[6] == 3))) {
		if(bottom[6] == 1) bottom[6] = 21;
		else if(bottom[6] == 3) {
			bottom[6] = 3;
			rotation++;
		} else {
			bottom[6] = 24;
			rotation--;
		}

		if(back[8] == 1) back[8] = 21;
		else if(back[8] == 3) back[8] = 3;
		else back[8] = 24;

		if(left[6] == 1) left[6] = 21;
		else if(left[6] == 3) left[6] = 3;
		else left[6] = 24;
	} else
	if(((bottom[6] == 1) && (back[8] == 5) && (left[6] == 2)) ||
	   ((bottom[6] == 5) && (back[8] == 2) && (left[6] == 1)) ||
	   ((bottom[6] == 2) && (back[8] == 1) && (left[6] == 5))) {
		if(bottom[6] == 1) bottom[6] = 61;
		else if(bottom[6] == 5) {
			bottom[6] = 5;
			rotation++;
		} else {
			bottom[6] = 22;
			rotation--;
		}

		if(back[8] == 1) back[8] = 61;
		else if(back[8] == 5) back[8] = 5;
		else back[8] = 22;

		if(left[6] == 1) left[6] = 61;
		else if(left[6] == 5) left[6] = 5;
		else left[6] = 22;
	} else
	if(((bottom[6] == 1) && (back[8] == 2) && (left[6] == 3)) ||
	   ((bottom[6] == 2) && (back[8] == 3) && (left[6] == 1)) ||
	   ((bottom[6] == 3) && (back[8] == 1) && (left[6] == 2))) {
		if(bottom[6] == 1) bottom[6] = 1;
		else if(bottom[6] == 2) {
			bottom[6] = 2;
			rotation++;
		} else {
			bottom[6] = 23;
			rotation--;
		}

		if(back[8] == 1) back[8] = 1;
		else if(back[8] == 2) back[8] = 2;
		else back[8] = 23;

		if(left[6] == 1) left[6] = 1;
		else if(left[6] == 2) left[6] =2;
		else left[6] = 23;
	} else
	if(((bottom[6] == 1) && (back[8] == 4) && (left[6] == 5)) ||
	   ((bottom[6] == 5) && (back[8] == 1) && (left[6] == 4)) ||
	   ((bottom[6] == 4) && (back[8] == 5) && (left[6] == 1))) {
		if(bottom[6] == 1) bottom[6] = 81;
		else if(bottom[6] == 5) {
			bottom[6] = 25;
			rotation--;
		} else {
			bottom[6] = 4;
			rotation++;
		}

		if(back[8] == 1) back[8] = 81;
		else if(back[8] == 5) back[8] = 25;
		else back[8] = 4;

		if(left[6] == 1) left[6] = 81;
		else if(left[6] == 5) left[6] = 25;
		else left[6] = 4;
	} else
	if(((bottom[6] == 6) && (back[8] == 2) && (left[6] == 5)) ||
	   ((bottom[6] == 2) && (back[8] == 5) && (left[6] == 6)) ||
   	   ((bottom[6] == 5) && (back[8] == 6) && (left[6] == 2))) {
		if(bottom[6] == 6) bottom[6] = 6;
		else if(bottom[6] == 2) {
			bottom[6] = 82;
			rotation++;
		} else {
			bottom[6] = 65;
			rotation--;
		}

		if(back[8] == 6) back[8] = 6;
		else if(back[8] == 2) back[8] = 82;
		else back[8] = 65;

		if(left[6] == 6) left[6] = 6;
		else if(left[6] == 2) left[6] = 82;
		else left[6] = 65;
	} else
	if(((bottom[6] == 6) && (back[8] == 4) && (left[6] == 3)) ||
	   ((bottom[6] == 4) && (back[8] == 3) && (left[6] == 6)) ||
	   ((bottom[6] == 3) && (back[8] == 6) && (left[6] == 4))) {
		if(bottom[6] == 6) bottom[6] = 86;
		else if(bottom[6] == 4) {
			bottom[6] = 84;
			rotation++;
		} else {
			bottom[6] = 63;
			rotation--;
		}

		if(back[8] == 6) back[8] = 86;
		else if(back[8] == 4) back[8] = 84;
		else back[8] = 63;

		if(left[6] == 6) left[6] = 86;
		else if(left[6] == 4) left[6] = 84;
		else left[6] = 63;
	} else
	if(((bottom[6] == 6) && (back[8] == 3) && (left[6] == 2)) ||
	   ((bottom[6] == 3) && (back[8] == 2) && (left[6] == 6)) ||
	   ((bottom[6] == 2) && (back[8] == 6) && (left[6] == 3))) {
		if(bottom[6] == 6) bottom[6] = 66;
		else if(bottom[6] == 3) {
			bottom[6] = 83;
			rotation++;
		} else {
			bottom[6] = 62;
			rotation--;
		}

		if(back[8] == 6) back[8] = 66;
		else if(back[8] == 3) back[8] = 83;
		else back[8] = 62;

		if(left[6] == 6) left[6] = 66;
		else if(left[6] == 3) left[6] = 83;
		else left[6] = 62;
	} else
	if(((bottom[6] == 6) && (back[8] == 5) && (left[6] == 4)) ||
	   ((bottom[6] == 5) && (back[8] == 4) && (left[6] == 6)) ||
	   ((bottom[6] == 4) && (back[8] == 6) && (left[6] == 5))) {
		if(bottom[6] == 6) bottom[6] = 26;
		else if(bottom[6] == 5) {
			bottom[6] = 85;
			rotation++;
		} else {
			bottom[6] = 64;
			rotation--;
		}

		if(back[8] == 6) back[8] = 26;
		else if(back[8] == 5) back[8] = 85;
		else back[8] = 64;

		if(left[6] == 6) left[6] = 26;
		else if(left[6] == 5) left[6] = 85;
		else left[6] = 64;
	} else return(3);



// corner 8
	if(((bottom[8] == 1) && (right[8] == 2) && (back[6] == 3)) ||
	   ((bottom[8] == 2) && (right[8] == 3) && (back[6] == 1)) ||
	   ((bottom[8] == 3) && (right[8] == 1) && (back[6] == 2))) {
		if(bottom[8] == 1) bottom[8] = 1;
		else if(bottom[8] == 2) {
			bottom[8] = 2;
			rotation++;
		} else {
			bottom[8] = 23;
			rotation--;
		}

		if(right[8] == 1) right[8] = 1;
		else if(right[8] == 2) right[8] = 2;
		else right[8] = 23;

		if(back[6] == 1) back[6] = 1;
		else if(back[6] == 2) back[6] = 2;
		else back[6] = 23;
	} else
	if(((bottom[8] == 1) && (right[8] == 3) && (back[6] == 4)) ||
	   ((bottom[8] == 3) && (right[8] == 4) && (back[6] == 1)) ||
   	   ((bottom[8] == 4) && (right[8] == 1) && (back[6] == 3))) {
		if(bottom[8] == 1) bottom[8] = 21;
		else if(bottom[8] == 3) {
			bottom[8] = 3;
			rotation++;
		} else {
			bottom[8] = 24;
			rotation--;
		}

		if(right[8] == 1) right[8] = 21;
		else if(right[8] == 3) right[8] = 3;
		else right[8] = 24;

		if(back[6] == 1) back[6] = 21;
		else if(back[6] == 3) back[6] = 3;
		else back[6] = 24;
	} else
	if(((bottom[8] == 1) && (right[8] == 5) && (back[6] == 2)) ||
	   ((bottom[8] == 5) && (right[8] == 2) && (back[6] == 1)) ||
	   ((bottom[8] == 2) && (right[8] == 1) && (back[6] == 5))) {
		if(bottom[8] == 1) bottom[8] = 61;
		else if(bottom[8] == 5) {
			bottom[8] = 5;
			rotation++;
		} else {
			bottom[8] = 22;
			rotation--;
		}

		if(right[8] == 1) right[8] = 61;
		else if(right[8] == 5) right[8] = 5;
		else right[8] = 22;

		if(back[6] == 1) back[6] = 61;
		else if(back[6] == 5) back[6] = 5;
		else back[6] = 22;
	} else
	if(((bottom[8] == 1) && (right[8] == 4) && (back[6] == 5)) ||
	   ((bottom[8] == 5) && (right[8] == 1) && (back[6] == 4)) ||
	   ((bottom[8] == 4) && (right[8] == 5) && (back[6] == 1))) {
		if(bottom[8] == 1) bottom[8] = 81;
		else if(bottom[8] == 5) {
			bottom[8] = 25;
			rotation--;
		} else {
			bottom[8] = 4;
			rotation++;
		}

		if(right[8] == 1) right[8] = 81;
		else if(right[8] == 5) right[8] = 25;
		else right[8] = 4;

		if(back[6] == 1) back[6] = 81;
		else if(back[6] == 5) back[6] = 25;
		else back[6] = 4;
	} else
	if(((bottom[8] == 6) && (right[8] == 2) && (back[6] == 5)) ||
	   ((bottom[8] == 2) && (right[8] == 5) && (back[6] == 6)) ||
   	   ((bottom[8] == 5) && (right[8] == 6) && (back[6] == 2))) {
		if(bottom[8] == 6) bottom[8] = 6;
		else if(bottom[8] == 2) {
			bottom[8] = 82;
			rotation++;
		} else {
			bottom[8] = 65;
			rotation--;
		}

		if(right[8] == 6) right[8] = 6;
		else if(right[8] == 2) right[8] = 82;
		else right[8] = 65;

		if(back[6] == 6) back[6] = 6;
		else if(back[6] == 2) back[6] = 82;
		else back[6] = 65;

	} else 
	if(((bottom[8] == 6) && (right[8] == 4) && (back[6] == 3)) ||
	   ((bottom[8] == 4) && (right[8] == 3) && (back[6] == 6)) ||
	   ((bottom[8] == 3) && (right[8] == 6) && (back[6] == 4))) {
		if(bottom[8] == 6) bottom[8] = 86;
		else if(bottom[8] == 4) {
			bottom[8] = 84;
			rotation++;
		} else {
			bottom[8] = 63;
			rotation--;
		}

		if(right[8] == 6) right[8] = 86;
		else if(right[8] == 4) right[8] = 84;
		else right[8] = 63;

		if(back[6] == 6) back[6] = 86;
		else if(back[6] == 4) back[6] = 84;
		else back[6] = 63;
	} else
	if(((bottom[8] == 6) && (right[8] == 3) && (back[6] == 2)) ||
	   ((bottom[8] == 3) && (right[8] == 2) && (back[6] == 6)) ||
	   ((bottom[8] == 2) && (right[8] == 6) && (back[6] == 3))) {
		if(bottom[8] == 6) bottom[8] = 66;
		else if(bottom[8] == 3) {
			bottom[8] = 83;
			rotation++;
		} else {
			bottom[8] = 62;
			rotation--;
		}

		if(right[8] == 6) right[8] = 66;
		else if(right[8] == 3) right[8] = 83;
		else right[8] = 62;

		if(back[6] == 6) back[6] = 66;
		else if(back[6] == 3) back[6] = 83;
		else back[6] = 62;
	} else 
	if(((bottom[8] == 6) && (right[8] == 5) && (back[6] == 4)) ||
	   ((bottom[8] == 5) && (right[8] == 4) && (back[6] == 6)) ||
	   ((bottom[8] == 4) && (right[8] == 6) && (back[6] == 5))) {
		if(bottom[8] == 6) bottom[8] = 26;
		else if(bottom[8] == 5) {
			bottom[8] = 85;
			rotation++;
		} else {
			bottom[8] = 64;
			rotation--;
		}

		if(right[8] == 6) right[8] = 26;
		else if(right[8] == 5) right[8] = 85;
		else right[8] = 64;

		if(back[6] == 6) back[6] = 26;
		else if(back[6] == 5) back[6] = 85;
		else back[6] = 64;
	} else return(3);



// put correct numbers on each edge or return error
// edge 1

	if(((top[1] == 1) && (back[1] == 2)) || ((top[1] == 2) && (back[1] == 1))) {
		if(top[1] == 1) {
			top[1] = 31;
			back[1] = 12;
		} else {
			top[1] = 12;
			back[1] = 31;
		}
	} else if(((top[1] == 1) && (back[1] == 5)) || ((top[1] == 5) && (back[1] == 1))) {
		if(top[1] == 1) {
			top[1] = 71;
			back[1] = 15;
		} else {
			top[1] = 15;
			back[1] = 71;
		}
	} else if(((top[1] == 1) && (back[1] == 4)) || ((top[1] == 4) && (back[1] == 1))) {
		if(top[1] == 1) {
			top[1] = 51;
			back[1] = 14;
		} else {
			top[1] = 14;
			back[1] = 51;
		}
	} else if(((top[1] == 1) && (back[1] == 3))  || ((top[1] == 3) && (back[1] == 1))) {
		if(top[1] == 1) {
			top[1] = 11;
			back[1] = 13;
		} else {
			top[1] = 13;
			back[1] = 11;
		}
	} else if(((top[1] == 6) && (back[1] == 2)) || ((top[1] == 2) && (back[1] == 6))) {
		if (top[1] == 6) {
			top[1] = 36;
			back[1] = 72;
		} else {
			top[1] = 72;
			back[1] = 36;
		}
	} else if(((top[1] == 6) && (back[1] == 5)) || ((top[1] == 5) && (back[1] == 6))) {
		if(top[1] == 6) {
			top[1] = 16;
			back[1] = 75;
		} else {
			top[1] = 75;
			back[1] = 16;
		}
	} else if(((top[1] == 6) && (back[1] == 4)) || ((top[1] == 4) && (back[1] == 6))) {
		if(top[1] == 6) {
			top[1] = 56;
			back[1] = 74;
		} else {
			top[1] = 74;
			back[1] = 56;
		}
	} else if(((top[1] == 6) && (back[1] == 3)) || ((top[1] == 3) && (back[1] == 6))) {
		if(top[1] ==6) {
			top[1] = 76;
			back[1] = 73;
		} else {
			top[1] = 73;
			back[1] = 76;
		}
	} else if(((top[1] == 3) && (back[1] == 4)) || ((top[1] == 4) && (back[1] == 3))) {
		if(top[1] == 3) {
			top[1] = 33;
			back[1] = 54;
		} else {
			top[1] = 54;
			back[1] = 33;
		}
	} else if(((top[1] == 4) && (back[1] == 5)) || ((top[1] == 5) && (back[1] == 4))) {
		if(top[1] == 4) {
			top[1] = 34;
			back[1] = 55;
		} else {
			top[1] = 55;
			back[1] = 34;
		}
	} else if(((top[1] == 5) && (back[1] == 2)) || ((top[1] == 2) && (back[1] == 5))) {
		if(top[1] == 5) {
			top[1] = 35;
			back[1] = 52;
		} else {
			top[1] = 52;
			back[1] = 35;
		}
	} else if(((top[1] == 2) && (back[1] == 3)) || ((top[1] == 3) && (back[1] == 2))) {
		if(top[1] == 2) {
			top[1] = 32;
			back[1] = 53;
		} else {
			top[1] = 53;
			back[1] = 32;
		}
	} else return(4);

// edge 2
	if(((top[3] == 1) && (left[1] == 2)) || ((top[3] == 2) && (left[1] == 1))) {
		if(top[3] == 1) {
			top[3] = 31;
			left[1] = 12;
		} else {
			top[3] = 12;
			left[1] = 31;
		}
	} else if(((top[3] == 1) && (left[1] == 5)) || ((top[3] == 5) && (left[1] == 1))) {
		if(top[3] == 1) {
			top[3] = 71;
			left[1] = 15;
		} else {
			top[3] = 15;
			left[1] = 71;
		}
	} else if(((top[3] == 1) && (left[1] == 4)) || ((top[3] == 4) && (left[1] == 1))) {
		if(top[3] == 1) {
			top[3] = 51;
			left[1] = 14;
		} else {
			top[3] = 14;
			left[1] = 51;
		}
	} else if(((top[3] == 1) && (left[1] == 3))  || ((top[3] == 3) && (left[1] == 1))) {
		if(top[3] == 1) {
			top[3] = 11;
			left[1] = 13;
		} else {
			top[3] = 13;
			left[1] = 11;
		}
	} else if(((top[3] == 6) && (left[1] == 2)) || ((top[3] == 2) && (left[1] == 6))) {
		if (top[3] == 6) {
			top[3] = 36;
			left[1] = 72;
		} else {
			top[3] = 72;
			left[1] = 36;
		}
	} else if(((top[3] == 6) && (left[1] == 5)) || ((top[3] == 5) && (left[1] == 6))) {
		if(top[3] == 6) {
			top[3] = 16;
			left[1] = 75;
		} else {
			top[3] = 75;
			left[1] = 16;
		}
	} else if(((top[3] == 6) && (left[1] == 4)) || ((top[3] == 4) && (left[1] == 6))) {
		if(top[3] == 6) {
			top[3] = 56;
			left[1] = 74;
		} else {
			top[3] = 74;
			left[1] = 56;
		}
	} else if(((top[3] == 6) && (left[1] == 3)) || ((top[3] == 3) && (left[1] == 6))) {
		if(top[3] == 6) {
			top[3] = 76;
			left[1] = 73;
		} else {
			top[3] = 73;
			left[1] = 76;
		}
	} else if(((top[3] == 3) && (left[1] == 4)) || ((top[3] == 4) && (left[1] == 3))) {
		if(top[3] == 3) {
			top[3] = 33;
			left[1] = 54;
		} else {
			top[3] = 54;
			left[1] = 33;
		}
	} else if(((top[3] == 2) && (left[1] == 3)) || ((top[3] == 3) && (left[1] == 2))) {
		if(top[3] == 2) {
			top[3] = 32;
			left[1] = 53;
		} else {
			top[3] = 53;
			left[1] = 32;
		}
	} else if(((top[3] == 4) && (left[1] == 5)) || ((top[3] == 5) && (left[1] == 4))) {
		if(top[3] == 4) {
			top[3] = 34;
			left[1] = 55;
		} else {
			top[3] = 55;
			left[1] = 34;
		}
	} else if(((top[3] == 5) && (left[1] == 2)) || ((top[3] == 2) && (left[1] == 5))) {
		if(top[3] == 5) {
			top[3] = 35;
			left[1] = 52;
		} else {
			top[3] = 52;
			left[1] = 35;
		}
	} else if(((top[3] = 2) && (left[1] == 3)) || ((top[3] == 3) && (left[1] == 2))) {
		if(top[3] == 2) {
			top[3] = 32;
			left[1] = 53;
		} else {
			top[3] = 53;
			left[1] = 32;
		}
	} else return(4);
// edge 3
	if(((top[5] == 1) && (right[1] == 2)) || ((top[5] == 2) && (right[1] == 1))) {
		if(top[5] == 1) {
			top[5] = 31;
			right[1] = 12;
		} else {
			top[5] = 12;
			right[1] = 31;
		}
	} else if(((top[5] == 1) && (right[1] == 5)) || ((top[5] == 5) && (right[1] == 1))) {
		if(top[5] == 1) {
			top[5] = 71;
			right[1] = 15;
		} else {
			top[5] = 15;
			right[1] = 71;
		}
	} else if(((top[5] == 1) && (right[1] == 4)) || ((top[5] == 4) && (right[1] == 1))) {
		if(top[5] == 1) {
			top[5] = 51;
			right[1] = 14;
		} else {
			top[5] = 14;
			right[1] = 51;
		}
	} else if(((top[5] == 1) && (right[1] == 3))  || ((top[5] == 3) && (right[1] == 1))) {
		if(top[5] == 1) {
			top[5] = 11;
			right[1] = 13;
		} else {
			top[5] = 13;
			right[1] = 11;
		}
	} else if(((top[5] == 6) && (right[1] == 2)) || ((top[5] == 2) && (right[1] == 6))) {
		if (top[5] == 6) {
			top[5] = 36;
			right[1] = 72;
		} else {
			top[5] = 72;
			right[1] = 36;
		}
	} else if(((top[5] == 6) && (right[1] == 5)) || ((top[5] == 5) && (right[1] == 6))) {
		if(top[5] == 6) {
			top[5] = 16;
			right[1] = 75;
		} else {
			top[5] = 75;
			right[1] = 16;
		}
	} else if(((top[5] == 6) && (right[1] == 4)) || ((top[5] == 4) && (right[1] == 6))) {
		if(top[5] == 6) {
			top[5] = 56;
			right[1] = 74;
		} else {
			top[5] = 74;
			right[1] = 56;
		}
	} else if(((top[5] == 6) && (right[1] == 3)) || ((top[5] == 3) && (right[1] == 6))) {
		if(top[5] ==6) {
			top[5] = 76;
			right[1] = 73;
		} else {
			top[5] = 73;
			right[1] = 76;
		}
	} else if(((top[5] == 3) && (right[1] == 4)) || ((top[5] == 4) && (right[1] == 3))) {
		if(top[5] == 3) {
			top[5] = 33;
			right[1] = 54;
		} else {
			top[5] = 54;
			right[1] = 33;
		}
	} else if(((top[5] == 4) && (right[1] == 5)) || ((top[5] == 5) && (right[1] == 4))) {
		if(top[5] == 4) {
			top[5] = 34;
			right[1] = 55;
		} else {
			top[5] = 55;
			right[1] = 34;
		}
	} else if(((top[5] == 5) && (right[1] == 2)) || ((top[5] == 2) && (right[1] == 5))) {
		if(top[5] == 5) {
			top[5] = 35;
			right[1] = 52;
		} else {
			top[5] = 52;
			right[1] = 35;
		}
	} else if(((top[5] == 2) && (right[1] == 3)) || ((top[5] == 3) && (right[1] == 2))) {
		if(top[5] == 2) {
			top[5] = 32;
			right[1] = 53;
		} else {
			top[5] = 53;
			right[1] = 32;
		}
	} else return(4);
	
// edge 4
	if(((top[7] == 1) && (front[1] == 2)) || ((top[7] == 2) && (front[1] == 1))) {
		if(top[7] == 1) {
			top[7] = 31;
			front[1] = 12;
		} else {
			top[7] = 12;
			front[1] = 31;
		}
	} else if(((top[7] == 1) && (front[1] == 5)) || ((top[7] == 5) && (front[1] == 1))) {
		if(top[7] == 1) {
			top[7] = 71;
			front[1] = 15;
		} else {
			top[7] = 15;
			front[1] = 71;
		}
	}
	else if(((top[7] == 1) && (front[1] == 4)) || ((top[7] == 4) && (front[1] == 1))) {
		if(top[7] == 1) {
			top[7] = 51;
			front[1] = 14;
		} else {
			top[7] = 14;
			front[1] = 51;
		}
	} else if(((top[7] == 1) && (front[1] == 3))  || ((top[7] == 3) && (front[1] == 1))) {
		if(top[7] == 1) {
			top[7] = 11;
			front[1] = 13;
		} else {
			top[7] = 13;
			front[1] = 11;
		}
	} else if(((top[7] == 6) && (front[1] == 2)) || ((top[7] == 2) && (front[1] == 6))) {
		if (top[7] == 6) {
			top[7] = 36;
			front[1] = 72;
		} else {
			top[7] = 72;
			front[1] = 36;
		}
	} else if(((top[7] == 6) && (front[1] == 5)) || ((top[7] == 5) && (front[1] == 6))) {
		if(top[7] == 6) {
			top[7] = 16;
			front[1] = 75;
		} else {
			top[7] = 75;
			front[1] = 16;
		}
	} else if(((top[7] == 6) && (front[1] == 4)) || ((top[7] == 4) && (front[1] == 6))) {
		if(top[7] == 6) {
			top[7] = 56;
			front[1] = 74;
		} else {
			top[7] = 74;
			front[1] = 56;
		}
	} else if(((top[7] == 6) && (front[1] == 3)) || ((top[7] == 3) && (front[1] == 6))) {
		if(top[7] ==6) {
			top[7] = 76;
			front[1] = 73;
		} else {
			top[7] = 73;
			front[1] = 76;
		}
	} else if(((top[7] == 3) && (front[1] == 4)) || ((top[7] == 4) && (front[1] == 3))) {
		if(top[7] == 3) {
			top[7] = 33;
			front[1] = 54;
		} else {
			top[7] = 54;
			front[1] = 33;
		}
	} else if(((top[7] == 4) && (front[1] == 5)) || ((top[7] == 5) && (front[1] == 4))) {
		if(top[7] == 4) {
			top[7] = 34;
			front[1] = 55;
		} else {
			top[7] = 55;
			front[1] = 34;
		}
	} else if(((top[7] == 5) && (front[1] == 2)) || ((top[7] == 2) && (front[1] == 5))) {
		if(top[7] == 5) {
			top[7] = 35;
			front[1] = 52;
		} else {
			top[7] = 52;
			front[1] = 35;
		}
	} else if(((top[7] == 2) && (front[1] == 3)) || ((top[7] == 3) && (front[1] == 2))) {
		if(top[7] == 2) {
			top[7] = 32;
			front[1] = 53;
		} else {
			top[7] = 53;
			front[1] = 32;
		}
	} else return(4);
	
// edge 5
	if(((bottom[1] == 1) && (front[7] == 5)) || ((bottom[1] == 5) && (front[7] == 1))) {
		if(bottom[1] == 1) {
			bottom[1] = 71;
			front[7] = 15;
		} else {
			bottom[1] = 15;
			front[7] = 71;
		}
	} else if(((bottom[1] == 1) && (front[7] == 2)) || ((bottom[1] == 2) && (front[7] == 1))) {
		if(bottom[1] == 1) {
			bottom[1] = 31;
			front[7] = 12;
		} else {
			bottom[1] = 12;
			front[7] = 31;
		}
	}
	else if(((bottom[1] == 1) && (front[7] == 4)) || ((bottom[1] == 4) && (front[7] == 1))) {
		if(bottom[1] == 1) {
			bottom[1] = 51;
			front[7] = 14;
		} else {
			bottom[1] = 14;
			front[7] = 51;
		}
	} else if(((bottom[1] == 1) && (front[7] == 3))  || ((bottom[1] == 3) && (front[7] == 1))) {
		if(bottom[1] == 1) {
			bottom[1] = 11;
			front[7] = 13;
		} else {
			bottom[1] = 13;
			front[7] = 11;
		}
	} else if(((bottom[1] == 6) && (front[7] == 2)) || ((bottom[1] == 2) && (front[7] == 6))) {
		if (bottom[1] == 6) {
			bottom[1] = 36;
			front[7] = 72;
		} else {
			bottom[1] = 72;
			front[7] = 36;
		}
	} else if(((bottom[1] == 6) && (front[7] == 5)) || ((bottom[1] == 5) && (front[7] == 6))) {
		if(bottom[1] == 6) {
			bottom[1] = 16;
			front[7] = 75;
		} else {
			bottom[1] = 75;
			front[7] = 16;
		}
	} else if(((bottom[1] == 6) && (front[7] == 4)) || ((bottom[1] == 4) && (front[7] == 6))) {
		if(bottom[1] == 6) {
			bottom[1] = 56;
			front[7] = 74;
		} else {
			bottom[1] = 74;
			front[7] = 56;
		}
	} else if(((bottom[1] == 6) && (front[7] == 3)) || ((bottom[1] == 3) && (front[7] == 6))) {
		if(bottom[1] == 6) {
			bottom[1] = 76;
			front[7] = 73;
		} else {
			bottom[1] = 73;
			front[7] = 76;
		}
	} else if(((bottom[1] == 3) && (front[7] == 4)) || ((bottom[1] == 4) && (front[7] == 3))) {
		if(bottom[1] == 3) {
			bottom[1] = 33;
			front[7] = 54;
		} else {
			bottom[1] = 54;
			front[7] = 33;
		}
	} else if(((bottom[1] == 4) && (front[7] == 5)) || ((bottom[1] == 5) && (front[7] == 4))) {
		if(bottom[1] == 4) {
			bottom[1] = 34;
			front[7] = 55;
		} else {
			bottom[1] = 55;
			front[7] = 34;
		}
	} else if(((bottom[1] == 5) && (front[7] == 2)) || ((bottom[1] == 2) && (front[7] == 5))) {
		if(bottom[1] == 5) {
			bottom[1] = 35;
			front[7] = 52;
		} else {
			bottom[1] = 52;
			front[7] = 35;
		}
	} else if(((bottom[1] == 2) && (front[7] == 3)) || ((bottom[1] == 3) && (front[7] == 2))) {
		if(bottom[1] == 2) {
			bottom[1] = 32;
			front[7] = 53;
		} else {
			bottom[1] = 53;
			front[7] = 32;
		}		
	} else return(4);
// edge 6
	if(((bottom[3] == 1) && (left[7] == 2)) || ((bottom[3] == 2) && (left[7] == 1))) {
		if(bottom[3] == 1) {
			bottom[3] = 31;
			left[7] = 12;
		} else {
			bottom[3] = 12;
			left[7] = 31;
		}
	} else if(((bottom[3] == 1) && (left[7] == 5)) || ((bottom[3] == 5) && (left[7] == 1))) {
		if(bottom[3] == 1) {
			bottom[3] = 71;
			left[7] = 15;
		} else {
			bottom[3] = 15;
			left[7] = 71;
		}
	}
	else if(((bottom[3] == 1) && (left[7] == 4)) || ((bottom[3] == 4) && (left[7] == 1))) {
		if(bottom[3] == 1) {
			bottom[3] = 51;
			left[7] = 14;
		} else {
			bottom[3] = 14;
			left[7] = 51;
		}
	} else if(((bottom[3] == 1) && (left[7] == 3))  || ((bottom[3] == 3) && (left[7] == 1))) {
		if(bottom[3] == 1) {
			bottom[3] = 11;
			left[7] = 13;
		} else {
			bottom[3] = 13;
			left[7] = 11;
		}
	} else if(((bottom[3] == 6) && (left[7] == 2)) || ((bottom[3] == 2) && (left[7] == 6))) {
		if (bottom[3] == 6) {
			bottom[3] = 36;
			left[7] = 72;
		} else {
			bottom[3] = 72;
			left[7] = 36;
		}
	} else if(((bottom[3] == 6) && (left[7] == 5)) || ((bottom[3] == 5) && (left[7] == 6))) {
		if(bottom[3] == 6) {
			bottom[3] = 16;
			left[7] = 75;
		} else {
			bottom[3] = 75;
			left[7] = 16;
		}
	} else if(((bottom[3] == 6) && (left[7] == 4)) || ((bottom[3] == 4) && (left[7] == 6))) {
		if(bottom[3] == 6) {
			bottom[3] = 56;
			left[7] = 74;
		} else {
			bottom[3] = 74;
			left[7] = 56;
		}
	} else if(((bottom[3] == 6) && (left[7] == 3)) || ((bottom[3] == 3) && (left[7] == 6))) {
		if(bottom[3] == 6) {
			bottom[3] = 76;
			left[7] = 73;
		} else {
			bottom[3] = 73;
			left[7] = 76;
		}
	} else if(((bottom[3] == 3) && (left[7] == 4)) || ((bottom[3] == 4) && (left[7] == 3))) {
		if(bottom[3] == 3) {
			bottom[3] = 33;
			left[7] = 54;
		} else {
			bottom[3] = 54;
			left[7] = 33;
		}
	} else if(((bottom[3] == 4) && (left[7] == 5)) || ((bottom[3] == 5) && (left[7] == 4))) {
		if(bottom[3] == 4) {
			bottom[3] = 34;
			left[7] = 55;
		} else {
			bottom[3] = 55;
			left[7] = 34;
		}
	} else if(((bottom[3] == 5) && (left[7] == 2)) || ((bottom[3] == 2) && (left[7] == 5))) {
		if(bottom[3] == 5) {
			bottom[3] = 35;
			left[7] = 52;
		} else {
			bottom[3] = 52;
			left[7] = 35;
		}
	} else if(((bottom[3] == 2) && (left[7] == 3)) || ((bottom[3] == 3) && (left[7] == 2))) {
		if(bottom[3] == 2) {
			bottom[3] = 32;
			left[7] = 53;
		} else {
			bottom[3] = 53;
			left[7] = 32;
		}		
	} else return(4);
// edge 7
	if(((bottom[5] == 1) && (right[7] == 2)) || ((bottom[5] == 2) && (right[7] == 1))) {
		if(bottom[5] == 1) {
			bottom[5] = 31;
			right[7] = 12;
		} else {
			bottom[5] = 12;
			right[7] = 31;
		}
	} else if(((bottom[5] == 1) && (right[7] == 5)) || ((bottom[5] == 5) && (right[7] == 1))) {
		if(bottom[5] == 1) {
			bottom[5] = 71;
			right[7] = 15;
		} else {
			bottom[5] = 15;
			right[7] = 71;
		}
	}
	else if(((bottom[5] == 1) && (right[7] == 4)) || ((bottom[5] == 4) && (right[7] == 1))) {
		if(bottom[5] == 1) {
			bottom[5] = 51;
			right[7] = 14;
		} else {
			bottom[5] = 14;
			right[7] = 51;
		}
	} else if(((bottom[5] == 1) && (right[7] == 3))  || ((bottom[5] == 3) && (right[7] == 1))) {
		if(bottom[5] == 1) {
			bottom[5] = 11;
			right[7] = 13;
		} else {
			bottom[5] = 13;
			right[7] = 11;
		}
	} else if(((bottom[5] == 6) && (right[7] == 2)) || ((bottom[5] == 2) && (right[7] == 6))) {
		if (bottom[5] == 6) {
			bottom[5] = 36;
			right[7] = 72;
		} else {
			bottom[5] = 72;
			right[7] = 36;
		}
	} else if(((bottom[5] == 6) && (right[7] == 5)) || ((bottom[5] == 5) && (right[7] == 6))) {
		if(bottom[5] == 6) {
			bottom[5] = 16;
			right[7] = 75;
		} else {
			bottom[5] = 75;
			right[7] = 16;
		}
	} else if(((bottom[5] == 6) && (right[7] == 4)) || ((bottom[5] == 4) && (right[7] == 6))) {
		if(bottom[5] == 6) {
			bottom[5] = 56;
			right[7] = 74;
		} else {
			bottom[5] = 74;
			right[7] = 56;
		}
	} else if(((bottom[5] == 6) && (right[7] == 3)) || ((bottom[5] == 3) && (right[7] == 6))) {
		if(bottom[5] == 6) {
			bottom[5] = 76;
			right[7] = 73;
		} else {
			bottom[5] = 73;
			right[7] = 76;
		}
	} else if(((bottom[5] == 3) && (right[7] == 4)) || ((bottom[5] == 4) && (right[7] == 3))) {
		if(bottom[5] == 3) {
			bottom[5] = 33;
			right[7] = 54;
		} else {
			bottom[5] = 54;
			right[7] = 33;
		}
	} else if(((bottom[5] == 4) && (right[7] == 5)) || ((bottom[5] == 5) && (right[7] == 4))) {
		if(bottom[5] == 4) {
			bottom[5] = 34;
			right[7] = 55;
		} else {
			bottom[5] = 55;
			right[7] = 34;
		}
	} else if(((bottom[5] == 5) && (right[7] == 2)) || ((bottom[5] == 2) && (right[7] == 5))) {
		if(bottom[5] == 5) {
			bottom[5] = 35;
			right[7] = 52;
		} else {
			bottom[5] = 52;
			right[7] = 35;
		}
	} else if(((bottom[5] == 2) && (right[7] == 3)) || ((bottom[5] == 3) && (right[7] == 2))) {
		if(bottom[5] == 2) {
			bottom[5] = 32;
			right[7] = 53;
		} else {
			bottom[5] = 53;
			right[7] = 32;
		}		
	} else return(4);
// edge 8
	if(((bottom[7] == 1) && (back[7] == 2)) || ((bottom[7] == 2) && (back[7] == 1))) {
		if(bottom[7] == 1) {
			bottom[7] = 31;
			back[7] = 12;
		} else {
			bottom[7] = 12;
			back[7] = 31;
		}
	} else if(((bottom[7] == 1) && (back[7] == 5)) || ((bottom[7] == 5) && (back[7] == 1))) {
		if(bottom[7] == 1) {
			bottom[7] = 71;
			back[7] = 15;
		} else {
			bottom[7] = 15;
			back[7] = 71;
		}
	}
	else if(((bottom[7] == 1) && (back[7] == 4)) || ((bottom[7] == 4) && (back[7] == 1))) {
		if(bottom[7] == 1) {
			bottom[7] = 51;
			back[7] = 14;
		} else {
			bottom[7] = 14;
			back[7] = 51;
		}
	} else if(((bottom[7] == 1) && (back[7] == 3))  || ((bottom[7] == 3) && (back[7] == 1))) {
		if(bottom[7] == 1) {
			bottom[7] = 11;
			back[7] = 13;
		} else {
			bottom[7] = 13;
			back[7] = 11;
		}
	} else if(((bottom[7] == 6) && (back[7] == 2)) || ((bottom[7] == 2) && (back[7] == 6))) {
		if (bottom[7] == 6) {
			bottom[7] = 36;
			back[7] = 72;
		} else {
			bottom[7] = 72;
			back[7] = 36;
		}
	} else if(((bottom[7] == 6) && (back[7] == 5)) || ((bottom[7] == 5) && (back[7] == 6))) {
		if(bottom[7] == 6) {
			bottom[7] = 16;
			back[7] = 75;
		} else {
			bottom[7] = 75;
			back[7] = 16;
		}
	} else if(((bottom[7] == 6) && (back[7] == 4)) || ((bottom[7] == 4) && (back[7] == 6))) {
		if(bottom[7] == 6) {
			bottom[7] = 56;
			back[7] = 74;
		} else {
			bottom[7] = 74;
			back[7] = 56;
		}
	} else if(((bottom[7] == 6) && (back[7] == 3)) || ((bottom[7] == 3) && (back[7] == 6))) {
		if(bottom[7] == 6) {
			bottom[7] = 76;
			back[7] = 73;
		} else {
			bottom[7] = 73;
			back[7] = 76;
		}
	} else if(((bottom[7] == 3) && (back[7] == 4)) || ((bottom[7] == 4) && (back[7] == 3))) {
		if(bottom[7] == 3) {
			bottom[7] = 33;
			back[7] = 54;
		} else {
			bottom[7] = 54;
			back[7] = 33;
		}
	} else if(((bottom[7] == 4) && (back[7] == 5)) || ((bottom[7] == 5) && (back[7] == 4))) {
		if(bottom[7] == 4) {
			bottom[7] = 34;
			back[7] = 55;
		} else {
			bottom[7] = 55;
			back[7] = 34;
		}
	} else if(((bottom[7] == 5) && (back[7] == 2)) || ((bottom[7] == 2) && (back[7] == 5))) {
		if(bottom[7] == 5) {
			bottom[7] = 35;
			back[7] = 52;
		} else {
			bottom[7] = 52;
			back[7] = 35;
		}
	} else if(((bottom[7] == 2) && (back[7] == 3)) || ((bottom[7] == 3) && (back[7] == 2))) {
		if(bottom[7] == 2) {
			bottom[7] = 32;
			back[7] = 53;
		} else {
			bottom[7] = 53;
			back[7] = 32;
		}		
	} else return(4);

// edge 9
	if(((left[3] == 1) && (back[5] == 2)) || ((left[3] == 2) && (back[5] == 1))) {
		if(left[3] == 1) {
			left[3] = 31;
			back[5] = 12;
		} else {
			left[3] = 12;
			back[5] = 31;
		}
	} else if(((left[3] == 1) && (back[5] == 5)) || ((left[3] == 5) && (back[5] == 1))) {
		if(left[3] == 1) {
			left[3] = 71;
			back[5] = 15;
		} else {
			left[3] = 15;
			back[5] = 71;
		}
	}
	else if(((left[3] == 1) && (back[5] == 4)) || ((left[3] == 4) && (back[5] == 1))) {
		if(left[3] == 1) {
			left[3] = 51;
			back[5] = 14;
		} else {
			left[3] = 14;
			back[5] = 51;
		}
	} else if(((left[3] == 1) && (back[5] == 3))  || ((left[3] == 3) && (back[5] == 1))) {
		if(left[3] == 1) {
			left[3] = 11;
			back[5] = 13;
		} else {
			left[3] = 13;
			back[5] = 11;
		}
	} else if(((left[3] == 6) && (back[5] == 2)) || ((left[3] == 2) && (back[5] == 6))) {
		if (left[3] == 6) {
			left[3] = 36;
			back[5] = 72;
		} else {
			left[3] = 72;
			back[5] = 36;
		}
	} else if(((left[3] == 6) && (back[5] == 5)) || ((left[3] == 5) && (back[5] == 6))) {
		if(left[3] == 6) {
			left[3] = 16;
			back[5] = 75;
		} else {
			left[3] = 75;
			back[5] = 16;
		}
	} else if(((left[3] == 6) && (back[5] == 4)) || ((left[3] == 4) && (back[5] == 6))) {
		if(left[3] == 6) {
			left[3] = 56;
			back[5] = 74;
		} else {
			left[3] = 74;
			back[5] = 56;
		}
	} else if(((left[3] == 6) && (back[5] == 3)) || ((left[3] == 3) && (back[5] == 6))) {
		if(left[3] == 6) {
			left[3] = 76;
			back[5] = 73;
		} else {
			left[3] = 73;
			back[5] = 76;
		}
	} else if(((left[3] == 3) && (back[5] == 4)) || ((left[3] == 4) && (back[5] == 3))) {
		if(left[3] == 3) {
			left[3] = 33;
			back[5] = 54;
		} else {
			left[3] = 54;
			back[5] = 33;
		}
	} else if(((left[3] == 4) && (back[5] == 5)) || ((left[3] == 5) && (back[5] == 4))) {
		if(left[3] == 4) {
			left[3] = 34;
			back[5] = 55;
		} else {
			left[3] = 55;
			back[5] = 34;
		}
	} else if(((left[3] == 5) && (back[5] == 2)) || ((left[3] == 2) && (back[5] == 5))) {
		if(left[3] == 5) {
			left[3] = 35;
			back[5] = 52;
		} else {
			left[3] = 52;
			back[5] = 35;
		}
	} else if(((left[3] == 2) && (back[5] == 3)) || ((left[3] == 3) && (back[5] == 2))) {
		if(left[3] == 2) {
			left[3] = 32;
			back[5] = 53;
		} else {
			left[3] = 53;
			back[5] = 32;
		}		
	} else return(4);
	 
// edge 10
	if(((front[3] == 1) && (left[5] == 2)) || ((front[3] == 2) && (left[5] == 1))) {
		if(front[3] == 1) {
			front[3] = 31;
			left[5] = 12;
		} else {
			front[3] = 12;
			left[5] = 31;
		}
	} else if(((front[3] == 1) && (left[5] == 5)) || ((front[3] == 5) && (left[5] == 1))) {
		if(front[3] == 1) {
			front[3] = 71;
			left[5] = 15;
		} else {
			front[3] = 15;
			left[5] = 71;
		}
	}
	else if(((front[3] == 1) && (left[5] == 4)) || ((front[3] == 4) && (left[5] == 1))) {
		if(front[3] == 1) {
			front[3] = 51;
			left[5] = 14;
		} else {
			front[3] = 14;
			left[5] = 51;
		}
	} else if(((front[3] == 1) && (left[5] == 3))  || ((front[3] == 3) && (left[5] == 1))) {
		if(front[3] == 1) {
			front[3] = 11;
			left[5] = 13;
		} else {
			front[3] = 13;
			left[5] = 11;
		}
	} else if(((front[3] == 6) && (left[5] == 2)) || ((front[3] == 2) && (left[5] == 6))) {
		if (front[3] == 6) {
			front[3] = 36;
			left[5] = 72;
		} else {
			front[3] = 72;
			left[5] = 36;
		}
	} else if(((front[3] == 6) && (left[5] == 5)) || ((front[3] == 5) && (left[5] == 6))) {
		if(front[3] == 6) {
			front[3] = 16;
			left[5] = 75;
		} else {
			front[3] = 75;
			left[5] = 16;
		}
	} else if(((front[3] == 6) && (left[5] == 4)) || ((front[3] == 4) && (left[5] == 6))) {
		if(front[3] == 6) {
			front[3] = 56;
			left[5] = 74;
		} else {
			front[3] = 74;
			left[5] = 56;
		}
	} else if(((front[3] == 6) && (left[5] == 3)) || ((front[3] == 3) && (left[5] == 6))) {
		if(front[3] == 6) {
			front[3] = 76;
			left[5] = 73;
		} else {
			front[3] = 73;
			left[5] = 76;
		}
	} else if(((front[3] == 3) && (left[5] == 4)) || ((front[3] == 4) && (left[5] == 3))) {
		if(front[3] == 3) {
			front[3] = 33;
			left[5] = 54;
		} else {
			front[3] = 54;
			left[5] = 33;
		}
	} else if(((front[3] == 4) && (left[5] == 5)) || ((front[3] == 5) && (left[5] == 4))) {
		if(front[3] == 4) {
			front[3] = 34;
			left[5] = 55;
		} else {
			front[3] = 55;
			left[5] = 34;
		}
	} else if(((front[3] == 5) && (left[5] == 2)) || ((front[3] == 2) && (left[5] == 5))) {
		if(front[3] == 5) {
			front[3] = 35;
			left[5] = 52;
		} else {
			front[3] = 52;
			left[5] = 35;
		}
	} else if(((front[3] == 2) && (left[5] == 3)) || ((front[3] == 3) && (left[5] == 2))) {
		if(front[3] == 2) {
			front[3] = 32;
			left[5] = 53;
		} else {
			front[3] = 53;
			left[5] = 32;
		}		
	} else return(4);
// edge 11
	if(((right[3] == 1) && (front[5] == 2)) || ((right[3] == 2) && (front[5] == 1))) {
		if(right[3] == 1) {
			right[3] = 31;
			front[5] = 12;
		} else {
			right[3] = 12;
			front[5] = 31;
		}
	} else if(((right[3] == 1) && (front[5] == 5)) || ((right[3] == 5) && (front[5] == 1))) {
		if(right[3] == 1) {
			right[3] = 71;
			front[5] = 15;
		} else {
			right[3] = 15;
			front[5] = 71;
		}
	}
	else if(((right[3] == 1) && (front[5] == 4)) || ((right[3] == 4) && (front[5] == 1))) {
		if(right[3] == 1) {
			right[3] = 51;
			front[5] = 14;
		} else {
			right[3] = 14;
			front[5] = 51;
		}
	} else if(((right[3] == 1) && (front[5] == 3))  || ((right[3] == 3) && (front[5] == 1))) {
		if(right[3] == 1) {
			right[3] = 11;
			front[5] = 13;
		} else {
			right[3] = 13;
			front[5] = 11;
		}
	} else if(((right[3] == 6) && (front[5] == 2)) || ((right[3] == 2) && (front[5] == 6))) {
		if (right[3] == 6) {
			right[3] = 36;
			front[5] = 72;
		} else {
			right[3] = 72;
			front[5] = 36;
		}
	} else if(((right[3] == 6) && (front[5] == 5)) || ((right[3] == 5) && (front[5] == 6))) {
		if(right[3] == 6) {
			right[3] = 16;
			front[5] = 75;
		} else {
			right[3] = 75;
			front[5] = 16;
		}
	} else if(((right[3] == 6) && (front[5] == 4)) || ((right[3] == 4) && (front[5] == 6))) {
		if(right[3] == 6) {
			right[3] = 56;
			front[5] = 74;
		} else {
			right[3] = 74;
			front[5] = 56;
		}
	} else if(((right[3] == 6) && (front[5] == 3)) || ((right[3] == 3) && (front[5] == 6))) {
		if(right[3] == 6) {
			right[3] = 76;
			front[5] = 73;
		} else {
			right[3] = 73;
			front[5] = 76;
		}
	} else if(((right[3] == 3) && (front[5] == 4)) || ((right[3] == 4) && (front[5] == 3))) {
		if(right[3] == 3) {
			right[3] = 33;
			front[5] = 54;
		} else {
			right[3] = 54;
			front[5] = 33;
		}
	} else if(((right[3] == 4) && (front[5] == 5)) || ((right[3] == 5) && (front[5] == 4))) {
		if(right[3] == 4) {
			right[3] = 34;
			front[5] = 55;
		} else {
			right[3] = 55;
			front[5] = 34;
		}
	} else if(((right[3] == 5) && (front[5] == 2)) || ((right[3] == 2) && (front[5] == 5))) {
		if(right[3] == 5) {
			right[3] = 35;
			front[5] = 52;
		} else {
			right[3] = 52;
			front[5] = 35;
		}
	} else if(((right[3] == 2) && (front[5] == 3)) || ((right[3] == 3) && (front[5] == 2))) {
		if(right[3] == 2) {
			right[3] = 32;
			front[5] = 53;
		} else {
			right[3] = 53;
			front[5] = 32;
		}		
	} else return(4);
// edge 12
	if(((back[3] == 1) && (right[5] == 2)) || ((back[3] == 2) && (right[5] == 1))) {
		if(back[3] == 1) {
			back[3] = 31;
			right[5] = 12;
		} else {
			back[3] = 12;
			right[5] = 31;
		}
	} else if(((back[3] == 1) && (right[5] == 5)) || ((back[3] == 5) && (right[5] == 1))) {
		if(back[3] == 1) {
			back[3] = 71;
			right[5] = 15;
		} else {
			back[3] = 15;
			right[5] = 71;
		}
	}
	else if(((back[3] == 1) && (right[5] == 4)) || ((back[3] == 4) && (right[5] == 1))) {
		if(back[3] == 1) {
			back[3] = 51;
			right[5] = 14;
		} else {
			back[3] = 14;
			right[5] = 51;
		}
	} else if(((back[3] == 1) && (right[5] == 3))  || ((back[3] == 3) && (right[5] == 1))) {
		if(back[3] == 1) {
			back[3] = 11;
			right[5] = 13;
		} else {
			back[3] = 13;
			right[5] = 11;
		}
	} else if(((back[3] == 6) && (right[5] == 2)) || ((back[3] == 2) && (right[5] == 6))) {
		if (back[3] == 6) {
			back[3] = 36;
			right[5] = 72;
		} else {
			back[3] = 72;
			right[5] = 36;
		}
	} else if(((back[3] == 6) && (right[5] == 5)) || ((back[3] == 5) && (right[5] == 6))) {
		if(back[3] == 6) {
			back[3] = 16;
			right[5] = 75;
		} else {
			back[3] = 75;
			right[5] = 16;
		}
	} else if(((back[3] == 6) && (right[5] == 4)) || ((back[3] == 4) && (right[5] == 6))) {
		if(back[3] == 6) {
			back[3] = 56;
			right[5] = 74;
		} else {
			back[3] = 74;
			right[5] = 56;
		}
	} else if(((back[3] == 6) && (right[5] == 3)) || ((back[3] == 3) && (right[5] == 6))) {
		if(back[3] == 6) {
			back[3] = 76;
			right[5] = 73;
		} else {
			back[3] = 73;
			right[5] = 76;
		}
	} else if(((back[3] == 3) && (right[5] == 4)) || ((back[3] == 4) && (right[5] == 3))) {
		if(back[3] == 3) {
			back[3] = 33;
			right[5] = 54;
		} else {
			back[3] = 54;
			right[5] = 33;
		}
	} else if(((back[3] == 4) && (right[5] == 5)) || ((back[3] == 5) && (right[5] == 4))) {
		if(back[3] == 4) {
			back[3] = 34;
			right[5] = 55;
		} else {
			back[3] = 55;
			right[5] = 34;
		}
	} else if(((back[3] == 5) && (right[5] == 2)) || ((back[3] == 2) && (right[5] == 5))) {
		if(back[3] == 5) {
			back[3] = 35;
			right[5] = 52;
		} else {
			back[3] = 52;
			right[5] = 35;
		}
	} else if(((back[3] == 2) && (right[5] == 3)) || ((back[3] == 3) && (right[5] == 2))) {
		if(back[3] == 2) {
			back[3] = 32;
			right[5] = 53;
		} else {
			back[3] = 53;
			right[5] = 32;
		}		
	} else return(4);
	refresh();
// check corners correct
	if(!(rotation % 3 == 0)) return(5);
// check edges correct
	if((top[3] % 10 == 1) || (top[3] % 10 == 6)) count++;
	if((top[5] % 10 == 1) || (top[5] % 10 == 6)) count++;
	if((front[1] % 10 == 1) || (front[1] % 10 == 6)) count++;
	if((front[3] % 10 == 1) || (front[3] % 10 == 6)) count++;
	if((front[5] % 10 == 1) || (front[5] % 10 == 6)) count++;
	if((front[7] % 10 == 1) || (front[7] % 10 == 6)) count++;
	if((bottom[3] % 10 == 1) || (bottom[3] % 10 == 6)) count++;
	if((bottom[5] % 10 == 1) || (bottom[5] % 10 == 6)) count++;
	if((back[1] % 10 == 1) || (back[1] % 10 == 6)) count++;
	if((back[3] % 10 == 1) || (back[3] % 10 == 6)) count++;
	if((back[5] % 10 == 1) || (back[5] % 10 == 6)) count++;
	if((back[7] % 10 == 1) || (back[7] % 10 == 6)) count++;
// red or orange not paired with white or yellow + 1    
	if((top[3] == 35) || (top[3] == 55) || (top[3] == 33) || (top[3] == 53)) count++;
	if((top[5] == 35) || (top[5] == 55) || (top[5] == 33) || (top[5] == 53)) count++;
	if((front[1] == 35) || (front[1] == 55) || (front[1] == 33) || (front[1] == 53)) count++;
	if((front[3] == 35) || (front[3] == 55) || (front[3] == 33) || (front[3] == 53)) count++;
	if((front[5] == 35) || (front[5] == 55) || (front[5] == 33) || (front[5] == 53)) count++;
	if((front[7] == 35) || (front[7] == 55) || (front[7] == 33) || (front[7] == 53)) count++;
	if((bottom[3] == 35) || (bottom[3] == 55) || (bottom[3] == 33) || (bottom[3] == 53)) count++;
	if((bottom[5] == 35) || (bottom[5] == 55) || (bottom[5] == 33) || (bottom[5] == 53)) count++;
	if((back[1] == 35) || (back[1] == 55) || (back[1] == 33) || (back[1] == 53)) count++;
	if((back[3] == 35) || (back[3] == 55) || (back[3] == 33) || (back[3] == 53)) count++;
	if((back[5] == 35) || (back[5] == 55) || (back[5] == 33) || (back[5] == 53)) count++;
	if((back[7] == 35) || (back[7] == 55) || (back[7] == 33) || (back[7] == 53)) count++; 
	if(count % 2) return(6);  
	print_cube(top, bottom, left, right, front, back);
	refresh();
	return(0);
}
