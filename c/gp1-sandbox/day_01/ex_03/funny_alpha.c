#include "funny_alpha.h"
#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void funny_alpha(void)
{
	for (int i = 65; i < 91; i += 2)
	{
		my_put_char(i);
		my_put_char(i+33);
	}
}
