#include "alpha_to_number.h"
//#include "my_put_number.h"

#include <stddef.h>
#include <stdio.h>

unsigned int string_length(char const* str)
{
	int length = 0;
	int n = 0;
	if (str != NULL)
	{
		if (*str == '-')
			n = 1;
		else
			n = 0;

		while (*(str + n) >= '0' && *(str + n) <= '9')
		{
			++length;
			++n;
		}	
	}
	//my_put_number(length);
	return length;
}

int alpha_to_number(char const* str)
{
	if (str != NULL) {
	int lengthVar = string_length(str);
	int num = 0;
	int num2 = 0;
	int n = 0;

	if (str[0] == '-')
	{
		if (str[1] < '0' || str[1] > '9')
			return 0;
		n = 1;
	}
	else
		n = 0;
	
	for (int i = 0; i < lengthVar; ++i)
	{
		num2 = str[i + n] - '0';
		//my_put_number(num2);

		for (int k = lengthVar - i - 1; k > 0; --k)
		{
			//my_put_number(num2);
			num2 *= 10;
			//my_put_number(num2);
		}
		num += num2;
		//my_put_number(num);
	}
	//my_put_number(num);
	if (str[0] == '-')
	{
		//my_put_number(num);
		return -num;
	}
	else
	{
		//my_put_number(num);
		return num;
	}
	}
	return 0;
}
