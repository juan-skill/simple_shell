#include "shell.h"

/**
 * env_linked_list - creates a linked list
 * from environmental variables
 * @env: environmental variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head = NULL;

	if (*env == NULL)
		return (NULL);


	head = NULL;
	while (*env != NULL)
		add_end_node(&head, *env++);

	return (head);
}

/**
 * _env - prints environmental variables
 *
 * @str: user's command into shell (i.e. "env")
 * Return: 0 on success
 */
int _env(char **str)
{
	free_double_ptr(str); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}

