#include "function_pointers.h"

/**
  * int_index - Executes a given function
  * @array: ...
  * @size: The size of the array
  * @action: Pointer to the used function
  *
  * Return: i
  */
int int_index(int *array, int size, int (*action)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && action != NULL)
		{
			while (i < size)
			{
				if (action(array[i]))
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
