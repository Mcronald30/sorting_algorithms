#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail shaker sort
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do

	{
		swapped = 0;
		for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(ptr, &(ptr->next), list);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (ptr = ptr->prev; ptr->prev != NULL; ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
		{
			swap_nodes(ptr->prev, &(ptr), list);
			print_list(*list);
			swapped = 1;
		}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Double pointer to the right node
 * @list: Double pointer to the head of the linked list
 */
void swap_nodes(listint_t *left, listint_t **right, listint_t **list)
{
	listint_t *temp;

	if (left->prev != NULL)
		left->prev->next = *right;
	else

		*list = *right;

	(*right)->prev = left->prev;
	left->prev = *right;
	left->next = (*right)->next;

	if ((*right)->next != NULL)
		(*right)->next->prev = left;

	(*right)->next = left;
	*right = left->next;

	if (*right != NULL)
		(*right)->prev = left;
}
