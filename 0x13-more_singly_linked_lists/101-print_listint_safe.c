#include "lists.h"
#include <stdio.h>
#include "lists.h"

/**
 * check_looped_listint - check if there is loop in a linked list and
 *            counts the number of unique nodes in a looped linked list
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: 0 - if the list is not looped,
 *         Otherwise - the number of unique nodes in the list.
 */

size_t check_looped_listint(const listint_t *head)
{
	const listint_t *umwere, *chriss;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	umwere = head->next;
	chriss = (head->next)->next;

	while (chriss) /* check if there is loop in the list */
	{
		if (umwere == chriss)
			break;
		umwere = umwere->next;
		chriss = (chriss->next)->next;
	}

	if (umwere == chriss) /* count unique node in a looped list */
	{
		umwere = head;
		while (umwere != chriss)
		{
			nodes++;
			umwere = umwere->next;
			chriss = chriss->next;
		}
		umwere = umwere->next;
		while (umwere != chriss)
		{
			nodes++;
			umwere = umwere->next;
		}
		return (nodes);
	}

return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = check_looped_listint(head);

	if (nodes == 0)
	{
		while (head != NULL)
		{
			nodes++;
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
