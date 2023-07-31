#include "main.h"
/**
 * _strstr - Entry point
 * @haystack: input
 * @needle: input
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *u = haystack;
		char *a = needle;

		while (*u == *a && *a != '\0')
		{
			u++;
			a++;
		}

		if (*a == '\0')
			return (haystack);
	}

	return (0);
}
