#include "sort.h"

/**
 * arr_max - array max
 * @array: array
 * @size: size of the array
 * Return: max
 */
int arr_max(int *array, size_t size)
{
	int data;
	size_t i;

	data = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > data)
			data = array[i];
	return (data);
}

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *new_arr, data, num;
	size_t i;

	if (size < 2 || !array)
		return;
	data = arr_max(array, size);

	arr = malloc(sizeof(size_t) * (data + 1));
	new_arr = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= data; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	for (i = 1; (int)i <= data; i++)
		arr[i] += arr[i - 1];
	print_array(arr, data + 1);
	for (i = 0; i < size; i++)
	{
		new_arr[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = new_arr[i];

	free(new_arr);
	free(arr);
}
