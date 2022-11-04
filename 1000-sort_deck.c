#include "deck.h"

/**
 * _strcmp - compare two strings
 * @str1: pointer to character var 1
 * @str2: pointer to character var 2
 *
 * Return: 1 str1 and str2 is equal, 0 they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == NULL)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}
/**
 * _position - returns the position of the card
 * @node: represent the card
 *
 * Return: return the card position
 */
int _position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 *_swap - swap a card for his previous one
 * @card: card to swap
 * @deck: card deck
 *
 * Return: a pointer to a card which was enter it
 */
deck_node_t *_swap(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * _sort - sorts a deck of cards
 * @deck: the doubly linked list
 *
 * Return: void has no return value
 */
void _sort(deck_node_t **deck)
{
	int value_prev, value_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing the previous value */
		if (node->prev)
		{
			value_prev = _position((node->prev));
			value_current = _position(node);
		}
		while ((node->prev) && (value_prev > value_current))
		{
			value_prev = _position((node->prev));
			value_current = _position(node);
			node = _swap(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - sorts a deck of cards
 * @deck: the doubly linked list
 *
 * Return: void has no return value
 */
void sort_deck(deck_node_t **deck)
{
	_sort(deck);
}
