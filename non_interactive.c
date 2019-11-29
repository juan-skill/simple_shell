#include "shell.h"


/**
 * start_mode_noninteractive - handles when user pipes commands
 * into shell via pipeline
 *
 * (e.g. echo "/bin/ls" | ./a.out)
 * @flag: constant symbolic of file descriptor
 */
void start_mode_noninteractive(int flag)
{
	size_t i = 0, n = 0;
	int len_command = 0, status = 0;
	char *command = NULL, *command_formmatted = NULL, **n_line, **token;
	size_t pf = 1024;

	env = env_linked_list(environ);
	pf = flag;

	i = getline(&command, &pf, stdin);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	command_formmatted = command;
	command = _ignore_delimiter(command, ' ');

	n_line = _str_tok(command, '\n'); /* tokenize each command string */
	if (command_formmatted != NULL)
		free(command_formmatted);

	for  (n = 0; n_line[n] != NULL; n++)
	{
		len_command++;
		token = NULL; /* tokenize each command in array of commands */

		token = _str_tok(n_line[n], ' ');
		status = built_in(token, len_command, n_line);

		if (status)
		{
			n++;
			continue;
		}
		/* if (built_in(token, nth_command, NULL) != 1) */
		status = _execve(token, len_command);
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(status);
}
