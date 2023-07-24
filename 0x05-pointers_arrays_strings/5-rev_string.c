#include "main.h"

/**
 * rev_string - Reverses a string
 * @n: Input string
 * Return: string in reverse
 */

void rev_string(char *n)
{
	char rev = n[0];
	int counter = 0;
	int i;

	while (n[counter] != '\0')
	counter++;
	for (i = 0; i < counter; i++)
	{
		counter--;
		rev = n[i];
		n[i] = n[counter];
		n[counter] = rev;
	}
}
