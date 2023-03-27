#include "monty.h"

/**
 * _add - add the top two nodes of a doubly linked list
 * store the result in second node and pop the top node
 * Return: 0 if all ok; -1 on error
 */
int _add(void)
{
	/* must have at least two nodes */
	if ((lctl.head == NULL) || (lctl.head->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lctl.jobNr);
		return (-1);
	}

	/* add top and next and store in next */
	lctl.head->next->n += lctl.head->n;

	/* pop the top */
	_pop();

	return (0);
}

