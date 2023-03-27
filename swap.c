#include "monty.h"

/**
 * _swap - swap the top two nodes of a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _swap(void)
{
	stack_t *temp;

	/* must have at least two nodes */
	if ((lctl.head == NULL) || (lctl.head->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lctl.jobNr);
		return (-1);
	}

	if (lctl.head->next == lctl.tail)  /* only two nodes */
	{
		lctl.head = lctl.tail;
		lctl.tail = lctl.head->prev;
		lctl.head->prev = NULL;
		lctl.head->next = lctl.tail;
		lctl.tail->prev = lctl.head;
		lctl.tail->next = NULL;
	}
	else  /* at least three nodes */
	{
		temp = lctl.head;
		lctl.head = lctl.head->next;
		lctl.head->prev = NULL;
		lctl.head->next->prev = temp;
		temp->next = lctl.head->next;
		temp->prev = lctl.head;
		lctl.head->next = temp;
	}

	return (0);
}

