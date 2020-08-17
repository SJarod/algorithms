#include "list.h"
#include "list_internal.h"

#include <stdlib.h>
#include <stdbool.h>

bool list_node_is_tail(t_list const* list, t_list_node const* node)
{
	if (list == NULL)
		return false;

	if (list->tail->next == node->next)
		return true;
	else
		return false;
}
