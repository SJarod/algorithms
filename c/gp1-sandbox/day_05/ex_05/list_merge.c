#include "list.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return NULL;
	if (list2 == NULL)
		return NULL;

	t_list* newList = list_create();

	newList->head = list1->head;
	list1->tail->next = list2->head;
	newList->size = list1->size + list2->size;
	newList->tail = list2->tail;
	newList->tail->next = NULL;
	list1->head = NULL;
	list2->head = NULL;
	list1->tail = NULL;
	list2->tail = NULL;
	list1->size = 0;
	list2->size = 0;

	return newList;
}
