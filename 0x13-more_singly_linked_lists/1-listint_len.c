#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* listint_len - prints all the elements of a linked list.
* @n: a linked list to print
*
* Return: the number of nodes
*/

size_t listint_len(const listint_t *n)
{
        size_t counter = 0;

        while (n != NULL)
        {
                ++counter;
                n = n->next;
        }

return (counter);
}
