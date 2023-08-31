#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: first number
 *
 * @m: second number to convert to
 *
 * Return: number of bits that was needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int k;
	int j;

	k = n ^ m;
	j = 0;

	while (k)
	{
		j++;
		k &= (k - 1);
	}

	return (j);
}
