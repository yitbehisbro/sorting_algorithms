#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: list of integer
 * @size: size of the array
 *
 * Return: void has no return value
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, num;
	int tmp, swap;

	for (num = size, swap = 1; num > 0 && swap; num--)
	{
		swap = 0;
		for (i = 0; (i + 1) < num; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
