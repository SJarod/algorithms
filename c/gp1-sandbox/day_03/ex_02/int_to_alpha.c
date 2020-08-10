#include "int_to_alpha.h"

#include <stdlib.h>

unsigned int num_length(int num)
{
	if (num < 0)
		num = -num;

	unsigned int div = 0;
	while (num >= 10)
	{
		num /= 10;
		++div;
	}

	return div + 1;
}

char* int_to_alpha(int num)
{
	int negative = 0;
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}

	char* str;
	str = malloc((num_length(num) + 1 + negative) * sizeof(char));
	int num2 = num;

	for (unsigned int i = negative; i < num_length(num) + negative; ++i)
	{
		num2 = num;

		for (unsigned int j = num_length(num) - i + negative; j > 0; --j)
		{
			if (j == 1)
				break;

			num2 = num2 / 10;
		}

		num2 -= num2 / 10 * 10;
		str[i] = num2 + '0';
	}

	if (negative == 1)
		str[0] = '-';

	return str;
}
