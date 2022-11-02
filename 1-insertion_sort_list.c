#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: list of the doubly linked list
 *
 * Return: void has no return value
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp;

	if (!list)
		return;

	head = *list;

	while (head)
	{
		while (head->next && (head->n > head->next->n))
		{
			tmp = head->next;
			head->next = tmp->next;
			tmp->prev = head->prev;

			if (head->prev)
				head->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = head;

			head->prev = tmp;
			tmp->next = head;

			if (tmp->prev)
				head = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		head = head->next;
	}
}
