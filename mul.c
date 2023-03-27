#include "monty.h"

/**
 * _mul - multiply the top two nodes of a doubly linked list
 * store the result in second node and pop the top node
 * Return: 0 if all ok; -1 on error
 */
int _mul(void)
{
	/* must have at least two nodes */
	if ((lctl.head == NULL) || (lctl.head->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lctl.jobNr);
		return (-1);
	}

	/* multiply top and second nodes and store in second */
	lctl.head->next->n *= lctl.head->n;

	/* pop the top */
	_pop();

	return (0);
}

