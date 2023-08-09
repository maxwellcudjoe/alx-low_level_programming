#include "main.h"

/**
 * create_file - creating a file
 * @filename: filename.
 * @text_content: content written in this file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fdrr;
	int nnletter;
	int rwwrr;

	if (!filename)
		return (-1);

	fdrr = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fdrr == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nnletter = 0; text_content[nnletter]; nnletter++)
		;

	rwwrr = write(fdrr, text_content, nnletter);

	if (rwwrr == -1)
		return (-1);

	close(fdrr);

	return (1);
}
