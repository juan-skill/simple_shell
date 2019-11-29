#include "shell.h"


/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len, len2;

	len = len2 = 0;
	len = _strlen(dest);
	len2 = _strlen(src);

	dest = _realloc(dest, len, (len + len2 + 1) * sizeof(char));
	dest = _memcpy(dest, src, len);

	return (dest);
}


/**
 * _realloc - allocate memory and set all values to 0
 *
 * @ptr: pointer to the memory previously allocated (malloc(old_size))
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 * Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr_new = NULL;
	unsigned int i;

	if (new_size == 0 && ptr != NULL) /* free memory if reallocate 0 */
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size) /* return ptr if reallocating same old size */
		return (ptr);

	ptr_new = malloc(new_size);
	if (ptr_new == NULL)
		return (NULL);

	if (ptr == NULL)
		return (ptr_new);

	/* fill up values up till minimum of old or new size */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)ptr_new + i) = *((char *)ptr + i);

	free(ptr); /* free old ptr */

	return (ptr_new);
}
