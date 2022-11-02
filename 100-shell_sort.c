#include "sort.h"

/**
 * _sort - sorts an array of integers in ascending order
 * @array: list of an integer of an array
 * @size: size of the array
 * @n: numbers
 *
 * Return: void has no return value
 */
void _sort(int *array, int size, int n)
{
	int tmp, i = 0, j;

	while ((i + n) < size)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (array[j] < array[j - n])
			{
				tmp = array[j];
				array[j] = array[j - n];
				array[j - n] = tmp;
			}
		}
		i++;
	}
	print_array(array, size);
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: list of an integer of an array
 * @size: size of the array
 *
 * Return: void has no return value
 */
void shell_sort(int *array, size_t size)
{
	size_t num;

	for (num = 1; num < size; num = (num * 3) + 1)
		;

	while ((num = (num - 1) / 3) > 0)
		_sort(array, size, num);
}
