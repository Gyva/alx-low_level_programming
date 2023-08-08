#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **j;
	int h, w;

	if (width <= 0 || height <= 0)
		return (NULL);

	j = malloc(sizeof(int *) * height);

	if (j == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		j[h] = malloc(sizeof(int) * width);

		if (j[h] == NULL)
		{
			for (; h >= 0; h--)
				free(j[h]);

			free(j);
			return (NULL);
		}
	}

	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
			j[h][w] = 0;
	}

	return (j);
}
