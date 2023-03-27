#include "monty.h"

int execOpcode2(char **args);
int is_int(char *str);

/**
 * execOpcode - execute an opcode
 * @args: the arguments vector for the current command
 * Return: 0 if ok, -1 on error
 */
int execOpcode(char **args)
{
	if (!_strcmp(args[0], "push"))  /* arg matches this function */
	{
		if ((args[1] == NULL) || !is_int(args[1]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", lctl.jobNr);
			return (-1);
		}
		return (_push(atoi(args[1])));
	}
	else if (!_strcmp(args[0], "pall"))  /* arg matches this function */
		return (_pall());
	else if (!_strcmp(args[0], "pint"))  /* arg matches this function */
		return (_pint());
	else if (!_strcmp(args[0], "pop"))  /* arg matches this function */
		return (_pop());
	else if (!_strcmp(args[0], "swap"))  /* arg matches this function */
		return (_swap());
	else if (!_strcmp(args[0], "add"))  /* arg matches this function */
		return (_add());
	else if (!_strcmp(args[0], "nop"))  /* arg matches this function */
		return (0);
	else if (!_strcmp(args[0], "sub"))  /* arg matches this function */
		return (_sub());
	else if (!_strcmp(args[0], "div"))  /* arg matches this function */
		return (_div());
	else if (!_strcmp(args[0], "mul"))  /* arg matches this function */
		return (_mul());

	return (execOpcode2(args));   /* break this loop */
}


/**
 * execOpcode2 - execute an opcode
 * @args: the arguments vector for the current command
 * Return: 0 if ok, -1 on error
 */
int execOpcode2(char **args)
{
	if (!_strcmp(args[0], "mod"))  /* arg matches this function */
		return (_mod());
	else if (!_strcmp(args[0], "pchar"))  /* arg matches this function */
		return (_pchar());
	else if (!_strcmp(args[0], "pstr"))  /* arg matches this function */
		return (_pstr());
	else if (!_strcmp(args[0], "rotl"))  /* arg matches this function */
		return (_rotl());
	else if (!_strcmp(args[0], "rotr"))  /* arg matches this function */
		return (_rotr());
	else if (!_strcmp(args[0], "stack"))  /* arg matches this function */
		return (_stack_mode());
	else if (!_strcmp(args[0], "queue"))  /* arg matches this function */
		return (_queue_mode());

	fprintf(stderr, "L%d: unknown instruction %s\n", lctl.jobNr, args[0]);
	return (-1);
}


/**
 * is_int - test if a string is all digits
 * @str: the string to test
 * Return: 1 if int or 0 otherwise
 */

int is_int(char *str)
{
	char *ptr = str;

	if (*ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!(isdigit(*ptr)))
			return (0);
		ptr++;
	}

	return (1);
}
