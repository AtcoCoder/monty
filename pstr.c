#include "monty.h"

/**
 * _pstr - print the char elements of a doubly linked list from top to bottom
 * Return: 0 if all ok; -1 on error
 */
int _pstr(void)
{
	const stack_t *ptr = lctl.head;

	while (ptr)
	{
		if ((ptr->n <= 0) || (ptr->n > 127))
			break;
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
	return (0);
}
