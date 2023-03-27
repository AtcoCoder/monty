#include "monty.h"

/**
 * _free_list - free a doubly linked list
 */
void _free_list(void)
{
	stack_t *ptr = NULL;

	/* scan nodes and free as necessary */
	if (lctl.head == NULL)	/* empty list case */
		return;

	if (lctl.head->next == NULL)		/* single node case */
	{
		free(lctl.head);
	}
	else
	{
		ptr = lctl.head->next;
		while (ptr->next)
		{
			free(lctl.head);
			lctl.head = ptr;
			ptr = ptr->next;
		}
		free(lctl.head);
		free(ptr);
	}
}
