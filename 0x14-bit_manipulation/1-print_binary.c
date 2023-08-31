#include "main.h"

/**
 * print_binary - function,prints binary_rep of a No.
 *
 *@n: printable number.
 *
 */

void print_binary(unsigned long int n)
{
	const unsigned long int num = n;

	if (num > 1)
		print_binary(num >> 1);

	_putchar((num & 1) + '0');
}
