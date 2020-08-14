#include "float.h"
#include "my_put_string.h"

#include <stdlib.h>

int main()
{
	/*t_float const num1 = create_float("73281236478210010547369549852147", 7);
	t_float const num2 = create_float("654147863214589743215478", 4);
	t_float num3;
	print_float(&num1);
	print_float(&num2);
	duplicate_float(&num3, &num1);
	add_digit_right(&num3, 5);
	add_digit_left(&num3, 9);

	reset_float(&num3);*/

	/*t_float flottant;
	init_from_string(&flottant, "123,456");
	print_float(&flottant);

	//add_digit_left(&flottant, 9);
	//add_digit_right(&flottant, 3);

	reset_float(&flottant);*/

	t_float num1;
	t_float num2;
	t_float num3;
	init_from_string(&num1, "7328123647821001054734954,9852147");
	init_from_string(&num2, "65414786321458974321,5478");
	add_floats(&num1, &num2, &num3);

	reset_float(&num1);
	reset_float(&num2);
	reset_float(&num3);

	return 0;
}
