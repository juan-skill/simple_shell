#include "shell.h"

/**
 * main - creates a simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	int fd = 0;
	int status = 0;

	/* check if in interactive shell or non_interactive */
	fd = isatty(STDIN_FILENO);
	if (fd)
		status = start_mode_interactive(0);
	else
		status = start_mode_noninteractive(1);

	if (status != EXIT_SUCCESS)
		return (status);

	return (EXIT_SUCCESS);
}
