#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

t_list* list_create(void)
{
	t_list* myList;

	myList = malloc(sizeof(t_list));

	myList->size = 0;
	myList->head = NULL;
	myList->tail = NULL;

	return myList;
}
