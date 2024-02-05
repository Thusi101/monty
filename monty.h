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

typedef struct errorstate{
	int error;
	int state;
} errorstate;

typedef struct stacknode{
		int data;
		struct stacknode *prev;
		struct stacknode *next;
} stacknode;

typedef struct instruction{
		char *opcode;
		void (*handler)(stacknode **stack, unsigned int line_number);
} instruction_t;

extern errorstate error_state;

/* EXEC */
int execute_monty(FILE *file_ptr);

/* OPCODES */
void _pushop(stacknode **stack, unsigned int line_number, char *a_value);
void _pallop(stacknode **stack, unsigned int line_number);
void _pintop(stacknode **stack, unsigned int line_number);
void _popop(stacknode **stack, unsigned int line_number);
void _swapop(stacknode **stack, unsigned int line_number);
void _addop(stacknode **stack, unsigned int line_number);
void add_node_at_top(stacknode **stack, int value);
void add_node_at_bottom(stacknode **stack, int value);
void _nopop(stacknode **stack, unsigned int line_number);
void _subop(stacknode **stack, unsigned int line_number);
void _divop(stacknode **stack, unsigned int line_number);
void _mulop(stacknode **stack, unsigned int line_number);
void _modop(stacknode **stack, unsigned int line_number);
void _pcharop(stacknode **stack, unsigned int line_number);
void _pstrop(stacknode **stack, unsigned int line_number);
void _rotlop(stacknode **stack, unsigned int line_number);
void _rotrop(stacknode **stack, unsigned int line_number);

/* OP_PUSH */
stacknode *add_dnodeint(stacknode **head, const int n);
stacknode *add_dnodeint_end(stacknode **head, const int n);

/* UTILS */
int handle_input(int argc, char **argv, FILE **fd);
char **handle_line(char *line);
void _math(stacknode **stack, char op);

/* DEBUG */
void debug(char **args, int line_number);

#endif /* MONTY_H */
