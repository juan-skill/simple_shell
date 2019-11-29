#include "shell.h"

/**
 * get_env - finds a copy of the environmental variable
 *
 * @env: list of enviromental variable
 * @str: string to store the variable
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int i_list, len_variable;
	char *var, *tmp_var = NULL;

	i_list = len_variable = 0;
	var = NULL;

	while (env != NULL)
	{
		/* find desired env variable */
		for (i_list = 0; (env->var)[i_list] == str[i_list]; i_list++)
			;
		if (str[i_list] == '\0' && (env->var)[i_list] == '=')
			break;
		env = env->next;
	}

	len_variable = _strlen(str);

	tmp_var = env->var;
	while ((len_variable + 1) > 0)
	{
		tmp_var++;
		len_variable--;
	}
	var = _strdup(tmp_var);

	return (var);
}
