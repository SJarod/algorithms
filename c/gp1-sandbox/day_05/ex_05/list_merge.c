#include "list.h"
#include "list_internal.h"

#include <stdlib.h>

t_list* list_merge(t_list* list1, t_list* list2)
{
	if (list1 == NULL)
		return NULL;
	if (list2 == NULL)
		return NULL;

	t_list*		newList = list_create();
	t_list*		tempList = list1;		//which list
	t_list_node*	temp = tempList->head->next;	//which node to pass and free
	t_list_node*	tempCur = tempList->head->next;	//which node to pass to list head
	t_list_node*	newTemp = newList->head;	//which node of the new list
	int		newListSize = list1->size + list2->size;

	newList->head = malloc(sizeof(t_list_node));
	newTemp = newList->head;
	newList->head->data = list1->head->data;
	newList->size = newListSize;

	for (int i = 0; i < newListSize - 1; ++i)
	{
		if (temp->next == NULL)
		{
			t_list_node* newNode = malloc(sizeof(t_list_node));
			newNode->next = NULL;
			newTemp->next = newNode;
			newNode->data = temp->data;

			tempList = list2;
			tempCur = tempList->head;
			temp = tempCur;
			newTemp = newTemp->next;

			newList->tail = newNode;
		}
		else if (temp->next != NULL)
		{
			t_list_node* newNode = malloc(sizeof(t_list_node));
			newNode->next = NULL;
			newTemp->next = newNode;
			newNode->data = temp->data;

			//free(temp);
			tempCur = tempCur->next;
			temp = tempCur;
			newTemp = newTemp->next;

			newList->tail = newNode;
		}
	}

	t_list_node* newNode = malloc(sizeof(t_list_node));
	newNode->next = NULL;
	newList->tail->next = newNode;
	newNode->data = list2->tail->data;
	newList->tail = newNode;

	temp = list1->head;

	for (int i = 1; i < list1->size; ++i)
	{
		if (list1->head->next == NULL)
		{
			list1->head = NULL;
			//free(list1->head);
			break;
		}

		if (list1->head->next != NULL)
		{
			temp = list1->head->next;
			free(list1->head);
		}
		else
		{
			list1->destroy(list1->head->data);
			free(list1->head);
		}

		list1->head = temp;
	}

	free(list1->head);
	temp = list2->head;

	for (int i = 1; i < list2->size; ++i)
	{
		if (list2->head->next == NULL)
		{
			list2->head = NULL;
			//free(list2->head);
			break;
		}

		if (list2->head->next != NULL)
		{
			temp = list2->head->next;
			free(list2->head);
		}
		else
		{
			list2->destroy(list2->head->data);
			free(list2->head);
		}

		list2->head = temp;
	}

	newList->tail = newTemp;

	free(list2->head);

	free(newNode);
	//free(newTemp);

	list1->size = 0;
	list2->size = 0;

	return newList;
}
