#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: a pointer to the array of integers
 * @size: epresents the number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t i, k;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (k = 0; k < size - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap = array[k];
				array[k] = array[k + 1];
				array[k + 1] = swap;
				print_array(array, size);
			}
		}
		i++;
	}
}
