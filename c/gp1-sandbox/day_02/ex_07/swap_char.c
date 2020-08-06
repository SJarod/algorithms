#include "swap_char.h"

void swap_char(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}
