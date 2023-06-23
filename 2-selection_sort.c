#include "sort.h"

/**
 * selection_sort - sort list with selection_sort
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, tmp, swap;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		for (min_idx = i, j = i; j < size; j++)
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				swap = 1;
			}
		if (swap == 1)
		{
			tmp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
			swap = 0;
		}
	}
}
