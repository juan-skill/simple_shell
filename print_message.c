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
 * @h: linked list to print
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
