#include "list.h"
#include "list_internal.h"

t_list_node* list_tail(t_list const* list)
{
	return list->tail;
}
