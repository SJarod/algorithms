#include "list.h"
#include "list_internal.h"

t_list_node* list_head(t_list const* list)
{
	return list->head;
}
