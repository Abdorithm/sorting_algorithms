#include "sort.h"

/**
 * merge - ...
 */
void merge(int *array, int l, int m, int r)
{
	int i;

	/* printf("\t%i %i %i\n", l, m, r); */
	for (i = l; i < m + 1; i++)
		printf("%i ", array[i]);
	printf("\n");

	for (i = m + 1; i <= r; i++)
		printf("%i ", array[i]);
	printf("\n");
}

/**
 * partition - creates two halfes of the array.
 * @array: the array.
 * @l: left index.
 * @r: right index.
 */
void partition(int *array, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		if ((r - l) % 2 == 0 && m)
			m--;
		partition(array, l, m);
		partition(array, m + 1, r);
		
		merge(array, l, m, r);
    }
}

/**
 * merge_sort - top-down implementation of merge sort.
 * @array: the array to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	partition(array, 0, size - 1);
}
