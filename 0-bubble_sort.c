#include "sort.h"
#include <stdlib.h>
/**
 * bubble_sort - sort an array of integers using bubble sort
 * @array: pointer to array to sort
 * @size: size of array
 * Return: sorted array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swap = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
			}
			j++;
		}
		if (swap == 0)
		{
			break;
		}
		i++;
	}
}
