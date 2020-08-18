#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_destroy(t_list** list)
{
	if (list == NULL)
		return;

	t_list_node* temp = (*list)->head; //malloc(sizeof(t_list_node));

	for (int i = 1; i < (*list)->size; ++i)
	{
		if ((*list)->head->next == NULL)
		{
			(*list)->head = NULL;
			break;
		}

		if ((*list)->head->next->next != NULL)
		{
			temp = (*list)->head->next->next;
			free((*list)->head->next);
		}
		else
		{
			free((*list)->head->next);
			free((*list)->head);
		}

		(*list)->head->next = temp;
	}

	(*list)->size = 0;
	free(*list);

	*list = NULL;
}
