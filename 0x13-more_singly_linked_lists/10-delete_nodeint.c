#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* delete_nodeint_at_index - remove the nth node of a linked list.
* @head: a linked list to print
* @index: index of the node that should be deleted. Index starts at 0.
*
* Return: the nth node, NULL otherwise.
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int k;
	listint_t *current, *next_node;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
		return (1);
	}

	current = *head;
	for (k = 0; k < index - 1; k++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}

	next_node = current->next;
	current->next = next_node->next;
	free(next_node);

return (1);
}
