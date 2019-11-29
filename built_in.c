#include "shell.h"

/**
 * built_in - handles builtins (exit, env)
 *
 * @token: user's typed command
 * @nth_command: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, int nth_command, char **command)
{
	char *tmp_command;
	int stat = 0;

	tmp_command = token[0];

	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(tmp_command, "exit") == 0)
	{
		stat = __exit(token, nth_command, command);
		return (stat);
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(tmp_command, "env") == 0)
	{
		_env(token);
		return (1);
	}

	return (0);
}
