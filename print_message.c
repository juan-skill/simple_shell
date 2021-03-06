#include "shell.h"

/**
 * not_found - writes messages error(e.g"./shell: 1: lfdss: not found")
 *
 * @command: user's typed command
 * @nth_command: nth user's typed command
 * @env: bring in environmental variables linked list
 */
void not_found(char *command, int nth_command, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env);

	write(STDOUT_FILENO, shell, count);

	/* show the colon */
	write(STDOUT_FILENO, ": \n", 2);

	/* convert cmd line num to string to write */
	num = itostr(nth_command);


	count = _strlen(num);
	write(STDOUT_FILENO, num, count);
	free(num);

	write(STDOUT_FILENO, ": ", 2);

	count = _strlen(command);
	write(STDOUT_FILENO, command, count);

	write(STDOUT_FILENO, ": ", 2);

	write(STDOUT_FILENO, "not found\n", 10);
	free(shell);
}

/**
 * print_list - _print linked list env
 *
 * @head: linked list to print
 * Return: length of linked list
 */
size_t print_list(list_t *head)
{
	list_t *tmp = head;
	int count, i;

	count = i = 0;

	if (head == NULL)
		return (0);

	while (tmp != NULL)
	{
		if (tmp->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			i = _strlen((tmp->var));
			write(STDOUT_FILENO, tmp->var, i);
			write(STDOUT_FILENO, "\n", 1);
		}
		tmp = tmp->next;
		count++;
	}
	return (count);
}


/**
 * illegal_number - write error message
 * ("sh: 3: exit: Illegal number abc (or -1)")
 *
 * @arg: argument exit code
 * @nth_command: number of command typed
 * @env: bring in environmental variables linked list
 *
 * Return: void
 */
void illegal_number(char *arg, int nth_command, list_t *env)
{
	int count = 0;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDERR_FILENO, shell, count);
	free(shell);
	write(STDERR_FILENO, ": ", 2);
	num = itostr(nth_command);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDERR_FILENO, num, count);
	free(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (arg[count] != '\0')
		count++;
	write(STDERR_FILENO, arg, count);
	write(STDERR_FILENO, "\n", 1);
}
