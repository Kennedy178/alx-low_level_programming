#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile- Read and display file.
 * @filename: file read
 * letters: number of letters to be read
 *
 * Return: 0 if fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters);
{

char *fer;
ssize_t ken, kene, kenne;
ken = open(filename, O_RDONLY);
if (ken == -1)
return (0);
fer = malloc(sizeof(char) * letters);
kenne = read(ken, fer, letters);
kene = write(STDOUT_FILEN0, fer, kenne);
free(fer);
close(ken);
return (kene);
}
