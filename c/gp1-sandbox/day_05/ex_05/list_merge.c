#include "list.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return NULL;
	if (list2 == NULL)
		return NULL;

	t_list* newList = list_create();
	list_init(newList, list1->compare, list2->destroy);	

	if (list1->head == NULL)
	{
		if (list2->head == NULL)
			return NULL;
		else
		{
			newList->head = list2->head;
			newList->tail = list2->tail;
			newList->size = list2->size;
			list2->head = NULL;
			list2->tail = NULL;
			list2->size = 0;
			return newList;
		}
	}
	else if (list2->head == NULL)
	{
		if (list1->head == NULL)
			return NULL;
		else
		{
			newList->head = list1->head;
			newList->tail = list1->tail;
			newList->size = list1->size;
			list1->head = NULL;
			list1->tail = NULL;
			list1->size = 0;
			return newList;
		}
	}

	newList->head = list1->head;
	//newList->head->next->next = list2->head;

	t_list_node* temp = newList->head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = list2->head;

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
