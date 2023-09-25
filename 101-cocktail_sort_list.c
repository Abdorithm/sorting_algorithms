#include "sort.h"

/**
 * swapit - swaps double linked list.
 * @node: fist node.
 * @list: the whole list.
*/
void swapit(listint_t *node, listint_t **list)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - 2-D bubble sort.
 * @list: the list to be sorted.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *seak = *list;
	int swapped = TRUE;

	if (!list || !(*list))
		return;

	while (swapped)
	{
		swapped = FALSE;
		while (seak->next != NULL)
		{
			if (!seak->next)
				break;
			if (seak->n > seak->next->n)
			{
				swapit(seak, list);
				swapped = TRUE;
				print_list(*list);
			}
			else
				seak = seak->next;
		}
		if (!swapped)
			break;

		while (seak->prev != NULL)
		{
			if (seak->n < seak->prev->n)
			{
				swapit(seak->prev, list);
				swapped = TRUE;
				print_list(*list);
			}
			else
				seak = seak->prev;
		}
		seak = seak->next;
	}
}

