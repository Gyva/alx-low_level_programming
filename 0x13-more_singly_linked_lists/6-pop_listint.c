#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* pop_listint - adds a new node at the beginning of a singly linked list.
* @head: a linked list to print
*
* Return: the address of the new element, or NULL if it failed.
*/

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int value = 0;

	if (*head == NULL)
		return (0);

	tmp = *head;
	*head = tmp->next;
	value = tmp->n;
	free(tmp);

	return (value);
}
