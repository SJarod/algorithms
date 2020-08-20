#include "parse_file.h"
#include "string_length.h"

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
		fseek(file, -1, SEEK_CUR);
		return 0;
	}
}

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	else
		return 0;
}

char* sub_string(char const* str, unsigned int pos, unsigned int len)
{
	if (str == NULL)
		return NULL;

	char* newStr = malloc(len * sizeof(char));

	for (unsigned int i = 0; i < len; ++i)
	{
		newStr[i] = str[i + pos];
	}

	return newStr;
}

char* read_line(FILE* file)
{
	if (file == NULL)
		return NULL;
	if (feof(file) == 1)
		return NULL;

	char c;
	int count = 0;	

	while (read_char(file, &c) == 1)
	{
		++count;
	}

	fseek(file, -count + 1, SEEK_CUR);

	char*	newStr = malloc(count * sizeof(char*));

	fgets(newStr, count + 2, file);

	if (newStr[string_length(newStr) - 1] == '\n')
		newStr[string_length(newStr) - 1] = '\0';

	return newStr;
}

int parse_section(const char* str, char** p_section_name)
{
	if (str == NULL)
		return 0;

	//*p_section_name = malloc(sizeof(char*));

	int	leftBracket = 0;
	int	rightBracket = 0;
	int	isSection = 0;
	int	lbPos, rbPos;

	for (unsigned int i = 0; i < string_length(str); ++i)
	{
		if (str[i] == '[')
		{
			++leftBracket;
			lbPos = i;
		}
		if (str[i] == ']')
		{
			++rightBracket;
			rbPos = i;
		}

		if (leftBracket == 1 && rightBracket == 1)
		{
			++isSection;
		}
	}

	if (isSection == 0)
		return 0;

	*p_section_name = malloc(rbPos * sizeof(char));

	int j = 0;

	for  (int i = lbPos + 1; i <= rbPos - 1; ++i)
	{
		(*p_section_name)[j] = str[i];
		++j;
	}

	return 1;
}

int parse_property(const char* str, char** p_name, char** p_value)
{
	if (str == NULL)
		return 0;

	int isProp = 0;
	int signPos = 0;

	//*p_name = malloc(sizeof(char*));
	//*p_value = malloc(sizeof(char*));

	for (unsigned int i = 0; i < string_length(str); ++i)
	{
		if (str[i] == '=')
		{
			isProp = 1;
			signPos = i;
			break;
		}
	}

	if (isProp == 0)
		return 0;

	*p_name = malloc(signPos * sizeof(char));
	int lengthVar = string_length(str) - signPos;
	*p_value = malloc(lengthVar * sizeof(char));

	int j = 0;

	for (int i = 0; i < signPos; ++i)
	{
		(*p_name)[i] = str[i];
	}

	for (unsigned int i = signPos + 1; str[i] != '\n'; ++i)
	{
		(*p_value)[j] = str[i];
		++j;
	}

	return 1;
}
