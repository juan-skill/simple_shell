#include "shell.h"

/**
 * _ignore_delimiter - return string without spaces in front (antes de)
 *
 * @command: string to find the delimiter
 * @delimiter: char delimiter to find
 * Return: new string
 */
char *_ignore_delimiter(char *command, char delimiter)
{
	char *tmp_command = NULL;

	tmp_command = command;

	while (*tmp_command == delimiter)
		tmp_command++;

	return (tmp_command);
}

/**
 * replace_newline - return string with \0 character instance of \n
 *
 * @command: command input typed string
 * Return: new string formmatted
 */
char *replace_newline(char *command)
{
	char *tmp_command = NULL;

	tmp_command = command;
	while (*tmp_command != '\n')
		tmp_command++;
	command[(tmp_command - command)] = '\0';

	return (command);
}


/**
 * formatt_input - fixed command typed user
 *
 * @command: command typed user
 * Return: a other string
 */
char *formatt_input(char *command)
{
	char *tmp_command = NULL;

	tmp_command = command;

	tmp_command = _ignore_delimiter(tmp_command, ' ');
	tmp_command = replace_newline(tmp_command);

	return (tmp_command);
}
