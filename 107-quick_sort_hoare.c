#include "sort.h"

/**
 * _swap - swaps ascending or descending order
 * @array: list of the integer
 * @int1: integer 1
 * @int2: integer 2
 */
void _swap(int *array, ssize_t int1, ssize_t int2)
{
	int tmp;

	tmp = array[int1];
	array[int1] = array[int2];
	array[int2] = tmp;
}

/**
 * _partition - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 * @min: the first integer
 * @max: the last integer index
 *
 * Return: void has no return value
 */
int _partition(int *array, int min, int max, int size)
{
	int current = min - 1, finder = max + 1;
	int pivot = array[max];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		_swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * _sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 * @min: the first integer
 * @max: the last integer index
 *
 * Return: void has no return value
 */
void _sort(int *array, ssize_t min, ssize_t max, int size)
{
	ssize_t position = 0;

	if (min < max)
	{
		position = _partition(array, min, max, size);
		_sort(array, min, position - 1, size);
		_sort(array, position, max, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_sort(array, 0, size - 1, size);
}
