#include "shell.h"

/**
 * add_end_node - adds a new node in the end of a list
 *
 * @head: pointer to the list.
 * @str: string to add to the new node.
 * Return: the address of a new node.
 */
list_t *add_end_node(list_t **head, char *str)
{
	list_t *new_node;
	list_t *tmp;

	new_node = tmp = NULL;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->var = _strdup(str);
	new_node->next = NULL;

	tmp = *head;
	/*if (!*head)*/
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*head = new_node;

	return (*head);
}


/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_linked_list(list_t *list)
{
	list_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}
}


/**
 * free_double_ptr - free malloced arrays
 * @str: array of strings
 */
void free_double_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
