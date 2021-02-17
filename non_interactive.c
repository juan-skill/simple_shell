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
 * count_arg - count the number of argument of token structure
 *
 * @str: double pointer to array of string
 * Return: the number of elements of array
 */
int count_arg(char **str)
{
	char **tmp = NULL;

	tmp = str;
	while (*tmp)
		tmp++;

	return (tmp - str);
}


/**
 * start_mode_noninteractive - handles when user pipes commands
 * into shell via pipeline
 *
 * (e.g. echo "/bin/ls" | ./a.out)
 * @flag: constant symbolic of file descriptor
 * Return: the status the execute the command
 */
int start_mode_noninteractive(int flag)
{
	int len_command = 0, status = 0, n = 0, count = 0;
	char *command = NULL, *command_formmatted = NULL,
		**n_line = NULL, **token = NULL, *other = NULL;

	env = env_linked_list(environ);
	if (get_line(&command, flag) == 0)
		free(command), exit(0);
	command_formmatted = command, command = c_ignore(command_formmatted);
	if (_strlen(command) == 0)
		free(command_formmatted), free_linked_list(env), exit(0);
	n_line = _str_tok(command, '\n'), count = count_arg(n_line);
	if (command_formmatted != NULL)
		free(command_formmatted), command = NULL, command_formmatted = NULL;
	for  (n = 0; n < count; n++)
	{/* tokenize each command in array of commands */
		len_command++, token = NULL, other = n_line[n];
		n_line[n] = _ignore_delimiter(other, ' ');
		if (_strlen(n_line[n]) == 0)
			free(other);
		token = _str_tok(n_line[n], ' ');
		if (other != NULL)
			free(other), other = NULL, n_line[n] = NULL;
		status = built_in(token, len_command, n_line);
		if (status)
		{	n++;
			continue;
		} /* if (built_in(token, nth_command, NULL) != 1) */
		status = _execve(token, len_command);
		if (status == 2)
		{
			for (; n_line[n + 1]; n++)
				free(n_line[n + 1]);
			break;
		}
	}
	if (env != NULL)
		free_linked_list(env);
	if (n_line != NULL)
		free_double_ptr(n_line);
	return (status);
}
