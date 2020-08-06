#include "sort_char.h"
//#include "my_put_string.h"

void swap_char(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void sort_char(char* tab, unsigned int tab_length)
{
	int nchar = tab_length - 1;
	//char select;
	//char select2;

	for (int i = nchar; i > 0; --i)
	{
		//for (int j = i; j > 1; --j)
		//{
			for (int k = 0; k < i; ++k)
			{
				if (tab[k] > tab[k+1])
				{
					//my_put_char(tab[k]);
					//my_put_char(tab[k+1]);
					swap_char(&tab[k], &tab[k+1]);
				}
			}
		//}
	}
}
