#include "my_station.h"
#include "string_length.h"
#include "my_put_string.h"
#include "string_compare.h"

#include <unistd.h>
#include <stdio.h>

void	right_char(int const length, char const* str, char* str2, int ascii)
{
	for (int i = 0; i < length; ++i)	//test and print each char of the string
	{
		if (str[i] < ascii)		//print the special char
		{
			str2[i] = str[i];
		}
		else if (ascii != str[i])	//print the testing char
		{
			str2[i] = ascii;
		}
		else				//print the corresponding char
		{
			str2[i] = str[i];
		}
	}
}

void	my_station(char const* str)
{
	if (str != NULL)
	{
		int		ascii		= '0';			//from 0 to 'z'
		int		endascii	= 'z';
		int const	length		= string_length(str);
		char		str2[length];				//store not corresponding string

		while (ascii <= endascii)				//test each char from 0 to 'z'
		{
			right_char(length, str, str2, ascii);		//check if the ascii char is corresponding
			my_put_string(str2);
			usleep(125000);

			if (string_compare(str, str2) == 0)		//stop the program when string is found
				break;

			fflush(stdout);
			my_put_char('\r');				//clear the output

			++ascii;

			if (ascii == '9' + 1)
				ascii = 'A';
			else if (ascii == 'Z' + 1)
				ascii = 'a';
		}

		my_put_char('\n');
	}
}
