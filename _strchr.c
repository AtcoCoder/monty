/*****************************************************************************/
#include "monty.h"

/**
 * _strchr - returns a pointer to the first occurrence of the character c
 * in the string s
 * @s: the dest buffer
 * @c: the character to search
 *
 * Return: the resulting string.
 */
char *_strchr(char *s, char c)
{
	char *str = s;

	int i = 0;

	while (s[i] != c)
	{
		if (s[i] == '\0')
			return ((char *)'\0');
		i++;
	}

	return (str + i);
}
