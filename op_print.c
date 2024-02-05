#include "monty.h"

/**
 * _pintop - prints the value from top of stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _pintop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		META.error = 1;
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * _pallop - prints all values from stack, from top to bottom
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _pallop(stacknode **stack, unsigned int line_number)
{
	stacknode *cur = *stack;
	(void)line_number;

	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

/**
 * _nopop - does absolutely nothing with nothing and prints nothing
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _nopop(stacknode **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pcharop - prints the value at top of stack as a char
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _pcharop(stacknode **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		META.error = 1;
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		META.error = 1;
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}

/**
 * _pstrop - prints the string starting at the top of the stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _pstrop(stacknode **stack, unsigned int line_number)
{
	stacknode *cur = *stack;
	(void)line_number;

	while (cur && (cur->n > 0 && cur->n <= 127))
	{
		printf("%c", cur->n);
		cur = cur->next;
	}
	printf("\n");
}
