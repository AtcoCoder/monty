#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
#include <ctype.h>

/**
 * push - pushes an element to the stack
 * @stack: pointer to the pointer to the first
 * element on the stack
 * @line_number: line number on which the bytecode exist
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *temp;
	int arg;
	char *token;

	temp = *stack;
	token = strtok(NULL, "\n ");
	if ((token == NULL) || (digits_only(token) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	arg = atoi(token);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp == NULL)
	{
		new->n = arg;
		new->next = NULL;
		new->prev = NULL;
		(*stack) = new;
	}
	new->n = arg;
	new->next = temp;
	new->prev = NULL;
	(*stack) = new;
}

/**
 * pall - prints the value at each node of the list stack_t
 * @stack: pointer to the first node of the list stack_t
 * @line_number: line number
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = *stack;
	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * digits_only - check whether a string contains only digits
 * @s: string
 * Return: 1 if s contains only digits, else 0.
 */
int digits_only(const char *s)
{
	while (*s)
	{
		if (isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}
