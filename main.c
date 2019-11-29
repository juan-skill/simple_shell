#include "shell.h"

/**
 * main - creates a simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	int fd = 0;

	/* check if in interactive shell or non_interactive*/
	fd = isatty(STDIN_FILENO);
	if (fd)
		start_mode_interactive(0);
	else
		 start_mode_noninteractive(1);

	return (EXIT_SUCCESS);
}
