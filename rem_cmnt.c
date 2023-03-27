#include "monty.h"

/**
 * remCmnt - scans cmdLine string and removes the trailing # comment if any
 *
 * @cmdLine: the command line
 * Return: a pointer to the command line free of any comment
 */

char *remCmnt(char *cmdLine)
{
	char *ptr = cmdLine;
	int sQuoteOpen = 0, dQuoteOpen = 0, cmntFound = 0;

	while (*ptr)
	{
		if (_strchr("\'\"#", *ptr))
		{
			switch (*ptr)
			{
			case '\'':
				if (sQuoteOpen)
					sQuoteOpen = 0;
				else
					sQuoteOpen = 1;
				break;
			case '\"':
				if (dQuoteOpen)
					dQuoteOpen = 0;
				else
					dQuoteOpen = 1;
				break;
			case '#':
				if (!sQuoteOpen && !dQuoteOpen)
					if ((ptr == cmdLine) || (*(ptr - 1) == ' '))
					{
						*ptr = '\0'; /*cmnt found */
						cmntFound = 1;
					}
				break;
			}
			if (cmntFound)
				break;
		}
		ptr++;   /* debug */

	}
	return (cmdLine);
}
