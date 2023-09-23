#include "sort.h"

/**
 * bubble_sort - Buble sort.
 * @array: target array
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t rear = 0, front = 1;
	int tmp, swapped = FALSE;

	for (; front < size; rear++, front++)
	{
		if (array[rear] > array[front])
		{
			tmp = array[front];
			array[front] = array[rear];
			array[rear] = tmp;

			swapped = TRUE;
			print_array(array, size);
		}
	}

	if (swapped == FALSE)
		return;

	bubble_sort(array, size);
}

