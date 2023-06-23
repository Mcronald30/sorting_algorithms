#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail shaker sort
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *first = NULL, *last = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		while (ptr->next)
		{
			if (ptr->n > ptr->next->n)
				swapnodes(ptr->next, ptr, list);
			else
				ptr = ptr->next;
		}
		last = ptr;
		while (ptr->prev != first)
		{
			if (ptr->n < ptr->prev->n)
				swapnodes(ptr, ptr->prev, list);
			else
				ptr = ptr->prev;
		}
		first = ptr;
	} while (first != last);
}

/**
 * swapnodes - Swaps two adjacent nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Double pointer to the right node
 * @list: Double pointer to the head of the linked list
 */
void swapnodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *temp1 = left->next;
	listint_t *temp2 = right->prev;

	if (temp1 != NULL)
		temp1->prev = right;
	if (temp2 != NULL)
		temp2->next = left;
	left->prev = temp2;
	right->next = temp1;
	left->next = right;
	right->prev = left;
	if (*list == right)
		*list = left;
	print_list(*list);
}

