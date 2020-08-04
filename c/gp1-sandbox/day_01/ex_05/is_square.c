#include "is_square.h"

#include <stdio.h>

void my_put_char(char c)
{
	fwrite(&c,sizeof(char),1,stdout);
}

void is_square(unsigned int num)
{
	switch (num % 5)
	{
	case 0:
		while (num >= 100)
		{
			num = num / 100;
		}
		if (num == 5)
		{
			my_put_char('N');
			break;
		}
		else if (num != 0 && num % 10 != 0)
		{
			is_square(num);
		}
		else
			my_put_char('N');
		break;
	case 1:
		my_put_char('Y');
		break;
	case 4:
		my_put_char('Y');
		break;
	default:
		my_put_char('N');
		break;
	}
}
