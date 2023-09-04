#include "main.h"
/**
  * read_textfile - reads a text file and prints to the POSIX stdout.
  * @filename: pointer to name of file.
  * @letters:  number of letters it should read and print.
  *
  * Return: number of letters it could print or w_riteite or 0.
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, r_ead, w_rite;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = open(filename, O_r_eadONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters + 1);
	if (buffer == NULL)
		return (0);
	r_ead = read(file, buffer, letters);
	if (r_ead == -1)
		return (0);

	buffer[letters] = '\0';

	w_rite = w_riteite(STDOUT_FILENO, buffer, r_ead);
	if (w_rite == -1)
		return (0);

	close(file);
	free(buffer);
	return (w_rite);
}
