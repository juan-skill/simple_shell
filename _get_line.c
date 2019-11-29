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
	int fd, i, indicator = 0;
	ssize_t nread_bytes = 0;
	char line[MAXLINE];

	indicator = flag;

	fd = open("/dev/tty", O_RDWR);
	if (fd < 0)
	{
		perror("r1");
		exit(1);
	}

	nread_bytes = read(fd, line, MAXLINE - 1);

	line[nread_bytes] = '\0';

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			indicator = 1;
		}
		i++;
	}

	if (indicator == 1)
	{
		*command = _strdup(line);
	}
	else
	{
		nread_bytes = 0;
	}

	return (nread_bytes);
}
