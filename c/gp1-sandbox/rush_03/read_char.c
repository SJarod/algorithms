#include "read_char.h"

#include <stdio.h>
#include <stdlib.h>

int read_char(FILE* file, char* pointer_c)
{
	if (file == NULL || pointer_c == NULL)
		return 0;

	*pointer_c = fgetc(file);
	if (feof(file) == 0)
		return 1;
	else
	{
		fseek(file, -1, SEEK_CUR);
		*pointer_c = fgetc(file);
		return 0;
	}
}
