#include "power_rec.h"

int power_rec(int base, unsigned int pow)
{
	if (pow == 1)
		return base;
	return base * power_rec(base, pow - 1);
}
