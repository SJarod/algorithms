#include "reverse_string.h"

#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c, sizeof(char), 1, stdout);
}

void my_put_string(char const* str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			//my_put_char(*(str));
			++str;
		}
	}
}

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

void reverse_string(char const* str)
{
	if (str != NULL)
	{
		if (*str == '\0')
			my_put_char('\0');
		else
		{
			int lengthVar = string_length(str);
		
			for (int i = lengthVar - 1; i > 0; --i)
			{
				my_put_char(*(str + i));
			}
			my_put_char(*str);
		}
	}
}
