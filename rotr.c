#include "monty.h"

/**
 * _rotr - rotate in reverse one step for a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _rotr(void)
{
	stack_t *temp;

	/* NULL checks */
	if (lctl.head == NULL)  /* empty list */
		return (0);

	if (lctl.head->next == NULL)  /* one node only */
		return (0);

	/* disconnect tail node */
	temp = lctl.tail;
	lctl.tail->prev->next = NULL;
	lctl.tail = lctl.tail->prev;

	/* attach the old tail to the head */
	temp->next = lctl.head;
	lctl.head->prev = temp;
	temp->prev = NULL;
	lctl.head = temp;

	return (0);
}
