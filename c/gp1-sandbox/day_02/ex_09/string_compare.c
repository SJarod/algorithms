#include "string_compare.h"
#include "string_length.h"

#include <stddef.h>

int string_compare(char const* str1, char const* str2)
{
	if (str1 != NULL && str2 != NULL)
	{
		int length1 = string_length(str1);
		int length2 = string_length(str2);
		
		if (length1 < length2)
			return -1;
		else if (length1 > length2)
			return 1;
		else
			return 0;
	}
	return 0;
}
