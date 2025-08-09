#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swap integers
 * @a: first int
 * @b: second int
 * Return: swapped integers
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - use partition scheme to sort array
 * @array: the array to sort
 * @size: size of the array
 * @pivot: swapping point
 * Return: index
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	while (j < j)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] < pivot)
			j--;

		if (i >= j)
			return j;

		swap(&array[i],&array[j]);
	}
}

/**
 * quick_sort - sort an array using quick sort
 * @array: pointer to array to sort
 * @size: size of the array
 * Return: sorted array
 */
void quick_sort(int *array, size_t size)
{
	size_t position;
	int pivot;

	if (size < 2)
		return;

		pivot = array[size / 2];
		position = partition(array, size, pivot);
		print_array(array, size);

		quick_sort(array, position + 1);
		quick_sort(array + position + 1, size - position - 1);
}
