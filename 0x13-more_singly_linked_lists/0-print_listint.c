#include <stdio.h>
#include "lists.h"

/**
* print_listint - prints all the elements of a linked list.
* @j: a linked list to print
*
* Return: the number of nodes
*/

size_t print_listint(const listint_t *j)
{
	size_t counter = 0;

	while (j)
	{
		printf("%d\n", j->n);
		++counter;
		j = j->next;
	}

return (counter);
}
