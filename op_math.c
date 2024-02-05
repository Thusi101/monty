#include "monty.h"

/**
 * _add - addition of the first two values at top of stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _addop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
 * @line_number: the line number
 */

void _subop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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
 * @line_number: the line number
 */

void _divop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		META.error = 1;
	}
	else
	{
		_math(stack, '/');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_number);
	}
}

/**
 * _mul - multiplication of the two values at top of stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _mulop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
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
 * @line_number: the line number
 */

void _modop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		META.error = 1;
	}
	else
	{
		_math(stack, '%');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_number);
	}
}
