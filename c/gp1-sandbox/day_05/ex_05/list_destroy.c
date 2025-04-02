#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_destroy(t_list** list)
{
	if (list == NULL || *list == NULL)
		return;

	if ((*list)->size == 0)
	{
		free(*list);
		return;
	}

	t_list_node* temp = (*list)->head; //malloc(sizeof(t_list_node));


	//(*list)->destroy((*list)->head->data);

	for (int i = 1; i < (*list)->size; ++i)
	{
		if ((*list)->head->next == NULL)
		{
			(*list)->head = NULL;
			break;
		}

		if ((*list)->head->next != NULL)
		{
			temp = (*list)->head->next;

			if ((*list)->destroy != NULL)
				(*list)->destroy((*list)->head->data);

			free((*list)->head);
			(*list)->head = NULL;
		}

		(*list)->head = temp;
	}

	if ((*list)->destroy != NULL)
		(*list)->destroy((*list)->head->data);
	free((*list)->head);
	(*list)->size = 0;
	free(*list);

	*list = NULL;
}
