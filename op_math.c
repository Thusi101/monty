#include "monty.h"

/**
 * _add - addition of the first two values at top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _add(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '+');
	}
}

/**
 * _sub - substraction of top of stack from 2nd top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _sub(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '-');
	}
}

/**
 * _div - division of second top of stack by top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _div(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '/');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}

/**
 * _mul - multiplication of the two values at top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _mul(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '*');
	}
}

/**
 * _mod - modulo of second top of stack by top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _mod(stack_t **stack, unsigned int line_nb)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_nb);
		META.error = 1;
	}
	else
	{
		_math(stack, '%');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}
