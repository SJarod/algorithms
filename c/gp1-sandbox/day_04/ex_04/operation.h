#ifndef __OPERATION__
#define __OPERATION__

int			addition(int a, int b);
int			substraction(int a, int b);
int			multiplication(int a, int b);
int			divistion(int a, int b);

typedef int		(*pointer_operation_type)(int a, int b);	//function pointer

pointer_operation_type	get_pointer_operation(char operator);		//return the corresponding function pointer
void			execute_operation(int l_operand, char operator, int r_operand);

#endif
