#include "string_to_word_array.h"
#include "string_length.h"
#include "string_sized_copy.h"
#include "my_put_number.h"
#include "my_put_string.h"

#include <stdlib.h>

int number_of_word(char const* str)
{
	if (str == 0)
		return 0;

	int	count = 0;

	for (unsigned int i = 0; i < string_length(str) - 1; ++i)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			++count;
		}
	}
	//my_put_number(count);
	return count + 1;
}

unsigned int word_length(char const* str, int number)
{
	if (str == 0)
		return 0;

	unsigned int	count = 0;

	if (number == 0)
		++count;

	for (unsigned int i = 0; i < string_length(str) - 1; ++i)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			if (str[i - 1] != ' ' || str[i - 1] != '\n' || str[i - 1] != '\t')
					count -= 1;

			if (number == 0)
			{
				//my_put_number(count);
				return count;
			}
			else
			{
				--number;
				count = 0;
			}
		}

		++count;
	}
	//my_put_number(count);
	return count;
}

char* which_word(char const* str, int x)
{
	if (str == 0)
		return 0;

	int	number = x;
	char*	word;
	int	wordPlace = 0;
	word = malloc((word_length(str, x) + 1) * sizeof(char));

	for (unsigned int i = 0; i < string_length(str); ++i)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			if (x == 0)
			{
				for (unsigned int j = 0; j < word_length(str, number); ++j)
				{
					word[j] = str[j + wordPlace];
				}
			}
			else
			{
				--x;
				wordPlace += word_length(str, x) + 1;
			}
		}
	}
	//my_put_string(word);
	return word;
}

char** string_to_word_array(char const* str)
{
	if (str == 0)
		return 0;

	int const	count = number_of_word(str);
	//int		word_start = 0;
	char**		wordArray;
	wordArray = malloc((number_of_word(str) + 1) * sizeof(char*));

	for (int m = 0; m < number_of_word(str) + 1; ++m)
	{
		wordArray[m] = malloc((word_length(str, m) + 1) * sizeof(char));
		//my_put_number(string_length(*(wordArray + m)));
	}

	for (int i = 0; i <= count + 1; ++i)
	{
		string_sized_copy(wordArray[i], which_word(str, i), word_length(str, i) + 1);
		free(which_word(str, i));
	}

	//my_put_number(word_length(str, 4));
	return wordArray;
}
