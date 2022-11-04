#include "sort.h"

/**
 * swap - swaps an integers
 * @int1: integer 1
 * @int2: integer 2
 */
void swap(int *int1, int *int2)
{
	int tmp = *int1;

	*int1 = *int2;
	*int2 = tmp;
}

/**
 * max_heap - the max heap
 * @array: list of an integers
 * @size: the length of the array
 * @idx: index
 * @n: size of the array to run
 */
void max_heap(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		max_heap(array, size, largest, n);
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
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		max_heap(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		max_heap(array, size, 0, i);
	}
}
