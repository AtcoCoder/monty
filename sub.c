#include "monty.h"

/**
 * _sub - subtract the top element from the second element
 *  of a doubly linked list
 * store the result in second node and pop the top node
 * Return: 0 if all ok; -1 on error
 */
int _sub(void)
{
	/* must have at least two nodes */
	if ((lctl.head == NULL) || (lctl.head->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lctl.jobNr);
		return (-1);
	}

	/* add top and next and store in next */
	lctl.head->next->n -= lctl.head->n;

	/* pop the top */
	_pop();

	return (0);
}

