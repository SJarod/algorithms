#ifndef __PARSE_FILE__
#define __PARSE_FILE__

#include <stdio.h>

int	read_char(FILE* file, char* pointer_c);
int	is_space(char c);
char*	sub_string(char const* str, unsigned int pos, unsigned int len);
char*	read_line(FILE* file);
int	parse_section(const char* str, char** p_section_name);
int	parse_property(const char* str, char** p_name, char** p_value);

#endif
