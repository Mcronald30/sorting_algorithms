#include "sort.h"

/**
 * insertion_sort_list -  represents the head of the doubly linked list.
 * @list: Doubly linked list sorted
 */
void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current;

	current = (*list)->next;
	
	while (current != NULL)
	{
		listint_t *temp = current->prev;
		
		while (temp != NULL && temp->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = temp;
			
			temp->next = current->next;
			current->prev = temp->prev;
			
			if (temp->prev != NULL)
				temp->prev->next = current;
			
			current->next = temp;
			temp->prev = current;
			
			print_list(*list);
			
			temp = current->prev;
		}
		current = current->next;
	}
}
