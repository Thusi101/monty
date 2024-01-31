#include "monty.h"

/**
 * release_s - frees the stack after runtime
 *
 * @dbl: the program stack
 */

void release_s(dbl_t *dbl)
{
	dbl_t *next;

	while (dbl != NULL)
	{
		next = dbl->next;
		free(dbl);
		dbl = next;
	}
}

/**
 * monty_dis - selects the correct function to call
 *
 * @args: the array of args
 * @dbl: the program stack
 * @line_num: the line number
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE if failure
 */

int monty_dis(char **args, dbl_t **dbl, unsigned int line_num)
{
	int i = 0;
	opcf_t opcf[] = {
		{"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"nop", _nop},
		{"sub", _sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{NULL, NULL}
	};

	if (strcmp(args[0], "push") == 0)
	{
		_push(stack, line_nb, args[1]);
		return (FORM.error);
	}

	if (strcmp(args[0], "stack") == 0)
	{
		FORM.type = DBL;
		return (FORM.error);
	}

	if (strcmp(args[0], "queue") == 0)
	{
		FORM.type = QUEUE;
		return (FORM.error);
	}

	while (opcf[i].opcode)
	{
		if (strcmp(args[0], opcf[i].opcode) == 0)
		{
			opcf[i].f(dbl, line_num);
			return (FORM.error);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, args[0]);
	FORM.error = 1;
	return (EXIT_FAILURE);
}

/**
 * monty_run - main interpreter loop
 *
 * @filep: file pointer to monty bytecode file
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE if failure
*/

int monty_run(FILE *filep)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	unsigned int line_nb = 1;

	dbl_t *dbl = NULL;

	while (getline(&line, &len, filep) != -1)
	{
		args = handle_line(line);
		if (args[0] && args[0][0] == '#')
			;
		else if (args[0] && monty_dispatch(args, &dbl, line_num) == 1)
		{
			free(args);
			free_dbl(dbl);
			free(line);
			return (EXIT_FAILURE);
		}
		free(args);
		line_num++;
	}
	free_dbl(dbl);
	free(line);
	return (EXIT_SUCCESS);
}
