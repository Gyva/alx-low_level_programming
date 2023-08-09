#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of key in a string
 * @i: string to evaluate
 *
 * Return: number of key
 */
int count_word(char *i)
{
	int tab, a, j;

	tab = 0;
	j = 0;

	for (a = 0; i[a] != '\0'; a++)
	{
		if (i[a] == ' ')
			tab = 0;
		else if (tab == 0)
		{
			tab = 1;
			j++;
		}
	}

	return (j);
}
/**
 * **strtow - splits a string into key
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int b, p = 0, len = 0, key, c = 0, start, end;

	while (*(str + len))
		len++;
	key = count_word(str);
	if (key == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (key + 1));
	if (matrix == NULL)
		return (NULL);

	for (b = 0; b <= len; b++)
	{
		if (str[b] == ' ' || str[b] == '\0')
		{
			if (c)
			{
				end = b;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[p] = tmp - c;
				p++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = b;
	}

	matrix[p] = NULL;

	return (matrix);
}
