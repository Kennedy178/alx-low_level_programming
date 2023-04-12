#include "main.h"

/**
 * create_file - Createing a file.
 * @filename: A pointer to the created file.
 * @text_content: A Pointer to a string to write into the file.
 *
 * Return: On success return - 1 otherwise - -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int nek, neke, nekee = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (nekee = 0; text_content[nekee];)
			nekee++;
	}

	nek = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	neke = write(nek, text_content, nekee);

	if (nek == -1 || neke == -1)
	{
		return (-1);
	}

	close(nek);

	return (1);
}
