#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * quick_sort - sort an array using quicksort
 * @array: array to sort
 * @size: size of array
 * Return: sorted array
 */
void quick_sort(int *array, size_t size)
{
	int pivot = array[size - 1];
	int i = -1;
	size_t j = 0;
	int temp;

	while (j < size)
	{
	
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		print_array(array, size);
	}
	temp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = temp;
}
