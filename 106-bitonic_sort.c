#include "sort.h"

/**
 * _swap - swaps ascending or descending order
 * @array: list of the integer
 * @int1: integer 1
 * @int2: integer 2
 * @order: 1: ascending order, 0 descending order
 */
void _swap(int *array, int int1, int int2, int order)
{
	int temp;

	if (order == (array[int1] > array[int2]))
	{
		temp = array[int1];
		array[int1] = array[int2];
		array[int2] = temp;
	}
}

/**
 * merge - mergs in ascending and decending
 * @array: list of the integer
 * @min: min element in the list
 * @n: number of elements
 * @order: 1: ascending order, 0 descending order
 */
void merge(int *array, int min, int n, int order)
{
	int mid, i;

	if (n > 1)
	{
		mid = n / 2;
		for (i = min; i < min + mid; i++)
			_swap(array, i, i + mid, order);
		merge(array, min, mid, order);
		merge(array, min + mid, mid, order);
	}
}

/**
 * _sort - sorts an array of integers in ascending order
 * @arr: list of the integer
 * @low: min element in the list
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void _sort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		_sort(arr, low, mid, 1, size);
		_sort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	_sort(array, 0, size, order, size);
}
