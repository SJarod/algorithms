#include "power_it.h"

int power_it(int base, unsigned int pow)
{
	if (pow == 0)
		return 1;

	if (pow <= 1)
		return base;

	int result = base;

	for (unsigned int i = 0; i < pow - 1; ++i)
	{
		result *= base;
	}

	return result;
}
