#include "operation.h"
#include "my_put_number.h"
#include "my_put_string.h"

#include <stddef.h>

int addition(int a, int b)
{
	return a + b;
}

int substraction(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	if (b == 0)
		return 0;

	return a / b;
}

pointer_operation_type get_pointer_operation(char operator)
{
	switch (operator)
	{
	case '+':
		{
			return &addition;
		}
	case '-':
		{
			return &substraction;
		}
	case '*':
		{
			return &multiplication;
		}
	case '/':
		{
			return &division;
		}
	default:
		{
			return NULL;
		}
	}

	return NULL;
}

void execute_operation(int l_operand, char operator, int r_operand)
{
	pointer_operation_type calculation = NULL;
	calculation = get_pointer_operation(operator);
	int result = calculation(l_operand, r_operand);

	my_put_number(result);
	my_put_char('\n');
}
