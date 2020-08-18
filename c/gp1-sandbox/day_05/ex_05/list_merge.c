#include "list.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return 0;
	if (list2 == NULL)
		return 0;

	t_list*		newList = list_create();
	t_list_node*	temp = list1->head;
	int		whichNode;

	for (int j = 0; j < list2->size; ++j)
	{
		whichNode = list2->size - j - 1;
		temp = list2->head;

		while (whichNode > 0)
		{
			temp = temp->next;
			--whichNode;
		}

		list_insert_next(newList, NULL, temp->data);
	}

	for (int j = 0; j < list1->size; ++j)
	{
		whichNode = list1->size - j - 1;
		temp = list1->head;

		while (whichNode > 0)
		{
			temp = temp->next;
			--whichNode;
		}

		list_insert_next(newList, NULL, temp->data);
	}	

	for (int i = 1; i < list1->size; ++i)
	{
		if (list1->head->next == NULL)
		{
			list1->head = NULL;
			break;
		}

		if (list1->head->next->next != NULL)
		{
			temp = list1->head->next->next;
			free(list1->head->next);
		}
		else
		{
			free(list1->head->next);
			free(list1->head);
		}

		list1->head->next = temp;
	}

	list1->size = 0;

	for (int i = 1; i < list2->size; ++i)
	{
		if (list2->head->next == NULL)
		{
			list2->head = NULL;
			break;
		}

		if (list2->head->next->next != NULL)
		{
			temp = list2->head->next->next;
			free(list2->head->next);
		}
		else
		{
			free(list2->head->next);
			free(list2->head);
		}

		list2->head->next = temp;
	}

	list2->size = 0;

	return newList;
}
