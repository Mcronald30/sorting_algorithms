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
	int exp, maximum = 0;
	int *output = '\0';

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}

/**
 * count_sort - a helper function to perform counting
 * sort based on a specific digit position
 * @arr: the pointer to the array of integers
 * @n: the number of elements in the array.
 * @exp: the digit position (power of 10) that is used for sorting.
 * output: array to save the temporary values.
 */
void count_sort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}

/**
 * get_max - function to determine the maximum
 * element in the given array.
 * @arr: the pointer to the array of integers.
 * @n: the number of elements in the array.
 */
int get_max(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}
