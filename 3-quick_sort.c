#include "sort.h"

/**
 * partition - rearranging the elements in the array 
 * @array: Pointer to the array of integers.
 * @low: The starting index of the partition being sorted.
 * @high: The ending index of the partition being sorted
 * @size: array size
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, temp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorts an array of integers recursively
 * @array: Pointer to the array of integers.
 * @low: The starting index of the partition being sorted.
 * @high: The ending index of the partition being sorted
 * @size: array size
 */
void qs(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		qs(array, low, pivot - 1, size);
		qs(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: Pointer to the array of integers.
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
