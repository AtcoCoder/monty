/*****************************************************************************/
#include "monty.h"
/**
 * _strlen - returns the length of a string
 * uses _putchar()
 *
 * @s: the string
 * Return: the length of the string
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

