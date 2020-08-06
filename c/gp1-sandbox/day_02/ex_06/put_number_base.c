#include "put_number_base.h"
#include "my_put_char.h"
#include "string_length.h"

#include <stddef.h>

void put_numbase(int number, char const* base)
{
	if (base != NULL)
	{
		if (string_length(base) != 0){
		if (string_length(base) == 1)
		{
			int count = 0;
			
			if (number < 0)
			{
				my_put_char('-');
				number = -number;
			}

			while (count <= number)
			{
				my_put_char(base[0]);
				++count;
			}
		}
		else
		{
			int lengthVar = string_length(base);
			//int nlength = string_length(base);
			//int sym[string_length(base)];
			int ndiv = number;
			int Ndiv = 0;
			int modulo = 0;

			if (number < 0)
			{
				my_put_char('-');
				number = -number;
			}

			//while ()
			//{
			//	sym[] = base[];
			//}

			while (ndiv != 0)
			{
				ndiv /= lengthVar;
				++Ndiv;
			}
			
			for (int i = Ndiv - 1; i > 0; --i)
			{
				int result = number;
	
				for (int j = i; j > 0; --j)
				{
					result /= lengthVar;
				}
	
				modulo = result % lengthVar;
				my_put_char(base[modulo]);
			}
			my_put_char(base[number % lengthVar]);
		}
		}
	}
}
