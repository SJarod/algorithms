#include "my_put_string.h"

#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void my_put_string(char const* str)
{
	if (str != NULL)
	{
		for (int i = 0; i < 5; ++i)
		{
			my_put_char(*(str + i));
		}
	}
}
