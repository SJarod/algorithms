#include "string_length.h"

#include <stddef.h>

unsigned int string_length(char const* str)
{
	int length = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			++length;
			++str;
		}
	}

	return length;
}
