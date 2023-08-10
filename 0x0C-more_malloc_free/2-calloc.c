#include "main.h"
#include <stdlib.h>

/**
* _calloc - allocate memory using malloc and initialize it to zero
*@member: number of elements
*@size: size of the memory block to be allocated
*
*Return: poiner to the address of the memory block
*/
void *_calloc(unsigned int member, unsigned int size)
{
	char *block;
	unsigned int i;

	if (member == 0 || size == 0)
		return (NULL);
	block = malloc(member * size);
	if (block != NULL)
	{
		for (i = 0; i < (member * size); i++)
			block[i] = 0;
		return (block);
	}
	else
		return (NULL);
}

