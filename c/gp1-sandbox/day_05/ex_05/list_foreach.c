#include "list.h"

#include <stdlib.h>

void list_foreach(t_list const* list, void (*action)(void*))
{
	if (list == NULL)
		return;
	if (action == NULL)
		return;

	t_list_node* temp = list->head;

	while (temp != NULL)
	{
		action(temp->data);
		temp = temp->next;
	}
}
