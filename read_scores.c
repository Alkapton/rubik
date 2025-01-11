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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rubik.h"

struct scores read_scores(void) {
	FILE *fp;
	char filename[256];
	struct scores the_scores;
	
	sprintf(filename, "High_Scores.dat");

	fp = fopen(filename, "a+");

	size_t read = fread(&the_scores, sizeof(struct scores), 1, fp);
	if(!read) {
		the_scores.p_scores = 0;
		the_scores.c_scores = 0;
		the_scores.hours = 0;
		the_scores.minuites = 0;
		the_scores.seconds = 0;
		fwrite(&the_scores, sizeof(struct scores), 1, fp);
	}
	fclose(fp);
	return(the_scores);
}
