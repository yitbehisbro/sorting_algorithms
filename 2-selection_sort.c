#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: list of an integer of an array
 * @size: size of the array
 *
 * Return: void has no return value 
 */
void selection_sort(int *array, size_t size);
{
	size_t i = 0, j, m;
	int tmp;

	while (i < size)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[m] > array[j])
				m = j;
		}
		if (i != m)
		{
			tmp = array[i];
			array[i] = array[m];
			array[m] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
