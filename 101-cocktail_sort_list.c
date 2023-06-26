#include "sort.h"

/**
 * swapme - Swaps two adjacent nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Double pointer to the right node
 * @list: Double pointer to the head of the linked list
 */
void swapme(listint_t *left, listint_t *right, listint_t **list)
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

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail shaker sort
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
        listint_t *check = *list, *first = NULL, *second = NULL;

        if (!list)
                return;
        if (!(*list))
                return;
        if (!(*list)->next)
                return;
        do {
                while (check->next)
                {
                        if (check->n > check->next->n)
                                swapme(check->next, check, list);
                        else
                                check = check->next;
                }
               second = check;
                while (check->prev != first)
                {
                        if (check->n < check->prev->n)
                                swapme(check, check->prev, list);
                        else
                                check = check->prev;
                }
                first = check;
        } while (first != second);
}
