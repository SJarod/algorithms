#include "print_alpha.h"
#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void print_alpha(void)
{
	for (int i = 97; i < 123; ++i)
	{
		my_put_char(i);
	}
}
