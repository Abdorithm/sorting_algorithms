#include "sort.h"

/**
 * document - documenting progress.
 * @array: the sorted array.
 * @splits: before sorting.
 * @length_1: first partition length.
 * @length_2: second partition length.
 * @l: beginning of the partitions.
 */
void document(int *array, int *splits, int length_1, int length_2, int l)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < length_1; i++)
	{
		printf("%i", splits[i]);
		if (i < length_1 - 1)
			printf(", ");
	}
	printf("\n");
	printf("[Right]: ");
	for (i = length_1; i < length_1 + length_2; i++)
	{
		printf("%i", splits[i]);
		if (i < length_1 + length_2 - 1)
			printf(", ");
	}
	printf("\n");
	printf("[Done]: ");
	for (i = l; i < l + length_1 + length_2; i++)
	{
		printf("%i", array[i]);
		if (i < l + length_1 + length_2 - 1)
			printf(", ");
	}
	printf("\n");
	free(splits);
}

/**
 * merge - sort and merge partitions.
 * @array: the array.
 * @l: left index.
 * @m: mid.
 * @r: right index.
 *
 * Return: void.
 */
void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int length_1 = m - l + 1, length_2 = r - m;
	int *splits = (int *)malloc(sizeof(int) * (length_1 + length_2));

	if (splits == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < length_1; i++)
		splits[i] = array[l + i];
	for (j = 0; j < length_2; j++)
		splits[j + length_1] = array[m + 1 + j];

	i = 0, j = length_1, k = l;
	while (i < length_1 && j < length_2 + length_1)
	{
		if (splits[i] <= splits[j])
		{
			array[k] = splits[i];
			i++;
		}
		else
		{
			array[k] = splits[j];
			j++;
		}
		k++;
	}

	while (i < length_1)
	{
		array[k] = splits[i];
		i++, k++;
	}

	while (j < length_2 + length_1)
	{
		array[k] = splits[j];
		j++, k++;
	}

	document(array, splits, length_1, length_2, l);
}

/**
 * partition - creates two halfes of the array.
 * @array: the array.
 * @l: left index.
 * @r: right index.
 *
 * Return: void.
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
