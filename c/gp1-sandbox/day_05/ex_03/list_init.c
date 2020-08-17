#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_init(t_list* list, int (*compare)(void*, void*), void (*destroy)(void*))
{
	if (list == NULL)
		return;

	add_element(list);

	list->compare = compare;
	list->destroy = destroy;
}

void add_element(t_list* list)
{
	if (list == NULL)
		return;

	list->size += 1;
	list->head = malloc(sizeof(t_list_node));
}
