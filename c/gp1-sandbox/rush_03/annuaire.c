#include "annuaire.h"
#include "read_char.h"

#include "my_put_string.h"
#include "my_put_number.h"
#include "string_length.h"

#include <stdio.h>
#include <stdlib.h>

FILE* which_file(char* fname)
{
	FILE* file = fopen(fname, "r+");
	return file;
}

void display(FILE* file)
{
	if (file == NULL)
	{
		my_put_string("No file available\n");
		return;
	}

	//reading file-------------------------------------------
	t_category*	head;
	char		c;
	t_category*	temp;
	int		i = 0;

	head = malloc(sizeof(t_category));
	temp = head;
	temp->str = malloc(sizeof(char));
	temp->next = NULL;

	while (read_char(file, &c) == 1)
	{
		if (c == '|' || c == '=')		//if char = '|' then create new node 
		{
			temp->next = malloc(sizeof(t_category));
			temp = temp->next;
			i = 0;
		}
		else if (c == '\n' || c == '\0')	//if end of line or file then create new node with NULL string in it
		{
			temp->next = malloc(sizeof(t_category));
			temp->next->str = NULL;
			temp->next->next = malloc(sizeof(t_category));
			temp = temp->next->next;
			i = 0;
		}
		else					//fill the string of node
		{
			temp->str = realloc(temp->str, (i + 1) * sizeof(char));
			temp->str[i] = c;
			++i;
		}

		if (c == '\n' && c == '\0')
			fseek(file, 1, SEEK_CUR);
	}

	//counting lines-----------------------------------------
	int	count = 0;

	fseek(file, 0, SEEK_SET);

	while (read_char(file, &c) == 1)
	{
		if (c == '\n' || c == '\0')
			++count;
	}

	//displaying nodes---------------------------------------
	int entry = 0;

	temp = head;

	for (int i = 0; i < count; ++i)
	{
		on_screen(temp, count, entry);	//function to print on screen
		++entry;

		while (temp->str != NULL)
		{
			temp = temp->next;
		}
		temp = temp->next;
	}

	fclose(file);

	//freeing all nodes--------------------------------------
	temp = head;

	while (temp->next != NULL)
	{
		if (temp->next == NULL)
		{
			free(temp);
			temp = head;
		}
		else
			temp = temp->next;
	}
}

void on_screen(t_category* head, int count, int entry)
{
	//assign node to struct s_directory----------------------
	t_directory* directory = malloc(sizeof(t_directory));

	for (int i = 0; i < count; ++i)
	{
		if (head != NULL)
			directory->FirstName = head;

		if (directory->FirstName->next != NULL)
			directory->LastName = directory->FirstName->next;

		if (directory->LastName->next != NULL)
			directory->Login = directory->LastName->next;

		if (directory->Login->next != NULL)
			directory->Function = directory->Login->next;

		if (directory->Function->next != NULL)
			directory->Key = directory->Function->next;

		if (directory->Key->next != NULL)
			directory->Value = directory->Key->next;

	}

	//displaying result--------------------------------------
	if (count == 0)
		return;

	my_put_string("Entry ");
	my_put_number(entry);
	my_put_string(":\n");

	if (directory->FirstName->str != NULL &&
			directory->LastName->str != NULL)
	{
		my_put_string("+ name: ");
		my_put_string(directory->FirstName->str);
		my_put_char(' ');
		my_put_string(directory->LastName->str);
		my_put_char('\n');
	}

	if (directory->Login->str != NULL)
	{
		my_put_string("+ login: ");
		my_put_string(directory->Login->str);
		my_put_char('\n');
	}

	if (directory->Function->str != NULL)
	{
		my_put_string("+ function: ");
		my_put_string(directory->Function->str);
		my_put_char('\n');
	}

	if (directory->Key->str != NULL &&
			directory->Value->str != NULL)
	{
		my_put_string("+ ");
		my_put_string(directory->Key->str);
		my_put_string(": ");
		my_put_string(directory->Value->str);
		my_put_char('\n');
	}

	free(directory);
}

void add(FILE* file, char* newLine)
{
	if (file == NULL || newLine == NULL)
		return;

	int		bars = 0;
	unsigned int	len = string_length(newLine);

	for (unsigned int i = 0; i < len; ++i)
	{
		if (newLine[i] == '|')
			++bars;
	}

	if (bars < 3)
	{
		my_put_string("string not acceptable\n");
		return;
	}

	fseek(file, 0, SEEK_END);
	fputs(newLine, file);
	fseek(file, 0, SEEK_SET);

	fclose(file);
}
