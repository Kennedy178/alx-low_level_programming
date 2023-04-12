#include "main.h"

/**
 * append_text_to_file - embed text to a file.
 *
 * @filename:   file to embed to.
 * @text_content: file to be embedded with text
 *
 * Return:      1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ken, kenn, kenny = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (kenny = 0; text_content[kenny];)
			kenny++;
	}

	ken = open(filename, O_WRONLY | O_APPEND);

	kenn = write(ken, text_content, kenny);

	if (ken == -1 || kenn == -1)
	{
		return (-1);
	}

	close(ken);

	return (1);
}
