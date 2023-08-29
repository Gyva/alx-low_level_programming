#include <string.h>
#include "lists.h"

/**
* free_listint - frees a singly linked list.
* @head: a linked list to print
*
* Return: void.
*/

void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
