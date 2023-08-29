#include "lists.h"

/**
* free_listint2 - frees a singly linked list.
* @head: a linked list to print
*
* Return: void.
*/

void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		(*head) = tmp;
	}
}
