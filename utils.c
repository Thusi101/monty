#include "monty.h"

/**
 * handle_input - handles the file given as path, and sets fd
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 * @fp: the file descriptor to set
 *
 * Return: 0 on success, otherwise EXIT_FAILURE
 */

int handle_input(int argc, char **argv, FILE **fp)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	*fp = fopen(argv[1], "r");
	if (*fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (0);
}

/**
 * handle_line - handles and tokenizes the line read from file
 *
 * @line: the line to tokenize
 *
 * Return: tokens as an array of strings
 */


char **handle_line(char *line)
{
	int i = 0, wc = 0, in = 0;
	char **args = NULL;

	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			wc++;
		}
		i++;
	}

	args = malloc(sizeof(char *) * (wc + 1));
	if (!args)
		return (NULL);

	i = 0;
	while ((args[i] = strtok(i == 0 ? line : NULL, " \n\t")))
		i++;

	return (args);
}

/**
 * free_args - frees the argument tokens array
 *
 * @args: array of tokens
 */


void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
}

/**
 * _math - performs all math operations
 *
 * @stack: the program stack
 * @op: operator
 */


void _math(stack_t **stack, char op)
{
	int res = 0;
	stack_t *tmp;

	if (op == '+')
		res = (*stack)->n + (*stack)->next->n;
	else if (op == '-')
		res = (*stack)->next->n - (*stack)->n;
	else if (op == '/')
	{
		if ((*stack)->n == 0)
			META.error = 1;
		else
			res = (*stack)->next->n / (*stack)->n;
	}
	else if (op == '*')
		res = (*stack)->n * (*stack)->next->n;
	else if (op == '%')
	{
		if ((*stack)->n == 0)
			META.error = 1;
		else
			res = (*stack)->next->n % (*stack)->n;
	}

	if (META.error == 1)
		return;

	(*stack)->next->n = res;
	tmp = (*stack)->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
