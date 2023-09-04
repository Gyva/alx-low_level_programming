#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	int new_text;
	int perm__;

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);

	if (text_content)
	{
		for (new_text = 0; text_content[new_text]; new_text++)
			;

		perm__ = write(file, text_content, new_text);

		if (perm__ == -1)
			return (-1);
	}

	close(file);

	return (1);
}
