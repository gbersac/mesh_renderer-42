/*
 * main.cxx
 * Copyright (C) 2015 guillaume <guillaume@guillaume-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include "TutorialConfig.h"

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout,"Usage: %s number\n",argv[0]);
		return 1;
	}
	double inputValue = atof(argv[1]);
	double outputValue = sqrt(inputValue);
	fprintf(stdout,"The square root of %g is %g\n",
			inputValue, outputValue);
	return 0;
}

