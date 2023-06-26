#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void count_sort(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

/**
 * radix_sort - sort an array of integers in ascending
 * order using the LSD.
 * @array: the pointer to the array of integers sorted.
 * @size: the number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count_sort - a helper function to perform counting
 * sort based on a specific digit position
 * @array: the pointer to the array of integers
 * @size: the number of elements in the array.
 * @exp: the digit position (power of 10) that is used for sorting.
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};

	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * get_max - function to determine the maximum
 * element in the given array.
 * @array: the pointer to the array of integers.
 * @size: the number of elements in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
