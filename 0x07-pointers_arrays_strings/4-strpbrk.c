#include "main.h"
/**
 * _strpbrk - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
		int u;

		while (*s)
		{
			for (u = 0; accept[u]; u++)
			{
			if (*s == accept[u])
			return (s);
			}
		s++;
		}

	return ('\0');
}
