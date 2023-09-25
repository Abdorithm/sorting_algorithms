#include "sort.h"

/**
 * merge - sort and merge partitions.
 * @array: the array.
 * @l: left index.
 * @m: mid.
 * @r: right index.
 */
void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int length_1 = m - l + 1; 
	int length_2 = r - m;
	int left[length_1], right[length_2];

	/*
	printf("\t%i %i %i\n", l, m, r); 

	for (i = l; i < m + 1; i++)
		printf("%i ", array[i]);
	printf("\n");

	for (i = m + 1; i <= r; i++)
		printf("%i ", array[i]);
	printf("\n");
	*/
	for (i = 0; i < length_1; i++)
        left[i] = array[l + i];
	for (j = 0; j < length_2; j++)
        right[j] = array[m + 1 + j];
}

/**
 * partition - creates two halfes of the array.
 * @array: the array.
 * @l: left index.
 * @r: right index.
 */
void partition(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

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
