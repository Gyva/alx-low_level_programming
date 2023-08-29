#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_nodeint_at_index - insert new node at the nth node of a linked list.
* @head: a linked list to print
* @idx: the position where new node added.
* @n: value to be added.
*
* Return: the nth node, NULL otherwise.
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *new, *tmp;

	if (head == NULL && idx != 0)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	tmp = *head;
	for (j = 0; j < idx - 1; j++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}

	new->next = tmp->next;
	tmp->next = new;

return (new);
}
