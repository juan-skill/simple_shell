#include "shell.h"

/**
 * __exit - s user input and then exits
 *
 * @full_command: typed command (e.g. "exit 99")
 * @nth_command: bring in nth user command line input
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */
int __exit(char **full_command, int nth_command, char **command)
{
	int i, num_exit = 0;
	char *first_command = NULL;

	(void)nth_command;

	first_command = full_command[1];

	if (full_command[1] != NULL) /* if no value given after exit, return 0 */
	{		/* num_exit = c_atoi(full_command[1]); */
		i = 0;
		while (first_command[i] != '\0')
		{
			if (first_command[i] >= '0' && first_command[i] <= '9') /* calculate num */
				num_exit = num_exit * 10 + (first_command[i] - '0');
			if (first_command[i] > '9' || first_command[i] < '0')
			{
				num_exit = -1;
				break;
			}
			i++;
		}

	}

	if (num_exit == -1) /* if value given after exit is invalid, perror */
	{
		/* print error msg */
		illegal_number(full_command[1], nth_command, env);
		free_double_ptr(full_command);
		return (2);
	}
	free_double_ptr(full_command); /* free user input before exiting program */
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);

	exit(num_exit);
}
