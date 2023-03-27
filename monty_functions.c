#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 */
void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

#include "monty.h"

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}

#include "monty.h"
/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
