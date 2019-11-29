#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints prompt
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * end_of_trasmission - exits program if Ctrl-D was pressed
 *
 * @nbytes_readed: characters read via get_line
 * @command: user's typed in command
 * Return: void
 */
void end_of_trasmission(int nbytes_readed, char *command)
{

	if (nbytes_readed == 0) /* handles Ctrl+D */
	{
		free(command); /* exit with newline if in shell */
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* ctrl+d prints newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * start_mode_interactive - repeatedly prompts user and executes
 * user's cmds if applicable
 *
 * @flag: int to modifier symbolic constant into open file despcriptor
 * Return: 0 on success
 */
int start_mode_interactive(int flag)
{
	size_t len_command = 0;
	int nth_command = 0, status = 0;
	char *command, *command_formatted, **token;

	env = env_linked_list(environ);

	signal(SIGINT, ctrl_c);
	for (;;)
	{
		command = NULL;
		token = NULL;
		len_command = 0; /* reset vars each time loop runs */

		write(STDOUT_FILENO, "$ ", 2);

		len_command = get_line(&command, flag);

		nth_command++;
		end_of_trasmission(len_command, command);

		command_formatted = command;
		command = formatt_input(command_formatted);

		if (command[0] == '\0')
		{
			free(command_formatted);
			continue;
		}

		token = _str_tok(command, ' ');/*token user cmd*/

		if (command_formatted != NULL)
			free(command_formatted);

		if (built_in(token, nth_command, NULL) != 1)
			status = _execve(token, nth_command);
	}

	return (status);
}
