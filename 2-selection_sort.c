#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * selection_sort - sort an array of integers using selection sort
 * @array: pointer to the array
 * @size: size of the array
 * Return: sorted array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min;
	int temp;

	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			j++;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
