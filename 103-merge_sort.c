#include "sort.h"

/**
 * _printf - display the sorted data
 * @str: message to be displayed
 * @array: buffer of an integer
 * @from: starting point
 * @to: the end point
 */
void _printf(char *str, int *array, int from, int to)
{
	char *separator;
	int i;

	printf("[%s]: ", str);
	separator = "";

	i = from;
	while (i <= to)
	{
		printf("%s%d", separator, array[i]);
		separator = ", ";
		i++;
	}
	printf("\n");
}

/**
 * _join - merges an array of integers in ascending order
 * @array: list of an integers
 * @min: min index of the array
 * @max: max index of the array
 * @mid: mid index of the array
 * @buffer: buffer of the integer
 *
 * Return: void has no return value
 */
void _join(int *array, int min, int max, int mid, int *buffer)
{
	int lo, lm, i;

	lo = i = min;
	lm = mid + 1;

	printf("Merging...\n");
	_printf("left", array, min, mid);
	_printf("right", array, mid + 1, max);

	while (lo <= mid && lm <= max)
	{
		if (array[lo] < array[lm])
			buffer[i++] = array[lo++];
		else
			buffer[i++] = array[lm++];
	}

	while (lo <= mid)
		buffer[i++] = array[lo++];

	while (lm <= max)
		buffer[i++] = array[lm++];

	for (i = min; i <= max; i++)
		array[i] = buffer[i];

	_printf("Done", array, min, max);
}

/**
 * _sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @min: min index of the array
 * @max: max index of the array
 * @mid: mid index of the array
 *
 * Return: void has no return value
 */
void _sort(int *array, int min, int max, int *buffer)
{
	int mid;

	if (min < max)
	{
		mid = (min + max - 1) / 2;
		_sort(array, min, mid, buffer);
		_sort(array, mid + 1, max, buffer);
		_join(array, min, max, mid, buffer);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void merge_sort(int *array, size_t size)
{
	int *ptr;

	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return;
	_sort(array, 0, size - 1, ptr);
	free(ptr);
}
