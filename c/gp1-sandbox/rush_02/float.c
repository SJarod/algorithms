#include "float.h"

#include "string_length.h"
#include "my_put_string.h"
#include "string_sized_copy.h"
#include "string_sized_concatenate.h"
#include "alpha_to_number.h"
#include "int_to_alpha.h"
#include "my_put_number.h"

#include <stdlib.h>

void	init_float(t_float* f)
{
	if (f == NULL)
		return;

	f->mantisse = NULL;
	f->exp = 0;
}

void	reset_float(t_float* f)
{
	if (f == NULL)
		return;

	free(f->mantisse);
	f->mantisse = NULL;
	f->exp = 0;
}

t_float	create_float(char* mantisse, int exp)
{
	t_float	floatNumber;
	floatNumber.mantisse = mantisse;
	floatNumber.exp = exp;

	return floatNumber;
}

void	duplicate_float(t_float* fdest, t_float const* fsrc)
{
	if (fsrc == NULL)
		return;

	fdest->mantisse = malloc(string_length(fsrc->mantisse) * sizeof(char));
	fdest->exp = fsrc->exp;
	string_sized_copy(fdest->mantisse, fsrc->mantisse, string_length(fsrc->mantisse));

	print_float(fdest);
}

void	add_digit_right(t_float* f, int digit)
{
	if (f == NULL)
		return;

	f->mantisse = realloc(f->mantisse,
			(string_length(f->mantisse) + 1) * sizeof(char));
	f->mantisse[string_length(f->mantisse)] = digit + '0';

	print_float(f);
}

void	add_digit_left(t_float* f, int digit)
{
	if (f == NULL)
		return;

	f->mantisse = realloc(f->mantisse,
			(string_length(f->mantisse) + 1) * sizeof(char));

	for (unsigned int i = string_length(f->mantisse); i > 0; --i)
	{
		f->mantisse[i] = f->mantisse[i - 1];
	}

	f->mantisse[0] = digit + '0';

	//my_put_string(newChar);
	print_float(f);
}

void	init_from_string(t_float* f, char const* str)
{
	if (str == NULL)
		return;

	int	num_afterComa = 0;						//how many numbers after the coma
	int	comaPos = 0;							//where is the coma

	f->mantisse = malloc((string_length(str) - 1) * sizeof(char));

	for (unsigned int i = 0; i < string_length(str); ++i)
	{
		if (str[i] == ',')
			num_afterComa = 1;

		if (num_afterComa == 0)
			++comaPos;						//count the numbers before the coma to get its position

		if (num_afterComa > 0)
			++num_afterComa;					//count the numbers after the coma
	}

	f->exp = num_afterComa - 2;

	for (int i = 0; i < comaPos; ++i)
	{
		f->mantisse[i] = str[i];
	}

	for (unsigned int i = comaPos; i < string_length(str); ++i)
	{
		f->mantisse[i] = str[i + 1];
	}

	//my_put_string(f->mantisse);
	//my_put_number(f->exp);
}

void	print_float(t_float const* f)
{
	for (unsigned int i = 0; i < string_length(f->mantisse) - f->exp; ++i)
	{
		my_put_char(f->mantisse[i]);
	}

	my_put_char(',');

	for (unsigned int i = string_length(f->mantisse) - f->exp; f->mantisse[i] != '\0'; ++i)
	{
		my_put_char(f->mantisse[i]);
	}

	my_put_char('\n');
}

char*	shortest_string(char* str1, char* str2)
{
	if (str1 == NULL)
		return 0;
	if (str2 == NULL)
		return 0;

	if (string_length(str1) >= string_length(str2))
		return str1;
	else
		return str2;
}

