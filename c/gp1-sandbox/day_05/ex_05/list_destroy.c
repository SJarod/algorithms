#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_destroy(t_list** list)
{
	if (list == NULL)
		return;

	t_list_node* temp = (*list)->head; //malloc(sizeof(t_list_node));

	(*list)->destroy((*list)->head->data);

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
			(*list)->destroy((*list)->head->next->data);
			free((*list)->head->next);
		}
		else
		{
			(*list)->destroy((*list)->head->next->data);
			free((*list)->head->next);
			free((*list)->head);
			break;
		}

		(*list)->head->next = temp;
	}

	(*list)->size = 0;
	free(*list);

	*list = NULL;
}
