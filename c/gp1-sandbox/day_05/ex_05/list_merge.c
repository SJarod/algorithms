#include "list.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return 0;
	if (list2 == NULL)
		return 0;

	t_list* newList = list_create();

	newList->head = list1->head;
	newList->tail = list2->tail;
	list1->tail->next = list2->head;

	return newList;
}
