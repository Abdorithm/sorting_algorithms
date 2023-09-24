#include "sort.h"

/**
 * selection_sort - Selection Sort.
 * @array: array to be sorted.
 * @size: the size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp, swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = FALSE;
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			swapped = TRUE;
		}

		if (swapped == TRUE)
			print_array(array, size);
	}
}

