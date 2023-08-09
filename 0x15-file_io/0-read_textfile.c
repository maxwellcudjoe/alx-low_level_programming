#include "main.h"

/**
 * read_textfile - this will read a text file and print the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: this will print letters. when It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdr;
	ssize_t nrdr, nwwrr;
	char *buf;

	if (!filename)
		return (0);

	fdr = open(filename, O_RDONLY);

	if (fdr == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrdr = read(fdr, buf, letters);
	nwwrr = write(STDOUT_FILENO, buf, nrdr);

	close(fdr);

	free(buf);

	return (nwwrr);
}
