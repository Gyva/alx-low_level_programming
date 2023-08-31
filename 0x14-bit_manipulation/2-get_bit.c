#include "main.h"

/**
 * get_bit - func:finds value of bit at an index.
 * @n:bit: the bit itself.
 * @index: index, all indices start at zero(0).
 *
 * Return: for if an error occurs elsewhre bit at index. 
 *
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num = n;
	unsigned int indx = index;

	if (indx >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((num & (1 << indx)) == 0)
		return (0);
	return (1);
}
