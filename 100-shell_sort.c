#include "sort.h"

/**
 * shell_sort - Shell sort algorithm that sorts
 * an array of integers in ascending order
 * @array: Pointer to the array of integers to be sorted
 * @size: The size of the array, specified as the number
 * of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, temp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
	}
}
