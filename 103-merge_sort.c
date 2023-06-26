#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - print left and right partitions
 * @array: the pointer to the integer array.
 * @size: indicates the total size of the array
 * @first: starting index from where the printing should begin.
 * @med: the ending index until which the printing should occur.
 */
void print_left_right(int *array, int size, int first, int med)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < med)
	{
		if (k != med - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = med;
	while (k < size)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - merge the values in the position of array
 * @array: pointer to the integer array.
 * @size: the total size of the array.
 * @n_copy: copy of array
 * @first: the starting index from where the printing should begin.
 * @med: the ending index until which the printing should occur.
 * first one of the second array
 */
void merge(int *array, int size, int first, int med, int *n_copy)
{
	int i, j, k;

	print_left_right(array, size, first, med);

	i = first;
	j = med;

	printf("[Done]: ");
	k = first;
	while (k < size)
	{
		if (i < med && (j >= size || array[i] <= array[j]))
		{
			n_copy[k] = array[i];
			i++;
		}
		else
		{
			n_copy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", n_copy[k]);
		else
			printf("%d\n", n_copy[k]);
		k++;
	}
}
/**
 * mergeSort - array separator
 * @n_copy: copy of array
 * @first: initial position
 * @size: size of the original  array
 * @array: the original array
 */
void mergeSort(int *n_copy, int first, int size, int *array)
{
	int med;

	if (size - first < 2)
		return;

	med = (size + first) / 2;

	mergeSort(array, first, med, n_copy);
	mergeSort(array, med, size, n_copy);

	merge(n_copy, size, first, med, array);
}
/**
 * copy_array - copy array of int
 * @arr: array source
 * @n_copy: array destination
 * @size : array size
 */
void copy_array(int *arr, int *n_copy, int size)
{
	int index;

	for (index = 0; index < (int)size; index++)
		n_copy[index] = arr[index];
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @size : array size
 */
void merge_sort(int *array, size_t size)
{
	int *n_copy;

	n_copy = malloc(sizeof(int) * size - 1);

	if (n_copy == NULL)
		return;

	copy_array(array, n_copy, size);

	mergeSort(n_copy, 0, size, array);
	free(n_copy);
}
