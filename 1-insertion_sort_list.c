#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insertion_sort_list - insertion sort a doubly linked list
 * @list: double pointer to head of list
 * Return: Sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted;
	listint_t *current;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		sorted = current->prev;

		while (sorted != NULL && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;

		current->prev = sorted->prev;
		current->next = sorted;
		sorted->prev = current;

		if (current->prev != NULL)
			current->prev->next = current;

		else
			*list = current;

		sorted = current->prev;
		print_list(*list);
		}
		current = next;
	}
}
