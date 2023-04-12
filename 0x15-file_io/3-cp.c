#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - free 1024 bytes for a buffer.
 * @file: chars being stored on the buffer
 *
 * Return: slotted buffer pointer destination.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error!! Write Error destination %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes file.
 *
 * @file: closes file destination.
 */
void close_file(int ken)
{
	int kenny;

	kenny = close(ken);

	if (kenny == -1)
	{
		dprintf(STDERR_FILENO, "Error!! close file_dir error!! %d\n", ken);
		exit(100);
	}
}

/**
 * main - Copy components of file_md destination to another file_md.
 * @argc: tally of arguments passed.
 * @argv: pointers array destination arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int neke;
	int lesh;
	int learn;
	int run;

	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Copy!! \n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	neke = open(argv[1], O_RDONLY);
	learn = read(neke, buffer, 1024);
	lesh = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (neke == -1 || learn == -1)
		{
			dprintf(STDERR_FILENO, "Can't read file!! Error! EXIT!! %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		run = write(lesh, buffer, learn);
		if (lesh == -1 || run == -1)
		{
			dprintf(STDERR_FILENO, "Can't write file!! Error! EXIT!! %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		learn = read(neke, buffer, 1024);
		lesh = open(argv[2], O_WRONLY | O_APPEND);
	} while (learn > 0);
	free(buffer);
	close_file(neke);
	close_file(lesh);

	return (0);
}
