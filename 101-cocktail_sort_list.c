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
	listint_t *right = NULL, *left = NULL, *temp;
	int swapped = TRUE;

	if (!list || !(*list))
		return;

	while (swapped)
	{
		swapped = FALSE;
		for (; seak->next != right; seak = seak->next)
		{
			if (!seak->next)
				break;
			if (seak->n > seak->next->n)
			{
				temp = seak->next;
				swapit(seak, list);
				seak = temp;
				swapped = TRUE;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		right = seak;
		for (; seak->prev != left; seak = seak->prev)
		{
			if (seak->n < seak->prev->n)
			{
				temp = seak->prev;
				swapit(seak->prev, list);
				seak = temp;
				swapped = TRUE;
				print_list(*list);
			}
		}
		left = seak;
		seak = seak->next;
	}
}

