#include "power_it.h"

int power_it(int base, unsigned int pow)
{
	if (pow <= 1)
		return base;

	for (unsigned int i = 0; i < pow - 1; ++i)
	{
		base *= base;
	}

	return base;
}
