#include "list.h"

#include <stdlib.h>

t_list_node* list_node_next(t_list_node const* node)
{
	if (node == NULL)
		return NULL;

	return node->next;
}
