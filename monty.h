#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1

/**
 * struct meta_s - structure containing the error status and state of the stack
 * @error: the error value (0 if no, 1 if yes)
 * @state: QUEUE or STACK
 */

typedef struct meta_s
{
	int error;
	int state;
} meta_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

meta_t META;

/* EXEC */
int monty_run(FILE *fp);

/* OPCODES */
void _push(stack_t **stack, unsigned int line_nb, char *a_value);
void _pall(stack_t **stack, unsigned int line_nb);
void _pint(stack_t **stack, unsigned int line_nb);
void _pop(stack_t **stack, unsigned int line_nb);
void _swap(stack_t **stack, unsigned int line_nb);
void _add(stack_t **stack, unsigned int line_nb);
void _nop(stack_t **stack, unsigned int line_nb);
void _sub(stack_t **stack, unsigned int line_nb);
void _div(stack_t **stack, unsigned int line_nb);
void _mul(stack_t **stack, unsigned int line_nb);
void _mod(stack_t **stack, unsigned int line_nb);
void _pchar(stack_t **stack, unsigned int line_nb);
void _pstr(stack_t **stack, unsigned int line_nb);
void _rotl(stack_t **stack, unsigned int line_nb);
void _rotr(stack_t **stack, unsigned int line_nb);

/* OP_PUSH */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/* UTILS */
int handle_input(int argc, char **argv, FILE **fd);
char **handle_line(char *line);
void _math(stack_t **stack, char op);

/* DEBUG */
void debug(char **args, int line_nb);

#endif /* MONTY_H */
