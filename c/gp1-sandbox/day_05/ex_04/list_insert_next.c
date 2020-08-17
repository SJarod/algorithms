#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_insert_next(t_list* list, t_list_node* node, void* data)
{
	if (list == NULL)
		return;

	if (node == NULL)
	{
		++list->size;
		list->head->data = data;
		return;
	}

	++list->size;

	node->next = malloc(sizeof(t_list_node));
	node->next->data = data;
}
