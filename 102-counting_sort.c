#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void counting_sort(int *array, size_t size)
{
	int *buffer, *aux, i, j, n;

	if (size < 2)
		return;
	n = i = 0;
	while (i < (int)size)
	{
		if (array[i] > n)
			n = array[i];
		i++;
	}
	buffer = malloc(sizeof(int) * (n + 1));
	if (!buffer)
		return;
	for (j = 0; j <= n; j++)
		buffer[j] = 0;

	for (i = 0; i < (int)size; i++)
		buffer[array[i]] += 1;
	for (i = 1; i <= n; i++)
		buffer[i] += buffer[i - 1];
	print_array(buffer, (n + 1));
	aux = malloc(sizeof(int) * (size + 1));

	if (!aux)
	{
		free(buffer);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		aux[buffer[array[i]] - 1] = array[i];
		buffer[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = aux[i];
	free(buffer);
	free(aux);
}
