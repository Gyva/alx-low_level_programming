#include "main.h"
/**
 *_memcpy - a function that copies memory area
 *@dest: memory where is stored
 *@src: memory where is copied
 *@n: number of bytes
 *
 *Return: copied memory with n bytes changed
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int u;

	for (u = 0; u < n; u++)

	{
		dest[u] = src[u];
	}

	return (dest);

}
