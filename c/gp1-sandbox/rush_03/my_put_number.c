#include "my_put_number.h"

#include "my_put_string.h"

#include <stddef.h>	

#include <limits.h>

void my_put_number(int num)
{	
	int intmin = 0;
	int x = 1;
	int i = 0;
	int n = 0;
	if ( num == INT_MIN)
	{
		num = num + 1;
		intmin = intmin + 1;
	}	
	if (num < 0)
	{	
		my_put_char('-');
		num = -num;
	}
	
	int num1 = num;
	if ( num < 10 )
	{	
		my_put_char(num + '0');
	}
	else if (num > 9)
	{	
		while (num >= 10)		
		{	
			num = num / 10;
			x = x * 10;
		}
		num = num1;	
		while (x >= 10)
		{
			i = num / x;
			my_put_char(i + '0');
			num = num % x;
			x = x / 10;
			if (x < 10)
			{	
				if (intmin == 1)
				{
					n = num % 10;
					n = n + 1;
					my_put_char(n + '0');
					num = num / 10;
					break;
				}	
				n = num % 10;	
				my_put_char(n + '0');	
				num = num / 10;
			}
		}		
	}

}
