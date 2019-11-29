#include "shell.h"

/**
 * calculate_len - counts number of 0s in a tens power number
 *
 * @n: number to analize
 * Return: count of digits of number
 */
unsigned int calculate_len(int n)
{
 	unsigned int count = 0;
 	int num = n;


 	while (num > 9 || num < -9)
 	{
		num /= 10;
 		count++;
 	}

	return (count);
}

/**
 * itostr - convertes an int into a string
 *
 * @number: int to becomes
 * Return: the int as a string or returns NULL if failed
 */
char *itostr(int number)
{
	int digits, base_ten, sign, x;
	unsigned int len;
	char *line = NULL;

	len = sign = x = 0;
	digits = number;
	base_ten = 1;

	if (number < 0)
		sign = 1;

	line = malloc((calculate_len(digits) + 2 + sign) * sizeof(char));
		if (line == NULL)
			return (NULL);

	if (number < 0)
	{
		line[len] = '-';
		len++;
	}

	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		base_ten *= 10;
	}
	for (digits = number; x >= 0; x--)
	{
		if (digits < 0)
		{
			line[len] = (digits / base_ten) * -1 + '0';
			len++;
		}
		else
		{
			line[len] = (digits / base_ten) + '0';
			len++;
		}
		digits %= base_ten;
		base_ten /= 10;
	}
	line[len] = '\0';

	return (line);
}
