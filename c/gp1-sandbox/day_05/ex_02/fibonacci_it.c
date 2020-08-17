#include "fibonacci_it.h"

unsigned int fibonacci_it(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int c;

	for (unsigned int i = 0; i < n - 1; ++i)
	{
		c = b;
		b = a + b;
		a = c;
	}

	return b;
}
