#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list -  sorts a doubly linked list of
 * integers in ascending order
 * @list: contain a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *insert;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		insert = current->prev;

		while (insert != NULL && current->n < insert->n)
		{
			if (insert->prev != NULL)
				insert->prev->next = current;
			current->prev = insert->prev;

			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;

			current->next = insert;
			insert->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			insert = current->prev;
		}
		current = next;
	}
}
