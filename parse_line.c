#include "monty.h"

#define plBUFFUNIT 80
#define plBUFFCAP 160

void parseMallocCheck(char **tokens);
/**
 * parseLine - parse string into tokens based on given delimiters
 * @str: the string to parse
 * @delim: the string of delimiters
 * Return: pointer to the vector of tokens
 */
char **parseLine(char *str, char *delim)
{
	char *ptr = str;
	char **tokens;
	size_t buffcap = plBUFFCAP, i = 0;

	tokens = malloc(sizeof(char *) * buffcap);
	parseMallocCheck(tokens);
	tokens[0] = NULL;
	while (*ptr)
	{
		while (*ptr)
		{
			if (!_strchr(delim, *ptr))
			{
				tokens[i] = ptr;
				tokens[i + 1] = NULL;
				break;
			}
			*ptr = '\0';
			ptr++;
		}
		while (*ptr)
		{
			if (_strchr(delim, *ptr))
				break;
			ptr++;
		}
		i++;
		/*if (i == buffcap)*/
		/*{ */
		/*	buffcap += plBUFFUNIT; */
		/*	tokens = realloc((void *) tokens,  */
		/*		sizeof(char *) * buffcap); */
		/*	parseMallocCheck(tokens); */
		/*} */
	}
	/*tokens = realloc((void *) tokens, sizeof(char *) * (i + 1));*/
	/*parseMallocCheck(tokens);*/
	return (tokens);
}

/**
 * parseMallocCheck - error check memory allocation
 *
 * @tokens: the double poiter allocated by malloc or realloc
 */
void parseMallocCheck(char **tokens)
{
	if (!tokens)
	{
		perror("parseLine: Memory Allocation Failure");
		exit(EXIT_FAILURE);
	}
}
