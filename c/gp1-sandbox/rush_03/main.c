#include "annuaire.h"

#include "string_compare.h"

#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc == 0)
		return 0;

	//display
	if (string_compare(argv[2], "display") == 0)
	{
		FILE* file = which_file(argv[1]);
		display(file);
	}
	//add a line to .txt
	if (string_compare(argv[2], "add") == 0)
	{
		FILE* file = which_file(argv[1]);
		add(file, argv[3]);
	}

	return 0;
}
