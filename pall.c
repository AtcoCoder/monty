#include "monty.h"

/**
 * _pall - print the elements of a doubly linked list
 * Return: 0 if all ok; -1 on error
 */
int _pall(void)
{
	const stack_t *ptr = lctl.head;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}

	return (0);
}
