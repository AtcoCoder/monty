#include "monty.h"

ssize_t nullChecks(char **lineptr, size_t *n, int fd);
int newlineCheck(char *buff, ssize_t nread, ssize_t *cumread, int fd);

#define STDSIZE ((size_t) 256)

/**
 * _getline - delimited string input
 * @lineptr: address of the pointer to the command line string
 * @n: pointer to the size of the buffer
 * @fd: file descriptor for the stream to read from
 * Return: the  number  of  characters read, including the newline character
 * but not including the terminating null byte; -1 on error including EOF
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t nread = 0;	/* number of bytes read this round */
	ssize_t cumread = 0;	/* cum number of bytes read */
	size_t buffsz = STDSIZE; /* actual buffer size, initial value *n */
	size_t readsz = STDSIZE;
	char *buff = NULL; /* buff will be updated and skipped */

	/* check for NULL pointer */
	if (nullChecks(lineptr, n, fd) == -1)
		return (-1);

	/* Initialise read parameters */
	buff = *lineptr;
	buffsz = *n; /* actual buffer size, initial value *n */
	readsz = (*n > STDSIZE) ? STDSIZE : *n;

	while (1)
	{
		/* read buffsize chars, readsz chars at a time (MAX) into buff */
		nread = read(fd, buff, readsz);

		/*check if read error */
		if (nread == -1)  /* read error */
			return (-1);

		if (nread == 0)  /* control/D */
		{
			if (cumread == 0)
			{
				**lineptr = '\0';
				cumread = -1;
			}
			else
			{
				*lineptr[cumread] = '\0';
			}
			break;
		}

		/* check if we have a newline */
		if (newlineCheck(buff, nread, &cumread, fd))
			break;
		cumread += nread;

		/* skip ahead nread on buff */
		buff += nread;
		buffsz -= nread;	/*update buffsz */

		/* enlarge buff so we can read again */
		/*if (buffsz < readsz)*/
		/*{*/
		/*	buff = realloc(buff, buffsz); */
		/*	*lineptr = realloc(*lineptr, (*n + readsz));*/
		/*	buff = *lineptr + cumread;*/
		/*	buffsz += readsz;*/
		/*	*n += readsz;*/
		/*}*/

	}

	return (cumread);
}


/**
 * nullChecks - check for NULL input data
 * @lineptr: address of the pointer to the command line string
 * @n: pointer to the size of the buffer
 * @fd: file descriptor for the stream to read from
 * Return: 0 if all ok, -1 on error
 */

ssize_t nullChecks(char **lineptr, size_t *n, int fd)
{
	/* check for NULL pointer */
	if ((lineptr == NULL) || (n == NULL) || (fd == -1))
	{
		errno = EINVAL;
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * (256 + 1));
		if (!(*lineptr))
		{
			perror("_getline");
			return (-1);
		}
		*n = 256;
	}

	return (0);
}

/**
 * newlineCheck - check for newline character
 * @buff: pointer to read buffer
 * @nread: the number of bytes read in the read cycle
 * @cumread: pointer to the cum number of bytes read
 * @fd: pointer to teh file descriptor for the stream to read from
 * Return: 0 if no newline or 1 if newline found
 */
int newlineCheck(char *buff, ssize_t nread, ssize_t *cumread, int fd)
{
	int i, newline = 0;

		/* check if we have a newline */
		for (i = 1, newline = 0; i <= nread; i++)
		{
			if (buff[i - 1] == '\n')
			{
				buff[i] = '\0';
				lseek(fd, -(nread - (i)), SEEK_CUR);
				cumread += i;
				newline = 1; /*newline found */
				break;
			}
		}
		if (newline)
			return (1);

	return (0);
}
