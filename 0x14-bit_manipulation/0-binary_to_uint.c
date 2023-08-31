#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * binary_to_uint - func;converts binary No. to an unsigned int.
 * @b:pointer: shows to a string of 0 and 1 chars(characters).
 *
 * Return: If b = NULL/has chars not 0/ one - zero.
 *         Else show converted No.
 *
 */

unsigned int binary_to_uint(const char *b)
{
	const char *binary_num = b;
	int x;
	unsigned int resp = 0;

	if (!binary_num)
		return (0);

	for (x = 0; binary_num[x]; x++)
	{
		if (binary_num[x] < '0' || binary_num[x] > '1')
			return (0);
		resp = 2 * resp + (binary_num[x] - '0');
	}

	return (resp);
}
