#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_insert_next(t_list* list, t_list_node* node, void* data)
{
	if (list == NULL)
		return;

	++list->size;
	t_list_node* newNode = malloc(sizeof(t_list_node));
	newNode->data = data;

	if (node == NULL)
	{
		//newNode = malloc(sizeof(t_list_node));
		//newNode->data = data;
		newNode->next = list->head;
		list->head = newNode;

		if (list->head->next == NULL)
		{
			list->tail = list->head;
		}

		return;
	}

	if (node->next == NULL)
	{
		node->next = newNode;
		newNode->next = NULL;
		list->tail = newNode;
	}

	newNode->next = node->next;
	node->next = newNode;
	list->tail->next = NULL;
}
