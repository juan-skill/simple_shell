#include "shell.h"

/**
 * count_options - returns number of delim into command
 *
 * @command: command typed
 * @delimiter: char to count into command
 * Return: number of delims so that (num token = delims + 1)
 */
int count_options(char *command, char delimiter)
{
	int num_delimiter;
	char *tmp_str;

	tmp_str = command;
	num_delimiter = 0;

	for (; *tmp_str != '\0'; tmp_str++)
	{
		if ((*tmp_str == delimiter) && (*(tmp_str + 1) != delimiter))
			num_delimiter++;

		if ((*tmp_str == delimiter) && (*(tmp_str + 1) == '\0'))
			num_delimiter--;
	}

	return (num_delimiter);
}


/**
 * _str_tok - splits string
 * @co: command typed string
 * @del: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_str_tok(char *co, char del)
{
	int len_bu, i_arr, j_arr, i_w, i_co, len_w, len_c;
	char **array_split = NULL;

	len_bu = i_co = len_c = i_arr = j_arr = i_w = len_w = 0;

	len_bu = count_options(co, del);

	/* malloc ptrs to store array of tokens (len_bu + 2), and NULL ptr */
	array_split = (char **)malloc((len_bu + 2) * sizeof(char *));
	if (array_split == NULL)
		return (NULL);

	len_c = _strlen(co);

	for (i_co = 0; i_co < len_c; i_co++)
	{
		if (co[i_co] != del)
		{
			for (i_w = i_co, len_w = 0; (co[i_w] != del) && (co[i_w] != '\0'); i_w++)
				len_w++;/*malloc.len for.each.toke ptin array */

			array_split[i_arr] = malloc(sizeof(char) * (len_w + 1));
			if (array_split[i_arr] == NULL)
				return (NULL);

			for (j_arr = 0; (co[i_co] != del) && (co[i_co] != '\0'); j_arr++, i_co++)
				array_split[i_arr][j_arr] = co[i_co];
			array_split[i_arr][j_arr] = '\0'; /* null terminate at end*/
		}

		if (i_co < len_c && (co[i_co + 1] != del && co[i_co + 1] != '\0'))
			i_arr++;/* handle repeated delimeters; increment ptr after ("ls __-l")*/
	}
	array_split[++i_arr] = NULL; /* set last array ptr to NULL */

	return (array_split);
}
