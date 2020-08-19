#include "list.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return NULL;
	if (list2 == NULL)
		return NULL;

	list1->tail->next = list2->head;
	list1->size += list2->size;
	list1->tail = list2->tail;
	list1->tail->next = NULL;

	return list1;
}
