#include "monty.h"

/**
 * _rotl - rotate upwards one step for a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _rotl(void)
{
	stack_t *temp;

	/* NULL checks */
	if (lctl.head == NULL)  /* empty list */
		return (0);

	if (lctl.head->next == NULL)  /* one node only */
		return (0);

	/* disconnect top node */
	temp = lctl.head;
	lctl.head->next->prev = NULL;
	lctl.head = lctl.head->next;

	/* attach old head to tail */
	lctl.tail->next = temp;
	temp->prev = lctl.tail;
	temp->next = NULL;
	lctl.tail = temp;

	return (0);
}
