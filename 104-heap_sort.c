#include "sort.h"

/**
 * _swap - swaps the integer
 * @array: the buffer of the integer
 * @n1: index 1
 * @n2: index 2
 */
void _swap(int *arr, int n1, int n2)
{
	arr[n1] = arr[n1] + arr[n2];
	arr[n2] = arr[n1] - arr[n2];
	arr[n1] = arr[n1] - arr[n2];
}

/**
 * recursion_heap - recursion that builds the max heap tree
 * @arr: list of an integers
 * @size: the length of the array
 * @limit: limit of the array
 * @i: the index value of numbers
 */
void recursion_heap(int *arr, int i, size_t size, int limit)
{
	int bigger;
	int i2;

	i2 = i * 2;

	if (i2 + 2 < limit)
	{
		recursion_heap(arr, i2 + 1, size, limit);
		recursion_heap(arr, i2 + 2, size, limit);
	}

	if (i2 + 1 >= limit)
		return;

	if (i2 + 2 < limit)
		bigger = (arr[i2 + 1] > arr[i2 + 2]) ? (i2 + 1) : (i2 + 2);
	else
		bigger = i2 + 1;

	if (arr[i] < arr[bigger])
	{
		_swap(arr, i, bigger);
		print_array(arr, size);
		recursion_heap(arr, bigger, size, limit);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;
	size_t limit;

	if (!array || size == 0)
		return;

	i = 0;
	limit = size;

	while (limit > 1)
	{
		recursion_heap(array, i, size, limit);
		if (array[i] >= array[limit - 1])
		{
			_swap(array, i, limit - 1);
			print_array(array, size);
		}
		limit--;
	}
}
