#include "main.h"

/**
 * main - Copies the content of a file to another file
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 if successful, otherwise a number between 97 and
 * 100 (each number represents an error)
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (file_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
	{
		close_file(file_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	copy_contents(file_from, file_to, argv[1], argv[2]);
	close_file(file_from), close_file(file_to);
	return (0);
}

/**
 * close_file - closes a file handle and exits program on failure
 * @file: The file handle
 */
void  close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d", file);
		exit(100);
	}
}

/**
 * copy_contents - Copies the contents from one file to another
 * @file_from: The source file handle
 * @file_to: The destination file handle
 * @file1: The source file name
 * @file2: The destination file name
 */
void copy_contents(int file_from, int file_to, char *file1, char *file2)
{
	int i, c, buffer_size = 1024;
	void *buffer = malloc(sizeof(char) * buffer_size);

	if (buffer != NULL)
	{
		for (i = 0; ; i += buffer_size)
		{
			c = read(file_from, buffer, buffer_size);
			if (c == 0)
				break;
			if (c < 0)
			{
				dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file1);
				exit(98);
			}
			if (write(file_to, buffer, c) != c)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file2);
				free(buffer);
				exit(99);
			}
		}
		free(buffer);
	}
}
