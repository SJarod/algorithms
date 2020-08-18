#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_remove_next(t_list* list, t_list_node* node, void** data)
{
	if (list == NULL)
		return;

	if (node == NULL)
		return;

	if (node->next == NULL)
		return;

	*data = node->next->data;

	if (node->next == list->tail)
	{
		node->next = NULL;
	}
	else
	{
		node->next = node->next->next;
	}
	free(node->next);

	--list->size;
}
