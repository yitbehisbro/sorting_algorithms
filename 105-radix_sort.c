#include "sort.h"

/**
 * _max - returns the max of the given integer
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: max value in the array of integer
 */
int _max(int *array, int size)
{
	int i, max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * _count - counts the number of the sorted array
 * @array: list of an integers
 * @n: the length of the array
 * @exp: exp is 10^i
 * @output: array to save the temporary values
 */
void _count(int *array, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = '\0';

	if (array == NULL || size < 2)
		return;

	maximum = _max(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		_count(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
