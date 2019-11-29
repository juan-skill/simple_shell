#include "shell.h"


/**
 * _memcpy - copies memory area
 *
 * @dest: a pointer to char that contains the array source
 * @src: a pointer to char that contains the array destination
 * @n:  lenght to concant
 * Return: a pointer that contains the copy
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int j;

	j = 0;
	while (src[j] != '\0')
		dest[n++] = src[j++];
	dest[n] = '\0';

	return (dest);
}


/**
 * _strcpy - copies the string pointed to by src,
 * to the buffer pointed to by dest.
 *
 * @src: source string to copy
 * @dest: buffer to copy string into
 * Return: returns pointer to copied string
 */
char *_strcpy(char *dest, const char *src)
{
	char *s;

	s = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';

	return (s);
}

/**
 * _strdup - duplicates a string to a newly allocated space
 *
 * @str: string to duplicate
 * Return: returns pointer to duplicated string
 */
char *_strdup(const char *str)
{
	char *s_dup;

	s_dup = NULL;

	if (str == NULL)
		return (NULL);

	s_dup = (char *)malloc((1 + _strlen(str)) * sizeof(char *));
	if (s_dup == NULL)
		return (NULL);

	s_dup = _strcpy(s_dup, str);

	return (s_dup);
}


/**
 * _strcmp - compares two strings
 *
 * @s1: a pointer to char that contains the first string
 * @s2: a pointer to char that contains the second string
 * Return: if s1 < s2 is negative, 0 if s2 is not found
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
		if (*s2 == '\0')
			return (0);

	return (*s1 - *s2);

}

/**
 * _strlen - returns the length of a string
 *
 * @s: string type char
 * Return: returns the lenght of a string
 */
int _strlen(const char *s)
{
	const char *ptr;

	ptr = s;
	while (*s != '\0')
		s++;

	return (s - ptr);
}
