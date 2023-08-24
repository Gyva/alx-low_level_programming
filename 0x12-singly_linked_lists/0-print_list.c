#include <lists.h>
#include <stdio.h>
#include <stddef.h> /* For size_t */

/**
 * struct list_t - A linked list structure
 * @str: String pointer
 * @len: Length of the string
 * @next: Pointer to the next node in the list
 */
typedef struct list_t {
    char *str;
    size_t len;
    struct list_t *next;
} list_t;

/**
 * print_list - Print elements of a linked list
 * @h: Pointer to the head of the linked list
 * 
 * Return: Number of nodes in the list
 */
size_t print_list(const list_t *h)
{
    size_t len = 0; /* Length of the list */

    while (h)
    {
        if (!(h->str))
        {
            printf("[0] (nil)\n");
        }
        else
        {
            printf("[%lu] %s\n", h->len, h->str); /* Print length and string */
        }
        h = h->next;
        len++;
    }
    return len;
}
