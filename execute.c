#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * free_stack - frees the stack after runtime
 * @stack: the program stack
 */

void free_stack(stacknode *stack)
{
	stacknode *current = stack;
	while (current)
	{
	       stacknode *temp = current;
	       current = current->next;
	       free(temp);
	}
}

/**
 * monty_dispatch - selects the correct function to call
 *
 * @args: the array of args
 * @stack: the program stack
 * @line_number: the line number
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE if failure
 */

int execute_instruction(char **args, stacknode **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"pall", _pallop}, {"pint", _pintop},
		{"pop", _popop}, {"swap", _swapop},
		{"add", _addop}, {"nop", _nopop},
		{"sub", _subop}, {"div", _divop},
		{"mul", _mulop}, {"mod", _modop},
		{"pchar", _pcharop}, {"pstr", _pstrop},
		{"rotl", _rotlop}, {"rotr", _rotrop},
		{NULL, NULL}
	};

	if (strcmp(args[0], "push") == 0)
	{
		if (args[1], == NULL)
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);	
		error_state.error = 1;:
		return (EXIT_FAILURE);
	}

	if (strcmp(args[0], "stack") == 0)
	{
		error_state.state = STACK;
		return (error_state.error);
	}

	if (strcmp(args[0], "queue") == 0)
	{
		META.state = QUEUE;
		return (error_state.error);
	}

	while (instructions[i].opcode)
	{
		if (strcmp(args[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (error_state.error);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
	error_state.error = 1;
	return (EXIT_FAILURE);
}

/**
 * monty_run - main interpreter loop
 *
 * @file_ptr: file pointer to monty bytecode file
 * @getline: read lines from file pointer
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE if failure
*/

int execute_monty(FILE *file_ptr)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	stacknode *stack = NULL;
	
	while (getline(&line, &len, file_ptr) != -1)
	{
		char **args = handle_line(line);
		if (args  == NULL)
		{
			fprint(stderr, "Error: failed to parse line %d\n", line_number);
			free(line);
			free_stack(stack);
			return (EXIT_FAILURE);
		}
		free(args);
		line_number++;
	}
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}
