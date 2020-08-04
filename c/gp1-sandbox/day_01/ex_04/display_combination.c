#include "display_combination.h"
#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void display_combination(void)
{
	for (int i = '0'; i <= '9'; ++i)
	{
		for (int j = 0; j < 9-i+48; ++j)
		{
			my_put_char(i);
			my_put_char(i+j+1);
			my_put_char(' ');
		}
	}
}
