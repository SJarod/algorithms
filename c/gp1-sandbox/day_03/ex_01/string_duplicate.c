#include "string_duplicate.h"
#include "string_length.h"
#include "my_put_string.h"
#include "string_sized_copy.h"

#include <stdlib.h>

char* string_duplicate(char const* str)
{
	if (str == 0)
		return 0;

	char* strDuplicate;

	strDuplicate = malloc(string_length(str) * sizeof(char));
	string_sized_copy(strDuplicate, str, string_length(str));

	return strDuplicate;
}
