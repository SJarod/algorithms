#ifndef __FLOAT__
#define __FLOAT__

typedef struct s_float
{
	char*	mantisse;
	int	exp;

} t_float;

void	init_float(t_float* f);
void	reset_float(t_float* f);
t_float	create_float(char* mantisse, int exp);					//create a t_float

void	duplicate_float(t_float* fdest, t_float const* fsrc);

void	add_digit_right(t_float* f, int digit);
void	add_digit_left(t_float* f, int digit);

void	init_from_string(t_float* f, char const* str);

void	print_float(t_float const* f);

char*	shortest_string(char* str1, char* str2);				//returns the length of the shortest string
void	add_mantisses(t_float const* f1, t_float const* f2, t_float* fres);
int	char_to_number(char c);
char	number_to_char(int num);

void	add_floats(t_float const* f1, t_float const* f2, t_float* fres);
void	multiply_floats(t_float const* f1, t_float const* f2, t_float* fres);

#endif
