#include "main.h"

/**
 * print_alphabet - print all alphabet in lowercase
 *
 * Return:void
 */

void print_alphabet(void)
{
	char Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
		_putchar(Alph);

	_putchar('\n');
}
