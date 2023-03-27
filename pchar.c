#include "monty.h"

/**
 * _pchar - print the ascii char of top element of a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _pchar(void)
{
	if (lctl.head != NULL)  /* list not empty */
	{
		if (((lctl.head->n) < 0) || ((lctl.head->n) > 127))
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lctl.jobNr);
			return (-1);
		}
		printf("%c\n", lctl.head->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lctl.jobNr);
		return (-1);
	}

	return (0);
}
