#include "is_prime.h"

#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c,sizeof(char),1,stdout);
}

void is_prime(unsigned int num)
{
	int prime = 1;
	if (num == 0 || num == 1)
		prime = 0;
	for (unsigned int i = 2; i < num; ++i)
	{
		if (num % i == 0)
		{
			prime = 0;
			break;
		}
	}

	if (prime == 0)
		my_put_char('N');
	else
		my_put_char('Y');
}
