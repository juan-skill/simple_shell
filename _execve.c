#include "shell.h"

/**
 * _execve - execute command user
 *
 * @token: command user typed
 * @nth_command: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execve(char **token, int nth_command)
{
	char *executable_path, *first_word;
	int status = 0, t = 0, ret;
	pid_t pid;

	first_word = token[0];
	/* check if command is absolute path */
	if (access(first_word, F_OK) == 0)
	{
		executable_path = first_word;
		t = 1; /*typed the full command  (e.g '/bin/ls' )*/
	} else	/* else find the full path, I have fullpath of the executable */
		executable_path = _which(first_word);

	if (access(executable_path, X_OK) == 0)
	{
		pid = fork(); /* fork and execute executable command */
		if (pid == 0) /* if child process, execute */
		{
			ret = execve(executable_path, token, environ);
			if (ret == -1)
			{
				not_found(first_word, nth_command, env);
				free_double_ptr(token);
				free_linked_list(env);
				_exit(0);
			}
		} else /* if parent, wait for child then free all */
		{
			wait(&status);
			free_double_ptr(token);
			if (t == 0)
				free(executable_path);
		}
	} else/* if it is not an executable, free */
	{
		not_found(first_word, nth_command, env);
		free_double_ptr(token);
		return (127);/*127 return the system doesn't understand comman*/
	}
	return (0);
}
