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
 * struct dblink_s - doubly linked list representation of a stack (or queue)
 * @i: integer
 * @bak: points to the previous element of the stack (or queue)
 * @fwd: points to the next element of the stack (or queue)
 * 
 */

typedef struct dblink_s
{
		int i;
		struct dblink_s *bak;
		struct dblink_s *fwd;
} dblink_t;

/**
 * struct form_s - structure containing the error status and state of the stack
 * @error: the error value (0 if no, 1 if yes)
 * @type: QUEUE or STACK
 */

typedef struct form_s
{
        int error;
        int type;
} form_t;

/**
 * struct opcf_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 */

typedef struct opcf_s
{
		char *opcode;
		void (*func)(dblink_t **dblink, unsigned int line_num);
} opcf_t;

form_t FORM;

/* EXEC */
int monty_run(FILE *fp);

/* OPCODES */
void _push(dblink_t **dblink, unsigned int line_num, char *a_value);
void _pall(dblink_t **dblink, unsigned int line_num);
void _pint(dblink_t **dblink, unsigned int line_num);
void _pop(dblink_t **dblink, unsigned int line_num);
void _swap(dblink_t **dblink, unsigned int line_num);
void _add(dblink_t **dblink, unsigned int line_num);
void _nop(dblink_t **dblink, unsigned int line_num);
void _sub(dblink_t **dblink, unsigned int line_num);
void _div(dblink_t **dblink, unsigned int line_num);
void _mul(dblink_t **dblink, unsigned int line_num);
void _mod(dblink_t **dblink, unsigned int line_num);
void _pchar(dblink_t **dblink, unsigned int line_num);
void _pstr(dblink_t **dblink, unsigned int line_num);
void _rotl(dblink_t **dblink, unsigned int line_num);
void _rotr(dblink_t **dblink, unsigned int line_num);

/* OP_PUSH */
dblink_t *add_dnodeint(dblink_t **head, const int i);
dblink_t *add_dnodeint_end(dblink_t **head, const int i);

/* UTILS */
int handle_input(int argc, char **argv, FILE **fd);
char **handle_line(char *line);
void _math(dblink_t **dblink, char op);

/* DEBUG */
void debug(char **args, int line_num);

#endif /* MONTY_H */
