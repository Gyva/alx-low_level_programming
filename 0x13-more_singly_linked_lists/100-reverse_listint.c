#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the linked list
 *
 * Return: pointer to the 1st node in the new list, fail otherwise
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current_head = NULL;
	listint_t *revt_head = NULL;

	while (*head)
	{
		current_head = (*head)->next;
		(*head)->next = revt_head;
		revt_head = *head;
		*head = current_head;
	}

	*head = revt_head;

	return (*head);
}
