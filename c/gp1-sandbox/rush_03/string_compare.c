#include "string_compare.h"
#include "string_length.h"

#include <stddef.h>

int string_compare(char const* str1, char const* str2)
{
	if (str1 != NULL && str2 != NULL)
	{
		int length1 = string_length(str1);
		int length2 = string_length(str2);
		
		int n = 0;

		if (length1 < length2)
			length1 = length2;

		for (int i = 0; i < length1; ++i)
		{
			while (str1[n] == str2[n])
			{
				++n;
				if (str1[n] < str2[n])
					return -1;
				else if (str1[n] > str2[n])
					return 1;
				else if (str1[n] == '\0' && str1[n-1] == str2[n-1])
					return 0;
			}
			return 0;
		}
	}
	return 0;
	
}
