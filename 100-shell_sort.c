#include "sort.h"

/**
 * shell_sort - Shell Sort.
 * @array: array to be sorted.
 * @size: array size.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, k;
	int tmp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			k = i;
			while (k >= gap && array[k - gap] > tmp)
			{
				array[k] = array[k - gap];
				k -= gap;
			}
			array[k] = tmp;
		}
		print_array(array, size);
	}
}

