#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

void list_insert_next(t_list* list, t_list_node* node, void* data)
{
	if (list == NULL)
		return;

	++list->size;
	t_list_node* newNode = node->next;

	if (node == NULL)
	{
		newNode = malloc(sizeof(t_list_node));
		newNode->data = data;
		newNode->next = list->head;
		list->head = newNode;
		return;
	}

	newNode = malloc(sizeof(t_list_node));
	newNode->data = data;

	if (node == list->tail)
		newNode->next = NULL;
	else
		newNode->next = node->next;

	node->next = newNode;
}
