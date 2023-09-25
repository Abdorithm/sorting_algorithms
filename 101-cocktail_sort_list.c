#include "sort.h"

/**
 * swapit - swaps double linked list.
 * @nod1: fist node.
 * @nod2: second node.
 * @list: the whole list.
*/
void swapit(listint_t *nod1, listint_t *nod2, listint_t **list)
{
	listint_t *nod1s_back = nod1->prev;
	listint_t *nod2s_front = nod2->next;

	if (nod1 == nod2)
		return;

	nod2->next = nod1;
	nod2->prev = nod1s_back;
	if (nod1s_back)
		nod1s_back->next = nod2;
	else
		*list = nod2;

	nod1->next = nod2s_front;
	nod1->prev = nod2;
	if (nod2s_front)
		nod2s_front->prev = nod1;
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
				swapit(seak, seak->next, list);
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
				swapit(seak->prev, seak, list);
				seak = temp;
				swapped = TRUE;
				print_list(*list);
			}
		}
		left = seak;
		seak = seak->next;
	}
}

