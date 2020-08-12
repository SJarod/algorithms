#ifndef __STRING_TO_WORD_ARRAY
#define __STRING_TO_WORD_ARRAY

int number_of_word(char const* str);
unsigned int word_length(char const* str, int number);
char* which_word(char const* str, int x);
char** string_to_word_array(char const* str);

#endif
