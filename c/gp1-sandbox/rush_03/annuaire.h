#ifndef __ANNUAIRE__
#define __ANNUAIRE__

#include <stdio.h>

//linked list============================================================================

//each node = each section string
typedef struct s_category
{
	char*			str;
	struct s_category*	next;

} t_category;


//name each string
typedef struct s_directory
{
	t_category*	FirstName;
	t_category*	LastName;
	t_category*	Login;
	t_category*	Function;
	t_category*	Key;
	t_category*	Value;

} t_directory;

//=======================================================================================


//open a file (.txt)
FILE*	which_file(char* fname);

//display file
void	display(FILE* file);

//choose what to display on screen
//arguments :
//	    t_category*	head	//start of line
//	    int		count	//number of lines
//	    int		entry	//number of entries (= to lines)
void	on_screen(t_category* head, int count, int entry);

//add a lin to .txt
void	add(FILE* file, char* newLine);





/*
//remove a line of .txt by passing login
void	remove(FILE* file, char* login);

//find a line of .txt by passing login
void	find(FILE* file, char* login);

//modify a t_annuaire of .txt
//which = what t_annuaire
//newData = new value
void	modify(FILE* file, char* login, char* which, char* newData);
*/

#endif
