#include "fibonacci_rec.h"

unsigned int fibonacci_rec(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	unsigned int result = fibonacci_rec(n - 1) + fibonacci_rec(n - 2);

	return result;
}
