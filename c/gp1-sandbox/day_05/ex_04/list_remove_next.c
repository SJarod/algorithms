#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_remove_next(t_list* list, t_list_node* node, void** data)
{
	if (list == NULL)
		return;

	if (node == NULL)
		return;

	*data = node->data;

	free(node->next);

	--list->size;
}
