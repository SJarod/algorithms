#ifndef __EXPRESSION__
#define __EXPRESSION__

char const*	consume_operator(char const* str, char* operator);
char const*	consume_operand(char const* str, int* number);
int		parse_expression(char const* str, int* left_operand, char* operator, int* right_operand);
void		execute_expression(char const* str);

#endif
