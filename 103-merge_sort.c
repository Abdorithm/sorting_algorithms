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
	int *splits = (int *)malloc(sizeof(int) * (length_1 + length_2));

	printf("\t%i %i %i\n", length_1, m, length_2);

	for (i = 0; i < length_1; i++)
		splits[i] = array[l + i];
	for (j = 0; j < length_2; j++)
		splits[j + length_1] = array[m + 1 + j];

	(void)k;
	for (i = 0; i < length_1 + length_2; i++)
		printf("%i ", splits[i]);
	printf("\n");
	free(splits);
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
