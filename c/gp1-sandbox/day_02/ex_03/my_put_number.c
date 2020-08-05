#include "my_put_number.h"

#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void value(int num)
{
	if (num < 10)
	{
		my_put_char(num + '0');
	}

	else
	{
		int num2 = num;
		int d = 0;

		while (num2 >= 10)
		{
			num2 /= 10;
			++d;
		}

		for (int i = d; i > 0; --i)
		{
			num2 = num;

			for (int j = i; j > 0; --j)
			{
				num2 /= 10;
			}

			my_put_char(num2 % 10 + '0');
		}
		my_put_char(num % 10 + '0');
	}
}

void my_put_number(int num)
{
	if (num < 0)
	{
		my_put_char('-');
		value(-num);
	}
	else
		value(num);
}
