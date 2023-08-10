#include "main.h"
#include <stddef.h>

/**
 * _realloc - Reallocate a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the newly reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    char *old_ptr = ptr;
    char *new_ptr_casted;

    if (new_size == old_size)
        return ptr;

    if (ptr == NULL)
        return malloc(new_size);

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;

    new_ptr_casted = new_ptr;
    for (unsigned int i = 0; i < old_size && i < new_size; i++)
        new_ptr_casted[i] = old_ptr[i];

    free(ptr);
    return new_ptr;
}
