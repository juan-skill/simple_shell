#include "shell.h"

/**
 * get_line - stores into malloced buffer the user's command into shell
 *
 * @command: buffer
 * @flag: constant symbolic file descriptor
 * Return: number of characters read
 */
size_t get_line(char **command, int flag)
{
	size_t i = 0, size = 0;
	int new_line = 0, n = 0, t = 0;
	char buff[1024] = {0};
	(void) flag;

	while (new_line == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)) > 0)
	{
		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				new_line = 1;
			n++;
		}

		if (t == 0)
		{
			*command = _strdup(buff);
			size = i + 1, t = 1;
		}
		else
		{
			*command = _strcat(*command, buff);
			size += i;
		}
	}

	if ((int)i == -1)
		return (-1);

	return (size);
}
