#include <string.h>
#include "lists.h"

/**
* add_nodeint - adds a new node at the beginning of a singly linked list.
* @head: a linked list to print
* @j: value to be added to the node
*
* Return: the address of the new element, or NULL if it failed.
*/

listint_t *add_nodeint(listint_t **head, const int j)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->j = j;
	new_node->next = (*head);
	(*head) = new_node;

	return (*head);
}
