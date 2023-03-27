#include "monty.h"

int push(const int n);
int enqueue(const int n);

/**
 * _push - push or enque a new node for a doubly linked list
 * @value: new node data int
 * Return: 0 if all ok, -1 on error
 */
int _push(const int value)
{

	switch (lctl.mode)
	{
	case 0:
		return (push(value));

	case 1:
		return (enqueue(value));
	}

	return (0);
}

/**
 * push - add a new node at the beginning of a doubly linked list
 * @n: new node data int
 * Return: 0 if all ok; -1 on error
 */
int push(const int n)
{
	stack_t *new;

	/* NULL checks */
	/* if (head == NULL) */
	/*	return (NULL); */


	/* malloc new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	/* fill in the data */
	new->n = n;

	/* set the 'prev' pointer */
	new->prev = NULL;

	/* attach to old head or NULL terminate*/
	if (lctl.head != NULL)
	{
		new->next = lctl.head;
		lctl.head->prev = new;
	}
	else   /* case of first node */
	{
		new->next = NULL;
		lctl.tail = new;   /* set tail if first node */
	}

	/* redirect the head pointer */
	lctl.head = new;

	return (0);
}

/**
 * enqueue - add a new node at the tail end of a doubly linked list
 * @n: new node data int
 * Return: 0 if all ok; -1 on error
 */
int enqueue(const int n)
{
	stack_t *new;

	/* NULL checks */
	/*if (head == NULL) */
	/*	return (NULL); */

	/* malloc new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}

	/* fill in the data */
	new->n = n;

	/* set the 'next' pointer */
	new->next = NULL;

	/* attach to old end or point prev to NULL*/
	if (lctl.head == NULL)  /* empty list */
	{
		new->prev = NULL;
		/* redirect the head pointer */
		lctl.head = new;
	}
	else if (lctl.head->next == NULL) /* single node */
	{
		new->prev = lctl.head;
		lctl.head->next = new;
	}
	else
	{
		new->prev = lctl.tail;
		lctl.tail->next = new;
	}

	/* redirect the tail pointer */
	lctl.tail = new; /* debug */

	return (0);
}

