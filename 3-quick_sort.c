#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 * Return: success
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * all_equal - check if all values in subarray are identical
 * @array: array to check
 * @low: starting index
 * @high: ending index
 * Return: 1 if equal, 0 otherwise
 */
int all_equal(int *array, size_t low, size_t high)
{
	int first = array[low];
	size_t i = low + 1;

	while (i <= high)
	{
		if (array[i] != first)
			return (0);
		i++;
	}
	return (1);
}

/**
 * lomuto_partition - swap values using lomuto partition
 * @array: the array to partition
 * @low: starting index
 * @high: ending index
 * @size: full array size
 * Return: final pivot position
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j = low;

	while (j < high)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
		j++;
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursion - recursive quicksort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: full array size
 * Return: sorted array
 */
void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		if (all_equal(array, low, high))
			return;

		pi = lomuto_partition(array, low, high, size);

		if (pi > 0)
			quick_sort_recursion(array, low, pi - 1, size);
		quick_sort_recursion(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sort an array using quicksort
 * @array: array to sort
 * @size: size of array
 * Return: sorted array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
