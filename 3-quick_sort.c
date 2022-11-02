#include "sort.h"

/**
 * _sort - sorts an array of integers in ascending order
 * @min: first element in the array
 * @max: last element in the array
 * @array: list of an integer of an array
 * @size: size of the array
 *
 * Return: void has no return value
 */
void _sort(int min, int max, int *array, int size)
{
	int p, w, i, tmp;

	if (min < max)
	{
		p = max;
		w = min;
		i = min;

		while (i < max)
		{
			if (array[i] < array[p])
			{
				if (i != w)
				{
					tmp = array[i];
					array[i] = array[w];
					array[w] = tmp;
					print_array(array, size);
				}
				w++;
			}
			i++;
		}
		if (w != p && array[w] != array[p])
		{
			tmp = array[w];
			array[w] = array[p];
			array[p] = tmp;
			print_array(array, size);
		}
		_sort(min, w - 1, array, size);
		_sort(w + 1, max, array, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: list of an integer of an array
 * @size: size of the array
 *
 * Return: void has no return value
 */
void quick_sort(int *array, size_t size)
{
	_sort(0, size - 1, array, size);
}
