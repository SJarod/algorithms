#include "expression.h"
#include "operation.h"
#include "alpha_to_number.h"
#include "string_sized_copy.h"
#include "string_length.h"
#include "my_put_string.h"
#include "my_put_number.h"

#include <stddef.h>
#include <stdlib.h>

char const* consume_operator(char const* str, char* operator)
{
	if (str == NULL)
		return NULL;
	if (operator == NULL)
		return NULL;

	char const* nextStr = str;

	int op_location = 0;
	int have_valid_op = 0;

	for (unsigned int i = 0; i < string_length(str) + 1; ++i)
	{
		for (unsigned int j = 0; j < string_length(str) + 1; ++j)
		{
			if (str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/')
				have_valid_op = 1;
		}

		if (have_valid_op == 0)
			return NULL;

		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			op_location = i;

			switch (str[i])
			{
			case '+':
				{
					*operator = '+';
					break;
				}
			case '-':
				{
					*operator = '-';
					break;
				}
			case '*':
				{
					*operator = '*';
					break;
				}
			case '/':
				{
					*operator = '/';
					break;
				}
			default:
				{
					//my_put_string("Expression is invalid\n");
					//return NULL;
				}
			}
		}
		else
		{
			//my_put_string("Expression is invalid\n");
			//return NULL;
		}
	}
	//my_put_string(&nextStr[op_location + 1]);
	//my_put_char('\n');
	//free((char*)str);
	//free((char*)nextStr);
	return &nextStr[op_location + 1];
}

char const* consume_operand(char const* str, int* number)
{
	if (str == NULL)
		return NULL;
	if (number == NULL)
		return NULL;

	char const* nextStr = str;
	char* strNumber;
	strNumber = malloc(string_length(str) * sizeof(char));
	int op_location = 0;
	int op_in_nextStr = 0;
	int is_letter = 0;
	int letter_location = 0;
	int end_of_string = 0;

	for (unsigned int i = 0; i < string_length(str) + 1; ++i)
	{
		//if (str[i] == '\0')
		//	return NULL;

		for (unsigned int j = 0; j < string_length(str); ++j)
		{
			if (str[j] < '0' || str[j] > '9')
			{
				is_letter = 1;
				letter_location = j;
				break;
			}
		}

		if (is_letter == 1)
		{
			for (int j = 0; j < letter_location; ++j)
			{
				strNumber[j] = str[j];
			}

			*number = alpha_to_number(strNumber);

			//my_put_number(*number);
			//my_put_string(&nextStr[letter_location]);
			free(strNumber);
			return &nextStr[letter_location];
		}

		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'/* || str[i] == '\0'*/)
		{
			op_in_nextStr = 1;
			op_location = i;
		}
		else
		{
			//my_put_string("Expression is invalid\n");
			//return NULL;
		}

		if (op_in_nextStr == 1)
		{
			//string_sized_copy(strNumber, str, i);

			//strNumber = malloc(i * sizeof(char));

			for (int j = 0; j < op_location; ++j)
			{
				strNumber[j] = str[j];
			}

			*number = alpha_to_number(strNumber);
		}
		else
		{
			//strNumber = malloc(i * sizeof(char));

			for (unsigned int j = 0; j < i; ++j)
			{
				strNumber[j] = str[j];
			}

			*number = alpha_to_number(strNumber);

			for (unsigned int j = 0; j < string_length(str); ++j)
			{
				strNumber[j] = 0;
			}

			end_of_string = 1;
		}
	}
	//my_put_string(strNumber);
	//my_put_char('\n');
	//my_put_number(*number);
	//my_put_char('\n');
	//free((char*)str);
	free(strNumber);

	if (end_of_string == 1)
		return strNumber;

	return &nextStr[op_location];
}

int parse_expression(char const* str, int* left_operand, char* operator, int* right_operand)
{
	if (str == NULL)
		return 0;
	if (left_operand == NULL)
		return 0;
	if (operator == NULL)
		return 0;
	if (right_operand == NULL)
		return 0;
	for (unsigned int i = 0; i < string_length(str) + 1; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	char const* nextStr = consume_operand(str, left_operand);

	if (nextStr == NULL)
		return 0;

	nextStr = consume_operator(nextStr, operator);

	if (nextStr == NULL)
		return 0;

	consume_operand(nextStr, right_operand);

	if (nextStr == NULL)
		return 0;

	//free((char*)nextStr);
	return 1;
}

void execute_expression(char const* str)
{
	if (str == 0)
		return;

	for (unsigned int i = 0; i < string_length(str) + 1; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			{
				my_put_string("Expression is invalid\n");
				return;
			}
		}
	}

	char operator;
	int num1;
	int num2;

	parse_expression(str, &num1, &operator, &num2);

	execute_operation(num1, operator, num2);

	//free((char*)str);
}
