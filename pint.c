#include "monty.h"

/**
 * _pint - print the top element of a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _pint(void)
{
	if (lctl.head != NULL)
		printf("%d\n", lctl.head->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lctl.jobNr);
		return (-1);
	}

	return (0);
}
