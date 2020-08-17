#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_destroy(t_list** list)
{
	for (int i = 0; i < (*list)->size; ++i)
	{
		free((*list)->head + i);
	}

	free(*list);
}
