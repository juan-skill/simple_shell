#include "shell.h"

/**
 * _which - find the command by appending it to PATH directory
 *
 * @str: first command(word) user typed
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str)
{
	char *path, *tmp_string, **token_path, *variable;
	int i = 0;

	path = tmp_string = NULL;
	variable = "PATH";

	/* get and tokenize PATH directories, then free original string */
	path = get_env(variable, env);

	/* get token entire PATH */
	token_path = _str_tok(path, ':');

	/*free path variable*/
	free(path);

	/* append "/cmd" to each token to see it's legit */
	for (i = 0; token_path[i] != NULL; i++)
	{
		tmp_string = _strdup(token_path[i]);
		tmp_string = _strcat(tmp_string, "/");
		tmp_string = _strcat(tmp_string, str);

		if (access(tmp_string, F_OK) == 0)
		{
			/* free tokens before returning legit fleshed path */
			free_double_ptr(token_path);
			return (tmp_string);
		}
		free(tmp_string); /* free concatenated string if cmd is never found */
	}
	free_double_ptr(token_path);

	return (str); /* return string if not found; won't pass execve */
}
