#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: a pointer to the array of integers
 * @size: epresents the number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, j, swapped = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
			swapped = array[j];
			array[j] = array[j + 1];
			array[j + 1] = swapped;
			print_array(array, size);
			}
		}
}
