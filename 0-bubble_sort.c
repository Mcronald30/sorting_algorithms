#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: a pointer to the array of integers
 * @size: epresents the number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = size;
	int swap;

	if (array == NULL)
		return;
	for (j = size; j > 0; j--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
