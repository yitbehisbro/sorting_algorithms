#include "sort.h"

/**
 * swap_list - swaps the elements of the list
 * @head1: first pointer to the list
 * @head2: second pointer to the list
 * @n: n is 0 for increase, n is 1 for decrease
 *
 * Return: no return
 */
void swap_list(listint_t **head1, listint_t **head2, int n)
{
	listint_t *h, *tmp;

	h = *head1;
	tmp = *head2;

	h->next = tmp->next;
	tmp->prev = h->prev;

	if (tmp->next)
		tmp->next->prev = h;

	if (h->prev)
		h->prev->next = tmp;

	h->prev = tmp;
	tmp->next = h;

	if (n == 0)
		*head1 = tmp;
	else
		*head2 = h;
}

/**
 * increase_sort - move the bigger numbers to the end
 * @head: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of the doubly linked list
 *
 * Return: no return
 */
void increase_sort(listint_t **head, listint_t **limit, listint_t **list)
{
	listint_t *h;

	for (h = *head; h != *limit && h->next != *limit; h = h->next)
	{
		if (h->n > h->next->n)
		{
			swap_list(&h, &(h->next), 0);
			if (h->prev == NULL)
				*list = h;
			print_list(*list);
		}
	}
	*limit = h;
	*head = h;
}

/**
 * decrease_sort - moves the smaller numbers to the start
 * @head: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of the doubly linked list
 *
 * Return: no return
 */
void decrease_sort(listint_t **head, listint_t **limit, listint_t **list)
{
	listint_t *h;

	for (h = *head; h != *limit && h->prev != *limit; h = h->prev)
	{
		if (h->n < h->prev->n)
		{
			swap_list(&(h->prev), &h, 1);
			if (h->prev->prev == NULL)
				*list = h->prev;
			print_list(*list);
		}
	}
	*limit = h;
	*head = h;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * @list: list of the doubly linked list
 *
 * Return: void has no return value
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *head;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	head = *list;

	do {
		increase_sort(&head, &limit1, list);
		decrease_sort(&head, &limit2, list);
	} while (limit1 != limit2);
}
