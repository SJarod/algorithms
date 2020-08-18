#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_init(t_list* list, int (*compare)(void*, void*), void (*destroy)(void*))
{
	if (list == NULL)
		return;

	list->compare = compare;
	list->destroy = destroy;
}
