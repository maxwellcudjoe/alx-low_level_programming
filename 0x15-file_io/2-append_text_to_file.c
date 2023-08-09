#include "main.h"

/**
 * append_text_to_file - This will append text at the end of a file 
 * @filename: filename.
 * @text_content: the content added.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fddrr;
	int nnletter;
	int rwwrr;

	if (!filename)
		return (-1);

	fddrr = open(filename, O_WRONLY | O_APPEND);

	if (fddrr == -1)
		return (-1);

	if (text_content)
	{
		for (nnletter = 0; text_content[nnletter]; nnletter++)
			;

		rwwrr = write(fddrr, text_content, nnletter);

		if (rwwrr == -1)
			return (-1);
	}

	close(fddrr);

	return (1);
}
