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

		list_insert_next(newList, NULL, list_node_data(temp));
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

		list_insert_next(newList, NULL, list_node_data(temp));
	}

	list_destroy(&list1);
	list_destroy(&list2);
	list_foreach(newList, newList->destroy);

	return newList;
}
