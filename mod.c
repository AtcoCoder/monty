#include "monty.h"

/**
 * _mod - modulus divide the second element by the top element
 *  of a doubly linked list
 * store the result in second node and pop the top node
 * Return: 0 if all ok; -1 on error
 */
int _mod(void)
{
	/* must have at least two nodes */
	if ((lctl.head == NULL) || (lctl.head->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lctl.jobNr);
		return (-1);
	}

	/* check divide by zero error */
	if (lctl.head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lctl.jobNr);
		return (-1);
	}

	/* mod divide second node by top nude  and store in second node */
	lctl.head->next->n %= lctl.head->n;

	/* pop the top */
	_pop();

	return (0);
}

