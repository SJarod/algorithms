#include "list.h"
#include "list_internal.h"

unsigned int list_size(t_list const* list)
{
	return list->size;
}
