#include "shell.h"


/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;

	return (str);
}


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
	char *command = NULL, *command_formmatted = NULL,
		**n_line = NULL, **token = NULL, *other = NULL;

	env = env_linked_list(environ);
	i = get_line(&command, flag);
	if (i == 0)
		free(command), exit(0);
	command_formmatted = command;
	command = c_ignore(command_formmatted);
	if (_strlen(command) == 0)
		free(command_formmatted), free_linked_list(env), exit(0);
	n_line = _str_tok(command, '\n'); /* tokenize each command string */
	if (command_formmatted != NULL)
		free(command_formmatted), command = NULL, command_formmatted = NULL;

	for  (n = 0; n_line[n] != NULL; n++)
	{
		len_command++, token = NULL; /* tokenize each command in array of commands */
		other = n_line[n];
		n_line[n] = _ignore_delimiter(other, ' ');
		if (_strlen(n_line[n]) == 0)
			free(other);
		token = _str_tok(n_line[n], ' ');
		if (other != NULL)
			free(other), other = NULL, n_line[n] = NULL;
		status = built_in(token, len_command, n_line);
		if (status)
		{
			n++;
			continue;
		} /* if (built_in(token, nth_command, NULL) != 1) */
		status = _execve(token, len_command);
	}
	if (env != NULL)
		free_linked_list(env);
	if (n_line != NULL)
		free_double_ptr(n_line);
	exit(status);
}
