#include "string_sized_copy.h"

char* string_sized_copy(char* dest, char const* src, unsigned int size_max)
{
	if (dest == 0)
		return 0;
	if (src == 0)
		return 0;

	for (unsigned int i = 0; i < size_max; ++i)
	{
		dest[i] = src[i];
	}

	return dest;
}