void	add_mantisses(t_float const* f1, t_float const* f2, t_float* fres)
{
	if (f1 == NULL)
		return;
	if (f2 == NULL)
		return;

	char*	longestStr;
	char*	shortestStr;
	int	result;

	if (string_length(f1->mantisse) == string_length(shortest_string(f1->mantisse, f2->mantisse)))
	{
		longestStr = f2->mantisse;
		shortestStr = f1->mantisse;
	}
	else
	{
		longestStr = f1->mantisse;
		shortestStr = f2->mantisse;
	}

	fres->mantisse = malloc((string_length(longestStr) + 1) * sizeof(char));

	for (unsigned int i = 0; i < string_length(longestStr) + 1; ++i)			//assign all fres->mantisse char to '0'
	{
		fres->mantisse[i] = '0';
	}

	for (unsigned int i = 0; i < string_length(longestStr) + 1; ++i)			//addition of f1->mantisse and f2->mantisse
	{
		result = char_to_number(longestStr[string_length(longestStr) - i]) +
			 char_to_number(shortestStr[string_length(shortestStr) - i]);
		fres->mantisse[string_length(longestStr) - i] = number_to_char(result);
	}

	for (unsigned int i = 0; i < string_length(fres->mantisse); ++i)			//some char are greater than 10: this loop will add 1 to the previous char
	{
		if (char_to_number(fres->mantisse[string_length(fres->mantisse) - i]) >= 10)
		{
			result = char_to_number(fres->mantisse[string_length(fres->mantisse) - i]) % 10;
			fres->mantisse[string_length(fres->mantisse) - i] = number_to_char(result);
			++fres->mantisse[string_length(fres->mantisse) - i - 1];
		}
	}

	if (fres->mantisse[0] >= 10)								//same as previous loop but for the first char
	{
		result = char_to_number(fres->mantisse[0]) % 10;
		fres->mantisse[0] = number_to_char(result);
		add_digit_left(fres, 1);
	}

	my_put_string(fres->mantisse);
}

int	char_to_number(char c)
{
	return c - '0';
}

char	number_to_char(int num)
{
	return num + '0';
}

void	add_floats(t_float const* f1, t_float const* f2, t_float* fres)
{
	if (f1 == NULL)
		return;
	if (f2 == NULL)
		return;

	char*	str1 = f1->mantisse;	//before coma of the first string
	char*	str2 = f2->mantisse;	//before coma of the second string
	char*	str3 = f1->mantisse;	//after coma of the first string
	char*	str4 = f2->mantisse;	//after coma of the second string
	char*	str5;			//addition of str1 and str2
	char*	str6;			//addition of str3 and str4
	int	result;

	for (int i = 0; f1->mantisse[i] != ',' || f2->mantisse[i] != ','; ++i)		//stores characters before the coma of f1->mantisse in str1
	{										//and the characters before the coma of f2->mantisse in str2
		str1[i] = f1->mantisse[i];
		str2[i] = f2->mantisse[i];

		if (f2->mantisse[i + 1] == ',')
		{
			for (int j = i + 1; f1->mantisse[j] != ','; ++j)
			{
				str1[i] = f1->mantisse[j];
			}
		}

		if (f1->mantisse[i + 1] == ',')
		{
			for (int j = i + 1; f2->mantisse[j] != ','; ++j)
			{
				str1[i] = f2->mantisse[j];
			}
		}
	}

	str5 = malloc(string_length(str1) * sizeof(char));

	for (unsigned int i = f1->exp; i < string_length(f1->mantisse); ++i)		//stores characters after the coma of f1->mantisse in str3
	{
		str3[i] = f1->mantisse[i];
	}

	for (unsigned int i = f2->exp; i < string_length(f2->mantisse); ++i)		//same as previous but for f2->mantisse in str4
	{
		str4[i] = f2->mantisse[i];
	}

	str6 = malloc(string_length(str4) * sizeof(char));

	if (f1->exp <= f2->exp)
		fres->exp = f2->exp + 1;
	else
		fres->exp = f1->exp + 1;

	for (unsigned int i = 0; i < string_length(str1); ++i)				//addition of str1 and str2 stored in str5
	{
		result = char_to_number(str1[string_length(str1) - i] + str2[string_length(str2) - i]);
		str5[i] = number_to_char(result);
	}

	for (unsigned int i = 0; i < string_length(str3); ++i)				//addition of str3 and str4 stored in str6
	{
		result = char_to_number(str3[string_length(str3) - i] + str4[string_length(str4) - i]);
		str6[i] = number_to_char(result);
	}
}

/*void	multiply_floats(t_float const* f1, t_float const* f2, t_float* fres)
{
	unsigned int shortestStrLen = shortest_string_length(f1->mantisse, f2->mantisse);

	for (unsigned int i = 0; i < shortestStrLen; ++i)
	{
		f2->mantisse[shortestStrLen - i]
	}
}*/
