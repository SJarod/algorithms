#include "string_sized_concatenate.h"
#include "string_length.h"
#include "string_sized_copy.h"

char* string_sized_concatenate(char* dest, char const* src, unsigned int size_max)
{
	return string_sized_copy(&dest[string_length(dest + 1)], src, size_max);
}
