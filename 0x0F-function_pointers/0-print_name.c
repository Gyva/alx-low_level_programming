#include "function_pointers.h"

/**
  * print_name - Prints a name
  * @name: The name to prints
  * @j: Pointer to function
  *
  * Return: Nothing
  */
void print_name(char *name, void (*j)(char *))
{
	if (name != NULL && j != NULL)
		j(name);
}
