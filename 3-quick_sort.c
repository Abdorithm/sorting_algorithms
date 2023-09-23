#include "sort.h"

/**
 * lomuto - implements the Lomuto partition scheme.
 * @array: pointer to the partition.
 * @low: ...
 * @high: ...
 * @size: ...
 */
void lomuto(int *array, int low, int high, size_t size)
{
	int pivot, j, i, temp;

	if (low >= high)
		return;

	pivot = array[high];
	j = low;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
			j++;
		}
	}

	temp = array[j];
	array[j] = array[high];
	array[high] = temp;
	print_array(array, size);

	lomuto(array, low, j - 1, size);
	lomuto(array, j + 1, high, size);
}

/**
 * quick_sort - implementation of the quick sort algorithm.
 * @array: pointer to the array.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	lomuto(array, 0, size - 1, size);
}
