#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion sort.
 * @list: double pointer to the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t **head, *temp, *key, *temp_key;

	head = list;
	if (head != NULL)
		key = (*head)->next;

	while (head != NULL && key != NULL)
	{
		temp = key->prev;
		temp_key = key;

		while (temp != NULL && temp->n > temp_key->n)
		{
			/* swap operation begins */
			temp->next = temp_key->next; /* 3 1 */
			if (temp_key->next != NULL)
				temp_key->next->prev = temp;
			temp_key->next = temp;
			temp_key->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp_key;
			temp->prev = temp_key;

			/* checking if we reached the first node in the list */
			if (temp_key->prev == NULL)
			{
				/* update the head to point to the new first node */
				(*head) = temp_key;
				print_list(*head);
				break;
			}
			else /* otherwise continue normally */
				temp = temp_key->prev;

			/* print the list after each swap */
			print_list(*head);
		}
		key = key->next;
	}
}
