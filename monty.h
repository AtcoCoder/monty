#ifndef _MONTY_ECI_JOY_H
#define _MONTY_ECI_JOY_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 1025
#define BUFFLEN (BUFFSIZE - 1)

extern char **environ;

typedef struct stat stat_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_ctl - doubly linked list controller
 * @mode: operating mode - stack(0) or queue(1)
 * @head: pointer to the front or top of the linked list
 * @tail: pointer to the rear or tail of the stack
 * @jobNr: the line number of the monty opcode command
 *
 * Description: list pointer structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct list_ctl
{
	int mode; /* 0 == stack; 1 == queue   */
	int jobNr; /* serial number of the opcode line */
	struct stack_s *head;
	struct stack_s *tail;

} list_ctl_t;

extern list_ctl_t lctl;

int _push(const int value);
int _pall(void);
int _pint(void);
int _pop(void);
int _swap(void);
int _add(void);
int _nop(void);
int _sub(void);
int _div(void);
int _mul(void);
int _mod(void);
/* int comment(void): */
int _pchar(void);
int _pstr(void);
int _rotl(void);
int _rotr(void);
int _stack_mode(void);
int _queue_mode(void);
int _bf_print(void);
int _bf_add(void);
void _free_list(void);

/* team library functions */
size_t _strlen(const char *s);
char *_strncat(char *dest, const char *src, int n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, int n);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
int _strtoi(const char *str, int *error);
char *_itostr(int n);
char **splitLine(char **cmdLine, char ***args);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **parseLine(char *str, char *delim);
char *_getenv(const char *name);
char *remCmnt(char *cmdLine);
void shellErr(int code);
int execOpcode(char **args);
void ssExit(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);

size_t print_dlistint(const stack_t *h);
size_t dlistint_len(const stack_t *h);
void free_dlistint(stack_t *head);
int sum_dlistint(stack_t *head);

#endif /*_MONTY_ECI_JOY_H*/
