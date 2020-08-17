#include "list.h"
#include "list_internal.h"

#include <stdlib.h>
#include <stdbool.h>

bool list_node_is_head(t_list const* list, t_list_node const* node)
{
	if (list == NULL)
		return false;
	if (list == NULL)
		return false;

	int test = 0;

	if (test == list->size)
		return true;

	list_node_is_head(list, node->next);
	++test;
	return false;
}
