#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @fn: A pointer to the name of the file.
 * @L: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or fn is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *fn, size_t L)
{
	ssize_t o, r, w;
	char *buffer;

	if (fn == NULL)
		return (0);

	buffer = malloc(sizeof(char) * L);
	if (buffer == NULL)
		return (0);

	o = open(fn, O_RDONLY);
	r = read(o, buffer, L);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
