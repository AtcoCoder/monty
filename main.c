#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - check the code
 * @argc: argument count
 * @argv: list of arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *file_path;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = argv[1];
	get_line(file_path);
	return (0);
}
