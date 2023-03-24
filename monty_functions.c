#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * get_function - selects the function to be executed
 *
 * @instruct: the opcode instruct
 *
 * Return: pointer to the selected function.
 */
function_pointer get_function(const char *instruct)
{
	instruction_t func_pointers[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;

	while (func_pointers[i].f != NULL &&
			(strcmp(func_pointers[i].opcode, instruct) != 0))
	{
		i++;
	}
	return (func_pointers[i].f);
}

/**
 * get_line - reads monty bytecode file line by line
 * @file_path: path of the monty bytecode file
 * Return: Nothing.
 */
void get_line(const char *file_path)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num = 1;
	char *instruct;
	char instruct_copy[256];
	function_pointer func;
	stack_t *stack;

	fp = fopen(file_path, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		instruct = tokenize(line, instruct_copy);
		if (instruct == NULL || instruct[0] == '#')
		{
			line_num += 1;
			continue;
		}
		func = get_function(instruct_copy);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruct_copy);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_num);
		line_num += 1;
	}
	fclose(fp);
	if (line)
	{
		free(line);
		exit(-1);
	}
}

/**
 * only_numword - removes all spaces and newline from str
 * @str: string
 * Return: Nothing.
 */
void only_numword(char *str)
{
	int i;
	int count = 0;

	for (i = 0; str[i]; i++)
		if ((str[i] != ' ') && (str[i] != '\n'))
			str[count++] = str[i];
	str[count] = '\0';
}

/**
 * tokenize - parse the line
 * @line: the line
 * @instruct_copy: container for filtered token
 * Return: the instruct or NULL if non exist.
 */
char *tokenize(char *line, char instruct_copy[])
{
	char *instruct;

	instruct = strtok(line, " ");
	if (instruct == NULL)
		return (NULL);
	strcpy(instruct_copy, instruct);
	only_numword(instruct_copy);
	return (instruct);
}
